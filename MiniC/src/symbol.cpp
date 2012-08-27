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

bool SymbolTableMgr::insertFunctionEntry(
    Stmt* pStmt,
    std::vector<Variable*> args,
    DataType* pReturnType)
{
    return m_pCurrentSymbolTable->insertFunctionEntry(pStmt, args, pReturnType);
}

bool SymbolTableMgr::insertVariableEntry(
    Stmt* pStmt,
    DataType* pType)
{
    return m_pCurrentSymbolTable->insertVariableEntry(pStmt, pType);
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
FunctionEntry* SymbolTable::getFunctionEntry(
    Stmt* pStmt)
{
    Log().Get(logDEBUG) << "Looking for Function: " << pStmt->getIdentifier()->getName() << std::endl;

    std::map<std::string, SymbolEntry*>::iterator iter = m_entries.find(pStmt->getIdentifier()->getName());

    if (iter != m_entries.end())
    {
        SymbolEntry* newSymbol = iter->second;
        FunctionEntry* newFunction = dynamic_cast<FunctionEntry*>(newSymbol);
        return newFunction;
    }
    else
    {
        if (m_pParent != NULL)
        {
            return m_pParent->getFunctionEntry(pStmt);
        }
        else
        {
            return NULL;
        }
    }
}

VariableEntry* SymbolTable::getVariableEntry(
    Stmt* pStmt)
{
    Log().Get(logDEBUG) << "Looking for Function: " << pStmt->getIdentifier()->getName() << std::endl;

    std::map<std::string, SymbolEntry*>::iterator iter = m_entries.find(pStmt->getIdentifier()->getName());

    if (iter != m_entries.end())
    {
        SymbolEntry* newSymbol = iter->second;
        VariableEntry* newVariable = dynamic_cast<VariableEntry*>(newSymbol);
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

bool SymbolTable::insertFunctionEntry(
    Stmt* pStmt,
    std::vector<Variable*> args,
    DataType* pReturnType)
{
    Log().Get(logDEBUG) << "Inserting Function: " << pStmt->getIdentifier()->getName() << std::endl;

    FunctionEntry* pNewEntry = new FunctionEntry(pStmt, args, pReturnType);

    typedef std::pair<std::string, SymbolEntry*> EntryPair;
    std::pair< std::map<std::string, SymbolEntry*>::iterator, bool> pair_return;

    pair_return = m_entries.insert(EntryPair(pStmt->getIdentifier()->getName(), pNewEntry));

    return pair_return.second;
}

bool SymbolTable::insertVariableEntry(
    Stmt* pStmt,
    DataType* pType)
{
    typedef std::pair<std::string, SymbolEntry*> EntryPair;
    std::pair< std::map<std::string, SymbolEntry*>::iterator, bool> pair_return;
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

    VariableEntry* pNewEntry = new VariableEntry(pStmt, pType, global, offset);

    Log().Get(logDEBUG) << "Inserting Variable: " << pStmt->getIdentifier()->getName() << std::endl;

    pair_return = m_entries.insert(EntryPair(pStmt->getIdentifier()->getName(), pNewEntry));

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

DataType* SymbolEntry::getType()
{
    return m_pType;
}

FunctionEntry::FunctionEntry(
    Stmt* pStmt,
    std::vector<Variable*> args,
    DataType* pReturnType)
    : SymbolEntry(pStmt, pReturnType),
      m_args(args)
{
}

std::vector<Variable*> FunctionEntry::getArgs()
{
    return m_args;
}

VariableEntry::VariableEntry(
    Stmt*        pStmt,
    DataType*    pType,
    bool         global,
    int          index)
    : SymbolEntry(pStmt, pType),
      m_global(global),
      m_index(index)
{
}

int VariableEntry::getIndex()
{
    return m_index;
}

bool VariableEntry::isGlobal()
{
    return m_global;
}