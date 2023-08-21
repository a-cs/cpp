# !/bin/sh
make && clear
NAME=btc

echo "\e[1;32mTest 1: Valid file name\e[0m"
./$NAME input.txt
echo

echo "\e[1;31mTest 2: Invalid file name\e[0m"
./$NAME invalidFilename.txt
echo


echo "\e[1;31mTest 3: Invalid values\e[0m"
./$NAME invalidValues.txt
echo