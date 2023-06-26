make && clear
NAME=ScalarConverter

echo "\e[1;32mTest 1: convert char 'a'\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME a
echo

echo "\e[1;32mTest 2: convert int 42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42
echo

echo "\e[1;32mTest 3: convert int +2147483647 \e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME +2147483647 
echo

echo "\e[1;32mTest 4: convert double +2147483648 \e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME +2147483648 
echo

echo "\e[1;32mTest 5: convert int -2147483648 \e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME -2147483648 
echo

echo "\e[1;32mTest 6: convert double -2147483649 \e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME -2147483649 
echo

echo "\e[1;32mTest 7: convert float nanf\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME nanf
echo

echo "\e[1;32mTest 8: convert float 42f\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42f
echo

echo "\e[1;32mTest 8: convert float 42.4f\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.4f
echo

echo "\e[1;32mTest 9: convert double nan\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME nan
echo

echo "\e[1;32mTest 10: convert double 42.4\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.4
echo

echo "\e[1;31mTest 11: invalid 42ab42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42ab42
echo

echo "\e[1;31mTest 12: invalid 42.42ff\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.42ff
echo

echo "\e[1;31mTest 13: invalid 42..42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42..42
echo

echo "\e[1;31mTest 14: invalid ++42\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME ++42
echo

echo "\e[1;31mTest 15: invalid 4f2\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 4f2
echo

echo "\e[1;31mTest 16: invalid 42.\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.
echo

echo "\e[1;31mTest 17: invalid 42.f\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.f
echo

echo "\e[1;31mTest 18: invalid 42.00\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.00
echo

echo "\e[1;31mTest 18: invalid 42.00f\e[0m"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./$NAME 42.00f
echo