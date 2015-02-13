/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 10:59:52        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#ifndef IOPERAND
# define IOPERAND

# include <string>

enum eOperandType { INT8 = 1, INT16, INT32, FLOAT, DOUBLE };

class IOperand {

	public:

		virtual int					getPrecision (void) const = 0;
		virtual eOperandType		getType (void) const = 0;

		virtual IOperand const *	operator+ (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator- (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator* (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator/ (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator% (IOperand const & rhs) const = 0;

		virtual std::string const &	toString (void) const = 0; // String representation of the instance

		virtual						~IOperand (void) {}
};

#endif
