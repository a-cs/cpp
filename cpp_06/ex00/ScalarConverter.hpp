#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
    	ScalarConverter &operator=(ScalarConverter const &obj);
		static bool isPseudo(const std::string &str);
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isInvalidString(const std::string &str);
		static bool hasMoreThanOneOfValidChars(const std::string &str);
		static void printPseudo(const std::string &str);
		static void printChar(const std::string &str);
		static void printInt(const std::string &str);
		static void printConversion(const std::string &c, const std::string &i, const float &f, const double &d);
		static void printConversion(const std::string &c, const int &i, const float &f, const double &d);

	public:
		~ScalarConverter();

		static void	convert(const std::string &str);

};

#endif