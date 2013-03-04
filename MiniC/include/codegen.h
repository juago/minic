#ifndef __CODEGEN__
#define __CODEGEN__

#include <stack>
#include <llvm\Config\config.h>
#if defined(LLVM_VERSION_MAJOR) && LLVM_VERSION_MAJOR == 3 && LLVM_VERSION_MINOR > 2 
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#else
#include <llvm/Module.h>
#include <llvm/Function.h>
#include <llvm/Type.h>
#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>
#include <llvm/IRBuilder.h>
#include <llvm/Instructions.h>
#include <llvm/CallingConv.h>
#endif

#include <llvm/PassManager.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>

class NBlock;

class CodeGenBlock 
{
public:
    llvm::BasicBlock *block;
    std::map<std::string, llvm::Value*> locals;
};

class CodeGenContext {
public:
    CodeGenContext() 
    { 
        m_pModule = new llvm::Module("c-main", llvm::getGlobalContext()); 
        m_pBuilder = new llvm::IRBuilder<>(llvm::getGlobalContext());
    }
    
    void generateCode(Block& root);
    llvm::GenericValue runCode();
    std::map<std::string, llvm::Value*>& locals() { return m_blocks.top()->locals; }
    llvm::BasicBlock* currentBlock() { return m_blocks.top()->block; }
    void pushBlock(llvm::BasicBlock *block) { m_blocks.push(new CodeGenBlock()); m_blocks.top()->block = block; }
    void popBlock() { CodeGenBlock *top = m_blocks.top(); m_blocks.pop(); delete top; }
    llvm::Module* getModule() const { return m_pModule; }
    llvm::IRBuilder<>* getBuilder() const { return m_pBuilder; }

    void SetMainFunction(llvm::Function* pMainFunc)
    {
        m_pMainFunction = pMainFunc;
    }

    llvm::Function* GetMainFunction()
    {
        return m_pMainFunction;
    }

private:
    std::stack<CodeGenBlock *>       m_blocks;
    llvm::Function*                  m_pMainFunction;
    llvm::Module*                    m_pModule;
    llvm::IRBuilder<>*               m_pBuilder;
};

#endif