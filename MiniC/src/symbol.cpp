#include "symbol.h"
#include "logger.h"

SymbolTableMgr::SymbolTableMgr()
{
    m_pGlobalSymbolTable = new SymbolTable(NULL);
    m_pCurrentSymbolTable = m_pGlobalSymbolTable;
}

void SymbolTableMgr::enterScope()
{
    m_pCurrentSymbolTable = new SymbolTable(m_pCurrentSymbolTable);
}

void SymbolTableMgr::leaveScope()
{
    if (m_pCurrentSymbolTable->getParent() != NULL)
    {
        // Set the maximum used index of the parent to the child if its greater
        m_pCurrentSymbolTable->getParent()->setMaxLocalCount(m_pCurrentSymbolTable->getMaxLocalCount());

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

void SymbolTableMgr::setCurrentFunc(FuncDefn* pFuncDefn)
{
    m_pCurrentFunc = pFuncDefn;
}

FuncDefn* SymbolTableMgr::getCurrentFunc()
{
    return m_pCurrentFunc;
}

SymbolTable::SymbolTable(
    SymbolTable* pParent)
    : m_pParent(pParent),
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
    Stmt* pStmt)
{
    Log().Get(logDEBUG) << "Looking for Function: " << pStmt->getIdentifier()->getName() << endl;

    map<string, FuncDefn*>::iterator iter = m_funcDefnList.find(pStmt->getIdentifier()->getName());

    if (iter != m_funcDefnList.end())
    {
        FuncDefn* newFunction = iter->second;
        return newFunction;
    }
    else
    {
        if (m_pParent != NULL)
        {
            return m_pParent->getFuncDefnEntry(pStmt);
        }
        else
        {
            return NULL;
        }
    }
}

Variable* SymbolTable::getVariableEntry(
    Stmt* pStmt)
{
    Log().Get(logDEBUG) << "Looking for Function: " << pStmt->getIdentifier()->getName() << endl;

    std::map<std::string, Variable*>::iterator iter = m_entries.find(pStmt->getIdentifier()->getName());

    if (iter != m_entries.end())
    {
        Variable* newVariable = iter->second;
        return newVariable;
    }
    else
    {
        if (m_pParent != NULL)
        {
            return m_pParent->getVariableEntry(pStmt);
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

int SymbolTable::getOffset()
{
    return m_currentOffset;
}

int SymbolTable::getNewOffset()
{
    int oldOffset = m_currentOffset;
    m_currentOffset++;
    setMaxLocalCount(m_currentOffset);
    return oldOffset;
}

SymbolTable* SymbolTable::getParent()
{
    return m_pParent;
}

int SymbolTable::getMaxLocalCount()
{
    return m_maxLocalCount;
}

void SymbolTable::setMaxLocalCount(int newLocalCount)
{
    if (m_maxLocalCount < newLocalCount)
    {
        m_maxLocalCount = newLocalCount;
    }
}

int SymbolTable::getDepth()
{
    return m_depth;
}