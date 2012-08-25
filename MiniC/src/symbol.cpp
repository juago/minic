#include "symbol.h"
#include "logger.h"

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
    Identifier* pIdent)
{
    Log().Get(logDEBUG) << "Looking for Function: " << pIdent->getName() << std::endl;

    std::map<std::string, SymbolEntry*>::iterator iter = m_entries.find(pIdent->getName());

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
            return m_pParent->getFunctionEntry(pIdent);
        }
        else
        {
            return NULL;
        }
    }
}

VariableEntry* SymbolTable::getVariableEntry(
    Identifier* pIdent)
{
    Log().Get(logDEBUG) << "Looking for Function: " << pIdent->getName() << std::endl;

    std::map<std::string, SymbolEntry*>::iterator iter = m_entries.find(pIdent->getName());

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
            return m_pParent->getVariableEntry(pIdent);
        }
        else
        {
            return NULL;
        }
    }
}

bool SymbolTable::insertFunctionEntry(
    Identifier* pIdent,
    std::vector<EnumDataType> args,
    EnumDataType returnType)
{
    Log().Get(logDEBUG) << "Inserting Function: " << pIdent->getName() << std::endl;

    FunctionEntry* pNewEntry = new FunctionEntry(pIdent, args, returnType);

    typedef std::pair<std::string, SymbolEntry*> EntryPair;
    std::pair< std::map<std::string, SymbolEntry*>::iterator, bool> pair_return;

    pair_return = m_entries.insert(EntryPair(pIdent->getName(), pNewEntry));

    return pair_return.second;
}

bool SymbolTable::insertVariableEntry(
    Identifier* pIdent,
    EnumDataType type)
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

    VariableEntry* pNewEntry = new VariableEntry(pIdent, type, global, offset);

    Log().Get(logDEBUG) << "Inserting Variable: " << pIdent->getName() << std::endl;

    pair_return = m_entries.insert(EntryPair(pIdent->getName(), pNewEntry));

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

EnumDataType SymbolEntry::getType()
{
    return m_type;
}

FunctionEntry::FunctionEntry(
    Identifier* pIdent,
    std::vector<EnumDataType> args,
    EnumDataType returnType)
    : SymbolEntry(pIdent, returnType),
      m_args(args)
{
}

std::vector<EnumDataType> FunctionEntry::getArgs()
{
    return m_args;
}

VariableEntry::VariableEntry(
    Identifier*  pIdent,
    EnumDataType type,
    bool         global,
    int          index)
    : SymbolEntry(pIdent, type),
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

