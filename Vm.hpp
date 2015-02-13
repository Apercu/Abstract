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

		void push (eOperandType type, std::string const & value);
		void push (IOperand const * op);

		void pop (void);

		void dump (void) const;

		void assert (IOperand const * op) const;

		void print (void) const;

		void exit (void);

		void add (void);
		void sub (void);
		void mul (void);
		void div (void);
		void mod (void);

		class AssertException: public ExecutionException {
			public:
				AssertException (const char * file, int line)
				{
					std::stringstream ss;
					ss << "\033[37m\033[41m" << "Assert failed" << "\033[0m at \033[35mline " << line << "\033[0m of \033[35m" << file << "\033[0m.";
					this->_msg = ss.str();
				}

				virtual const char * what (void) const throw ()
				{
					return this->_msg.c_str();
				}

				AssertException (AssertException const & ref) { VOID(ref); }
				~AssertException (void) {}

			private:

				std::string		_msg;

				AssertException & operator= (AssertException const & ref);
				AssertException (void);
		};

			class EmptyStackException: public ExecutionException {
				public:
					EmptyStackException (const char * file, int line)
					{
						std::stringstream ss;
						ss << "\033[37m\033[41m" << "The stack is empty, cannot perform your operation " << "\033[0m at \033[35mline " << line << "\033[0m of \033[35m" << file << "\033[0m.";
						this->_msg = ss.str();
					}

					virtual const char * what (void) const throw ()
					{
						return this->_msg.c_str();
					}

					EmptyStackException (EmptyStackException const & ref) { VOID(ref); }
					~EmptyStackException (void) {}

				private:
					std::string		_msg;

					EmptyStackException & operator= (EmptyStackException const & ref);
					EmptyStackException (void);
			};

			class NotEnoughOperandsException: public ExecutionException {
				public:
					NotEnoughOperandsException (const char * file, int line)
				{
					std::stringstream ss;
					ss << "\033[37m\033[41m" << "Not enough operands on the stack to make this operation " << "\033[0m at \033[35mline " << line << "\033[0m of \033[35m" << file << "\033[0m.";
					this->_msg = ss.str();
				}

				virtual const char * what (void) const throw ()
				{
					return this->_msg.c_str();
				}

				NotEnoughOperandsException (NotEnoughOperandsException const & ref) { VOID(ref); }
				~NotEnoughOperandsException (void) {}

			private:
				std::string		_msg;

				NotEnoughOperandsException & operator= (NotEnoughOperandsException const & ref);
				NotEnoughOperandsException (void);
		};

	private:

		std::list<IOperand const *>		_stack;

		Vm & operator= (Vm const & ref);

		IOperand const *	createInt8   (std::string const & value) const;
		IOperand const *	createInt16  (std::string const & value) const;
		IOperand const *	createInt32  (std::string const & value) const;
		IOperand const *	createFloat  (std::string const & value) const;
		IOperand const *	createDouble (std::string const & value) const;

};

typedef IOperand const * (Vm::*VmFn)(std::string const & value) const;

#endif
