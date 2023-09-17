#include <stdio.h>
#include <stdlib.h>

#include "Colors.h"
#include "InputOutput.h"
#include "StringFuncs.h"
#include "UnitTests.h"

#define IF_ERR_PRINT(X)               \
{                                     \
    if (IsFatalError())               \
    {                                 \
        fprintf(stderr, RED_TEXT(X)); \
        PrintError();                 \
        return (int)ErrorInfo.error;  \
    }                                 \
} 

int main()
{
#ifdef TESTING
    TestAll();
    IF_ERR_PRINT("Unite tests errors.\n");
#else
    TextType text = {};

    const char* const inFileName = "Onegin.txt";

    FILE* inStream = TryOpenFile(inFileName, "rb");
    IF_ERR_PRINT("Can't open file");

    ReadTextAndParse(&text, inStream);
    IF_ERR_PRINT("");
    
    fclose(inStream);
    ///--------------------

    const char* const outFileName = "Output.txt";

    FILE* outStream = TryOpenFile(outFileName, "wb");
    IF_ERR_PRINT("Can't open file");

    qsort(text.linesArr, text.linesCnt, sizeof((text.linesArr)[0]), StrCmp);

    PrintLines(text.linesArr, text.linesCnt, outStream);
    IF_ERR_PRINT("Error printing sorted file.\n");

    PrintTextsSeparators(outStream);

    ///--------------------

    //qsort(text.linesArr, text.linesCnt, sizeof((text.linesArr)[0]), StrRCmp);
    MyQSort(text.linesArr, text.linesCnt, 0, text.linesCnt - 1, StrRCmp);
    
    PrintLines(text.linesArr, text.linesCnt, outStream);
    IF_ERR_PRINT("Error printing reversed sorter output.\n");

    PrintTextsSeparators(outStream);

    ///--------------------

    PrintText(text.text, text.textSz, outStream);
    IF_ERR_PRINT("Error printing not sorted output.\n")

    fclose(outStream);
    ///--------------------

    TextTypeDestructor(&text);

#endif
}

#undef IF_ERR_PRINT