#include <node.h>
#include <visitor.h>

void DataType::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Identifier::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Integer::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Double::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Float::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Bool::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Char::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void FunctionCall::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Assignment::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Block::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void NegateUnaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void AdditionUnaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void SubtractUnaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void AdditionBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void SubtractionBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void MultiplicationBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void DivisionBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void ModulusBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void OrBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void AndBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void LECompareBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void LTCompareBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void GECompareBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void GTCompareBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void EQCompareBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void NECompareBinaryExpr::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void NullStmt::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void IfStmt::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void WhileStmt::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void ReturnStmt::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void ExprStmt::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void Variable::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void FuncDecl::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void FuncDefn::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}

void MainDefn::accept(Visitor* pVisitor)
{
    pVisitor->visit(this);
}