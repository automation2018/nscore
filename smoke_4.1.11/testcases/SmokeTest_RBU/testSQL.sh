#!/bin/sh

dbname="test"
username="netstorm"
psql -t $dbname $username << EOF
SELECT onloadtime FROM  pagerbudetailrecord_44933;
EOF
