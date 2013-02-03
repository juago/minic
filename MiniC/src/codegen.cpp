#include "node.h"
#include "codegen.h"
#include "parser.h"

using namespace std;
using namespace llvm;

/* Compile the AST into a module */
void CodeGenContext::generateCode(Block& root)
{
	std::cout << "Generating code...\n";
	
	/* Create the top level interpreter function to call as entry */
	vector<Type*> argTypes;
	// FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), makeArrayRef(argTypes), false);
	// m_pMainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", m_pModule);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry");
	
	/* Push a new variable/block context */
	pushBlock(bblock);
	root.codeGen(*this); /* emit bytecode for the toplevel block */
	ReturnInst::Create(getGlobalContext(), bblock);
	popBlock();
	
	/* Print the bytecode in a human-readable format 
	   to see if our program compiled properly
	 */
	std::cout << "Code is generated.\n";
	PassManager pm;
	pm.add(createPrintModulePass(&outs()));
	pm.run(*m_pModule);
}

/* Executes the AST by running the main function */
GenericValue CodeGenContext::runCode() {
	std::cout << "Running code...\n";
	ExecutionEngine *ee = EngineBuilder(m_pModule).create();
	vector<GenericValue> noargs;
	GenericValue v = ee->runFunction(m_pMainFunction, noargs);
	std::cout << "Code was run.\n";
	return v;
}