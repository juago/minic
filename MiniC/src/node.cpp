#include <node.h>
#include <visitor.h>
#include <codegen.h>

/* Returns an LLVM type based on the identifier */
static Type *typeOf(std::string& type) 
{
    if (type.compare("int") == 0) {
		return Type::getInt64Ty(getGlobalContext());
	}
    else if (type.compare("double") == 0) {
		return Type::getDoubleTy(getGlobalContext());
	}
	return Type::getVoidTy(getGlobalContext());
}

Value* Variable::codeGen(CodeGenContext& context)
{
    std::cout << "Creating Variable Declaration: " << m_pId->getName() << std::endl;
    AllocaInst* pAlloc = new AllocaInst(typeOf(m_datatype->getDataType()), m_pId->getName(), context.currentBlock());
    context.locals()[m_pId->getName()] = pAlloc;
    if (m_pAssignmentExpr != NULL)
    {
        Assignment assn(m_pId, m_pAssignmentExpr, getLineNo());
        assn.codeGen(context);
    }

    return pAlloc;
}

Value* Integer::codeGen(CodeGenContext& context)
{
    return ConstantInt::get(Type::getInt32Ty(getGlobalContext()), m_value);
}

Value* Double::codeGen(CodeGenContext& context)
{
    return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), m_value);
}

Value* Float::codeGen(CodeGenContext& context)
{
    return ConstantFP::get(Type::getFloatTy(getGlobalContext()), m_value);
}

Value* Bool::codeGen(CodeGenContext& context)
{
    return ConstantInt::get(Type::getInt1Ty(getGlobalContext()), m_value);
}

Value* Char::codeGen(CodeGenContext& context)
{
    return ConstantInt::get(Type::getInt8Ty(getGlobalContext()), m_value);
}

Value* FunctionCall::codeGen(CodeGenContext& context)
{
    Function* pFunction = context.getModule()->getFunction(m_pId->getName());
    if (pFunction == NULL)
    {
        std::cerr << "No such function: " << m_pId->getName() << std::endl;
    }

    std::vector<Value *> args;
    ExprList::const_iterator it;
    for (it = m_arguments.begin(); it != m_arguments.end(); ++it)
    {
        args.push_back((*it)->codeGen(context));
    }

    CallInst* pCall = CallInst::Create(pFunction, makeArrayRef(args), "", context.currentBlock());
    std::cout << "Creating method call: " << m_pId->getName() << std::endl;
    return pCall;
}

Value* AdditionBinaryExpr::codeGen(CodeGenContext& context)
{
    Value* pL = m_pLhs->codeGen(context);
    Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateAdd(pL, pR, "addtmp");
}

Value* SubtractionBinaryExpr::codeGen(CodeGenContext& context)
{
    Value* pL = m_pLhs->codeGen(context);
    Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateSub(pL, pR, "addtmp");
}

Value* MultiplicationBinaryExpr::codeGen(CodeGenContext& context)
{
    Value* pL = m_pLhs->codeGen(context);
    Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateMul(pL, pR, "addtmp");
}

Value* DivisionBinaryExpr::codeGen(CodeGenContext& context)
{
    Value* pL = m_pLhs->codeGen(context);
    Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateFDiv(pL, pR, "addtmp");
}

Value* ModulusBinaryExpr::codeGen(CodeGenContext& context)
{
    Value* pL = m_pLhs->codeGen(context);
    Value* pR = m_pRhs->codeGen(context);

    if (pL == NULL || pR == NULL)
        return NULL;

    return context.getBuilder()->CreateFRem(pL, pR, "addtmp");
}

Value* Block::codeGen(CodeGenContext& context)
{
    StmtList::const_iterator it;
	Value *last = NULL;
	for (it = m_Stmts.begin(); it != m_Stmts.end(); it++) 
    {
		std::cout << "Generating code for " << typeid(**it).name() << endl;
		last = (**it).codeGen(context);
	}
	
    std::cout << "Creating block" << endl;
	return last;
}

Value* MainDefn::codeGen(CodeGenContext& context)
{
	FunctionType* fType = FunctionType::get(Type::getInt32Ty(getGlobalContext()), 0);
	Function* pMainFunc = Function::Create(fType, GlobalValue::InternalLinkage, "main", context.getModule());

	context.SetMainFunction(pMainFunc);

	return pMainFunc;
}