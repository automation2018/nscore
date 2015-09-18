#!/usr/bin/env python

import xml.dom.minidom 

# Class to hold the TestResults object
class TestResultsModel(object):
    def __init__(self,id,testrun,status,description):
        self.id          = id
        self.testrun     = testrun 
        self.status      = status
        self.description = description

    # Returns the testresults as dictionary of items 
    def asDict(self):
        testresults = { 
           'id'          : self.id,
           'testrun'     : self.testrun,
           'status'      : self.status,
           'description' : self.description
        }
        return testresults 
  

# Parse the testresults object,
# where object is a list of all testcases  
def parse(testresults, name, failcount, passcount, totalcount):
    '''
    XSD: 
    <testsuites>
        <testsuite name = "">
            <testcase id = "">
                <testrun></testrun>
                <status></status>
                <description></description>
            </testcase>
        </testsuite>
    </testsuites>
    '''   
      
    doc = xml.dom.minidom.Document()

    root = doc.createElement("testsuites")
    testsuite = doc.createElement("testsuite")
    #testsuite.setAttribute("name", name) 
    #root.setAttribute("name", name) 
    testsuite.setAttribute("failures", failcount) 
    testsuite.setAttribute("passed", passcount) 
    testsuite.setAttribute("total", totalcount) 
 
    doc.appendChild(root)
    root.appendChild(testsuite) 
   
    for r in testresults:
        testcase = doc.createElement("testcase")
        testcase.setAttribute("id",r['id'])
    
        # Create element nodes for testcase 
        testrun = doc.createElement("testrun")
        status = doc.createElement("status") 
        description = doc.createElement("description") 
        fmt = doc.createElement("format") 
  
        # Create text nodes for items and append to element nodes  
        testrun.appendChild(doc.createTextNode(r['testrun']))
        status.appendChild(doc.createTextNode(r['status']))
        description.appendChild(doc.createTextNode(r['description']))

        # Add all child nodes to testcase element node
        testcase.appendChild(testrun)
        testcase.appendChild(status)
        testcase.appendChild(description)
     
        #Finally add the testcase node to root node.
        #root.appendChild(testcase)
        testsuite.appendChild(testcase)
 
    # Returns a formatted XML with indentation = 4
    #return doc.toprettyxml(indent = "    ") 
    return doc



def parseCommandLine():
    import argparse 
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input",
                        help="The Input Test Results File in text format",
                        required=True) 

    parser.add_argument("-o", "--output",
                        help="The Output Test Results File in XML format. Not mandatory. It will parse the filename from input file",
                        required=False) 
    parser.add_argument("-n", "--name",
                        help="Testsuite name", 
                        required=False) 
     
    parser.add_argument("-f", "--failed",
                        help="Failed Testcases count",
                        required=False) 
    parser.add_argument("-p", "--passed",
                        help="Passed Testcases count",
                        required=False) 

    parser.add_argument("-t", "--total",
                        help="Total Testcases count",
                        required=False) 
    return parser
   
def processTestResultsFile(testresultFile):
    l = [] 
    with open(testresultFile, 'r') as f:
        for line in f:
            if line.startswith("TestID") or (line.strip() == "") or line.startswith("Failed"):
                continue
    
            id, testrun, status, desc = line.split(",")
            l.append(TestResultsModel(id, testrun, status, desc.strip()).asDict())
    
    return l 
     

def writeXML(outfile, data):
    with open(outfile, 'w') as outfile:
        outfile.write(data.toprettyxml(indent = "    ")) 


def main():
    parser = parseCommandLine() 
    opts = parser.parse_args() 

    infile  = opts.input 
    outfile = opts.output
    name = opts.name 
    failcount = opts.failed
    passcount = opts.passed 
    totalcount = opts.total 


    if not outfile:
        import os 
        outfile, ext = os.path.splitext(infile)
        outfile  = outfile + ".xml" 

    if not name:
        name = "Default" 
       
    if not failcount:
        failcount = "NA"
    
    if not passcount:
        passcount = "NA"
    
    if not totalcount:
        totalcount = "NA"     
       
    
         
    testresult = processTestResultsFile(infile)
    result = parse(testresult, name, failcount, passcount, totalcount) 
    writeXML(outfile, result) 
       
      
if __name__ == "__main__":
    main() 

