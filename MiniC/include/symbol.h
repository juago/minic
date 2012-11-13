#ifndef __SYMBOL__
#define __SYMBOL__

#include "utils.h"
#include "node.h"

class SymbolTable;
class FunctionEntry;
class VariableEntry;

class SymbolTableMgr
{
private:
    SymbolTable* m_pCurrentSymbolTable;
    SymbolTable* m_pGlobalSymbolTable;
    FuncDefn*    m_pCurrentFunc;

public:
    SymbolTableMgr();
    ~SymbolTableMgr();

    void enterScope();
    void leaveScope();
    bool insertFuncDefnEntry(FuncDefn* pFuncDefn);
    bool insertFuncDeclEntry(FuncDecl* pFuncDecl);
    bool insertVariableEntry(Variable* pVariable);
    FuncDefn* getCurrentFunc();

private:
    void setCurrentFunc(FuncDefn* pFuncDefn);
};

class SymbolTable
{
protected:
    map<string, FuncDecl*>                        m_funcDeclList;
    map<string, FuncDefn*>                        m_funcDefnList;
    map<string, Variable*>                        m_entries;
    vector<SymbolTable*>                          m_symbolTableEntries;
    SymbolTable*                                  m_pParent;
    int                                           m_currentOffset;
    int                                           m_maxLocalCount;
    int                                           m_depth;

public:
    SymbolTable(SymbolTable* pParent);
    FuncDefn* getFuncDefnEntry(Stmt* pStmt);
    Variable* getVariableEntry(Stmt* pStmt);
    bool insertFuncDefnEntry(FuncDefn* pFuncDefn);
    bool insertFuncDeclEntry(FuncDecl* pFuncDecl);
    bool insertVariableEntry(Variable* pVariable);
    int getOffset();
    int getNewOffset();
    SymbolTable* getParent();
    int getMaxLocalCount();
    void setMaxLocalCount(int maxLocalCount);
    int getDepth();
};

typedef std::pair<std::string, Variable*> StmtPair;
typedef std::pair< std::map<std::string, Variable*>::iterator, bool> PairReturn;

#endif