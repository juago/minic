#include "arch/x86.h"

x86Register::x86Register(std::string reg_name)
    : m_regName(reg_name),
      m_isAllocatable(false),
      m_isAllocated(false)
{
}

std::string x86Register::getName() const
{
    return m_regName;
}

bool x86Register::isAllocatable() const
{
    return m_isAllocatable;
}

bool x86Register::isAllocated() const
{
    return m_isAllocated;
}

void x86Register::setAllocatable()
{
    m_isAllocatable = true;
}

void x86Register::allocate()
{
    m_isAllocated = true;
}

void x86Register::deallocate()
{
    m_isAllocated = false;
}

//---------------------------------------------------------------
x86Target::x86Target(int base_fp)
{
    m_allRegs.push_back("%ebx");
    m_allRegs.push_back("%esi");
    m_allRegs.push_back("%edi");
    m_allRegs.push_back("%eax");
    m_allRegs.push_back("%ecx");
    m_allRegs.push_back("%edx");

    std::copy(m_allRegs.begin(), m_allRegs.end(), m_regsFree.begin());
    
    m_nextTemp = base_fp - WORD_SIZE;

    m_callerSaveRegs.push_back("%eax");
    m_callerSaveRegs.push_back("%ecx");
    m_callerSaveRegs.push_back("%edx");

    m_calleeSaveRegs.push_back("%ebx");
    m_calleeSaveRegs.push_back("%esi");
    m_calleeSaveRegs.push_back("%edi");

    m_byteCompatRegs.push_back("%eax");
    m_byteCompatRegs.push_back("%ebx");
    m_byteCompatRegs.push_back("%ecx");
    m_byteCompatRegs.push_back("%edx");
}

// caller-save registers by convention need to be saved by the caller prior
// to calling subroutines.

// callee-save registers need to be saved by the callee (the subroutine itself)
// 

/*
 * Save the caller-save registers, which should be done before the current function
 * makes a function call, so that the registers don't get corrupted by the called 
 * function.
 *
 * Normally this is done by pushing the caller-save registers onto the stack
 * just before the function call is made and popping them off afterwards; however,
 * due to the workings of this particular stack machine it's easier to just move
 * the contents of the caller-save registers, if they are currently being used,
 * into temporary variables.
 */

void x86Target::saveCallerSaves()
{
    for (int i = 0; i < m_callerSaveRegs.size(); ++i)
    {
        if (std::find(m_regsFree.begin(), m_regsFree.end(), m_callerSaveRegs[i]) == m_regsFree.end())
        {

        }
    }
}

/*
 * Copy the least recently used register on the stack into a temporary
 * variable. The register must be in the valid registers.
 */
std::string x86Target::copyRegToTemp(std::vector<std::string> validRegs,
                                      std::string comment_str)
{
    // If no free temp variables exist, create a new one.
    if (m_memFree.size() == 0)
    {
        std::string reg = toString(m_nextTemp) + "(%ebp)";
        m_memFree.push_back(reg);
        m_nextTemp -= WORD_SIZE;
    }

    // Get an unused temp var
    std::string mem = pop(m_memFree);

    // find the least recently used register on the stack
    std::string reg = "";
    int index = 0;

    std::vector<std::string>::iterator iter;
    for (iter = m_stack.begin(); iter != m_stack.end(); ++iter)
    {
        if (isInVector(validRegs, *iter))
        {
            reg = *iter;
            break;
        }

        ++index;
    }

    if (reg == "")
        throw std::exception("No free registers inside or outside of stack");

    // emit code to copy the register to the memory location
    if (comment_str == "")
    {
        comment_str = "Stack Machine: copy register to temp";
    }

    emitComment(comment_str);
    emitln("  movl " + reg + ", " + mem);

    m_stack[index] = mem;
    return reg;
}

/*
 * Returns a free register that is in the valid regs list. If no registers
 * are available, the most least recently used eligible one is freed (by moving
 * its content to a temporary variable) and returned.
 */
std::string x86Target::getFreeReg(std::vector<std::string> validRegs,
                                  std::string preferredReg)
{
    if (m_regsFree.size() > 0)
    {
        std::string reg = "";
        if (preferredReg != "" && isInVector(m_regsFree, preferredReg))
            reg = preferredReg;
        else
        {
            for (int i = 0; i < m_regsFree.size(); ++i)
            {
                if (isInVector(validRegs, m_regsFree[i]))
                    reg = m_regsFree[i];
            }
        }

        if (reg != "")
        {
            eraseVectorElement(m_regsFree, reg);
            // If this register is a callee-save register that
            // we haven't used before, add it to our list of used
            // callee-save registers.
            if (isInVector(m_calleeSaveRegs, reg) && !isInVector(m_calleeSaveRegsUsed, reg))
                m_calleeSaveRegsUsed.push_back(reg);

            return reg;
        }
    }

    // Copy a register into a temp var and return the register
    return copyRegToTemp(validRegs, "");
}

