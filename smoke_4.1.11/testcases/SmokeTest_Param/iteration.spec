$TestDescription|$ScriptName|$User|%Ord|%Rb|$Sessions|%REFRESH_MODE
#Cases for Search Param
SMOKE-009-001|Search_Param2Url|1|1|"9CAD"|1|//
SMOKE-009-002|Search_Param2Url_SaveLength|1|1|"NNNNN"|1|//
SMOKE-009-003|Search_Param2Url_SaveLengthWihtSaveOffset|1|1|"NNNNN"|1|//
SMOKE-009-004|Search_Param2Url_SaveLengthWihtSaveOffset|1|1|"NNNNN"|1|//
SMOKE-009-005|Search_Param2Url_TwopagesSearch_SaveLengthWihtSaveOffset|1|1|"</title>"|1|//
SMOKE-009-006|Search_Param2Url_ALLpagesSearch_SaveLengthWihtSaveOffset|1|1|"</title>"|1|//
#
#Cases for check point
SMOKE-009-007|TwoUrl_Checkpoint|1|FOUND|"WEB99CAD"|4|//
SMOKE-009-008|TwoUrl_Checkpoint|1|NOTFOUND|"WEBAD"|4|//
SMOKE-009-009|TwoUrl_Checkpoint_RegularExp|1|FOUND|"netstorm"|2|//
SMOKE-009-010|TwoUrl_Checkpoint_RegularExp|1|NOTFOUND|"nstorm"|2|//
SMOKE-009-011|TwoUrl_Checkpoint_RegularExp_ActionOnfailcontinue|1|NOTFOUND|"nstorm"|1|//
SMOKE-009-012|TwoUrl_Checkpoint_RegularExp_ActionOnfailStop|1|NOTFOUND|"nstorm"|1|//
SMOKE-009-013|TwoUrl_Checkpoint_File|1|FOUND|DataFile|2|//
SMOKE-009-014|TwoUrl_Checkpoint_File|1|FOUND|DataFileCVFail|2|//
#
#Cases for file param
SMOKE-009-015|FileParam_5Url_Use|1|USE|Userpass.dat|1|//
SMOKE-009-016|FileParam_5Url_Use|1|SESSION|Userpass.dat|4|//
#
#Miscellinous cases of parameterization
SMOKE-009-017|FileParam_5Url_ModeWeighted|1|USE|Userpass.dat|1|//
SMOKE-009-018|Search_Param2Url|1|1|"khth"|1|//
SMOKE-009-019|Search_Param5Url_SinglePagesSearch_SaveLengthWihtSaveOffset_ORD_ALL|1|ALL|"cavisson"|1|//
#
#Case for date and time parameter
#SMOKE-009-020|Parameterization_Script|1|//|//|1|//

#case for the validation of nsl_unique_number_var keyword 
SMOKE-009-021|hpd_tours_parameterization|1|NA|NA|3|USE
SMOKE-009-022|hpd_tours_parameterization|1|NA|NA|3|SESSION

#case for random number parameter,validation of nsl_random_number_var keyword
SMOKE-009-023|param_script|1|NA|NA|3|SESSION
SMOKE-009-024|param_script|3|NA|NA|3|USE

#case for json parameter
SMOKE-009-025|hpd_json|1|NA|NA|1|NA

#case for arrary parameter
SMOKE-009-026|hpd_tours_arrayPerameter|1|NA|NA|1|NA

#case for declare array parameter,validation of nsl_decl_array keyword
SMOKE-009-027|hpd_param|1|NA|NA|1|NA

#Case for static var parameter
#SMOKE-009-020|Parameterization_Script_static|1|SESSION|SEQUENTIAL|3
#SMOKE-009-021|Parameterization_Script_static|1|USE|SEQUENTIAL|3
