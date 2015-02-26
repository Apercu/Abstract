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

void ft_check_arguments (int ac)
{
	if (ac > 2) {
		throw ArgumentsException();
	}
}

int main (int ac, char ** av)
{
	try {
		ft_check_arguments(ac);
		Parser p(av[1]);
		p.doYourJob();
	} catch (ExecutionException & e) {
		std::cout << e.what() << std::endl;
	} catch (ArgumentsException & e) {
		std::cout << "Usage: " << e.what() << std::endl;
	} catch (FilesystemException & e) {
		std::cout << "FS: " << e.what() << std::endl;
	} catch (JustAnExitException & e) {
		VOID(e);
	} catch (std::exception & e) {
		std::cout << "Unknown: " << e.what() << std::endl;
	}

	return (0);
}

/* ============================== Exceptions ================================ */

SyntaxException::SyntaxException (const std::string &arg, int nb, const char * file, int line)
{
	std::stringstream ss;
	ss << "\033[31m" << arg << "\033[0m\033[37m\nat \033[34mline:" << nb << "\033[0m\033[37m (throwed at \033[34mL" << line << "\033[0m\033[37m of \033[34m" << file << "\033[0m\033[37m).\033[0m";
	this->_msg = ss.str();
}

SyntaxException::SyntaxException (SyntaxException const & ref)
{
	*this = ref;
}

SyntaxException & SyntaxException::operator= (SyntaxException const & ref)
{
	VOID(ref);
	return *this;
}

SyntaxException::~SyntaxException (void)
{
}

const char * SyntaxException::what (void) const throw ()
{
	return this->_msg.c_str();
}

ExecutionException::ExecutionException (const std::string &arg, int nb, const char * file, int line)
{
	std::stringstream ss;
	ss << "\033[31m" << arg << "\033[0m\033[37m\nat \033[34mline:" << nb << "\033[0m\033[37m (throwed at \033[34mL" << line << "\033[0m\033[37m of \033[34m" << file << "\033[0m\033[37m).\033[0m";
	this->_msg = ss.str();
}

ExecutionException::ExecutionException (ExecutionException const & ref)
{
	*this = ref;
}

ExecutionException & ExecutionException::operator= (ExecutionException const & ref)
{
	VOID(ref);
	return *this;
}

ExecutionException::~ExecutionException (void)
{
}

const char * ExecutionException::what (void) const throw ()
{
	return this->_msg.c_str();
}

const char * ArgumentsException::what (void) const throw ()
{
	return "Please pass one or no arguments, is that complicated?";
}

const char * FilesystemException::what (void) const throw ()
{
	return "The specified input can't be opened.";
}

const char * JustAnExitException::what (void) const throw ()
{
	return "This is simply an exit.";
}
