#ifndef PORT_H
#define PORT_H

#include <string>
#include "type.h"

class BlockBase;

class Port
{
protected:
	Type data;
public:
	const BlockBase &block;
	const std::string name;
	Port(const BlockBase & b, const Type &t, std::string name);
	virtual Type & Value() = 0;
	TypeValue & operator[](const std::string &s);
};

class InPort : public Port
{
public:
	InPort(const BlockBase & b, const Type &t, std::string name);
	Type & Value() override;
};

class OutPort : public Port
{
public:
	OutPort(const BlockBase & b, const Type &t, std::string name);
	Type & Value() override;
};


#endif // PORT_H