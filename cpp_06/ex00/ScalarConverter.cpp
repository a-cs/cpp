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

void ScalarConverter::convert(const std::string &str){
	std::string	c,i = "";
	float		f = 0.0;
	double		d = 0.0;
	
	if(isPseudo(str)){
		c = "impossible";
		i = "impossible";
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
	}


	std::cout << "char:" << c << "\n"
			<< "int:" << i << "\n"
			<< "float: "<< f << "f\n"
			<< "double: "<< d << "\n";

}