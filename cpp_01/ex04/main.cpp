/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:11:07 by acarneir          #+#    #+#             */
/*   Updated: 2023/04/04 21:37:49 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace(std::string line, std::string oldStr, std::string newStr){
	int	i = 0;
	if (oldStr.empty())
		return (line);

	while (true)
	{
		i = line.find(oldStr, i);
		if(i == std::string::npos){
			return line;
		}
		line.erase(i, oldStr.length());
		line.insert(i, newStr);
		i += newStr.length();
	}
	
}

int	main(int argc, char **argv) {
	std::ifstream	file;
	std::ofstream	fileReplace;
	std::string		line;

	if(argc != 4) {
		std::cout << "You should pass 3 arguments (a filename and two strings).\n";
		return 1;
	}
	file.open(argv[1]);
	if (!file.is_open()){
		std::cout << "Could not find a valid file with the name: " << argv[1] << "\n";
		return 1;
	}
	fileReplace.open((std::string)argv[1] + ".replace");
	while(getline(file, line)) {
		line = replace(line, argv[2], argv[3]);
		fileReplace << line << "\n";
	}
	file.close();
	fileReplace.close();
	
	return (0);
}