/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 11:37:37        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#ifndef PARSER_CLASS
# define PARSER_CLASS

# include "abstract.hpp"
# include <sstream>

class Parser {

	public:

		Parser	(char * str);
		~Parser (void);

		class BadInputException: public ExecutionException {
			public:
				BadInputException (const char * file, int line)
				{
					std::stringstream ss;
					ss << "\033[37m\033[41m" << "The specified input can't be opened " << "\033[0m at \033[35mline " << line << "\033[0m of \033[35m" << file << "\033[0m.";
					this->_msg = ss.str();
				}

				virtual const char * what (void) const throw ()
				{
					return this->_msg.c_str();
				}

				BadInputException (BadInputException const & ref) { VOID(ref); }
				~BadInputException (void) {}

			private:
				std::string		_msg;

				BadInputException & operator= (BadInputException const & ref);
				BadInputException (void);
		};

		class NoExitException: public ExecutionException {
			public:
				NoExitException (const char * file, int line)
				{
					std::stringstream ss;
					ss << "\033[37m\033[41m" << "No exit instruction has been found within your program " << "\033[0m at \033[35mline " << line << "\033[0m of \033[35m" << file << "\033[0m.";
					this->_msg = ss.str();
				}

				virtual const char * what (void) const throw ()
				{
					return this->_msg.c_str();
				}

				NoExitException (NoExitException const & ref) { VOID(ref); }
				~NoExitException (void) {}

			private:
				std::string		_msg;

				NoExitException & operator= (NoExitException const & ref);
				NoExitException (void);
		};

	private:

		Parser (Parser const & ref);
		Parser & operator= (Parser const & ref);
		Parser (void);

};

#endif
