#include "InputOutput.h"

//------------------------------------------------------------------------------------------------

int ReadTextAndParse(TextType* text, FILE* const inStream)
{
    assert(text);
    assert(inStream);
    
    text->text = ReadText(inStream);

    if (text->text == nullptr)
        return -1;
    
    const size_t newTextSize = UniteChars(text->text, '\n');

    char* const tmp = (char*) realloc(text->text, newTextSize * sizeof(*(text->text)));
    
    if (tmp) 
        text->text = tmp;

    text->linesArr = BuildLinesArr(text->text, '\n', &text->linesCnt);

    if (text->linesArr == nullptr)
        return -1;

    text->textSz = newTextSize - 1;
    
    return 0;
}

//------------------------------------------------------------------------------------------------

char* ReadText(FILE* const inStream)
{
    assert(inStream);

    long tmpFileSize = GetFileSize(inStream);
    
    if (tmpFileSize == -1)
        return nullptr;

    const size_t fileSize = (size_t) tmpFileSize + 1;

    char* text = (char*) calloc(fileSize, sizeof(*text)); 

    if (text == nullptr)
    {
        UpdateError(Errors::MEMORY_ALLOCATION_ERR);
        return text;
    }

    size_t nRead = fread(text, sizeof(char), fileSize, inStream);

    assert(nRead == fileSize - 1);

    text[fileSize - 1] = '\0';

    return text;
}

//------------------------------------------------------------------------------------------------

int PrintLines(const char* const* const linesArr, const size_t linesArrSz, FILE* const outStream)
{
    assert(linesArr);
    assert(linesArrSz > 0);
    assert(outStream);

    for (size_t i = 0; i < linesArrSz; ++i)
    {
        assert(i < linesArrSz);

        int printingError = PutLine(linesArr[i], '\n', outStream);

        if (printingError == EOF)
            return printingError;
    }

    return 0;
}

//------------------------------------------------------------------------------------------------

size_t PrintText(const char* const text, const size_t length, FILE* const outStream)
{
    assert(text);
    assert(length > 0);
    assert(outStream);
    
    size_t nPrintedVals = fwrite(text, sizeof(*text), length, outStream);

    if (nPrintedVals != length)
        UpdateError(Errors::PRINTING_TO_FILE_ERR);

    return nPrintedVals;
}

//------------------------------------------------------------------------------------------------

off_t GetFileSize(const char* const fileName)
{
    assert(fileName);

    struct stat fileStats = {0};

    int statError = stat(fileName, &fileStats);

    if (statError)
        UpdateError(Errors::GETTING_FILE_SIZE_ERR);

    if (statError) return -1;
    return fileStats.st_size;
}

//------------------------------------------------------------------------------------------------

long GetFileSize(FILE* const fp)
{
    assert(fp);
    
    if (fseek(fp, 0, SEEK_END) != 0)
        UpdateError(Errors::GETTING_FILE_SIZE_ERR);

    long fileSz = ftell(fp);

    if (fileSz == -1)
        UpdateError(Errors::GETTING_FILE_SIZE_ERR);
    
    if (fseek(fp, 0, SEEK_SET) != 0)
        UpdateError(Errors::GETTING_FILE_SIZE_ERR);

    return fileSz;
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

FILE* TryOpenFile(const char* const fileName, const char* const mode)
{
    assert(fileName);
    assert(mode);

    FILE* fp = fopen(fileName, mode);

    if (fp == nullptr)
        UpdateError(Errors::FILE_OPENING_ERR);

    return fp;
}

//------------------------------------------------------------------------------------------------