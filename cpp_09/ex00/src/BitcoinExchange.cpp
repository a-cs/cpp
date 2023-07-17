#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}


BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj){
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj){
	if(this != &obj){
		this->database = obj.database;
	}
	return (*this);
}

bool	BitcoinExchange::isInvalidLine(std::string line, int lineCount){
	int	pipeCount = 0;

	if (lineCount == 0 && line == "date | value")
		return true;
	if (line.size() == 0)
		return true;
	pipeCount = std::count(line.begin(), line.end(), '|');
	if (pipeCount == 0 || pipeCount > 1 || line.size() < 14) {
		std::cout << "Error: bad input => " << line << std::endl;
		return true;
	}
	return false;
}

bool	BitcoinExchange::isInvalidDate(std::string line, std::string *date){
	int			year = 0;
	int			month= 0;
	int			day = 0;
	std::string	dateStr = "";

	dateStr = line.substr(0, line.find(" | "));

	*date = dateStr;
	if (dateStr.size() != 10)
		return true;

	sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day);
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		return true;
	if (month == 2 && day > 29)
		return true;
	if (month == 2 && day == 29 && year != 2012 && year != 2016 && year != 2020)
		return true;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		return true;
	if (dateStr < "2009-01-02" || dateStr > "2022-03-29")
		return true;

	return false;
}


void	BitcoinExchange::displayValue(std::string line, int lineCount){
	std::string	date = "";
	
	if(isInvalidLine(line, lineCount))
		return ;
	if(isInvalidDate(line, &date)){
		std::cout << "Error: invalid date => \"" << date << "\"\n";
		return ;
	}
	std::cout << line << std::endl;
}

int BitcoinExchange::run(char *fileName){
	std::ifstream	file(fileName);
	std::string		line;
	int				lineCount = 0;

	if(!file.is_open()){
		std::cout << "Error: Failed to open file \"" << fileName << "\"\n";
		return 1;
	}

	while(std::getline(file, line)){
		displayValue(line, lineCount);
		lineCount++;
	}
	// std::cout << fileName << std::endl;
	file.close();
	return 0;
}