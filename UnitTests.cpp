#include "UnitTests.h"

void TestAll()
{
    TestMyQSort();
}

void TestMyQSort()
{
    static const char* fileTest = "Onegin.txt";
    TextType text1 = {}, text2 = {};

    FILE* inStream1 = TryOpenFile(fileTest, "rb");
    if (IsFatalError()) return;

    ReadTextAndParse(&text1, inStream1);
    if (IsFatalError()) return;

    FILE* inStream2 = TryOpenFile(fileTest, "rb");
    if (IsFatalError()) return;

    ReadTextAndParse(&text2, inStream2);
    if (IsFatalError()) return;

    MyQSort(text1.linesArr, text1.linesCnt, 0, text1.linesCnt - 1, StrCmp);
    qsort(text2.linesArr, text2.linesCnt, sizeof(*(text2.linesArr)), StrCmp);

    for (size_t i = 0; i < text1.linesCnt; ++i)
    {
        if (strcmp(text1.linesArr[i], text2.linesArr[i]) != 0)
        {
            fprintf(stderr, RedText("Error sorts doesn't match on string %zu: \n"), i + 1);

            PutLine(text1.linesArr[i], '\n', stderr);
            PutLine(text2.linesArr[i], '\n', stderr);

            break;
        }
    }

    TextTypeDestructor(&text1);
    TextTypeDestructor(&text2);
}