#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	int				pos = 0;
	std::string		dataFileName = "data.csv";
	std::ifstream	data(dataFileName.c_str());
	std::string		line;

	while (std::getline(data, line)) {
		if (pos == 0 || line.size() == 0) {
			pos++;
			continue;
		}
		std::string date;
		float value;

		date = line.substr(0, line.find(","));
		value = strtod(line.substr(line.find(",")+1).c_str(), NULL);
		this->database[date] = value;
		pos++;
	}
	data.close();
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
	std::string separator = " | ";

	dateStr = line.substr(0, line.find(separator));

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

bool	BitcoinExchange::isInvalidNumber(std::string line, float *nbr){
	std::string	numberStr = "";
	std::string separator = " | ";
	float number = 0;

	numberStr = line.substr(line.find(separator) + separator.size());
	number = strtod(numberStr.c_str(), NULL);
	if(numberStr != "0" && number == 0){
		std::cout << "Error: invalid number.\n";
		return true;
	}
	if (number > 1000) {
		std::cout << "Error: too large number.\n";
		return true;
	}
	if (number < 0) {
		std::cout << "Error: not a positive number.\n";
		return true;
	}
	*nbr = number;

	return false;
}

float	BitcoinExchange::getDbValueFromDate(std::string date){
	if (this->database.find(date) != this->database.end()) {
		return this->database.at(date);
	}

	std::map<std::string, float>::const_iterator upperBound = this->database.upper_bound(date);
	if (upperBound == this->database.begin()) {
		return upperBound->second;
	}
	--upperBound;
	return upperBound->second;
}


void	BitcoinExchange::displayValue(std::string line, int lineCount){
	std::string	date = "";
	float nbr = 0;
	
	if(isInvalidLine(line, lineCount))
		return ;
	if(isInvalidDate(line, &date)){
		std::cout << "Error: invalid date => \"" << date << "\"\n";
		return ;
	}
	if(isInvalidNumber(line, &nbr)){
		return ;
	}

	float dbValue = getDbValueFromDate(date);
	std::cout << date << " => " << nbr << " = " << nbr * dbValue << std::endl;
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
	file.close();
	return 0;
}