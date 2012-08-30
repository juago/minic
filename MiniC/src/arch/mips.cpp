#include "arch/mips.h"

namespace mips
{
    std::string push(std::string val)
    {
        std::string code = "";
        code += "li $a0, " + val + "\n";
        code += "sw $a0, 0($sp)\n";
        code += "addiu $sp $sp -4\n";
        return code;
    }
}