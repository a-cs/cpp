#!/bin/bash
make && clear
NAME=sed


echo "pineapple straberry watermelon fruit juice lemon" > file

echo -e "\e[1;32mTest 1: "a" => "b"\e[0m"
./$NAME file "a" "b" && cat file.replace
sed 's/a/b/g' file

echo

echo -e "\e[1;32mTest 2: "pineapple" => "pear"\e[0m"
./$NAME file "pineapple" "pear" && cat file.replace
sed 's/pineapple/pear/g' file

echo

echo -e "\e[1;32mTest 3: "strawberry" => "orange"\e[0m"
./$NAME file "strawberry" "orange" && cat file.replace
sed 's/strawberry/orange/g' file

echo

echo -e "\e[1;32mTest 4: "fruit" => "car"\e[0m"
./$NAME file "fruit" "car" && cat file.replace
sed 's/fruit/car/g' file

echo

echo -e "\e[1;32mTest 5: "r" => "l"\e[0m"
./$NAME file "r" "l" && cat file.replace
sed 's/r/l/g' file

echo

echo -e "\e[1;32mTest 6: "watermelon" => "watermelonTomato"\e[0m"
./$NAME file "watermelon" "watermelonTomato" && cat file.replace
sed 's/watermelon/watermelonTomato/g' file

echo

echo -e "\e[1;31mTest 7: invalid file\e[0m"
./$NAME invalid_file "fruit" "fruit" && cat file.replace
sed 's/"fruit"/"fruit"/g' invalid_file

echo

echo -e "\e[1;31mTest 8: two arguments\e[0m"
./$NAME file "fruit" && cat file.replace

echo

echo -e "\e[1;31mTest 9: four arguments\e[0m"
./$NAME file "fruit" "fruit" "fruit" && cat file.replace

echo

echo -e "\e[1;31mTest 10: "empty string" => "empty string"\e[0m"
./$NAME file "" "a" && cat file.replace
sed 's/""/""/g' file

echo

echo -e "\e[1;31mTest 11: "a" => "empty string"\e[0m"
./$NAME file "a" "" && cat file.replace
sed 's/a//g' file

echo
