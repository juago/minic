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
    Block*       m_pGlobalProgramBlock;
    vector<Stmt*>  m_tempScopeStmtList;

public:
    SymbolTableMgr();
    ~SymbolTableMgr();

    void enterScope(Block* pBlock);
    void leaveScope();
    bool insertFuncDefnEntry(FuncDefn* pFuncDefn);
    bool insertFuncDeclEntry(FuncDecl* pFuncDecl);
    bool insertVariableEntry(Variable* pVariable);
    bool insertStmtEntry(Stmt* pStmt);
    FuncDefn* getCurrentFunc();

    Stmt* isIdentifierPresent(string identifier);

private:
    void setCurrentFunc(FuncDefn* pFuncDefn);
    Stmt* isInTemporaryList(string identifier);
    Stmt* isInParentScopes(string identifier);
};

class SymbolTable
{
protected:
    map<string, FuncDecl*>                        m_funcDeclList;
    map<string, FuncDefn*>                        m_funcDefnList;
    map<string, Variable*>                        m_entries;
    vector<SymbolTable*>                          m_symbolTableEntries;
    Block*                                        m_pBlock;
    SymbolTable*                                  m_pParent;
    int                                           m_currentOffset;
    int                                           m_maxLocalCount;
    int                                           m_depth;

public:
    SymbolTable(Block* pBlock, SymbolTable* pParent);
    FuncDefn* getFuncDefnEntry(Stmt* pStmt);
    Variable* getVariableEntry(Stmt* pStmt);
    bool insertFuncDefnEntry(FuncDefn* pFuncDefn);
    bool insertFuncDeclEntry(FuncDecl* pFuncDecl);
    bool insertVariableEntry(Variable* pVariable);
    bool insertStmtEntry(Stmt* pStmt);

    void setMaxLocalCount(int maxLocalCount);

    /* Getter Functions */
    SymbolTable* getParent() { return m_pParent; }

    int getDepth() { return m_depth; }
    int getMaxLocalCount() { return m_maxLocalCount; }

    int getOffset() { return m_currentOffset; }
    int getNewOffset();
};

typedef std::pair<std::string, Variable*> StmtPair;
typedef std::pair< std::map<std::string, Variable*>::iterator, bool> PairReturn;

#endif