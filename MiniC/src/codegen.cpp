#include "node.h"
#include "codegen.h"
#include "parser.h"

using namespace std;

/* Compile the AST into a module */
void CodeGenContext::generateCode(Block& root)
{
    std::cout << "Generating code...\n";
    root.codeGen(*this); /* emit bytecode for the toplevel block */
    
    /* Print the bytecode in a human-readable format 
       to see if our program compiled properly
     */
    std::cout << "Code is generated.\n";
    llvm::PassManager pm;
    pm.add(llvm::createPrintModulePass(&llvm::outs()));
    pm.run(*m_pModule);
}

/* Executes the AST by running the main function */
llvm::GenericValue CodeGenContext::runCode() {
    std::cout << "Running code...\n";
    llvm::ExecutionEngine *ee = llvm::EngineBuilder(m_pModule).create();
    vector<llvm::GenericValue> noargs;
    llvm::GenericValue v = ee->runFunction(m_pMainFunction, noargs);
    std::cout << "Code was run.\n";
    return v;
}