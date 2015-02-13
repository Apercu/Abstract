/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 11:38:00        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#include <iostream>
#include <fstream>
#include "Parser.hpp"

Parser::Parser (char * str)
{
	std::ifstream	file;

	if (str) {
		file.open(str);
		if (!file.is_open()) {
			throw Parser::BadInputException(__FILE__, __LINE__);
		}
	}

	std::string line;
	while (std::getline((str ? file : std::cin), line)) {
		if (!line.compare(";;")) {
			std::cout << "END" << std::endl;
		} else if (line.at(0) != ';') {
			std::cout << "not comment" << std::endl;
		}
		std::cout << line << std::endl;
	}
}

Parser::~Parser (void)
{
}
