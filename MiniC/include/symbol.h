#ifndef __SYMBOL__
#define __SYMBOL__

#include "utils.h"
#include "node.h"

class SymbolEntry;
class FunctionEntry;
class VariableEntry;

class SymbolTable
{
protected:
    std::map<std::string, SymbolEntry*, std::less<std::string> > m_entries;
    SymbolTable*                                                 m_pParent;
    int                                                          m_currentOffset;
    int                                                          m_maxLocalCount;
    int                                                          m_depth;

public:
    SymbolTable(SymbolTable* pParent);
    FunctionEntry* getFunctionEntry(Identifier* pIdent);
    VariableEntry* getVariableEntry(Identifier* pIdent);
    bool insertFunctionEntry(Identifier* pIdent_, std::vector<EnumDataType> args, EnumDataType returnType);
    bool insertVariableEntry(Identifier* pIdent_, EnumDataType type);
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
    Identifier*  m_pIdent;
    EnumDataType m_type;

public:
    SymbolEntry(Identifier* pIdent, EnumDataType type) : m_pIdent(pIdent), m_type(type)
    {
    }

    virtual ~SymbolEntry()
    {
    }

    EnumDataType getType();
};

class FunctionEntry : public SymbolEntry
{
protected:
    EnumDataType              m_returnType;
    std::vector<EnumDataType> m_args;

public:
    FunctionEntry(Identifier* pIdent, std::vector<EnumDataType> args, EnumDataType returnType);
    std::vector<EnumDataType> getArgs();
};

class VariableEntry : public SymbolEntry
{
protected:
    int                       m_index;
    bool                      m_global;

public:
    VariableEntry(Identifier* pIdent, EnumDataType type, bool global, int index);
    int getIndex();
    bool isGlobal();
};

#endif