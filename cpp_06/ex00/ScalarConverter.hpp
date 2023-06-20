#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
    	ScalarConverter &operator=(ScalarConverter const &obj);
		static bool isPseudo(const std::string &str);

	public:
		~ScalarConverter();

		static void	convert(const std::string &str);

};

#endif