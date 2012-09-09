#ifndef __X86__
#define __X86__

#include "utils.h"
#include "node.h"
#include <arch/target.h>

class x86Register
{
protected:
    // The Register name
    std::string m_regName;

    // Whether this register can be allocated or not.
    bool        m_isAllocatable;

    // Whether this register is allocated at the current point
    // during code generation.
    bool        m_isAllocated;

public:
    explicit x86Register(std::string reg_name);
    ~x86Register() { }

    std::string getName() const;
    bool        isAllocatable() const;
    void        setAllocatable();
    void        allocate();
    bool        isAllocated() const;
    void        deallocate();
};

class x86Target : public Target
{
public:
    x86Target(int base_fp);
    ~x86Target();

protected:
    void saveCallerSaves();

private:
    std::string copyRegToTemp(std::vector<std::string> validRegs,
                              std::string comment_str);

    std::string getFreeReg(std::vector<std::string> validRegs,
                           std::string preferredReg);

    std::string getTypeValidReg(std::string type);

private:
    std::vector<std::string> m_allRegs;
    std::vector<std::string> m_regsFree;
    std::vector<std::string> m_regsAlmostFree;
    std::vector<std::string> m_calleeSaveRegsUsed;
    std::vector<std::string> m_callerSaveRegs;
    std::vector<std::string> m_calleeSaveRegs;
    std::vector<std::string> m_byteCompatRegs;
    std::vector<std::string> m_memFree;
    std::vector<std::string> m_stack;
    std::vector<std::string> m_typeStack;

    int                      m_nextTemp;
    
protected:
    std::string       m_currentFuncName;
    const DataType*   m_pFuncReturnType;
};

#endif