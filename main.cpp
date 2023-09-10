#include <stdio.h>
#include <stdlib.h>

#include "InputOutput.h"
#include "StringFuncs.h"

int main()
{
    setbuf(stdout, nullptr);
    static const char* const fileName = "Onegin.txt"; 

    FILE* const oneginInput = fopen(fileName, "r");

    if (oneginInput == nullptr)
        return -1;

    const size_t fileSize = GetFileSize(fileName);

    //printf("%d\n", fileSize);

    char* text = (char *) calloc(fileSize + 1, sizeof(char));

    if (text == nullptr)
        return -1;

    ReadText(text, fileSize + 1, oneginInput);

    size_t sz = 0;
    const char** ptrArr = BuildPtrArr(text, '\n', &sz);
    
    PrintText(ptrArr, sz);

    free(ptrArr);
    ptrArr = nullptr;

    free(text);
    text = nullptr;
}