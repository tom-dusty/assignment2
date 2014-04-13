#include "Statement.h"
#include "Expression.h"

Node * Statement::clone(void) const
{
	std::cout <<"Working!"<<std::endl;
	return new Statement(*this);
}

Statement::Statement(void) : Node(3)
{
}

std::string Statement::to_String(std::stringstream& strIn)
{
	children[0]->to_String(strIn);
	strIn << " ";
	children[1]->to_String(strIn);
	strIn << " ";
	children[2]->to_String(strIn);
	strIn << "\n";
	return strIn.str();
}