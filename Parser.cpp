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
			throw ExecutionException("The specified input can't be opened", __FILE__, __LINE__);
		}
	}

	// "No exit instruction has been found within your program "

	std::string line;

	while (std::getline((str ? file : std::cin), line, '\0')) {
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
