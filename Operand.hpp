/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 11:11:30        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#ifndef OPERAND_CLASS
# define OPERAND_CLASS

# include "IOperand.hpp"
# include "abstract.hpp"
# include "Vm.hpp"
# include <sstream>
# include <iostream>
# include <math.h>
# include <limits>

template <typename T>
class Operand: public IOperand {

	public:

		Operand (eOperandType type, std::string const & val): _type(type), _str(val)
		{
		}

		virtual ~Operand (void) {}

		int				getPrecision (void) const
		{
			return this->_type;
		}

		eOperandType	getType (void) const
		{
			return this->_type;
		}

		std::string const &	toString (void) const
		{
			return this->_str;
		}

		IOperand const *	operator+ (IOperand const & rhs) const
		{
			double				one;
			double				two;
			eOperandType		type;
			std::stringstream	res;

			this->_gulpParams(one, two, type, rhs);
			res << (one + two);
			return this->_renderOperand(type, res);
		}

		IOperand const *	operator- (IOperand const & rhs) const
		{
			double				one;
			double				two;
			eOperandType		type;
			std::stringstream	res;

			this->_gulpParams(one, two, type, rhs);
			res << (one - two);
			return this->_renderOperand(type, res);
		}

		IOperand const *	operator* (IOperand const & rhs) const
		{
			double				one;
			double				two;
			eOperandType		type;
			std::stringstream	res;

			this->_gulpParams(one, two, type, rhs);
			res << (one * two);
			return this->_renderOperand(type, res);
		}

		IOperand const *	operator/ (IOperand const & rhs) const
		{
			double				one;
			double				two;
			eOperandType		type;
			std::stringstream	res;

			this->_gulpParams(one, two, type, rhs);
			res << (one / two);
			return this->_renderOperand(type, res);
		}

		IOperand const *	operator% (IOperand const & rhs) const
		{
			double				one;
			double				two;
			eOperandType		type;
			std::stringstream	res;

			this->_gulpParams(one, two, type, rhs);
			res << fmod(one, two);
			return this->_renderOperand(type, res);
		}

	private:

		eOperandType		_type;
		std::string			_str;

		void				_gulpParams (double & one, double & two, eOperandType & type, IOperand const & rhs) const
		{
			std::stringstream	ss(this->_str);
			std::stringstream	ss2(rhs.toString());

			ss >> one;
			ss2 >> two;

			type = (this->_type > rhs.getType() ? this->_type : rhs.getType());
		}

		IOperand const *	_renderOperand (eOperandType & type, std::stringstream & stream) const
		{
			std::stringstream ss;

			if (type == INT8 || type == INT16 || type == INT32) {
				int tmp;
				stream >> tmp;
				ss << tmp;
			}
			else if (type == FLOAT) {
				float tmp;
				stream >> tmp;
				ss << tmp;
			}
			else {
				ss << stream.str();
			}

			return Vm::single().createOperand(type, ss.str());
		}

		Operand (void);
		Operand (Operand const & ref);
		Operand & operator= (Operand const & ref);

};

#endif
