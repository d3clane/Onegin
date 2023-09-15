#include "InputOutput.h"

//------------------------------------------------------------------------------------------------

int ReadTextAndParse(TextType* text, const char* const inFileName)
{
    assert(text);
    assert(inFileName);

    text->inFileName = inFileName;

    text->text = ReadText(text->inFileName);
    if (text->text == nullptr)
        return -1;
    
    const size_t newTextSize = UniteSymbols(text->text, '\n');
    
    text->textSz = newTextSize - 1;

    char* const tmp = (char*) realloc(text->text, newTextSize * sizeof(*(text->text)));

    if (tmp != nullptr)
        text->text = tmp;

    text->ptrArr = BuildPtrArr(text->text, '\n', &text->ptrArrSz);

    //Replace(text->text, '\n', '\0');

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
    
    if (tmpFileSize == -1)
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
    
    assert(nRead == fileSize - 1);

    text[fileSize - 1] = '\0';

    fclose(inStream);

    return text;
}

//------------------------------------------------------------------------------------------------

int PrintText(const char* const* const ptrArr, const size_t sz, const char* const outFileName)
{
    assert(ptrArr);
    assert(sz > 0);
    assert(outFileName);

    FILE* const outStream = fopen(outFileName, "a");

    if (outStream == nullptr)
        return 1;

    for (size_t i = 0; i < sz; ++i)
    {
        assert(i < sz);

        int printingError = MyPuts(ptrArr[i], '\n', outStream);

        if (printingError == EOF)
            return printingError;
    }

    fprintf(outStream, "\n\n\n\n\n\n\n\n\n\n\n");
    fprintf(outStream, "---------------------------------------------------------------------------------");
    fprintf(outStream, "\n\n\n\n\n\n\n\n\n\n\n");

    fclose(outStream);

    return 0;
}

//------------------------------------------------------------------------------------------------

size_t PrintStartText(const char* const text, const size_t length, const char* const outFileName)
{
    assert(text);
    assert(length > 0);
    assert(outFileName);

    FILE* const outStream = fopen(outFileName, "a");

    if (outStream == nullptr)
        return 0;
    
    size_t nPrintedVals = fwrite(text, sizeof(*text), length, outStream);

    fprintf(outStream, "\n\n\n\n\n\n\n\n\n\n\n");
    fprintf(outStream, "---------------------------------------------------------------------------------");
    fprintf(outStream, "\n\n\n\n\n\n\n\n\n\n\n");

    fclose(outStream);

    return nPrintedVals;
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

int MyPuts(const char* str, const char separator, FILE* const outStream)
{
    assert(str);
    assert(outStream);

    while (*str != separator && *str != '\0')
    {
        int printingError = putc(*str, outStream);

        if (printingError == EOF)
            return printingError;
        
        ++str;
    }

    return putc('\n', outStream);
}

//------------------------------------------------------------------------------------------------

void cleanFile(const char* const fileName) 
{
    assert(fileName);

    FILE *fp = fopen(fileName, "w");

    if (fp == nullptr)
        return;

    fclose(fp);
}

//------------------------------------------------------------------------------------------------

void TextTypeDestructor(TextType* const text)
{
    if (text == nullptr)
        return;

    assert(text);
    free(text->text);
    text->text = nullptr;

    assert(text);
    free(text->ptrArr);
    text->ptrArr = nullptr;

    assert(text);
    text->ptrArrSz = 0;
}

//------------------------------------------------------------------------------------------------