#ifndef __NODE__
#define __NODE__

#include <iostream>
#include <string>
#include <vector>

#include "logger.h"

class Stmt;
class Expr;
class Variable;

typedef std::vector<Stmt*> StmtList;
typedef std::vector<Expr*> ExprList;
typedef std::vector<Variable*> VariableList;

typedef unsigned long long ull;

enum EnumDataType
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
    explicit Node(ull lineNo) : m_lineNo(lineNo) 
    {
    }

    virtual ~Node() { }

private:
    ull m_lineNo;
};

class Expr : public Node
{
public:
    Expr(ull lineNo) : Node(lineNo) {}
};

class DataType : public Expr
{
private:
    EnumDataType m_type;

public:
    DataType(const EnumDataType dataType,
             ull lineNo) :
      m_type(dataType), Expr(lineNo) 
    { 
        Log().Get(logINFO) << "Creating DataType: " << dataType << std::endl;  
    }
};

class Identifier : public Expr
{
private:
    std::string m_name;

public:
    Identifier(const std::string& name,
                ull lineNo) :
        m_name(name), Expr(lineNo) 
    {
        Log().Get(logINFO) << "Creating Identifier: " << m_name << std::endl;
    }
};

class Stmt : public Node
{
public:
    Stmt(ull lineNo) : Node(lineNo) { }
};

class Integer : public Expr
{
public:
    long long m_value;

public:
    Integer(long long value,
             ull lineNo) : m_value(value), Expr(lineNo) 
    {
        Log().Get(logINFO) << "Creating Integer" << std::endl;  
    }
};

class Double : public Expr
{
public:
    double m_value;

public:
    Double(double value, 
            ull lineNo) : m_value(value), Expr(lineNo) 
    {
        Log().Get(logINFO) << "Creating Double" << std::endl;  
    }
};

class Float : public Expr
{
private:
    float m_value;

public:
    Float(float value,
           ull lineNo) : m_value(value), Expr(lineNo)
    {
        Log().Get(logINFO) << "Creating Float" << std::endl;  
    }
};

class Bool : public Expr
{
private:
    bool m_value;

public:
    Bool(bool value,
          ull  lineNo) : m_value(value), Expr(lineNo)
    {
        Log().Get(logINFO) << "Creating Bool" << std::endl;
    }
};

class Char : public Expr
{
private:
    char m_value;

public:
    Char(char value,
          ull  lineNo) : m_value(value), Expr(lineNo)
    {
        Log().Get(logINFO) << "Creating Char" << std::endl;
    }
};

class FunctionCall : public Expr
{
private:
    const Identifier* m_pId;
    ExprList     m_arguments;

public:
    FunctionCall(const Identifier* pId,
                ExprList& arguments,
                ull lineNo) :
    m_pId(pId), m_arguments(arguments), Expr(lineNo)
    {
        Log().Get(logINFO) << "Creating FunctionCall" << std::endl;  
    }

    FunctionCall(const Identifier* pId,
                ull lineNo) : m_pId(pId), Expr(lineNo) 
    {
        Log().Get(logINFO) << "Creating FunctionCall" << std::endl;  
    }
};

class BinaryOperator : public Expr
{
private:
    int          m_op;
    Expr* m_pLhs;
    Expr* m_pRhs;

public:
    BinaryOperator(Expr* pLhs, 
                    int op, 
                    Expr* pRhs,
                    ull lineNo) :
    m_pLhs(pLhs), m_pRhs(pRhs), m_op(op), Expr(lineNo)
    {
        Log().Get(logINFO) << "Creating BinaryOperator" << std::endl;  
    }
};

class Assignment : public Expr
{
private:
    Identifier* m_pLhs;
    Expr* m_pRhs;

public:
    Assignment(Identifier* pLhs,
                Expr* pRhs,
                ull lineNo) : 
    m_pLhs(pLhs), m_pRhs(pRhs), Expr(lineNo)
    {
        Log().Get(logINFO) << "Creating Assignment" << std::endl;  
    }
};

class Block : public Expr
{
private:
    StmtList m_Stmts;

public:
    Block(ull lineNo) : Expr(lineNo) 
    {
        Log().Get(logINFO) << "Creating Block" << std::endl;  
    }

    void AddStmt(Stmt* pStmt)
    {
        m_Stmts.push_back(pStmt);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class UnaryExpr : public Expr
{
    protected:
        Expr* m_pRhs;

    public:
        UnaryExpr(Expr* pRhs, ull lineNo) : Expr(lineNo), m_pRhs(pRhs) 
        {
        }
};

class NegateUnaryExpr : public UnaryExpr
{
    public:
        NegateUnaryExpr(Expr* pRhs, ull lineNo) : UnaryExpr(pRhs, lineNo)
        {
        }
};

class AdditionUnaryExpr : public NegateUnaryExpr
{
    public:
        AdditionUnaryExpr(Expr* pRhs, ull lineNo) : NegateUnaryExpr(pRhs, lineNo)
        {
        }
};

class SubtractUnaryExpr : public NegateUnaryExpr
{
    public:
        SubtractUnaryExpr(Expr* pRhs, ull lineNo) : NegateUnaryExpr(pRhs, lineNo)
        {
        }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BinaryExpr : public Expr
{
protected:
    Expr* m_pLhs;
    Expr* m_pRhs;

public:
    BinaryExpr(Expr* pLhs,
                Expr* pRhs,
                ull          lineNo) : m_pLhs(pLhs), m_pRhs(pRhs), Expr(lineNo)
    {
    }
};

class NumberBinaryExpr : public BinaryExpr
{
public:
    NumberBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : BinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class AdditionBinaryExpr : public NumberBinaryExpr
{
public:
    AdditionBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class SubtractioBinaryExpr : public NumberBinaryExpr
{
public:
    SubtractioBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class MultiplicatioBinaryExpr : public NumberBinaryExpr
{
public:
    MultiplicatioBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class DivisioBinaryExpr : public NumberBinaryExpr
{
public:
    DivisioBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class ModulusBinaryExpr : public NumberBinaryExpr
{
public:
    ModulusBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class LogicBinaryExpr : public BinaryExpr
{
public:
    LogicBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : BinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class OrBinaryExpr : public LogicBinaryExpr
{
public:
    OrBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : LogicBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class AndBinaryExpr : public LogicBinaryExpr
{
public:
    AndBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : LogicBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompareBinaryExpr : public BinaryExpr
{
public:
    CompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : BinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class LECompareBinaryExpr : public CompareBinaryExpr
{
public:
    LECompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : CompareBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class LTCompareBinaryExpr : public CompareBinaryExpr
{
public:
    LTCompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : CompareBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class GECompareBinaryExpr : public CompareBinaryExpr
{
public:
    GECompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : CompareBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class GTCompareBinaryExpr : public CompareBinaryExpr
{
public:
    GTCompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : CompareBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class EqCompareBinaryExpr : public CompareBinaryExpr
{
public:
    EqCompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : CompareBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

class NECompareBinaryExpr : public CompareBinaryExpr
{
public:
    NECompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : CompareBinaryExpr(pLhs, pRhs, lineNo)
    {
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ExprStmt : public Stmt
{
private:
    Expr* m_pExpr;

public:
    ExprStmt(Expr* pExpr,
                         ull lineNo) : 
    m_pExpr(pExpr), Stmt(lineNo) 
    {
        Log().Get(logINFO) << "Creating ExprStmt" << std::endl;  
    }
};

class Variable : public Stmt
{
private:
    const DataType* m_datatype;
    Identifier*     m_pId;
    Expr*     m_pAssignmentExpr;

public:
    Variable(const DataType* dataType, 
              Identifier* pId,
              ull lineNo) : 
    m_datatype(dataType), m_pId(pId), m_pAssignmentExpr(NULL), Stmt(lineNo) 
    {
        Log().Get(logINFO) << "Creating Variable" << std::endl;  
    }

    Variable(const DataType* dataType,
              Identifier* pId,
              Expr* assignmentExpr,
              ull lineNo) :
    m_datatype(dataType), m_pId(pId), m_pAssignmentExpr(assignmentExpr), Stmt(lineNo) 
    {
        Log().Get(logINFO) << "Creating Variable" << std::endl;  
    }
};

class FuncDecl : public Stmt
{
protected:
    const DataType*   m_pDataType;
    const Identifier* m_pID;
    VariableList       m_arguments;

public:
    FuncDecl(const DataType* datatype,
                         const Identifier* id,
                         const VariableList& arguments,
                         ull lineNo) :
    m_pDataType(datatype), m_pID(id), m_arguments(arguments), Stmt(lineNo) 
    {
        Log().Get(logINFO) << "Creating FuncDecl" << std::endl;  
    }
};

class FuncDefn : public Stmt
{
protected:
    const DataType*   m_pDataType;
    const Identifier* m_pID;
    VariableList       m_arguments;
    Block*            m_pBlock;

public:
    FuncDefn(const DataType* datatype, 
                        const Identifier* id,
                        const VariableList& arguments,
                        Block* block,
                        ull lineNo) :
    m_pDataType(datatype), m_pID(id), m_arguments(arguments), m_pBlock(block),
    Stmt(lineNo)
    {
        Log().Get(logINFO) << "Creating FuncDefn" << std::endl;  
    }
};

class MainDefn : public FuncDefn
{
public:
    MainDefn(const DataType* datatype, 
                    const VariableList& arguments,
                    Block* block,
                    ull lineNo) :
    FuncDefn(datatype, new Identifier("main", lineNo),
                        arguments, block, lineNo) 
    {
        Log().Get(logINFO) << "Creating MainDefn" << std::endl;  
    }
};

class NConditionalExpr : public Stmt
{
public:
    NConditionalExpr(ull lineNo) : Stmt(lineNo) 
    {
        Log().Get(logINFO) << "Creating NConditionalExpr" << std::endl;  
    }
};

#endif