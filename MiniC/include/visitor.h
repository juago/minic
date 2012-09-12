#ifndef __VISITOR__
#define __VISITOR__

#include <utils.h>
#include <node.h>
#include <output.h>

class Visitor
{
public:
    Visitor(Output* pOutput) : m_pOutput(pOutput) { }
    ~Visitor();

    template <typename T>
    void visit(T* pT)
    {
        pT->accept(this);
    }

    //virtual void visit(DataType*                 pDataType) = 0;
    //virtual void visit(Identifier*               pIdentifier) = 0;
    //virtual void visit(Stmt*                     pStmt) = 0;
    //virtual void visit(Integer*                  pInteger) = 0;
    //virtual void visit(Float*                    pFloat) = 0;
    //virtual void visit(Double*                   pDouble) = 0;
    //virtual void visit(Bool*                     pBool) = 0;
    //virtual void visit(Char*                     pChar) = 0;
    //virtual void visit(FunctionCall*             pFuncCall) = 0;
    //virtual void visit(Assignment*               pAssignment) = 0;
    //virtual void visit(Block*                    pBlock) = 0;
    //virtual void visit(UnaryExpr*                pUnaryExpr) = 0;
    //virtual void visit(NegateUnaryExpr*          pNegateUnaryExpr) = 0;
    //virtual void visit(AdditionUnaryExpr*        pAdditionUnaryExpr) = 0;
    //virtual void visit(SubtractUnaryExpr*        pSubtractUnaryExpr) = 0;
    //virtual void visit(NumberBinaryExpr*         pBinaryExpr) = 0;
    //virtual void visit(AdditionBinaryExpr*       pAdditionBinaryExpr) = 0;
    //virtual void visit(SubtractionBinaryExpr*    pSubtractionBinaryExpr) = 0;
    //virtual void visit(MultiplicationBinaryExpr* pMultiplicationBinaryExpr) = 0;
    //virtual void visit(DivisionBinaryExpr*       pDivisionBinaryExpr) = 0;
    //virtual void visit(ModulusBinaryExpr*        pModulusBinaryExpr) = 0;
    //virtual void visit(LogicBinaryExpr*          pLogicBinaryExpr) = 0;
    //virtual void visit(OrBinaryExpr*             pOrBinaryExpr) = 0;
    //virtual void visit(AndBinaryExpr*            pAndBinaryExpr) = 0;
    //virtual void visit(LECompareBinaryExpr*      pLECompareBinaryExpr) = 0;
    //virtual void visit(LTCompareBinaryExpr*      pLTCompareBinaryExpr) = 0;
    //virtual void visit(GECompareBinaryExpr*      pGECompareBinaryExpr) = 0;
    //virtual void visit(GTCompareBinaryExpr*      pGTCompareBinaryExpr) = 0;
    //virtual void visit(EQCompareBinaryExpr*      pEQCompareBinaryExpr) = 0;
    //virtual void visit(NECompareBinaryExpr*      pNECompareBinaryExpr) = 0;
    //virtual void visit(IfStmt*                   pIfStmt) = 0;
    //virtual void visit(WhileStmt*                pWhileStmt) = 0;
    //virtual void visit(ReturnStmt*               pReturnStmt) = 0;
    //virtual void visit(ExprStmt*                 pExprStmt) = 0;
    //virtual void visit(Variable*                 pVariable) = 0;
    //virtual void visit(FuncDecl*                 pFuncDecl) = 0;
    //virtual void visit(FuncDefn*                 pFuncDefn) = 0;
    //virtual void visit(MainDefn*                 pMainDefn) = 0;

protected:
    Output*          m_pOutput;
};

#endif