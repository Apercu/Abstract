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
#include <iterator>

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


void Vm::push (eOperandType type, std::string const & value)
{
	this->_stack.push_front(this->createOperand(type, value));
}

void Vm::push (IOperand const * op)
{
	this->_stack.push_front(op);
}

void Vm::pop (void)
{
	if (this->_stack.size() < 1) {
		throw Vm::EmptyStackException(__FILE__, __LINE__);
	}
	delete *(this->_stack.begin());
	this->_stack.pop_front();
}

void Vm::dump (void) const
{
	std::list<IOperand const *>::const_iterator it = this->_stack.begin();
	while (it != this->_stack.end()) {
		std::cout << (*it)->toString() << std::endl;
	}
}

void Vm::assert (IOperand const * op) const
{
	IOperand const * top = *(this->_stack.begin());
	if (top->getType() != op->getType() && top->toString() != op->toString()) {
		throw Vm::AssertException(__FILE__, __LINE__);
	}
}

void Vm::print (void) const
{
	IOperand const * top = *(this->_stack.begin());
	IOperand const * tmp = this->createOperand(INT8, top->toString());
	this->assert(tmp);
	std::stringstream ss;
	int res;
	ss << top->toString();
	ss >> res;
	std::cout << static_cast<char>(res) << std::endl;
}

void Vm::exit (void)
{
	std::cout << "Exiting..." << std::endl;
}

void Vm::add (void)
{
	if (this->_stack.size() < 2) { throw Vm::NotEnoughOperandsException(__FILE__, __LINE__); }
	IOperand const * one = *(this->_stack.begin());
	IOperand const * two = *(std::next(this->_stack.begin()));
	this->push(*one + *two);
}

void Vm::sub (void)
{
	if (this->_stack.size() < 2) { throw Vm::NotEnoughOperandsException(__FILE__, __LINE__); }
	IOperand const * one = *(this->_stack.begin());
	IOperand const * two = *(std::next(this->_stack.begin()));
	this->push(*one - *two);
}

void Vm::mul (void)
{
	if (this->_stack.size() < 2) { throw Vm::NotEnoughOperandsException(__FILE__, __LINE__); }
	IOperand const * one = *(this->_stack.begin());
	IOperand const * two = *(std::next(this->_stack.begin()));
	this->push(*one * *two);
}

void Vm::div (void)
{
	if (this->_stack.size() < 2) { throw Vm::NotEnoughOperandsException(__FILE__, __LINE__); }
	IOperand const * one = *(this->_stack.begin());
	IOperand const * two = *(std::next(this->_stack.begin()));
	this->push(*one / *two);
}

void Vm::mod (void)
{
	if (this->_stack.size() < 2) { throw Vm::NotEnoughOperandsException(__FILE__, __LINE__); }
	IOperand const * one = *(this->_stack.begin());
	IOperand const * two = *(std::next(this->_stack.begin()));
	this->push(*one % *two);
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
