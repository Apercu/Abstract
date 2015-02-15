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

		Instruction (VmBasics fn, VmParams extra, eOperandType type, std::string const & value, int line);
		~Instruction (void);

		VmBasics			basic;
		VmParams			extra;

		eOperandType		type;
		std::string const &	value;

		int					line;

	private:

		Instruction (Instruction const & ref);
		Instruction & operator= (Instruction const & ref);

};

#endif
