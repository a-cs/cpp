# !/bin/sh
make && clear
NAME=PmergeMe

# echo "\e[1;32mTest 1: Valid file name\e[0m"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME input.txt
# echo

# echo "\e[1;31mTest 2:Invalid file name\e[0m"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME invalidFilename.txt
# echo

echo
echo "\e[1;32mTest 1 - sort 10 numbers from 0 to 9\e[0m"
echo
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME `shuf -i 0-9 -n 10 | xargs`

echo
echo "\e[1;31mError tests\e[0m"
echo
echo "\e[1;31mTest 2 - No arguments\e[0m"
echo
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME

echo
echo "\e[1;31mTest 3 - Not an int: 10 1 2147483648\e[0m"
echo
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 10 1 2147483648

echo
echo "\e[1;31mTest 4 - Not a number: 10 a 2 3 321 1 42 42\e[0m"
echo
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 10 a 2 3 321 1 42 42

echo
echo "\e[1;31mTest 5 - All in one argument: \"42 42 0\"\e[0m"
echo
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME "42 42 0"

echo
echo "\e[1;31mTest 6 - Negative numbers: 10 984 -2 3 321 1 42 -42\e[0m"
echo
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 10 984 -2  3 321 1 42 -42