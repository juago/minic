#ifndef __VISITOR__
#define __VISITOR__

#include "utils.h"

class Visitor
{
public:
    Visitor();
    ~Visitor();

    void visit(Node* pNode);

}


#endif