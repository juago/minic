#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include <map>
#include <stack>
#include <string>

#include "node.h"

class SymbolTable;
class SymbolTableStack;

class SymbolTableEntry
{
public:
	std::string  getName() const;
	SymbolTable* getSymbolTable() const;


private:
	std::string     m_name;
	SymbolTable*    m_pSymTab;
	int             m_lineNo;
	Node*           m_pNode;
};



#endif