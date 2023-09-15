#include <stdio.h>
#include <stdlib.h>

#include "Colors.h"
#include "InputOutput.h"
#include "StringFuncs.h"
#include "UnitTests.h"

int main()
{
    setbuf(stdout, nullptr);
    //TestAll();

    TextType text = {};

    const char* const inFileName = "Onegin.txt";

    if (ReadTextAndParse(&text, inFileName) != 0)
        return -1;

    ///--------------------

    const char* const outputFile    = "Output.txt";

    cleanFile(outputFile);

    //MyQSort(text.ptrArr, text.ptrArrSz, 0, text.ptrArrSz - 1, StrCmp);

    qsort(text.ptrArr, text.ptrArrSz, sizeof((text.ptrArr)[0]), qsortStrCmp);

    if (PrintText(text.ptrArr, text.ptrArrSz, outputFile) != 0)
    {
        fprintf(stderr, RedText("Error printing sorted output\n"));
        return -1;
    }

    ///--------------------

    //qsort(text.ptrArr, text.ptrArrSz, sizeof(*(text.ptrArr)), StrRCmp);
    
    MyQSort(text.ptrArr, text.ptrArrSz, 0, text.ptrArrSz - 1, StrRCmp);

    if (PrintText(text.ptrArr, text.ptrArrSz, outputFile) != 0)
    {
        fprintf(stderr, RedText("Error printing reversed sorter output\n"));
        return -1;
    }

    ///--------------------

    if (PrintStartText(text.text, text.textSz, outputFile) != text.textSz)
    {
        fprintf(stderr, RedText("Error printing not sorted output\n"));
        return -1;
    }

    ///--------------------

    TextTypeDestructor(&text);
}