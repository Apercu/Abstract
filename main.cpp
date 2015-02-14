/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 10:59:07        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#include "Vm.hpp"
#include "Parser.hpp"
#include "Operand.hpp"
#include "abstract.hpp"
#include <iostream>
#include <sstream>

int main (int ac, char ** av)
{
	if (ac > 2) {
		std::cout << "Please pass one or no arguments, is that complicated?" << std::endl;
		return (-1);
	}

	try {
		Parser p(av[1]);
		p.doYourJob();
	} catch (ExecutionException & e) {
		std::cout << e.what() << std::endl;
	} catch (SyntaxException & e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}






/* ======================== Exceptions bullshit ============================= */

SyntaxException::SyntaxException (const char * file, int line)
{
	std::stringstream ss;
	ss << "\033[37m\033[41m" << "Syntax error: " << "\033[0m at \033[35mline " << line << "\033[0m of \033[35m" << file << "\033[0m.";
	this->_msg = ss.str();
}

SyntaxException::SyntaxException (SyntaxException const & ref)
{
	*this = ref;
	VOID(ref);
}

SyntaxException::~SyntaxException (void)
{
}

const char * SyntaxException::what (void) const throw ()
{
	return this->_msg.c_str();
}

ExecutionException::ExecutionException (const std::string &arg, const char * file, int line)
{
	std::stringstream ss;
	ss << "\033[37m\033[41m" << arg << "\033[0m\033[37m at \033[34mline " << line << "\033[0m\033[37m of \033[34m" << file << "\033[0m.";
	this->_msg = ss.str();
}

ExecutionException::ExecutionException (ExecutionException const & ref)
{
	*this = ref;
	VOID(ref);
}

ExecutionException::~ExecutionException (void)
{
}

const char * ExecutionException::what (void) const throw ()
{
	return this->_msg.c_str();
}
