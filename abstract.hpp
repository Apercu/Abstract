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

class SyntaxException: public std::exception {
	public:
		SyntaxException (const char * file, int line);

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
		ExecutionException (const std::string &arg, const char * file, int line);

		virtual const char * what (void) const throw ();

		ExecutionException (ExecutionException const & ref);
		~ExecutionException (void);

	private:
		std::string		_msg;

		ExecutionException & operator= (ExecutionException const & ref);
		ExecutionException (void);
};

#endif
