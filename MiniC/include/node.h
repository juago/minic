#ifndef __NODE__
#define __NODE__

#include <iostream>
#include <string>
#include <vector>
#include <visitor.h>

#include <llvm\Config\config.h>
#if defined(LLVM_VERSION_MAJOR) && LLVM_VERSION_MAJOR == 3 && LLVM_VERSION_MINOR > 2 
#include <llvm/IR/Value.h>
#else
#include <llvm/Value.h>
#endif

#include "logger.h"
#include "utils.h"

class Stmt;
class Expr;
class Variable;

//@todo: This is done since including codegen.h is causing compile errors with llvm. 
// Anyways it's better to just have a forward declaration than to include the entire
// llvm libraries from here.
class CodeGenContext;

// Visitor forward declarations
class Visitor;

typedef std::vector<Stmt*> StmtList;
typedef std::vector<Expr*> ExprList;
typedef std::vector<Variable*> VariableList;

typedef unsigned long long ull;

enum EnumDataType
{
    _VOID_ = 0,
    _CHAR_,
    _SHORT_,
    _INT_,
    _LONG_,
    _FLOAT_,
    _DOUBLE_,
    _SIGNED_,
    _UNSIGNED_,
    _BOOL_,
    _COMPLEX_,
    _IMAGINARY_,
    _STRUCT_OR_UNION_,
    _ENUM_,
    _TYPENAME_,
};

class Node
{
public:
    explicit Node(ull lineNo) : m_lineNo(lineNo) 
    {
    }

    virtual ~Node() { }

    virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }

    ull getLineNo() const { return m_lineNo; }

private:
    const ull m_lineNo;
};

class Expr : public Node
{
public:
    Expr(ull lineNo) : Node(lineNo) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
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
    }

    std::string getTypeStr() const { return getDataTypeStr(m_type); }
    llvm::Type* getLLVMType(CodeGenContext& context);

private:
    static std::string getDataTypeStr(EnumDataType t)
    {
        switch(t)
        {
        case _VOID_:
            return "void";
        case _CHAR_:
            return "char";
        case _SHORT_:
            return "short";
        case _INT_:
            return "int";
        case _LONG_:
            return "long";
        case _FLOAT_:
            return "float";
        case _DOUBLE_:
            return "double";
        case _SIGNED_:
            return "signed";
        case _UNSIGNED_:
            return "unsigned";
        case _BOOL_:
            return "bool";
        case _COMPLEX_:
            return "complex";
        case _IMAGINARY_:
            return "imaginary";
        case _STRUCT_OR_UNION_:
            return "struct_or_union";
        case _ENUM_:
            return "enum";
        case _TYPENAME_:
            return "typename";
        default:
            return "invalid datatype";
        }

        return "";
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
    }

    std::string getName() const { return m_name; }
};

class Stmt : public Node
{
public:
    Stmt(ull lineNo) : Node(lineNo) { }
    virtual const Identifier* getIdentifier() { return NULL; } 
};

class Integer : public Expr
{
public:
    long long m_value;

public:
    Integer(long long value,
             ull lineNo) : m_value(value), Expr(lineNo) 
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Double : public Expr
{
public:
    double m_value;

public:
    Double(double value, 
            ull lineNo) : m_value(value), Expr(lineNo) 
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Float : public Expr
{
private:
    float m_value;

public:
    Float(float value,
           ull lineNo) : m_value(value), Expr(lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Bool : public Expr
{
private:
    bool m_value;

public:
    Bool(bool value,
          ull  lineNo) : m_value(value), Expr(lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Char : public Expr
{
private:
    char m_value;

public:
    Char(char value,
          ull  lineNo) : m_value(value), Expr(lineNo)
    {
    }
    
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class FunctionCall : public Expr
{
private:
    const Identifier* m_pId;
    ExprList          m_arguments;

public:
    FunctionCall(const Identifier* pId,
                 ExprList& arguments,
                 ull lineNo) :
    m_pId(pId), m_arguments(arguments), Expr(lineNo)
    {
    }

    FunctionCall(const Identifier* pId,
                ull lineNo) : m_pId(pId), Expr(lineNo) 
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Assignment : public Expr
{
private:
    const Identifier* m_pLhs;
    Expr* m_pRhs;

public:
    Assignment(const Identifier* pLhs,
               Expr* pRhs,
               ull lineNo) : 
    m_pLhs(pLhs), m_pRhs(pRhs), Expr(lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class Block : public Expr
{
private:
    StmtList m_Stmts;

public:
    Block(ull lineNo) : Expr(lineNo) 
    {
    }

    void AddStmt(Stmt* pStmt)
    {
        m_Stmts.push_back(pStmt);
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
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

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class SubtractionBinaryExpr : public NumberBinaryExpr
{
public:
    SubtractionBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class MultiplicationBinaryExpr : public NumberBinaryExpr
{
public:
    MultiplicationBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class DivisionBinaryExpr : public NumberBinaryExpr
{
public:
    DivisionBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class ModulusBinaryExpr : public NumberBinaryExpr
{
public:
    ModulusBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : NumberBinaryExpr(pLhs, pRhs, lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
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

class EQCompareBinaryExpr : public CompareBinaryExpr
{
public:
    EQCompareBinaryExpr(Expr* pLhs, Expr* pRhs, ull lineNo) : CompareBinaryExpr(pLhs, pRhs, lineNo)
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
class NullStmt : public Stmt
{
public:
    NullStmt(ull lineNo) : Stmt(lineNo)
    {
    }

};

class IfStmt : public Stmt
{
protected:
    Expr* m_pCond;
    Stmt* m_pThenStmt;
    Stmt* m_pElseStmt;

public:
    IfStmt(Expr* pCond, Stmt* pThen, ull lineNo) : m_pCond(pCond), m_pThenStmt(pThen), Stmt(lineNo)
    {
    }

    IfStmt(Expr* pCond, Stmt* pThen, Stmt* pElse, ull lineNo) : m_pCond(pCond), m_pThenStmt(pThen), m_pElseStmt(pElse), Stmt(lineNo)
    {
    }

};

class WhileStmt : public Stmt
{
protected:
    Expr* m_pCond;
    Stmt* m_pStmt;

public:
    WhileStmt(Expr* pCond, Stmt* pStmt, ull lineNo) : m_pCond(pCond), m_pStmt(pStmt), Stmt(lineNo)
    {
    }

};

class ReturnStmt : public Stmt
{
protected:
    Expr* m_pReturnExpr;

public:
    ReturnStmt(Expr* pReturnExpr, ull lineNo) : m_pReturnExpr(pReturnExpr), Stmt(lineNo)
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
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
    }

};

class Variable : public Stmt
{
private:
    DataType*       m_pDatatype;
    Identifier*     m_pId;
    Expr*           m_pAssignmentExpr;

public:
    Variable(DataType* dataType, 
             Identifier* pId,
             ull lineNo) : 
    m_pDatatype(dataType), m_pId(pId), m_pAssignmentExpr(NULL), Stmt(lineNo) 
    {
    }

    Variable(DataType* dataType,
             Identifier* pId,
             Expr* assignmentExpr,
             ull lineNo) :
    m_pDatatype(dataType), m_pId(pId), m_pAssignmentExpr(assignmentExpr), Stmt(lineNo) 
    {
    }

    DataType* getDataType() { return m_pDatatype; }

    Identifier* getIdentifier() { return m_pId; }
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class FuncDecl : public Stmt
{
protected:
    DataType*   m_pDataType;
    Identifier* m_pId;
    VariableList*     m_pArgs;

public:
    FuncDecl(DataType* datatype,
             Identifier* id,
             VariableList* pArgs,
             ull lineNo) :
    m_pDataType(datatype), m_pId(id), m_pArgs(pArgs), Stmt(lineNo) 
    {
    }

    Identifier* getIdentifier() { return m_pId; }
};

class FuncDefn : public Stmt
{
protected:
    DataType*   m_pReturnType;
    Identifier* m_pId;
    VariableList*     m_pArgs;
    Block*            m_pBlock;
        
public:
    FuncDefn(DataType* pReturnType, 
             Identifier* id,
             VariableList* pArgs,
             Block* block,
             ull lineNo) :
    m_pReturnType(pReturnType), m_pId(id), m_pArgs(pArgs), m_pBlock(block),
    Stmt(lineNo)
    {
    }

    Identifier* getIdentifier() { return m_pId; }
    DataType*   getReturnType() { return m_pReturnType; }
    void setBlock(Block* pBlock)
    {
        m_pBlock = pBlock;
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class MainDefn : public FuncDefn
{
public:
    MainDefn(DataType* datatype, 
             VariableList* pArgs,
             Block* block,
             ull lineNo)
    : FuncDefn(datatype, new Identifier("main", lineNo),
               pArgs, block, lineNo) 
    {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context);
};

template <typename T>
T* Error(const char* pStr)
{
    fprintf(stderr, "Error: %s\n", pStr);
    return NULL;
}

#endif