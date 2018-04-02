import sqlite3
import csv
import sys

class FixtureModel(object):
    def __init__(self, testid, categoryid, componentid, description): 
        self.testid      = testid
        self.categoryid  = categoryid
        self.componentid = componentid
        self.description = description

    def asDict(self):
        fixtures = {
           'testid' : self.testid,
           'category'     : self.categoryid, 
           'componentid' : self.componentid,
           'description' : self.description
        }
        return fixtures

class SQLiteToCsv(object):

    def __init__(self, db):
        self.database = db

    def dump(self, sql, filename):
        f = csv.writer(file(filename, 'wb'))

        connection = sqlite3.connect(self.database)
        cursor = connection.cursor()

        cursor.execute(sql)

        f.writerow([d[0] for d in cursor.description])

        f.writerows(cursor.fetchall())

class CsvToSqlite(object):
    
    def process(self, infile):
        l = []
        with open(infile, 'r') as f:
            for line in f:
                testid, categoryid, componentid, description = line.strip().split(",")
                l.append(FixtureModel(testid, categoryid, componentid, description).asDict())
        return l
    
    def upload_to_db(self, db, arr):
	connection = sqlite3.connect(db)
	cursor = connection.cursor()
	
	cursor.execute('SELECT id FROM fixtures WHERE id=(SELECT MAX(id) FROM fixtures)')
	max_id = cursor.fetchone()
	_id = int(max_id[0])
	data = []

	for result in arr:
	    data.append((_id + 1,
		result['componentid'],
		result['category'],
		result['testid'],
		result['description']))
	    _id += 1
  
	cursor.executemany('''INSERT INTO 
		fixtures 
		VALUES(?, ?, ?, ?, ?)''', data)
        connection.commit()
	cursor.close()
        
if __name__ == '__main__':
    obj1 = CsvToSqlite()  
    database = 'analytics.db'
    ld = obj1.process(sys.argv[1])
    obj1.upload_to_db(database, ld)

    obj2 = SQLiteToCsv('analytics.db')
    #sql = 'select name,categoryid,componentid,description from testcase where buildid = 31 and categoryid = 2'
    obj2.dump(sql, sys.argv[1])
