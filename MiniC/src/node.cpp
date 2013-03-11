#include <node.h>
#include <visitor.h>
#include <codegen.h>

#include <llvm/ADT/SmallVector.h>

llvm::Type* DataType::getLLVMType(CodeGenContext& context)
{
    switch(m_type)
    {
    case _VOID_:
        return context.getBuilder()->getVoidTy();
    case _CHAR_:
        return context.getBuilder()->getInt8Ty();
    case _SHORT_:
        return context.getBuilder()->getInt16Ty();
    case _INT_:
        return context.getBuilder()->getInt32Ty();
    case _LONG_:
        return context.getBuilder()->getInt64Ty();
    case _FLOAT_:
        return context.getBuilder()->getFloatTy();
    case _DOUBLE_:
        return context.getBuilder()->getDoubleTy();
        //case _SIGNED_:
        //    break;
        //case _UNSIGNED_:
        //    return "unsigned";
    case _BOOL_:
        return context.getBuilder()->getInt1Ty();
        //case _COMPLEX_:
        //    return "complex";
        //case _IMAGINARY_:
        //    return "imaginary";
        //case _STRUCT_OR_UNION_:
        //    return "struct_or_union";
        //case _ENUM_:
        //    return "enum";
        //case _TYPENAME_:
        //    return "typename";
    default:
        // return "invalid datatype";
        break;
    }
}


llvm::Value* Variable::codeGen(CodeGenContext& context)
{
    llvm::Value* pVar = NULL;
    
    if (context.currentSymbolTable()->currentScope == "global")
    {
        llvm::GlobalVariable* pVar = new llvm::GlobalVariable(*context.getModule(),
                                                              m_pDatatype->getLLVMType(context),
                                                              false, 
                                                              llvm::GlobalValue::InternalLinkage,
                                                              NULL);
    }
    else
    {
        pVar = context.getBuilder()->CreateAlloca(m_pDatatype->getLLVMType(context),
                                                  0,
                                                  m_pId->getName());
    }

    context.locals()[m_pId->getName()] = pVar;
    
    if (m_pAssignmentExpr != NULL)
    {
        Assignment assn(m_pId, m_pAssignmentExpr, getLineNo());
        assn.codeGen(context);
    }

    return pVar;
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

llvm::Value* Assignment::codeGen(CodeGenContext& context)
{
    return m_pRhs->codeGen(context);
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
    
    llvm::CallInst* pCall = context.getBuilder()->CreateCall(pFunction,
                                                             llvm::makeArrayRef(args));

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
        last = (**it).codeGen(context);
    }
    
    return last;
}

llvm::Value* FuncDefn::codeGen(CodeGenContext& context)
{
    llvm::SmallVector<llvm::Type*, 4> argTypes;
    VariableList::iterator it;

    for (it = m_pArgs->begin(); it != m_pArgs->end(); it++) 
    {
        argTypes.push_back((*it)->getDataType()->getLLVMType(context));
    }

    llvm::ArrayRef<llvm::Type*> arrayRef = llvm::makeArrayRef(argTypes);

    llvm::FunctionType* fType = llvm::FunctionType::get(getReturnType()->getLLVMType(context),
                                                        arrayRef,
                                                        false);

    llvm::Function* pFunction = llvm::Function::Create(fType,
                                                       llvm::GlobalValue::InternalLinkage,
                                                       getIdentifier()->getName(),
                                                       context.getModule());

    llvm::BasicBlock *bblock = llvm::BasicBlock::Create(llvm::getGlobalContext(),
                                                        "entry",
                                                        pFunction,
                                                        0);
    context.getBuilder()->SetInsertPoint(bblock);
    context.pushBlock(bblock);

    m_pBlock->codeGen(context);

    return pFunction;
}

llvm::Value* MainDefn::codeGen(CodeGenContext& context)
{
    llvm::FunctionType* fType = llvm::FunctionType::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()),
                                                        0);
    
    llvm::Function* pMainFunc = llvm::Function::Create(fType,
                                                       llvm::GlobalValue::InternalLinkage,
                                                       "main",
                                                       context.getModule());

    context.SetMainFunction(pMainFunc);

    vector<llvm::Type*> argTypes;
    VariableList::iterator it;
    
    for (it = m_pArgs->begin(); it != m_pArgs->end(); it++) 
    {
        argTypes.push_back((*it)->getDataType()->getLLVMType(context));
    }

    llvm::BasicBlock *bblock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", pMainFunc, 0);
    context.getBuilder()->SetInsertPoint(bblock);
    context.pushBlock(bblock);

    m_pBlock->codeGen(context);

    return pMainFunc;
}

llvm::Value* ReturnStmt::codeGen(CodeGenContext& context)
{
    llvm::ReturnInst* pReturnInst = context.getBuilder()->CreateRet(m_pReturnExpr->codeGen(context));
    return pReturnInst;
}