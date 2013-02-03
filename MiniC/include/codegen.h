#ifndef __CODEGEN__
#define __CODEGEN__

#include <stack>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRBuilder.h>

#include <llvm/PassManager.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
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
        m_pModule = new Module("c-main", getGlobalContext()); 
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

	void SetMainFunction(Function* pMainFunc)
	{
		m_pMainFunction = pMainFunc;
	}

	Function* GetMainFunction()
	{
		return m_pMainFunction;
	}

private:
    std::stack<CodeGenBlock *> m_blocks;
    Function*                  m_pMainFunction;
    Module*                    m_pModule;
    IRBuilder<>*               m_pBuilder;
};

#endif