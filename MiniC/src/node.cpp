#include <node.h>
#include <visitor.h>
#include <codegen.h>

/* Returns an LLVM type based on the identifier */
static llvm::Type *typeOf(std::string& type) 
{
    if (type.compare("int") == 0) {
        return llvm::Type::getInt64Ty(llvm::getGlobalContext());
    }
    else if (type.compare("double") == 0) {
        return llvm::Type::getDoubleTy(llvm::getGlobalContext());
    }
    return llvm::Type::getVoidTy(llvm::getGlobalContext());
}

llvm::Value* Variable::codeGen(CodeGenContext& context)
{
    std::cout << "Creating Variable Declaration: " << m_pId->getName() << std::endl;
    llvm::AllocaInst* pAlloc = new llvm::AllocaInst(typeOf(m_datatype->getDataType()), m_pId->getName(), context.currentBlock());
    context.locals()[m_pId->getName()] = pAlloc;
    if (m_pAssignmentExpr != NULL)
    {
        Assignment assn(m_pId, m_pAssignmentExpr, getLineNo());
        assn.codeGen(context);
    }

    return pAlloc;
}

llvm::Value* Integer::codeGen(CodeGenContext& context)
{
    return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), m_value);
}

llvm::Value* Double::codeGen(CodeGenContext& context)
{
    return llvm::ConstantFP::get(llvm::Type::getDoubleTy(llvm::getGlobalContext()), m_value);
}

llvm::Value* Float::codeGen(CodeGenContext& context)
{
    return llvm::ConstantFP::get(llvm::Type::getFloatTy(llvm::getGlobalContext()), m_value);
}

llvm::Value* Bool::codeGen(CodeGenContext& context)
{
    return llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvm::getGlobalContext()), m_value);
}

llvm::Value* Char::codeGen(CodeGenContext& context)
{
    return llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvm::getGlobalContext()), m_value);
}

llvm::Value* FunctionCall::codeGen(CodeGenContext& context)
{
    llvm::Function* pFunction = context.getModule()->getFunction(m_pId->getName());
    if (pFunction == NULL)
    {
        std::cerr << "No such function: " << m_pId->getName() << std::endl;
    }

    std::vector<llvm::Value *> args;
    ExprList::const_iterator it;
    for (it = m_arguments.begin(); it != m_arguments.end(); ++it)
    {
        args.push_back((*it)->codeGen(context));
    }

    llvm::CallInst* pCall = llvm::CallInst::Create(pFunction, llvm::makeArrayRef(args), "", context.currentBlock());
    std::cout << "Creating method call: " << m_pId->getName() << std::endl;
    return pCall;
}

llvm::Value* AdditionBinaryExpr::codeGen(CodeGenContext& context)
{
    llvm::Value* pL = m_pLhs->codeGen(context);
    llvm::Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateAdd(pL, pR, "addtmp");
}

llvm::Value* SubtractionBinaryExpr::codeGen(CodeGenContext& context)
{
    llvm::Value* pL = m_pLhs->codeGen(context);
    llvm::Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateSub(pL, pR, "addtmp");
}

llvm::Value* MultiplicationBinaryExpr::codeGen(CodeGenContext& context)
{
    llvm::Value* pL = m_pLhs->codeGen(context);
    llvm::Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateMul(pL, pR, "addtmp");
}

llvm::Value* DivisionBinaryExpr::codeGen(CodeGenContext& context)
{
    llvm::Value* pL = m_pLhs->codeGen(context);
    llvm::Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateFDiv(pL, pR, "addtmp");
}

llvm::Value* ModulusBinaryExpr::codeGen(CodeGenContext& context)
{
    llvm::Value* pL = m_pLhs->codeGen(context);
    llvm::Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateFRem(pL, pR, "addtmp");
}

llvm::Value* Block::codeGen(CodeGenContext& context)
{
    StmtList::const_iterator it;
    llvm::Value *last = NULL;
    for (it = m_Stmts.begin(); it != m_Stmts.end(); it++) 
    {
        std::cout << "Generating code for " << typeid(**it).name() << endl;
        last = (**it).codeGen(context);
    }
    
    std::cout << "Creating block" << endl;
    return last;
}

llvm::Value* MainDefn::codeGen(CodeGenContext& context)
{
    llvm::FunctionType* fType = llvm::FunctionType::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 0);
    llvm::Function* pMainFunc = llvm::Function::Create(fType, llvm::GlobalValue::InternalLinkage, "main", context.getModule());

    context.SetMainFunction(pMainFunc);

    return pMainFunc;
}