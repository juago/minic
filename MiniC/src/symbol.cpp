#include "symbol.h"
#include "logger.h"

// extern Block* pProgramBlock;

SymbolTableMgr::SymbolTableMgr()
{
    m_pGlobalProgramBlock = new Block(0);
    m_pGlobalSymbolTable = new SymbolTable(m_pGlobalProgramBlock, NULL);
    m_pCurrentSymbolTable = m_pGlobalSymbolTable;
}

void SymbolTableMgr::enterScope(Block* pBlock)
{
    Log().Get(logDEBUG) << "Entering new Scope: " << endl;
    m_pCurrentSymbolTable = new SymbolTable(pBlock, m_pCurrentSymbolTable);
}

void SymbolTableMgr::leaveScope()
{
    if (m_pCurrentSymbolTable->getParent() != NULL)
    {
        // Set the maximum used index of the parent to the child if its greater
        m_pCurrentSymbolTable->getParent()->setMaxLocalCount(m_pCurrentSymbolTable->getMaxLocalCount());

        vector<Stmt*>::iterator varListIterator = m_tempScopeStmtList.begin();
        while (varListIterator != m_tempScopeStmtList.end())
        {
            m_pCurrentSymbolTable->insertStmtEntry(*varListIterator);
            ++varListIterator;
        }

        m_tempScopeStmtList.clear();

        Log().Get(logDEBUG) << "Leaving Scope: " << endl;

        // Restore scope to parent
        m_pCurrentSymbolTable = m_pCurrentSymbolTable->getParent();
    }
}

bool SymbolTableMgr::insertFuncDefnEntry(
    FuncDefn* pFuncDefn)
{
    return m_pCurrentSymbolTable->insertFuncDefnEntry(pFuncDefn);
    m_pCurrentFunc = pFuncDefn;
}

bool SymbolTableMgr::insertFuncDeclEntry(
    FuncDecl* pFuncDecl)
{
    return m_pCurrentSymbolTable->insertFuncDeclEntry(pFuncDecl);
}

bool SymbolTableMgr::insertVariableEntry(
    Variable* pVariable)
{
    return m_pCurrentSymbolTable->insertVariableEntry(pVariable);
}

bool SymbolTableMgr::insertStmtEntry(Stmt* pStmt)
{
    // return m_pCurrentSymbolTable->insertStmtEntry(pStmt);
    m_tempScopeStmtList.push_back(pStmt);
    return true;
}

void SymbolTableMgr::setCurrentFunc(FuncDefn* pFuncDefn)
{
    m_pCurrentFunc = pFuncDefn;
}

FuncDefn* SymbolTableMgr::getCurrentFunc()
{
    return m_pCurrentFunc;
}

Stmt* SymbolTableMgr::isInTemporaryList(string identifier)
{
    vector<Stmt *>::iterator tempListIter = m_tempScopeStmtList.begin();
    while (tempListIter != m_tempScopeStmtList.end())
    {
        Stmt* pStmt = (*tempListIter);
        if (pStmt->getIdentifier()->getName() == identifier)
            return pStmt;
        ++tempListIter;
    }

    return NULL;
}

Stmt* SymbolTableMgr::isInParentScopes(string identifier)
{
    SymbolTable* pTable = m_pCurrentSymbolTable;
	Stmt* pStmt = NULL;
    while (pTable->getParent() != NULL)
    {
        pTable = pTable->getParent();
		pStmt = pTable->getVariableEntry(identifier);
		if (pStmt == NULL)
			pStmt = pTable->getFuncDefnEntry(identifier);
    }

	return pStmt;
}

Stmt* SymbolTableMgr::isIdentifierPresent(string identifier)
{
    // First search in the temporary scope
    Stmt* pStmt = isInTemporaryList(identifier);

    if (pStmt == NULL)
    {
        // Now search in parent scopes to see if its global or local
        pStmt = isInParentScopes(identifier);
    }

	return pStmt;
}

//--------------------------------------------------- SYMBOL TABLE IMPLEMENTATION -----------------------------------------------------

SymbolTable::SymbolTable(
    Block*       pBlock,
    SymbolTable* pParent)
    : m_pBlock(pBlock),
      m_pParent(pParent),
      m_currentOffset(0),
      m_maxLocalCount(0),
      m_depth(0)
{
    // If there is a parent then we need its offset
    if (m_pParent != NULL && m_pParent->getParent() != NULL)
    {
        m_currentOffset = m_pParent->getOffset();
        m_maxLocalCount = m_pParent->getMaxLocalCount();
        m_depth         = m_pParent->getDepth() + 1;
    }
}

// Search the symbol table recursively for the function
FuncDefn* SymbolTable::getFuncDefnEntry(
    string identifier)
{
    Log().Get(logDEBUG) << "Looking for Function: " << identifier << endl;

    map<string, FuncDefn*>::iterator iter = m_funcDefnList.find(identifier);

    if (iter != m_funcDefnList.end())
    {
        FuncDefn* newFunction = iter->second;
        return newFunction;
    }
    else
    {
        if (m_pParent != NULL)
        {
            return m_pParent->getFuncDefnEntry(identifier);
        }
        else
        {
            return NULL;
        }
    }
}

Variable* SymbolTable::getVariableEntry(
	string identifier)
{
    Log().Get(logDEBUG) << "Looking for Variable: " << identifier << endl;

    std::map<std::string, Variable*>::iterator iter = m_entries.find(identifier);

    if (iter != m_entries.end())
    {
        Variable* newVariable = iter->second;
        return newVariable;
    }
    else
    {
        if (m_pParent != NULL)
        {
            return m_pParent->getVariableEntry(identifier);
        }
        else
        {
            return NULL;
        }
    }
}

bool SymbolTable::insertFuncDefnEntry(
    FuncDefn* pFuncDefn)
{
    Log().Get(logDEBUG) << "Inserting Function Definition: " << pFuncDefn->getIdentifier()->getName() << std::endl;

    m_funcDefnList.insert(make_pair(pFuncDefn->getIdentifier()->getName(), pFuncDefn));

    return true;
}

bool SymbolTable::insertFuncDeclEntry(
    FuncDecl* pFuncDecl)
{
    Log().Get(logDEBUG) << "Inserting Function Declaration: " << pFuncDecl->getIdentifier()->getName() << std::endl;

    m_funcDeclList.insert(make_pair(pFuncDecl->getIdentifier()->getName(), pFuncDecl));

    return true;
}

bool SymbolTable::insertVariableEntry(
    Variable* pVariable)
{
    PairReturn pair_return;
    bool global;

    int offset = 0;
    if (m_pParent == NULL)
    {
        global = true;
    }
    else
    {
        global = false;
        offset = getNewOffset();
    }

    Log().Get(logDEBUG) << "Inserting Variable: " << pVariable->getIdentifier()->getName() << std::endl;

    auto p = make_pair(pVariable->getIdentifier()->getName(), pVariable);

    pair_return = m_entries.insert(p);

    return pair_return.second;
}

bool SymbolTable::insertStmtEntry(
    Stmt* pStmt)
{
    m_pBlock->AddStmt(pStmt);
    return true;
}

int SymbolTable::getNewOffset()
{
    int oldOffset = m_currentOffset;
    m_currentOffset++;
    setMaxLocalCount(m_currentOffset);
    return oldOffset;
}

void SymbolTable::setMaxLocalCount(int newLocalCount)
{
    if (m_maxLocalCount < newLocalCount)
    {
        m_maxLocalCount = newLocalCount;
    }
}