#ifndef __BACKEND__
#define __BACKEND__

#include <string>

class Backend
{
public:
    virtual std::string DataTypeCodeGen() = 0;

    virtual std::string IdentifierCodeGen() = 0;

    virtual std::string IntegerCodeGen() = 0;

    virtual std::string DoubleCodeGen() = 0;

    virtual std::string FloatCodeGen() = 0;

    virtual std::string BoolCodeGen() = 0;

    virtual std::string CharCodeGen() = 0;

    virtual std::string FunctionCallCodeGen() = 0;

    virtual std::string BlockCodeGen() = 0;

    virtual std::string AdditionUnaryExprCodeGen() = 0;

    virtual std::string SubtractUnaryExprCodeGen() = 0;

    virtual std::string AdditionBinaryExprCodeGen() = 0;

    virtual std::string SubtractionBinaryExprCodeGen() = 0;

    virtual std::string MultiplicationBinaryExprCodeGen() = 0;

    virtual std::string DivisionBinaryExprCodeGen() = 0;

    virtual std::string ModulusBinaryExprCodeGen() = 0;

    virtual std::string OrBinaryExprCodeGen() = 0;

    virtual std::string AndBinaryExprCodeGen() = 0;

    virtual std::string LECompareBinaryExprCodeGen() = 0;

    virtual std::string LTCompareBinaryExprCodeGen() = 0;

    virtual std::string GECompareBinaryExprCodeGen() = 0;

    virtual std::string GTCompareBinaryExprCodeGen() = 0;

    virtual std::string EQCompareBinaryExprCodeGen() = 0;

    virtual std::string NECompareBinaryExprCodeGen() = 0;

    virtual std::string NullStmtCodeGen() = 0;

    virtual std::string IfStmtCodeGen() = 0;

    virtual std::string WhileStmtCodeGen() = 0;

    virtual std::string ReturnStmtCodeGen() = 0;

    virtual std::string ExprStmtCodeGen() = 0;

    virtual std::string VariableCodeGen() = 0;

    virtual std::string FuncDeclCodeGen() = 0;

    virtual std::string FuncDefnCodeGen() = 0;

    virtual std::string MainDefnCodeGen() = 0;
};

#endif