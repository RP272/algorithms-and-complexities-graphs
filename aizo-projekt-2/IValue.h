#ifndef IVALUE_HPP
#define IVALUE_HPP

class IValue
{
public:
	virtual ~IValue() {};
	virtual int	get_value() = 0;
};

#endif