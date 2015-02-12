/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 12:05:38        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#ifndef VM_CLASS
# define VM_CLASS

# include <string>
# include <map>
# include "IOperand.hpp"

class Vm {

	public:

		static Vm & single (void);

		Vm	(void);
		Vm	(Vm const & ref);
		~Vm	(void);

		IOperand const *	createOperand (eOperandType type, std::string const & value) const;

	private:

		Vm & operator= (Vm const & ref);

		IOperand const *	createInt8   (std::string const & value) const;
		IOperand const *	createInt16  (std::string const & value) const;
		IOperand const *	createInt32  (std::string const & value) const;
		IOperand const *	createFloat  (std::string const & value) const;
		IOperand const *	createDouble (std::string const & value) const;

};

typedef IOperand const * (Vm::*VmFn)(std::string const & value) const;

#endif
