#include <arch/mips.h>
#include <utils.h>

std::string MipsVisitor::reg_name(MipsRegister reg)
{
    std::string prefix = "$";
    std::string code_str = stringify(reg);
    return prefix + code_str;
}

std::string MipsVisitor::push(std::string val)
{
    std::string code = "";
    code += "li $a0, " + val + "\n";
    code += "sw $a0, 0($sp)\n";
    code += "addiu $sp $sp -4\n";
    return code;
}

std::string MipsVisitor::emit_load_word(MipsRegister dst, int offset, MipsRegister src)
{
    std::string code_str = "lw " + toString(offset) + "(" + reg_name(src) + ")" + "\n";
    return code_str;
}

std::string MipsVisitor::emit_store_word(MipsRegister dst, int offset, MipsRegister src)
{
    std::string code_str = "sw " + reg_name(src) + " " + toString(offset) + "(" + reg_name(dst) + ")" + "\n";
    return code_str;
}

std::string MipsVisitor::emit_addiu(MipsRegister dst, MipsRegister src, int immd)
{
    std::string code_str = "addiu " + reg_name(dst) + " " + reg_name(dst) + " " + stringify(immd) + "\n";
    return code_str;
}

std::string MipsVisitor::emit_li(MipsRegister dst, int immd)
{
    std::string code_str = "li " + reg_name(dst) + " " + stringify(immd) + "\n";
    return code_str;
}

/// Arithmetic Operations ///

std::string MipsVisitor::emit_add(MipsRegister dst, MipsRegister src1, MipsRegister src2)
{
    std::string code_str = "add " + reg_name(dst) + " " + reg_name(src1) + " " + reg_name(src2) + "\n";
    return code_str;
}

std::string MipsVisitor::emit_sub(MipsRegister dst, MipsRegister src1, MipsRegister src2)
{
    std::string code_str = "sub " + reg_name(dst) + " " + reg_name(src1) + " " + reg_name(src2) + "\n";
    return code_str;
}

std::string MipsVisitor::emit_mul(MipsRegister dst, MipsRegister src1, MipsRegister src2)
{
    std::string code_str = "mul " + reg_name(dst) + " " + reg_name(src1) + " " + reg_name(src2) + "\n";
    return code_str;
}

std::string MipsVisitor::emit_div(MipsRegister dst, MipsRegister src1, MipsRegister src2)
{
    std::string code_str = "div " + reg_name(dst) + " " + reg_name(src1) + " " + reg_name(src2) + "\n";
    return code_str;
}
