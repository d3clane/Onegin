#include "InputOutput.h"

char* ReadText(char* const text, const size_t fileSize, FILE* const inStream)
{
    assert(text);
    assert(fileSize > 0);
    assert(inStream);

    size_t nRead = fread(text, sizeof(char), fileSize, inStream);
    
    //printf("%d\n", nRead);
    assert(nRead == fileSize - 1);

    text[fileSize - 1] = '\0';

    return text;
}

void PrintText(const char* const* const ptrArr, const size_t sz)
{
    assert(ptrArr);
    assert(sz > 0);

    for (size_t i = 0; i < sz; ++i)
    {
        assert(i < sz);
        MyPuts(ptrArr[i], '\n');
    }
}

size_t GetFileSize(const char* const fileName)
{
    assert(fileName);

    struct stat fileStats = {0};

    stat(fileName, &fileStats);

    return (size_t) fileStats.st_size; //что за off_t
}

void MyPuts(const char *str, const char lim)
{
    assert(str);

    while (*str != lim && *str != '\0')
    {
        putchar(*str);
        ++str;
    }

    putchar('\n');
}
