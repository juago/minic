#ifndef __CODEGEN__
#define __CODEGEN__

#include <stack>
#include <llvm/Module.h>
#include <llvm/Function.h>
#include <llvm/Type.h>
#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/Instructions.h>
#include <llvm/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/IRBuilder.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

class NBlock;

class CodeGenBlock 
{
public:
    BasicBlock *block;
    std::map<std::string, Value*> locals;
};

class CodeGenContext {
public:
    CodeGenContext() 
    { 
        m_pModule = new Module("main", getGlobalContext()); 
        m_pBuilder = new IRBuilder<>(getGlobalContext());
    }
    
    void generateCode(Block& root);
    GenericValue runCode();
    std::map<std::string, Value*>& locals() { return m_blocks.top()->locals; }
    BasicBlock* currentBlock() { return m_blocks.top()->block; }
    void pushBlock(BasicBlock *block) { m_blocks.push(new CodeGenBlock()); m_blocks.top()->block = block; }
    void popBlock() { CodeGenBlock *top = m_blocks.top(); m_blocks.pop(); delete top; }
    Module* getModule() const { return m_pModule; }
    IRBuilder<>* getBuilder() const { return m_pBuilder; }

private:
    std::stack<CodeGenBlock *> m_blocks;
    Function*                  m_pMainFunction;
    Module*                    m_pModule;
    IRBuilder<>*               m_pBuilder;
};

#endif