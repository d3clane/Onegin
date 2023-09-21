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
    return 0;
#endif

    // reading input

    TextType text = {};

    const char* const inFileName = "Onegin.txt";

    TextTypeCtor(&text, inFileName);
    IF_ERR_PRINT("Reading text from file and parsing error.\n");
    
    //--------------------

    // open out file

    const char* const outFileName = "Output.txt";

    FILE* outStream = TryOpenFile(outFileName, "wb");
    IF_ERR_PRINT("Can't open file.\n");

    //--------------------

    // print sorted

    qsort(text.lines, text.linesCnt, sizeof((text.lines)[0]), StrCmp);

    PrintLines(text.lines, text.linesCnt, outStream);
    IF_ERR_PRINT("Error printing sorted file.\n");

    PrintTextsSeparators(outStream);

    //--------------------

    // print reversed sorted

    MyQSort(text.lines, text.linesCnt, 0, text.linesCnt - 1, StrRCmp);
    
    PrintLines(text.lines, text.linesCnt, outStream);
    IF_ERR_PRINT("Error printing reversed sorter output.\n");

    PrintTextsSeparators(outStream);

    //--------------------

    // print not changed text

    PrintText(text.text, text.textSz, outStream);
    IF_ERR_PRINT("Error printing not sorted output.\n")

    fclose(outStream);

    ///--------------------

    TextTypeDestructor(&text);
}

#undef IF_ERR_PRINT