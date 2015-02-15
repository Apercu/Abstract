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

# include "IOperand.hpp"

class Instruction;

# include "abstract.hpp"

# include <string>
# include <map>
# include <list>
# include <sstream>

class Vm {

	public:

		static Vm & single (void);

		Vm	(void);
		Vm	(Vm const & ref);
		~Vm	(void);

		IOperand const *	createOperand (eOperandType type, std::string const & value) const;

		void pushInstruction	(VmBasics fn, int i);
		void pushInstruction	(VmParams fn, IOperand const * op, int i);
		void execute			(void);
		int  getLine			(void) const;

		void push (eOperandType type, std::string const & value);
		void push (IOperand const * op);

		void pop	(void);
		void dump	(void);

		void assert (IOperand const * op);

		void print	(void);
		void exit	(void);
		void check	(void);

		void add	(void);
		void sub	(void);
		void mul	(void);
		void div	(void);
		void mod	(void);

	private:

		int								_line;
		std::list<IOperand const *>		_stack;
		std::list<Instruction *>		_instructs;

		Vm & operator= (Vm const & ref);

		IOperand const *	createInt8   (std::string const & value) const;
		IOperand const *	createInt16  (std::string const & value) const;
		IOperand const *	createInt32  (std::string const & value) const;
		IOperand const *	createFloat  (std::string const & value) const;
		IOperand const *	createDouble (std::string const & value) const;

};

#endif
