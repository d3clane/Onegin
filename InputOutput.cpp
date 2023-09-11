#include "InputOutput.h"

//------------------------------------------------------------------------------------------------

int ReadTextAndParse(TextType* text)
{
    assert(text);
    assert(text->fileName);

    text->text = ReadText(text->fileName);

    if (text->text == nullptr)
        return -1;
    
    text->ptrArr = BuildPtrArr(text->text, '\n', &text->ptrArrSz);

    if (text->ptrArr == nullptr)
    {
        fprintf(stderr, RedText("Error build pointers array\n"));
        return -1;
    }

    return 0;
}

//------------------------------------------------------------------------------------------------

char* ReadText(const char* const fileName)
{
    assert(fileName);

    off_t tmpFileSize = GetFileSize(fileName);

    if (tmpFileSize != 0)
    {
        fprintf(stderr, RedText("Error getting file size %s\n"), fileName);
        return nullptr;
    }

    const size_t fileSize = (size_t) tmpFileSize + 1;

    char* text = (char*) calloc(fileSize, sizeof(*text)); 

    if (text == nullptr)
    {
        fprintf(stderr, RedText("Error callocing memory for text\n"));
        return text;
    }

    FILE* inStream = fopen(fileName, "rb");

    if (inStream == nullptr)
    {
        fprintf(stderr, RedText("Error opening file %s\n"), fileName);
        return nullptr;
    }

    size_t nRead = fread(text, sizeof(char), fileSize, inStream);
    
    //printf("%d\n", nRead);
    assert(nRead == fileSize - 1);

    text[fileSize - 1] = '\0';

    fclose(inStream);
    return text;
}

//------------------------------------------------------------------------------------------------

int PrintText(const char* const* const ptrArr, const size_t sz)
{
    assert(ptrArr);
    assert(sz > 0);

    for (size_t i = 0; i < sz; ++i)
    {
        assert(i < sz);
        int printingError = MyPuts(ptrArr[i], '\n');

        if (printingError == EOF)
            return printingError;
    }

    return 0;
}

//------------------------------------------------------------------------------------------------

off_t GetFileSize(const char* const fileName)
{
    assert(fileName);

    struct stat fileStats = {0};

    int statError = stat(fileName, &fileStats);

    if (statError) return -1;
    return fileStats.st_size;
}

//------------------------------------------------------------------------------------------------

int MyPuts(const char* str, const char separator)
{
    assert(str);

    while (*str != separator && *str != '\0')
    {
        int printingError = putchar(*str);

        if (printingError == EOF)
            return printingError;
        
        ++str;
    }

    return putchar('\n');
}

//------------------------------------------------------------------------------------------------
