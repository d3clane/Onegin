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

    TextTypeCtor(&text1, inStream1);
    if (IsFatalError()) return;

    FILE* inStream2 = TryOpenFile(fileTest, "rb");
    if (IsFatalError()) return;

    TextTypeCtor(&text2, inStream2);
    if (IsFatalError()) return;

    MyQSort(text1.lines, text1.linesCnt, 0, text1.linesCnt - 1, StrCmp);
    qsort(text2.lines, text2.linesCnt, sizeof(*(text2.lines)), StrCmp);

    for (size_t i = 0; i < text1.linesCnt; ++i)
    {
        if (strcmp(text1.lines[i].line, text2.lines[i].line) != 0)
        {
            fprintf(stderr, RED_TEXT("Error sorts doesn't match on string %zu: \n"), i + 1);

            PutLine(text1.lines[i], stderr);
            PutLine(text2.lines[i], stderr);

            break;
        }
    }

    TextTypeDestructor(&text1);
    TextTypeDestructor(&text2);
}