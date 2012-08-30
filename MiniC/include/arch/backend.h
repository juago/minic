#ifndef __BACKEND__
#define __BACKEND__

#include <string>

class Backend
{
public:
    std::string DataTypeCodeGen() = 0;

    std::string IdentifierCodeGen() = 0;

    std::string IntegerCodeGen() = 0;

    std::string DoubleCodeGen() = 0;

    std::string FloatCodeGen() = 0;

    std::string BoolCodeGen() = 0;

    std::string CharCodeGen() = 0;

    std::string FunctionCallCodeGen() = 0;

    std::string BlockCodeGen() = 0;

    std::string AdditionUnaryExprCodeGen() = 0;

    std::string SubtractUnaryExprCodeGen() = 0;

    std::string AdditionBinaryExprCodeGen() = 0;

    std::string SubtractionBinaryExprCodeGen() = 0;

    std::string MultiplicationBinaryExprCodeGen() = 0;

    std::string DivisionBinaryExprCodeGen() = 0;

    std::string ModulusBinaryExprCodeGen() = 0;

    std::string OrBinaryExprCodeGen() = 0;

    std::string AndBinaryExprCodeGen() = 0;

    std::string LECompareBinaryExprCodeGen() = 0;

    std::string LTCompareBinaryExprCodeGen() = 0;

    std::string GECompareBinaryExprCodeGen() = 0;

    std::string GTCompareBinaryExprCodeGen() = 0;

    std::string EQCompareBinaryExprCodeGen() = 0;

    std::string NECompareBinaryExprCodeGen() = 0;

    std::string NullStmtCodeGen() = 0;

    std::string IfStmtCodeGen() = 0;

    std::string WhileStmtCodeGen() = 0;

    std::string ReturnStmtCodeGen() = 0;

    std::string ExprStmtCodeGen() = 0;

    std::string VariableCodeGen() = 0;

    std::string FuncDeclCodeGen() = 0;

    std::string FuncDefnCodeGen() = 0;

    std::string MainDefnCodeGen() = 0;
};

#endif