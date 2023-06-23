#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}


ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj){
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj){
	(void)obj;
	return (*this);
}

bool ScalarConverter::isPseudo(const std::string &str){
	std::string specialTypes[6] = {
	"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	for(int i = 0; i < 6; i++)
	{
		if(str == specialTypes[i])
			return true;
	}
	return false;
}

void ScalarConverter::printPseudo(const std::string &str){
	std::string	c= "impossible";
	std::string	i= "impossible";
	float		f = 0.0;
	double		d = 0.0;
	if (str[str.length() - 1] == 'f')
	{
		f = atof(str.c_str());
		d = static_cast<double>(f);
	}
	else
	{
		d = atof(str.c_str());
		f = static_cast<float>(d);
	}
	printConversion(c, i, f, d);
}

bool ScalarConverter::isChar(const std::string &str){
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

void ScalarConverter::printChar(const std::string &str){
	std::string	c = "";
	int 		i;
	float		f;
	double		d;
	c += str;
	i = static_cast<int>(str[0]);
	f = static_cast<float>(str[0]);
	d = static_cast<double>(str[0]);
	printConversion(c, i, f, d);
}


void ScalarConverter::printConversion(const std::string &c, const std::string &i, const float &f, const double &d){
	std::cout << "char:" << c << "\n"
			<< "int:" << i << "\n"
			<< "float: "<< f << "f\n"
			<< "double: "<< d << "\n";
}

void ScalarConverter::printConversion(const std::string &c, const int &i, const float &f, const double &d){
	std::cout << "char:" << c << "\n"
			<< "int:" << i << "\n"
			<< "float: "<< f << "f\n"
			<< "double: "<< d << "\n";
}

void ScalarConverter::convert(const std::string &str){
	if(isPseudo(str)){
		printPseudo(str);
		return ;
	}

	if(isChar(str)){
		printChar(str);
		return ;
	}

	



}