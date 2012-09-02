#ifndef __X86__
#define __X86__

#include "utils.h"

enum x86RegEnum
{
    eax,
    esi,
    edi,
    eax,
    ecx,
    edx,
};

class x86Registers
{
public:
    x86Registers(int base_fp);
    ~x86Registers();


private:
    std::string getRegister(x86RegEnum reg);
    std::vector<x86RegEnum> m_regsFree;
    std::vector<x86RegEnum> m_regsAlmostFee;
    std::vector<x86RegEnum> m_memFree;
    int                     m_nextTemp;

};

#endif