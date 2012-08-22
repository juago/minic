#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include <map>
#include <stack>
#include <string>

#include "node.h"

class SymbolTable;
class SymbolTableStack;

class SymbolTable
{
public:
    void AddSymbol(NStatement* pStmtNode);

private:
    std::map<NStatement *> m_decls;
};

class SymbolTableStack
{
public:

private:
    SymbolTableEntry*              m_pGlobalSymTable;
    std::stack<SymbolTableEntry *> m_symStack;
};



#endif