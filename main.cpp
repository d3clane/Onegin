#include <stdio.h>
#include <stdlib.h>

#include "Colors.h"
#include "InputOutput.h"
#include "StringFuncs.h"

int main()
{
    //setbuf(stdout, nullptr);
    static const char* const fileName = "Onegin.txt"; 
    char *text = nullptr;
    const char **ptrArr = nullptr;
    size_t ptrArrSz = 0;

    if (ReadTextAndParse(fileName, &text, &ptrArr, &ptrArrSz) == -1)
        return -1;

    PrintText(ptrArr, ptrArrSz);

    if (PrintText(ptrArr, ptrArrSz) == EOF)
    {
        fprintf(stderr, RedText("Error printing to output\n"));
        return -1;
    }
    
    free(ptrArr);
    ptrArr = nullptr;

    free(text);
    text = nullptr;
}