/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/14 16:06:52        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#ifndef INSTRUCTION_CLASS
# define INSTRUCTION_CLASS

# include "abstract.hpp"

class Instruction {

	public:

		Instruction (VmBasics fn, VmParams extra, IOperand const * op);
		~Instruction (void);

		VmBasics			basic;
		VmParams			extra;
		IOperand const *	param;

	private:

		Instruction (Instruction const & ref);
		Instruction & operator= (Instruction const & ref);

};

#endif
