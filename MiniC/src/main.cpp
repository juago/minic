#include <iostream>
#include "node.h"

using namespace std;

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

    yyin = inpFile;

    yyparse();

    if (pMain == NULL)
    {
        std::cout << "Error no main function defined" << std::endl;
    }

    system("pause");
    return 0;
}