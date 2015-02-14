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

Parser::Parser (char * str): _filename(str)
{
	// "No exit instruction has been found within your program "
	this->_firstMap["add"] = &Vm::add;
	this->_firstMap["sub"] = &Vm::sub;
	this->_firstMap["mul"] = &Vm::mul;
	this->_firstMap["div"] = &Vm::div;
	this->_firstMap["mod"] = &Vm::mod;
	this->_firstMap["print"] = &Vm::print;
	this->_firstMap["exit"] = &Vm::exit;
	this->_firstMap["dump"] = &Vm::dump;
	this->_firstMap["pop"] = &Vm::pop;

	this->_secondMap["push"] = &Vm::push;
	this->_secondMap["assert"] = &Vm::assert;
}

Parser::~Parser (void)
{
}

void Parser::doYourJob (void)
{
	std::ifstream	file;
	std::string		line;

	this->_initJob(file);
	while (std::getline((this->_filename ? file : std::cin), line) && line != ";;") {
		if (line.at(0) != 59) {
			std::cout << line << std::endl;
		}
	}
	this->_finishJob(file);
}

void Parser::_initJob (std::ifstream & file)
{
	if (this->_filename) {
		file.open(this->_filename);
		if (!file.is_open()) {
			EXECEXCEPT("The specified input can't be opened");
		}
	}
}

void Parser::_finishJob (std::ifstream & file)
{
	if (file) {
		file.close();
	}
}
