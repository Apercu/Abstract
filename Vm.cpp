/* ========================================================================== */
/*                                                                            */
/*    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      */
/*    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      */
/*    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                    */
/*    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/12 12:15:03        */
/*         ██║███████╗ ██║  ██║ ╚████╔╝                                       */
/*         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        */
/*                                                                            */
/* ========================================================================== */

#include "Vm.hpp"
#include "Operand.hpp"

Vm::Vm (void)
{
}

Vm::~Vm (void)
{
}

Vm::Vm (Vm const & ref)
{
	*this = ref;
}

Vm & Vm::operator= (Vm const & ref)
{
	VOID(ref);
	return *this;
}

Vm & Vm::single (void)
{
	static Vm i;
	return i;
}

IOperand const *	Vm::createOperand (eOperandType type, std::string const & value) const
{
	static std::map<eOperandType, VmFn> map = {
		{ INT8, &Vm::createInt8 },
		{ INT16, &Vm::createInt16 },
		{ INT32, &Vm::createInt32 },
		{ DOUBLE, &Vm::createDouble },
		{ FLOAT, &Vm::createFloat }
	};

	return (this->*(map[type]))(value);
}

IOperand const * Vm::createInt8 (std::string const & value) const
{
	return new Operand<int8_t>(INT8, value);
}

IOperand const * Vm::createInt16 (std::string const & value) const
{
	return new Operand<int16_t>(INT16, value);
}

IOperand const * Vm::createInt32 (std::string const & value) const
{
	return new Operand<int32_t>(INT32, value);
}

IOperand const * Vm::createFloat (std::string const & value) const
{
	return new Operand<float>(FLOAT, value);
}

IOperand const * Vm::createDouble (std::string const & value) const
{
	return new Operand<double>(DOUBLE, value);
}
