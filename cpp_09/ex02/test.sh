# !/bin/sh
make re && clear
NAME=PmergeMe

echo
echo "\e[1;32mTest 1 - sort 1 number\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 1

echo
echo "\e[1;32mTest 1 - sort 2 number\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 2 1

echo
echo "\e[1;32mTest 1 - sort 3 number\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 2 1 3

echo
echo "\e[1;32mTest 1 - sort 4 number\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 2 0 4 3

echo
echo "\e[1;32mTest 1 - sort 5 number\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 5 2 0 4 3

echo
echo "\e[1;32mTest 1 - sort 14 numbers\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 94 58 23 95 75 20 33 10 78 0 76 7 70 65

echo
echo "\e[1;32mTest 2 - sort 15 numbers\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 94 58 23 95 75 20 33 10 78 0 76 7 70 65 87

# echo
# echo "\e[1;32mTest 1 - sort 10 numbers from 0 to 9\e[0m"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME `shuf -i 0-9 -n 10 | xargs`

# echo
# echo "\e[1;32mTest 2 - sort 11 numbers from 0 to 10\e[0m"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME `shuf -i 0-10 -n 11 | xargs`

echo
echo "\e[1;31mError tests\e[0m"
echo "\e[1;31mTest 2 - No arguments\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME

echo
echo "\e[1;31mTest 3 - Not an int: 10 1 2147483648\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 10 1 2147483648

echo
echo "\e[1;31mTest 4 - Not a number: 10 a 2 3 321 1 42 42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 10 a 2 3 321 1 42 42

echo
echo "\e[1;31mTest 5 - All in one argument: \"42 42 0\"\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME "42 42 0"

echo
echo "\e[1;31mTest 6 - Negative numbers: 10 984 -2 3 321 1 42 -42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 10 984 -2  3 321 1 42 -42

echo
echo "\e[1;31mTest 7 - Duplicates: 1 42 42 0\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 1 42 42 0