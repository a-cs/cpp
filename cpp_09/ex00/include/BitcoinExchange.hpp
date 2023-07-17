
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &obj);
    	BitcoinExchange &operator=(BitcoinExchange const &obj);
		~BitcoinExchange();

		int 	run(char *fileName);
		void	displayValue(std::string line, int lineCount);
		bool	isInvalidLine(std::string line, int lineCount);
		bool	isInvalidDate(std::string line, std::string *date);
};

#endif