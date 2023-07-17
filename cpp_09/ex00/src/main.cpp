#include "../include/BitcoinExchange.hpp"

int	main(int argc, char** argv) {
	if(argc != 2){
		std::cout << "Error: invalid arguments, you must provide only a file name as an argument.\n";
		return 1;
	} else {
		BitcoinExchange bitcoinExchange;
		
		return (bitcoinExchange.run(argv[1]));
	}

}