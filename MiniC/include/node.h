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

typedef unsigned long long ull;

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
    explicit Node(ull lineNo) : m_lineNo(lineNo) {}
    virtual ~Node() { }

private:
    ull m_lineNo;
};

class NExpression : public Node
{
public:
    NExpression(ull lineNo) : Node(lineNo) {}
};

class NDataType : public NExpression
{
private:
    DataType m_type;

public:
    NDataType(const DataType dataType,
              ull lineNo) :
      m_type(dataType), NExpression(lineNo) 
    { 
        Log().Get(logINFO) << "Creating NDataType: " << dataType << std::endl;  
    }
};

class NIdentifier : public NExpression
{
private:
    std::string m_name;

public:
    NIdentifier(const std::string& name,
                ull lineNo) :
        m_name(name), NExpression(lineNo) 
    {
        Log().Get(logINFO) << "Creating NIdentifier: " << m_name << std::endl;
    }
};

class NStatement : public Node
{
public:
    NStatement(ull lineNo) : Node(lineNo) { }
};

class NInteger : public NExpression
{
public:
    long long m_value;

public:
    NInteger(long long value,
             ull lineNo) : m_value(value), NExpression(lineNo) 
    {
        Log().Get(logINFO) << "Creating NInteger" << std::endl;  
    }
};

class NDouble : public NExpression
{
public:
    double m_value;

public:
    NDouble(double value, 
            ull lineNo) : m_value(value), NExpression(lineNo) 
    {
        Log().Get(logINFO) << "Creating NDouble" << std::endl;  
    }
};

class NFloat : public NExpression
{
private:
    float m_value;

public:
    NFloat(float value,
           ull lineNo) : m_value(value), NExpression(lineNo)
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
    NMethodCall(const NIdentifier* pId,
                ExpressionList& arguments,
                ull lineNo) :
    m_pId(pId), m_arguments(arguments), NExpression(lineNo)
    {
        Log().Get(logINFO) << "Creating NMethodCall" << std::endl;  
    }

    NMethodCall(const NIdentifier* pId,
                ull lineNo) : m_pId(pId), NExpression(lineNo) 
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
    NBinaryOperator(NExpression* pLhs, 
                    int op, 
                    NExpression* pRhs,
                    ull lineNo) :
    m_pLhs(pLhs), m_pRhs(pRhs), m_op(op), NExpression(lineNo)
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
    NAssignment(NIdentifier* pLhs,
                NExpression* pRhs,
                ull lineNo) : 
    m_pLhs(pLhs), m_pRhs(pRhs), NExpression(lineNo)
    {
        Log().Get(logINFO) << "Creating NAssignment" << std::endl;  
    }
};

class NBlock : public NExpression
{
private:
    StatementList m_statements;

public:
    NBlock(ull lineNo) : NExpression(lineNo) 
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
    NExpressionStatement(NExpression* pExpression,
                         ull lineNo) : 
    m_pExpression(pExpression), NStatement(lineNo) 
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
    NVariable(const NDataType* dataType, 
              NIdentifier* pId,
              ull lineNo) : 
    m_datatype(dataType), m_pId(pId), m_pAssignmentExpr(NULL), NStatement(lineNo) 
    {
        Log().Get(logINFO) << "Creating NVariable" << std::endl;  
    }

    NVariable(const NDataType* dataType,
              NIdentifier* pId,
              NExpression* assignmentExpr,
              ull lineNo) :
    m_datatype(dataType), m_pId(pId), m_pAssignmentExpr(assignmentExpr), NStatement(lineNo) 
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
    NFunctionDeclaration(const NDataType* datatype,
                         const NIdentifier* id,
                         const VariableList& arguments,
                         ull lineNo) :
    m_pDataType(datatype), m_pID(id), m_arguments(arguments), NStatement(lineNo) 
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
    NFunctionDefinition(const NDataType* datatype, 
                        const NIdentifier* id,
                        const VariableList& arguments,
                        NBlock* block,
                        ull lineNo) :
    m_pDataType(datatype), m_pID(id), m_arguments(arguments), m_pBlock(block),
    NStatement(lineNo)
    {
        Log().Get(logINFO) << "Creating NFunctionDefinition" << std::endl;  
    }
};

class NMainDefinition : public NFunctionDefinition
{
public:
    NMainDefinition(const NDataType* datatype, 
                    const VariableList& arguments,
                    NBlock* block,
                    ull lineNo) :
    NFunctionDefinition(datatype, new NIdentifier("main", lineNo),
                        arguments, block, lineNo) 
    {
        Log().Get(logINFO) << "Creating NMainDefinition" << std::endl;  
    }
};

class NConditionalExpression : public NStatement
{
public:
    NConditionalExpression(ull lineNo) : NStatement(lineNo) 
    {
        Log().Get(logINFO) << "Creating NConditionalExpression" << std::endl;  
    }
};

#endif