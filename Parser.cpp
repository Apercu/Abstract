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

Parser::Parser (char * str): _filename(NULL)
{
	std::ifstream	file;

	if (str) {
		file.open(str);
		if (!file.is_open()) {
			throw ExecutionException("The specified input can't be opened", __FILE__, __LINE__);
		}
		this->_filename = str;
		file.close();
	}

	// "No exit instruction has been found within your program "
}

Parser::~Parser (void)
{
}

void Parser::doYourJob (void)
{
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
