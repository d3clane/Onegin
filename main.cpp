#include <stdio.h>
#include <stdlib.h>

#include "Colors.h"
#include "InputOutput.h"
#include "StringFuncs.h"
#include "UnitTests.h"

int main()
{
#ifdef TESTING
    TestAll();
#else
    TextType text = {};

    const char* const inFileName = "Onegin.txt";

    if (ReadTextAndParse(&text, inFileName) != 0)
        return -1;

    ///--------------------

    const char* const outputFile    = "Output.txt";

    WipeFile(outputFile);

    //MyQSort(text.linesArr, text.linesCnt, 0, text.linesCnt - 1, StrCmp);

    qsort(text.linesArr, text.linesCnt, sizeof((text.linesArr)[0]), qsortStrCmp);

    if (PrintLines(text.linesArr, text.linesCnt, outputFile) != 0)
    {
        fprintf(stderr, RedText("Error printing sorted output\n"));
        return -1;
    }

    ///--------------------

    //qsort(text.linesArr, text.linesCnt, sizeof(*(text.linesArr)), StrRCmp);

    MyQSort(text.linesArr, text.linesCnt, 0, text.linesCnt - 1, StrRCmp);

    if (PrintLines(text.linesArr, text.linesCnt, outputFile) != 0)
    {
        fprintf(stderr, RedText("Error printing reversed sorter output\n"));
        return -1;
    }

    //PrintTextsSeparators();

    ///--------------------

    if (PrintText(text.text, text.textSz, outputFile) != text.textSz)
    {
        fprintf(stderr, RedText("Error printing not sorted output\n"));
        return -1;
    }

    //PrintTextsSeparators();

    ///--------------------

    TextTypeDestructor(&text);

#endif
}