/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 11:40:45        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#ifndef ABSTRACT
# define ABSTRACT

# define VOID(V)	static_cast<void>(V)

class Vm;

# include "IOperand.hpp"

typedef IOperand const * (Vm::*VmFn)(std::string const & value) const;
typedef void (Vm::*VmBasics)(void);
typedef void (Vm::*VmParams)(IOperand const * op);



/* ----------------------------- EXCEPTIONS --------------------------------- */

# define EXECEXCEPT(STR, NB)	throw ExecutionException(STR, NB, __FILE__, __LINE__);
# define SYNTEXCEPT(STR, NB)	throw SyntaxException(STR, NB, __FILE__, __LINE__);
# define FILEEXCEPT(STR, NB)	throw FilesystemException(STR, NB, __FILE__, __LINE__);

class SyntaxException: public std::exception {
	public:
		SyntaxException (const std::string &arg, int nb, const char * file, int line);

		virtual const char * what (void) const throw ();

		SyntaxException (SyntaxException const & ref);
		~SyntaxException (void);

	private:
		std::string		_msg;

		SyntaxException & operator= (SyntaxException const & ref);
		SyntaxException (void);
};

class ExecutionException: public std::exception {
	public:
		ExecutionException (const std::string &arg, int nb, const char * file, int line);

		virtual const char * what (void) const throw ();

		ExecutionException (ExecutionException const & ref);
		~ExecutionException (void);

	private:
		std::string		_msg;

		ExecutionException (void);
		ExecutionException & operator= (ExecutionException const & ref);
};

class BasicException: public std::exception {};

class ArgumentsException: public BasicException {
	public:
		virtual const char * what (void) const throw ();
};

class FilesystemException: public BasicException {
	public:
		virtual const char * what (void) const throw ();
};

#endif
