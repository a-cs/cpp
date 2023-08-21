# !/bin/sh
make && clear
NAME=RPN

echo
echo "\e[1;32mTest 1: \"8 9 * 9 - 9 - 9 - 4 - 1 +\"\e[0m"
echo "Expected: 42"
echo -n "Result:   "
./$NAME "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo
echo "\e[1;32mTest 2: \"7 7 * 7 -\"\e[0m"
echo "Expected: 42"
echo -n "Result:   "
./$NAME "7 7 * 7 -"

echo
echo "\e[1;32mTest 3: \"1 2 * 2 / 2 * 2 4 - +\"\e[0m"
echo "Expected: 0"
echo -n "Result:   "
./$NAME "1 2 * 2 / 2 * 2 4 - +"

echo
echo "\e[1;31mTest 4: \"(1 + 1)\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "(1 + 1)"

echo
echo "\e[1;31mTest 5: \"1 2 3 +\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "1 2 3 +"

echo
echo "\e[1;31mTest 6: \"12 3 +\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "12 3 +"

echo
echo "\e[1;31mTest 7: \"1 + 2\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "1 + 2"

echo
echo "\e[1;31mTest 8: \"1 a +\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "1 a +"

echo
echo "\e[1;31mTest 9: \"1\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "1"

echo
echo "\e[1;31mTest 10: \"1.5 + 2\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "1.5 + 2"

echo
echo "\e[1;31mTest 11: \"+ 1 1\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "+ 1 1"

echo
echo "\e[1;31mTest 12: \"1 0 /\"\e[0m"
echo "Expected: Error"
echo -n "Result:   "
./$NAME "1 0 /"