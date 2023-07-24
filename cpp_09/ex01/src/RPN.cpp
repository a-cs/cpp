#include "../include/RPN.hpp"

RPN::RPN() {}


RPN::~RPN() {}

RPN::RPN(RPN const &obj){
	*this = obj;
}

RPN &RPN::operator=(RPN const &obj){
	if(this != &obj){
		this->inputElementsList = obj.inputElementsList;
	}
	return (*this);
}

bool	RPN::validateInput(std::string input){
	for(size_t i = 0; i < input.size(); i++){
		if(input[i] == ' ')
			continue;
		if(std::isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			this->inputElementsList.push_back(input[i]);
		else {
			std::cout << "Error\n";
			return false;
		}
	}
	return true;
}

int RPN::calculate(std::string input){
	std::list<int>	resultList;
	int				result = 0;

	if(!validateInput(input)){
		return 1;
	}

	for (std::list<char>::iterator it = this->inputElementsList.begin(); it != this->inputElementsList.end(); it++){
		if(it == this->inputElementsList.begin()){
			resultList.push_front(*it - '0');
			it++;
			if(!std::isdigit(*it)){
				std::cout << "Error\n";
				return 1;
			}
			resultList.push_front(*it - '0');
			continue;
		}
		else {
			if(!std::isdigit(*it)){
				if(resultList.size() < 2){
					std::cout << "Error\n";
					return 1;
				}
				result = resultList.front();
				resultList.pop_front();
				if(*it == '+')
					result = resultList.front() + result;
				else if(*it == '-')
					result = resultList.front() - result;
				else if(*it == '*')
					result = resultList.front() * result;
				else if(*it == '/'){
					if(result == 0){
						std::cout << "Error\n";
						return 1;
					}
					result = resultList.front() / result;
				}
				resultList.pop_front();
				resultList.push_front(result);
			} else
				resultList.push_front(*it - '0');
		}
	}

	if(resultList.size() != 1){
		std::cout << "Error\n";
		return 1;
	}

	std::cout << resultList.front() << std::endl;
	
	return 0;
}