#ifndef __TARGET__
#define __TARGET__

#include <iostream>
#include <fstream>

#include <utils.h>

class Target
{
public:
    Target();
    virtual ~Target();

protected:
    virtual void emit(std::string output)
    {
        std::cout << output;
    }

    virtual void emitln(std::string output)
    {
        emit(output);
        emit(NEWLINE);
    }

    virtual void emitOp(std::string op)
    {
        emitln(TAB + op);
    }

    virtual void emitOp(std::string op,
                        std::string arg)
    {
        emitOp(op + TAB + arg);
    }

    virtual void emitOp(std::string op,
                        std::string arg1,
                        std::string arg2)
    {
        emitOp(op, arg1 + COMMA + SPACE + arg2);
    }

    virtual void emitLabel(std::string label)
    {
        emitln(label + COLON);
    }

    virtual void emitComment(std::string comment)
    {
        emitln(TAB + "; " + comment);
    }

protected:
    bool m_runtimeFuncUnderscorePrefix;
    std::ofstream m_outputFile;
};

#endif