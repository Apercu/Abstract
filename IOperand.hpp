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

enum eOperandType { INT8, INT16, INT32, FLOAT, DOUBLE };

class IOperand {

	public:
		virtual int					getPrecision (void) const = 0; // Precision of the type of the instance
		virtual eOperandType		getType (void) const = 0; // Type of the instance

		virtual IOperand const *	operator+ (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator- (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator* (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator/ (IOperand const & rhs) const = 0;
		virtual IOperand const *	operator% (IOperand const & rhs) const = 0;

		virtual std::string const &	toString (void) const = 0; // String representation of the instance

		virtual						~IOperand (void) {}
};

#endif
