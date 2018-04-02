$TestDescription|$Script|$User|$Sessions|%trans1|%trans2|%trans3|%trans4|%end_as|$Server_host

#Case1- One static and multiple dynamic transactions.
SMOKE-066-001|Smoke_Dynamic_Tx|5|50|"static_tx"|"{dynamic1}"|"{dynamic2}"|"{dynamic3}"|#|127.0.0.1 10.10.30.69 -

#Case2- All dynamic transactions.
SMOKE-066-002|Smoke_Dynamic_Tx|5|50|"{dummy_tx}"|"{dynamic1}"|"{dynamic2}"|"{dynamic3}"|#|127.0.0.1 10.10.30.69 -

#Case3- One static using c-var and multiple dynamic transactions.
SMOKE-066-003|Smoke_Dynamic_Tx|5|50|c_var|"{dynamic1}"|"{dynamic2}"|"{dynamic3}"|#|127.0.0.1 10.10.30.69 -

#Case4- Static to c-var using end_as.
SMOKE-066-004|Smoke_Dynamic_Tx2|5|50|"static_tx"|"{dynamic1}"|"static_tx2"|"{dynamic3}"|var|127.0.0.1 10.10.30.69 -

#Case5- Dynamic to c-var using end_as.
SMOKE-066-005|Smoke_Dynamic_Tx2|5|50|"static_tx"|"{dynamic1}"|"{dynamic2}"|"{dynamic3}"|var|127.0.0.1 10.10.30.69 -

#Case6- C-var to dynamic using end_as.
SMOKE-066-006|Smoke_Dynamic_Tx2|5|50|"static_tx"|"{dynamic1}"|var|"{dynamic2}"|"{dynamic3}"|127.0.0.1 10.10.30.69 -

#Case7- Static to dynamic using end_as.
SMOKE-066-007|Smoke_Dynamic_Tx2|5|50|"static_tx"|"{dynamic1}"|"static_tx2"|"{dynamic2}"|"{dynamic3}"|127.0.0.1 10.10.30.69 -

#Case8- Dynamic to static using end_as.
SMOKE-066-008|Smoke_Dynamic_Tx2|5|50|"static_tx"|"{dynamic1}"|"{dynamic2}"|"{dynamic3}"|"static_tx2"|127.0.0.1 10.10.30.69 -
