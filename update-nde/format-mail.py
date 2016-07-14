#!/usr/bin/env python

# Author : Vishal Singhal
# Purpose : Generate html mail report for NDE test updates


import jinja2
import sys

nde_out_file = "/home/automation/workbench/automation/nscore/logs/out.html"


def check_and_set_project_status(mail_status):
    if mail_status == 'FAIL' or mail_status == 'ABORT':
        stat = "<td style='background-color: #FBE9E7'>Failed</td>"
    else:
        stat = "<td style='background-color: #E8F5E9'>Passed</td>"
    return stat


def get_version():
	with open('/home/netstorm/work/etc/version') as fr:
		data = fr.readlines()
		release = data[0].strip().split(' ')[1]
		version = data[1].strip().split(' ')[1]

	return release, version


html = """
<!DOCTYPE html>
<html>
<head>
    <style type='text/css'>
        hr {
          color: #A3C3FF;
        }
        .lead {
        font-size: 1.68rem;
        color: #616161;
        font-weight: 300;
        }
  
        body{
            font-size: .9rem;
            color: #333;
        }
       .container{
          width: 90%;
          padding: 50px;
          border: 1px solid #e0e0e0;
        }
        table {
            border-collapse: collapse;
            width: 80%;
        }
        table, th, td {
            border: 1px solid #e0e0e0;
            padding: 10px;
            font-size: 1em;
        }
        th {
           background-color: #f5f5f5;
           text-align: left;
           color: #333;
        }
         tr td{
        }
        .divider {
          border-top: 1px solid #e0e0e0;
        }

        .signature{ color: #607d8b;}

    </style>
</head>
<body>
    <div class='container'>
    <table style='width: 92%!important; border: 0px;'>
        <tr>
          <td width='30%' style='border: 0px!important; padding: 0px !important'><h2 class='lead'>Report For: Continuous Monitoring</h2></td>
          <td width='70%' style='border: 0px! important; padding: 0px!important'>
            <table>
               <tr>
               <th>Status</th>
               <th>Host</th>
			   <th>Start Time</th>
			   <th>End Time</th>
               </tr>
               <tr>
			   {{ message.head_status }}
               <td>216.66.23.194</td>
			   <td>{{ message.smokestart }}</td>
			   <td>{{ message.smokeend }}</td>
               </tr>
            </table>
          </td>
        </tr>
    </table>
    <br>
	 <table style='width: 80%!important; border: 0px;'>
        <caption class='lead'>{{ message.caption }}</caption>
		   <tr>
			 <th>Task</th>
			 <th>Start Time</th>
			 <th>End Time</th>
			 <th>Status</th>
		   </tr>
		   {% for row in message.table %}
			   <tr>
				 <td>{{ row.task }}</td>
				 <td>{{ row.start }}</td>
				 <td>{{ row.end }}</td>
                 {% if row.status == "FAIL" %}
				     <td style='background-color: #FBE9E7'>FAIL</td>
				 {% elif row.status == "PASS" %}
                     <td style='background-color: #E8F5E9'>PASS</td>
				 {% else %}
				     <td style='background-color: #ff9999'>ABORT</td>
				 {% endif %}
			   </tr>
		   {% endfor %}
	  </table>

    <br><br>

	{% if message.status == 'PASS' %}
	     <ol>
		     <li>Running test was stopped successfully </li>
		     <li>Cloud server upgraded with latest build {{ message.release }} B{{ message.build }}</li>
			 <li>Started the test again</li>
		 </ol>
	{% else %}
	     <ol>
		     <li>Cloud server updates aborted. Please check trend and logs</li>
		 </ol>
	{% endif %}

    <br><br>

    <p class='signature'>
        Automation Team,
        <br>Cavisson Systems Inc
    </p>

    </div>
</body>
</html>"""

args = sys.argv
message = {
    'caption' : 'Individual Task Status',
	'smokestart' : args[1],
    'table' : [
        {'task' : 'Smoke Health Status',
        'start' : args[1],
		'end' : args[2],
		'status' : args[3]
		},
		{ 'task' : 'Test Stop',
		'start' : args[4],
		'end' : args[5],
		'status' : args[6],
		},
		{ 'task' : 'Build Upgrade',
		'start' : args[7],
		'end' : args[8],
		'status' : args[9]
		},
		{ 
		'task' : 'Test Start',
		'start' : args[10],
		'end' : args[11],
		'status' : args[12]
		}
],
    'status' : args[12],
	'smokeend' : args[13],
}

head_stat = check_and_set_project_status(args[12])
rel, ver = get_version()
message['release'] = rel
message['build'] = ver
message['head_status'] = head_stat 
p = jinja2.Template(html)

with open(nde_out_file, 'w') as fw:
	fw.write(p.render(message=message))
