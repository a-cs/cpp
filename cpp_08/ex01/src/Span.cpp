#include "Span.hpp"

Span::Span(): n(0){}


Span::~Span() {}

Span::Span(Span const &obj){
	*this = obj;
}

Span &Span::operator=(Span const &obj){
	if(this != &obj){
		this->n = obj.n;
		this->vec = obj.vec;
	}
	return (*this);
}	

Span::Span(unsigned int n): n(n){}


void	Span::addNumber(int number){
	if(vec.size() == n)
		throw std::out_of_range("The Span is already full");
	vec.push_back(number);
}

int		Span::shortestSpan(){
	if(this->vec.size() <= 1)
		throw std::out_of_range("Not enough elements to calculate the distance");
	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	int distance = INT_MAX;
	for (unsigned int i = 0; i + 1 < sortedVec.size(); i++) {
		int currentDistance = sortedVec[i + 1] - sortedVec[i];
		if (currentDistance < distance) {
			distance = currentDistance;
		}
	}
	return distance;
}

int		Span::longestSpan(){
	if(this->vec.size() <= 1)
		throw std::out_of_range("Not enough elements to calculate the distance");
	int max = *std::max_element(vec.begin(), vec.end());
	int min = *std::min_element(vec.begin(), vec.end());
	return max - min;
}

void	Span::fillNextAvailablePositionsWithValue(unsigned int pos, int value){
	unsigned int i = 0;

	if (vec.size() + pos > n) 
		throw std::out_of_range("Position is greater than the available Span size");
	
	while (i < pos) {
		vec.push_back(value);
		i++;
	}
}

