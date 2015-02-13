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

#include <iostream>
#include "Vm.hpp"
#include "Parser.hpp"
#include "abstract.hpp"

int main (int ac, char ** av)
{
	if (ac > 2) {
		std::cout << "Please" << std::endl;
	}

	try {
		Parser p(av[1]);
	} catch (ExecutionException & e) {
		std::cout << "Execution error: " << e.what() << std::endl;
	} catch (SyntaxException & e) {
		std::cout << "A syntax error has been detected: " << e.what() << std::endl;
	} catch (std::exception & e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}

	return (0);
}
