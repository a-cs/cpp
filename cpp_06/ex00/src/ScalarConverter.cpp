#include "../include/ScalarConverter.hpp"

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

bool ScalarConverter::isInt(const std::string &str){
	for(size_t i=0; i< str.length(); i++){
		if(i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if(!isdigit(str[i]))
			return false;
	}
	if(strtod(str.c_str(), NULL) > INT_MAX || strtod(str.c_str(), NULL) < INT_MIN )
		return false;
	return true;
}

void ScalarConverter::printInt(const std::string &str){
	std::string	c = "";
	int 		i;
	float		f;
	double		d;
	i = atoi(str.c_str());
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	if(i < 32)
		c = "Non displayable";
	if(i < 0 || i > 126)
		c = "impossible";
	printConversion(c, i, f, d);
}

bool ScalarConverter::isFloat(const std::string &str){
	if(str.find_first_of("f") == std::string::npos)
		return false;
	return true;
}

void ScalarConverter::printFloat(const std::string &str){
	std::string	c = "";
	int 		i;
	float		f;
	double		d;
	f = atof(str.c_str());
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	if(i >= 0 && i < 32)
		c = "Non displayable";
	if(i < 0 || i > 126)
		c = "impossible";
	printConversion(c, i, f, d);
}

void ScalarConverter::printDouble(const std::string &str){
	std::string	c = "";
	int 		i;
	float		f;
	double		d;
	d = atof(str.c_str());
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	if(i >= 0 && i < 32)
		c = "Non displayable";
	if(i < 0 || i > 126)
		c = "impossible";
	if(strtod(str.c_str(), NULL) > INT_MAX || strtod(str.c_str(), NULL) < INT_MIN ){
		printConversion(c, "impossible", f, d);
	}
	else{
		printConversion(c, i, f, d);
	}
}

bool ScalarConverter::hasMoreThanOneOfValidChars(const std::string &str){
	std::string	validChars = "+-.f";
	for(size_t i = 0; i< validChars.length(); i++)
		if(str.find_first_of(validChars[i]) != str.find_last_of(validChars[i]))
			return true;
	return false;
}

bool ScalarConverter::isInvalidString(const std::string &str){
	size_t fPos, dotPos, plusPos, minusPos;
	if(str.find_first_not_of("0123456789+-.f") != std::string::npos)
		return true;
	if(hasMoreThanOneOfValidChars(str))
		return true;

	fPos = str.find_first_of("f");
	if(fPos != std::string::npos && fPos != str.length() - 1)
		return true;
	dotPos = str.find_first_of(".");
	if(dotPos != std::string::npos && dotPos == str.length() - 1)
		return true;
	if(fPos != std::string::npos && dotPos != std::string::npos && dotPos == fPos - 1)
		return true;
	if(fPos == std::string::npos && dotPos != std::string::npos && dotPos < str.length() - 2)
		return true;
	if(fPos != std::string::npos && dotPos != std::string::npos && dotPos < str.length() - 3)
		return true;
	plusPos = str.find_last_of("+");
	// std::cout << "+pos = " << plusPos << "\n";
	if(plusPos != std::string::npos && plusPos != 0)
		return true;
	minusPos = str.find_last_of("-");
	if(minusPos != std::string::npos && minusPos != 0)
		return true;

	return false;
}


void ScalarConverter::printConversion(const std::string &c, const std::string &i, const float &f, const double &d){
	std::cout.precision(1);
	std::cout << std::fixed 
			<< "char: " << c << "\n"
			<< "int: " << i << "\n"
			<< "float: "<< f << "f\n"
			<< "double: "<< d << "\n";
}

void ScalarConverter::printConversion(const std::string &c, const int &i, const float &f, const double &d){
	std::string newC = "";
	
	if(c.length() == 1)
		newC = "'"+c+"'";
	else
		newC = c;
	std::cout.precision(1);
	std::cout << std::fixed 
			<< "char: " << newC << "\n"
			<< "int: " << i << "\n"
			<< "float: "<< f << "f\n"
			<< "double: "<< d << "\n";

}

void ScalarConverter::convert(const std::string &str){
	if(isPseudo(str))
		printPseudo(str);
	else if(isChar(str))
		printChar(str);
	else if(isInvalidString(str))
		std::cout << "The string has an Invalid character!\n";
	else if(isInt(str))
		printInt(str);
	else if(isFloat(str))
		printFloat(str);
	else
		printDouble(str);
}