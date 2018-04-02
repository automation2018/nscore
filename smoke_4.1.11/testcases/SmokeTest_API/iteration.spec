#######################################################################################################################
#  Iteration suit for C api's                          								      #
#  Use "NA" to replace strings where values are not applicable(FILE_NAME and inputString)                             #
#  Use -1 to replace integers where values are not applicable(FILE_MODE and TEST_CASE_TYPE_NUM)                       #
#  $ Replaces values from iteration.spec to scenario and % replaces values from iteration.spec to flow file in script #
#######################################################################################################################
$TestDescription|$ScriptName|$User|%inputString|%API_TYPE|%TEST_CASE_TYPE_NUM|%FILE_NAME|%FILE_MODE
######################################################################################################################
SMOKE-001-001|API|1|"string to be saved decl var using save_string_api"|SAVE_STRING|0|"NA"|-1

SMOKE-001-002|API|1|"NA"|EVAL_STRING|0|"NA"|-1

SMOKE-001-003|API|1|"NA"|ADV_PARAM|0|"NA"|-1

SMOKE-001-004|API|1|"NA"|ADV_PARAM|1|"NA"|-1

SMOKE-001-005|API|1|"Testing NS_SAVE_DATA_VAR api"|SAVE_DATA_VAR|-1|"save.data"|NS_APPEND_FILE

SMOKE-001-006|API|1|"Testing NS_SAVE_DATA_VAR api"|SAVE_DATA_VAR|-1|"/home/netstorm/save.data"|NS_TRUNC_FILE

SMOKE-001-007|API|1|"Testing NS_SAVE_DATA_VAR api"|SAVE_DATA_VAR|-1|"/root/save.data"|NS_TRUNC_FILE

SMOKE-001-008|API|1|"Testing NS_SAVE_DATA_VAR api"|SAVE_DATA_VAR|-1|"/ThisPathDoNotExists/save.data"|NS_TRUNC_FILE

SMOKE-001-009|API|1|"Testing NS_SAVE_DATA_EVAL api"|SAVE_DATA_EVAL|-1|"save.data"|NS_APPEND_FILE

SMOKE-001-010|API|1|"Testing NS_SAVE_DATA_EVAL api"|SAVE_DATA_EVAL|-1|"/home/netstorm/save.data"|NS_TRUNC_FILE

SMOKE-001-011|API|1|"Testing NS_SAVE_DATA_EVAL api"|SAVE_DATA_EVAL|-1|"/root/save.data"|NS_TRUNC_FILE

SMOKE-001-012|API|1|"Testing NS_SAVE_DATA_EVAL api"|SAVE_DATA_EVAL|-1|"/ThisPathDoNotExists/save.data"|NS_TRUNC_FILE

SMOKE-001-013|API|1|"Testing NS_SAVE_DATA_EX api"|SAVE_DATA_EX|-1|"save.data"|NS_APPEND_FILE

SMOKE-001-014|API|1|"Testing NS_SAVE_DATA_EX api"|SAVE_DATA_EX|-1|"/home/netstorm/work/save.data"|NS_TRUNC_FILE 

SMOKE-001-015|API|1|"Testing NS_SAVE_DATA_EX api"|SAVE_DATA_EX|-1|"/root/save.data"|NS_APPEND_FILE

SMOKE-001-016|API|1|"Testing NS_SAVE_DATA_EX api"|SAVE_DATA_EX|-1|"/ThisPathDoNotExists/save.data"|NS_TRUNC_FILE

SMOKE-001-017|API|1|351988|SET_INT_VAL|0|"NA"|-1

SMOKE-001-018|API|1|"NA"|GET_INT_VAL|0|"NA"|-1

SMOKE-001-019|API|1|"a-z0-9A-Z._"|GET_RANDOM_STR|0|"NA"|-1 

SMOKE-001-020|API|1|"NA"|GETTERS|0|"NA"|-1  

SMOKE-001-021|API|1|"Ever wondered why Jack and Jill went up the hill?"|CHK_STR_CPY|0|"NA"|-1

SMOKE-001-024|hpd_msg_resp_api|1|"Hello everyone"|API_GET_RESPONSE_MESSAGE|0|"api_resp.html"|NS_TRUNC_FILE
