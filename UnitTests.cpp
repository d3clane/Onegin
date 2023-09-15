#include "UnitTests.h"

void TestAll()
{
    TestMyQSort();
}

void TestMyQSort()
{
    static const char* fileTest = "Onegin.txt";
    TextType text1, text2;

    ReadTextAndParse(&text1, fileTest);
    ReadTextAndParse(&text2, fileTest);

    MyQSort(text1.linesArr, text1.linesCnt, 0, text1.linesCnt - 1, StrCmp);
    qsort(text2.linesArr, text2.linesCnt, sizeof(*(text2.linesArr)), qsortStrCmp);

    for (size_t i = 0; i < text1.linesCnt; ++i)
    {
        if (strcmp(text1.linesArr[i], text2.linesArr[i]) != 0)
        {
            fprintf(stderr, RedText("Error sorts doesn't match on string %zu: \n"
                                    "MyQSort string: %s\n"
                                    "qsort   string: %s\n"),
                            i + 1, text1.linesArr[i], text2.linesArr[i]);
            break;
        }
    }

    TextTypeDestructor(&text1);
    TextTypeDestructor(&text2);
}