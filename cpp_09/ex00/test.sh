# !/bin/sh
make && clear
NAME=btc

echo "\e[1;32mTest 1: Valid file name\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME input.txt
echo

echo "\e[1;31mTest 2:Invalid file name\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME invalidFilename.txt
echo


echo "\e[1;31mTest 2:Invalid values\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME invalidValues.txt
echo