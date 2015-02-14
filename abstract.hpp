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
# include <sstream>

class SyntaxException: public std::exception {
	public:
		SyntaxException (const char * file, int line)
		{
			std::stringstream ss;
			ss << "\033[37m\033[41m" << "Syntax error: " << "\033[0m at \033[35mline " << line << "\033[0m of \033[35m" << file << "\033[0m.";
			this->_msg = ss.str();
		}

		virtual const char * what (void) const throw ()
		{
			return this->_msg.c_str();
		}

		SyntaxException (SyntaxException const & ref) { VOID(ref); }
		~SyntaxException (void) {}

	private:
		std::string		_msg;

		SyntaxException & operator= (SyntaxException const & ref);
		SyntaxException (void);
};

class ExecutionException: public std::exception {
	public:
		ExecutionException (const std::string &arg, const char * file, int line)
		{
			std::stringstream ss;
			ss << "\033[37m\033[41m" << arg << "\033[0m\033[37m at \033[34mline " << line << "\033[0m\033[37m of \033[34m" << file << "\033[0m.";
			this->_msg = ss.str();
		}

		virtual const char * what (void) const throw ()
		{
			return this->_msg.c_str();
		}

		ExecutionException (ExecutionException const & ref) { VOID(ref); }
		~ExecutionException (void) {}

	private:
		std::string		_msg;

		ExecutionException & operator= (ExecutionException const & ref);
		ExecutionException (void);
};

#endif
