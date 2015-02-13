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

class Parser {

	public:

		Parser	(char * str);
		~Parser (void);

		class BadInputException: public ExecutionException {
			public:
				virtual const char * what (void) const throw ()
				{
					return ("The specified input can't be opened.");
				}
		};


		class NoExitException: public ExecutionException {
			public:
				virtual const char * what (void) const throw ()
				{
					return ("No exit instruction has been found within your program.");
				}
		};

	private:

		Parser (Parser const & ref);
		Parser & operator= (Parser const & ref);
		Parser (void);

};

#endif
