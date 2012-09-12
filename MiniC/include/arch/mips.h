#ifndef __MIPS__
#define __MIPS__

#include <string>

#include <node.h>
#include <visitor.h>

// These are the registers for Mips. Currently, listed only are the ones
// from QtSpim.
enum MipsRegister
{
    r0,
    at,
    v0,
    v1,
    a0,
    a1,
    a2,
    a3,
    t0,
    t1,
    t2,
    t3,
    t4,
    t5,
    t6,
    t7,
    t8,
    t9,
    s0,
    s1,
    s2,
    s3,
    s4,
    s5,
    s6,
    s7,
    s8,
    k0,
    k1,
    gp,
    sp,
    ra
};

// This is a 1 register stack machine as described in the Coursera Mips Code Generation strategy. The register which is used
// as the accumulator is a0.
class MipsVisitor : public Visitor
{
public:
    MipsVisitor();
    virtual ~MipsVisitor();
    // Stack Based Code Gen would use push & pop frequently.
    static std::string push(std::string val);
    static std::string pop();

    void visit(DataType*                 pDataType);
    void visit(Identifier*               pIdentifier);
    void visit(Stmt*                     pStmt);
    void visit(Integer*                  pInteger);
    void visit(Float*                    pFloat);
    void visit(Double*                   pDouble);
    void visit(Bool*                     pBool);
    void visit(Char*                     pChar);
    void visit(FunctionCall*             pFuncCall);
    void visit(Assignment*               pAssignment);
    void visit(Block*                    pBlock);
    void visit(UnaryExpr*                pUnaryExpr);
    void visit(NegateUnaryExpr*          pNegateUnaryExpr);
    void visit(AdditionUnaryExpr*        pAdditionUnaryExpr);
    void visit(SubtractUnaryExpr*        pSubtractUnaryExpr);
    void visit(NumberBinaryExpr*         pBinaryExpr);
    void visit(AdditionBinaryExpr*       pAdditionBinaryExpr);
    void visit(SubtractionBinaryExpr*    pSubtractionBinaryExpr);
    void visit(MultiplicationBinaryExpr* pMultiplicationBinaryExpr);
    void visit(DivisionBinaryExpr*       pDivisionBinaryExpr);
    void visit(ModulusBinaryExpr*        pModulusBinaryExpr);
    void visit(LogicBinaryExpr*          pLogicBinaryExpr);
    void visit(OrBinaryExpr*             pOrBinaryExpr);
    void visit(AndBinaryExpr*            pAndBinaryExpr);
    void visit(LECompareBinaryExpr*      pLECompareBinaryExpr);
    void visit(LTCompareBinaryExpr*      pLTCompareBinaryExpr);
    void visit(GECompareBinaryExpr*      pGECompareBinaryExpr);
    void visit(GTCompareBinaryExpr*      pGTCompareBinaryExpr);
    void visit(EQCompareBinaryExpr*      pEQCompareBinaryExpr);
    void visit(NECompareBinaryExpr*      pNECompareBinaryExpr);
    void visit(IfStmt*                   pIfStmt);
    void visit(WhileStmt*                pWhileStmt);
    void visit(ReturnStmt*               pReturnStmt);
    void visit(ExprStmt*                 pExprStmt);
    void visit(Variable*                 pVariable);
    void visit(FuncDecl*                 pFuncDecl);
    void visit(FuncDefn*                 pFuncDefn);
    void visit(MainDefn*                 pMainDefn);

protected:
    std::string emit_load_word (MipsRegister dst, int offset, MipsRegister src);
    std::string emit_store_word(MipsRegister dst, int offset, MipsRegister src);
    std::string emit_addiu     (MipsRegister dst, MipsRegister src, int immd);
    std::string emit_li        (MipsRegister dst, int immd);

    std::string emit_add       (MipsRegister dst, MipsRegister src1, MipsRegister src2);
    std::string emit_sub       (MipsRegister dst, MipsRegister src1, MipsRegister src2);
    std::string emit_mul       (MipsRegister dst, MipsRegister src1, MipsRegister src2);
    std::string emit_div       (MipsRegister dst, MipsRegister src1, MipsRegister src2);

private:
    std::string reg_name(MipsRegister reg);
};

#endif