#include <iostream>
#include "node.h"
#include "codegen.h"

using namespace std;

TLogLevel Log::reportingLevel = logERROR;

extern int yyparse();
extern FILE *yyin;
extern Block*    pProgramBlock;
extern MainDefn* pMain;

int main(int argc, char **argv)
{
    FILE *inpFile = fopen(argv[1], "r");
    if (!inpFile)
    {
        cout << "Error opening File" << endl;
        return -1;
    }

    Log().Get(logINFO) << "Starting Parsing of File: " << argv[1] << endl;

    yyin = inpFile;

    yyparse();

    if (pMain == NULL)
    {
        std::cout << "Error no main function defined" << std::endl;
    }

    CodeGenContext context;
    context.generateCode(*pProgramBlock);

    system("pause");
    return 0;
}