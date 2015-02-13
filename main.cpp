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
#include "abstract.hpp"

int main (int ac, char ** av)
{
	VOID(av);
	if (ac > 2) {
		std::cout << "Please" << std::endl;
	}

	Vm vm = Vm::single();

	IOperand const * op = vm.createOperand(INT8, "20");
	IOperand const * op2 = vm.createOperand(INT8, "12");

	std::cout << op->toString() << std::endl;
	std::cout << (*op + *op2)->toString() << std::endl;

	delete op;

	return (0);
}
