#ifndef __NODE__
#define __NODE__

#include <iostream>
#include <string>
#include <vector>

#include "logger.h"

class NStatement;
class NExpression;
class NVariable;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariable*> VariableList;

enum DataType
{
    C_VOID = 0,
    C_CHAR,
    C_SHORT,
    C_INT,
    C_LONG,
    C_FLOAT,
    C_DOUBLE,
    C_SIGNED,
    C_UNSIGNED,
    C_BOOL,
    C_COMPLEX,
    C_IMAGINARY,
    C_STRUCT_OR_UNION,
    C_ENUM,
    C_TYPENAME,
};

class Node
{
public:
    virtual ~Node() { }
};

class NExpression : public Node
{
};

class NDataType : public NExpression
{
private:
    DataType m_type;

public:
    NDataType(const DataType dataType) :
      m_type(dataType) 
    { 
        Log().Get(logINFO) << "Creating NDataType: " << dataType << std::endl;  
    }
};

class NIdentifier : public NExpression
{
private:
    std::string m_name;

public:
    NIdentifier(const std::string& name)
        : m_name(name) 
    {
        Log().Get(logINFO) << "Creating NIdentifier: " << m_name << std::endl;
    }
};

class NStatement : public Node
{
};

class NInteger : public NExpression
{
public:
    long long m_value;

public:
    NInteger(long long value) : m_value(value) 
    {
        Log().Get(logINFO) << "Creating NInteger" << std::endl;  
    }
};

class NDouble : public NExpression
{
public:
    double m_value;

public:
    NDouble(double value) : m_value(value) 
    {
        Log().Get(logINFO) << "Creating NDouble" << std::endl;  
    }
};

class NFloat : public NExpression
{
private:
    float m_value;

public:
    NFloat(float value) : m_value(value) 
    {
        Log().Get(logINFO) << "Creating NFloat" << std::endl;  
    }
};

class NMethodCall : public NExpression
{
private:
    const NIdentifier* m_pId;
    ExpressionList     m_arguments;

public:
    NMethodCall(const NIdentifier* pId, ExpressionList& arguments) :
    m_pId(pId), m_arguments(arguments) 
    {
        Log().Get(logINFO) << "Creating NMethodCall" << std::endl;  
    }

    NMethodCall(const NIdentifier* pId) : m_pId(pId) 
    {
        Log().Get(logINFO) << "Creating NMethodCall" << std::endl;  
    }
};

class NBinaryOperator : public NExpression
{
private:
    int          m_op;
    NExpression* m_pLhs;
    NExpression* m_pRhs;

public:
    NBinaryOperator(NExpression* pLhs, int op, NExpression* pRhs) :
    m_pLhs(pLhs), m_pRhs(pRhs), m_op(op) 
    {
        Log().Get(logINFO) << "Creating NBinaryOperator" << std::endl;  
    }
};

class NAssignment : public NExpression
{
private:
    NIdentifier* m_pLhs;
    NExpression* m_pRhs;

public:
    NAssignment(NIdentifier* pLhs, NExpression* pRhs) : 
    m_pLhs(pLhs), m_pRhs(pRhs) 
    {
        Log().Get(logINFO) << "Creating NAssignment" << std::endl;  
    }
};

class NBlock : public NExpression
{
private:
    StatementList m_statements;

public:
    NBlock() 
    {
        Log().Get(logINFO) << "Creating NBlock" << std::endl;  
    }

    void AddStatement(NStatement* pStmt)
    {
        m_statements.push_back(pStmt);
    }
};

class NExpressionStatement : public NStatement
{
private:
    NExpression* m_pExpression;

public:
    NExpressionStatement(NExpression* pExpression) : 
    m_pExpression(pExpression) 
    {
        Log().Get(logINFO) << "Creating NExpressionStatement" << std::endl;  
    }
};

class NVariable : public NStatement
{
private:
    const NDataType* m_datatype;
    NIdentifier*     m_pId;
    NExpression*     m_pAssignmentExpr;

public:
    NVariable(const NDataType* dataType, NIdentifier* pId) : 
    m_datatype(dataType), m_pId(pId), m_pAssignmentExpr(NULL) 
    {
        Log().Get(logINFO) << "Creating NVariable" << std::endl;  
    }

    NVariable(const NDataType* dataType, NIdentifier* pId, NExpression* assignmentExpr) :
    m_datatype(dataType), m_pId(pId), m_pAssignmentExpr(assignmentExpr) 
    {
        Log().Get(logINFO) << "Creating NVariable" << std::endl;  
    }
};

class NFunctionDeclaration : public NStatement
{
protected:
    const NDataType*   m_pDataType;
    const NIdentifier* m_pID;
    VariableList       m_arguments;

public:
    NFunctionDeclaration(const NDataType* datatype, const NIdentifier* id,
                         const VariableList& arguments) :
    m_pDataType(datatype), m_pID(id), m_arguments(arguments) 
    {
        Log().Get(logINFO) << "Creating NFunctionDeclaration" << std::endl;  
    }
};

class NFunctionDefinition : public NStatement
{
protected:
    const NDataType*   m_pDataType;
    const NIdentifier* m_pID;
    VariableList       m_arguments;
    NBlock*            m_pBlock;

public:
    NFunctionDefinition(const NDataType* datatype, const NIdentifier* id,
                         const VariableList& arguments, NBlock* block) :
    m_pDataType(datatype), m_pID(id), m_arguments(arguments), m_pBlock(block) 
    {
        Log().Get(logINFO) << "Creating NFunctionDefinition" << std::endl;  
    }
};

class NMainDefinition : public NFunctionDefinition
{
public:
    NMainDefinition(const NDataType* datatype, 
                    const VariableList& arguments, NBlock* block) :

    NFunctionDefinition(datatype, new NIdentifier("main"),
                        arguments, block) 
    {
        Log().Get(logINFO) << "Creating NMainDefinition" << std::endl;  
    }
};

class NConditionalExpression : public NStatement
{
public:
    NConditionalExpression() 
    {
        Log().Get(logINFO) << "Creating NConditionalExpression" << std::endl;  
    }
};

#endif