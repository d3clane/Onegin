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
    
    const size_t newTextSize = UniteChars(text->text, '\n');
    
    text->textSz = newTextSize - 1;

    char* const tmp = (char*) realloc(text->text, newTextSize * sizeof(*(text->text)));

    if (tmp != nullptr) 
    {
        UpdateError(Errors::MEMORY_ALLOCATION_ERR);
        text->text = tmp;
    }

    text->linesArr = BuildLinesArr(text->text, '\n', &text->linesCnt);

    if (text->linesArr == nullptr)
        return -1;

    return 0;
}

//------------------------------------------------------------------------------------------------

char* ReadText(const char* const fileName)
{
    assert(fileName);

    off_t tmpFileSize = GetFileSize(fileName);
    
    if (tmpFileSize == -1)
    {
        UpdateError(Errors::GETTING_FILE_SIZE_ERR);
        return nullptr;
    }

    const size_t fileSize = (size_t) tmpFileSize + 1;

    char* text = (char*) calloc(fileSize, sizeof(*text)); 

    if (text == nullptr)
    {
        UpdateError(Errors::MEMORY_ALLOCATION_ERR);
        return text;
    }

    FILE* inStream = fopen(fileName, "rb");

    if (inStream == nullptr)
    {
        UpdateError(Errors::FILE_OPENING_ERR);

        free(text);
        return nullptr;
    }

    size_t nRead = fread(text, sizeof(char), fileSize, inStream);
    
    assert(nRead == fileSize - 1);

    text[fileSize - 1] = '\0';

    fclose(inStream);

    return text;
}

//------------------------------------------------------------------------------------------------

int PrintLines(const char* const* const linesArr, const size_t linesArrSz, const char* const outFileName)
{
    assert(linesArr);
    assert(linesArrSz > 0);
    assert(outFileName);

    FILE* const outStream = fopen(outFileName, "a");

    if (outStream == nullptr)
        return 1;

    for (size_t i = 0; i < linesArrSz; ++i)
    {
        assert(i < linesArrSz);

        int printingError = PutLine(linesArr[i], '\n', outStream);

        if (printingError == EOF)
            return printingError;
    }

    fclose(outStream);

    return 0;
}

//------------------------------------------------------------------------------------------------

size_t PrintText(const char* const text, const size_t length, const char* const outFileName)
{
    assert(text);
    assert(length > 0);
    assert(outFileName);

    FILE* const outStream = fopen(outFileName, "a");

    if (outStream == nullptr)
        return 0;
    
    size_t nPrintedVals = fwrite(text, sizeof(*text), length, outStream);

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

int PutLine(const char* str, const char separator, FILE* const outStream)
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

void WipeFile(const char* const fileName) 
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
    free(text->linesArr);
    text->linesArr = nullptr;

    assert(text);
    text->linesArr = 0;
}

//------------------------------------------------------------------------------------------------