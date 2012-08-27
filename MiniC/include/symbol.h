#ifndef __SYMBOL__
#define __SYMBOL__

#include "utils.h"
#include "node.h"

class SymbolTable;
class SymbolEntry;
class FunctionEntry;
class VariableEntry;

class SymbolTableMgr
{
private:
    SymbolTable* m_pCurrentSymbolTable;
    SymbolTable* m_pGlobalSymbolTable;

public:
    SymbolTableMgr();
    ~SymbolTableMgr();

    void enterScope();
    void leaveScope();
    bool insertFunctionEntry(Stmt* pStmt, std::vector<Variable*> args, DataType* pReturnType);
    bool insertVariableEntry(Stmt* pStmt, DataType* pType);
};

class SymbolTable
{
protected:
    std::map<std::string, SymbolEntry*, std::less<std::string> > m_entries;
    std::vector<SymbolTable*>                                    m_symbolTableEntries;
    SymbolTable*                                                 m_pParent;
    int                                                          m_currentOffset;
    int                                                          m_maxLocalCount;
    int                                                          m_depth;

public:
    SymbolTable(SymbolTable* pParent);
    FunctionEntry* getFunctionEntry(Stmt* pStmt);
    VariableEntry* getVariableEntry(Stmt* pStmt);
    bool insertFunctionEntry(Stmt* pStmt, std::vector<Variable*> args, DataType* pReturnType);
    bool insertVariableEntry(Stmt* pStmt, DataType* pType);
    int getOffset();
    int getNewOffset();
    SymbolTable* getParent();
    int getMaxLocalCount();
    void setMaxLocalCount(int maxLocalCount);
    int getDepth();
};

class SymbolEntry
{
protected:
    Stmt*  m_pStmt;
    DataType* m_pType;

public:
    SymbolEntry(Stmt* pStmt, DataType* pType) : m_pStmt(pStmt), m_pType(pType)
    {
    }

    virtual ~SymbolEntry()
    {
    }

    DataType* getType();
};

class FunctionEntry : public SymbolEntry
{
protected:
    DataType*                 m_pReturnType;
    std::vector<Variable*>    m_args;

public:
    FunctionEntry(Stmt* pStmt, std::vector<Variable*> args, DataType* pReturnType);
    std::vector<Variable*> getArgs();
};

class VariableEntry : public SymbolEntry
{
protected:
    int                       m_index;
    bool                      m_global;

public:
    VariableEntry(Stmt* pStmt, DataType* pType, bool global, int index);
    int getIndex();
    bool isGlobal();
};

#endif