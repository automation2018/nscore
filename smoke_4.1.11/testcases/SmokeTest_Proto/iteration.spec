$TestDescription|$ScriptName|$User|$Sessions|%type|%rr_type|%name
#
##DNS testcases
#SMOKE-010-001|Smoke_Dns|1|2|A|A|www.yahoo.com
#SMOKE-010-002|Smoke_Dns|1|2|AAAA|AAAA|www.yahoo.com
#SMOKE-010-003|Smoke_Dns|1|2|MX|MX|www.yahoo.com
#SMOKE-010-004|Smoke_Dns|1|2|NS|NS|www.yahoo.com
#SMOKE-010-005|Smoke_Dns|1|2|SOA|SOA|www.yahoo.com
#SMOKE-010-006|Smoke_Dns|1|2|PTR|PTR|www.yahoo.com
#SMOKE-010-007|Smoke_Dns|1|2|CNAME|CNAME|www.yahoo.com
#
##POP3 testcases
##SMOKE-010-008|Smoke_Pop3|1|3|//|//|//
#
##FTP test cases
SMOKE-010-009|Smoke_Ftp_Txt|1|1|Y|A|//
SMOKE-010-010|Smoke_Ftp_Bin|1|1|Y|I|//
SMOKE-010-011|Smoke_Ftp_Txt|1|1|N|A|//
SMOKE-010-012|Smoke_Ftp_Bin|1|1|N|I|//
#
##SMTP testcases
##SMOKE-010-013|Smoke_Smtp|1|1|automation@cavisson.com|Cavisson!|automation@cavisson.com
#
##IMAP testcases
#SMOKE-010-014|Smoke_Imap|1|1|HEADER|1|10.10.30.96
#SMOKE-010-015|Smoke_Imap|1|1|TEXT|1|10.10.30.96
#SMOKE-010-016|Smoke_Imap|1|1|BODY|2|10.10.30.96
#
##HESSIAN testcases
#SMOKE-010-017|Smoke_Hessian|1|1|//|//|/home/netstorm/work/scripts/Smoke_Hessian/HessianService1.xml
#SMOKE-010-018|Smoke_Hessian|1|1|//|//|/home/netstorm/work/scripts/Smoke_Hessian/HessianService2.xml
