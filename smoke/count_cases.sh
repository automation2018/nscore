#  Returns count of testcases to run in current testsuite
function get_test_case_count() {
  testcases=$(cat testsuites/Smoke.conf |grep -v "#" | cut -d ' ' -f2)
  count=0
  for testcase in ${testcases}
  do
    i=$(grep -ci "^SMOKE-" testcases/${testcase}/iteration.spec)
    count=$((count + i))
  done
  echo ${count}
}

total_cases=$(get_test_case_count)
echo "toatal cases count = $total_cases"
