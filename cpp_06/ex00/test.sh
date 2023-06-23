make && clear
NAME=ScalarConverter

echo "\e[1;32mTest 1: convert char 'a'\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME a
echo

echo "\e[1;32mTest 2: convert int 42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42
echo

echo "\e[1;32mTest 3: convert float nanf\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME nanf
echo

echo "\e[1;32mTest 4: convert float 42.42f\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.42f
echo

echo "\e[1;32mTest 5: convert double nan\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME nan
echo

echo "\e[1;32mTest 6: convert double 42.42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.42
echo