#ifndef __VISITOR__
#define __VISITOR__

#include <utils.h>
#include <node.h>
#include <output.h>

class DataType;
class Identifier;
class Stmt;
class Integer;
class Float;
class Double;
class Bool;
class Char;
class FunctionCall;
class Assignment;
class Block;
class NegateUnaryExpr;
class AdditionUnaryExpr;
class SubtractUnaryExpr;
class AdditionBinaryExpr;
class SubtractionBinaryExpr;
class MultiplicationBinaryExpr;
class DivisionBinaryExpr;
class ModulusBinaryExpr;
class OrBinaryExpr;
class AndBinaryExpr;
class CompareBinaryExpr;
class LECompareBinaryExpr;
class LTCompareBinaryExpr;
class GECompareBinaryExpr;
class GTCompareBinaryExpr;
class NECompareBinaryExpr;
class EQCompareBinaryExpr;
class NullStmt;
class IfStmt;
class WhileStmt;
class ReturnStmt;
class ExprStmt;
class Variable;
class FuncDecl;
class FuncDefn;
class MainDefn;

class Visitor
{
public:
    Visitor(Output* pOutput) : m_pOutput(pOutput) { }
    ~Visitor();

    virtual void visit(DataType*                 pDataType) = 0;
    virtual void visit(Identifier*               pIdentifier) = 0;
    virtual void visit(Stmt*                     pStmt) = 0;
    virtual void visit(Integer*                  pInteger) = 0;
    virtual void visit(Float*                    pFloat) = 0;
    virtual void visit(Double*                   pDouble) = 0;
    virtual void visit(Bool*                     pBool) = 0;
    virtual void visit(Char*                     pChar) = 0;
    virtual void visit(FunctionCall*             pFuncCall) = 0;
    virtual void visit(Assignment*               pAssignment) = 0;
    virtual void visit(Block*                    pBlock) = 0;
    virtual void visit(NegateUnaryExpr*          pNegateUnaryExpr) = 0;
    virtual void visit(AdditionUnaryExpr*        pAdditionUnaryExpr) = 0;
    virtual void visit(SubtractUnaryExpr*        pSubtractUnaryExpr) = 0;
    virtual void visit(AdditionBinaryExpr*       pAdditionBinaryExpr) = 0;
    virtual void visit(SubtractionBinaryExpr*    pSubtractionBinaryExpr) = 0;
    virtual void visit(MultiplicationBinaryExpr* pMultiplicationBinaryExpr) = 0;
    virtual void visit(DivisionBinaryExpr*       pDivisionBinaryExpr) = 0;
    virtual void visit(ModulusBinaryExpr*        pModulusBinaryExpr) = 0;
    virtual void visit(OrBinaryExpr*             pOrBinaryExpr) = 0;
    virtual void visit(AndBinaryExpr*            pAndBinaryExpr) = 0;
    virtual void visit(LECompareBinaryExpr*      pLECompareBinaryExpr) = 0;
    virtual void visit(LTCompareBinaryExpr*      pLTCompareBinaryExpr) = 0;
    virtual void visit(GECompareBinaryExpr*      pGECompareBinaryExpr) = 0;
    virtual void visit(GTCompareBinaryExpr*      pGTCompareBinaryExpr) = 0;
    virtual void visit(EQCompareBinaryExpr*      pEQCompareBinaryExpr) = 0;
    virtual void visit(NECompareBinaryExpr*      pNECompareBinaryExpr) = 0;
    virtual void visit(IfStmt*                   pIfStmt) = 0;
    virtual void visit(WhileStmt*                pWhileStmt) = 0;
    virtual void visit(ReturnStmt*               pReturnStmt) = 0;
    virtual void visit(ExprStmt*                 pExprStmt) = 0;
    virtual void visit(Variable*                 pVariable) = 0;
    virtual void visit(FuncDecl*                 pFuncDecl) = 0;
    virtual void visit(FuncDefn*                 pFuncDefn) = 0;
    virtual void visit(MainDefn*                 pMainDefn) = 0;

protected:
    Output*          m_pOutput;
};

#endif