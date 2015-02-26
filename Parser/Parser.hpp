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
# include "Vm.hpp"
# include <sstream>
# include <fstream>
# include <map>

class Parser {

	public:

		Parser	(char * str);
		~Parser (void);

		void doYourJob (void);

	private:

		char *								_filename;

		std::map<std::string, VmBasics>		_firstMap;
		std::map<std::string, VmParams>		_secondMap;
		std::map<std::string, eOperandType>	_thirdMap;

		void	_finishJob		(std::ifstream & file, bool execute);
		void	_initJob		(std::ifstream & file);
		void	_parseThisLine	(std::string & line, int i);

		Parser (Parser const & ref);
		Parser & operator= (Parser const & ref);
		Parser (void);

};

#endif
