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
        
    text->lines = BuildLinesArr(text->text, '\n', &(text->linesCnt));

    if (text->lines == nullptr)
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
        UPDATE_ERR(Errors::MEMORY_ALLOCATION_ERR);
        return text;
    }

    size_t nRead = fread(text, sizeof(char), fileSize, inStream);

    assert(nRead == fileSize - 1);

    text[fileSize - 1] = '\0';

    return text;
}

//------------------------------------------------------------------------------------------------

int PrintLines(LineType* lines, const size_t linesCnt, FILE* const outStream)
{
    assert(lines);
    assert(linesCnt > 0);
    assert(outStream);

    for (size_t i = 0; i < linesCnt; ++i)
    {
        assert(i < linesCnt);

        int printingError = PutLine(lines[i], outStream);

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
        UPDATE_ERR(Errors::PRINTING_TO_FILE_ERR);

    return nPrintedVals;
}

//------------------------------------------------------------------------------------------------

off_t GetFileSize(const char *const fileName)
{
    assert(fileName);

    struct stat fileStats = {0};

    int statError = stat(fileName, &fileStats);

    if (statError)
        UPDATE_ERR(Errors::GETTING_FILE_SIZE_ERR);

    if (statError) return -1;
    return fileStats.st_size;
}

//------------------------------------------------------------------------------------------------

long GetFileSize(FILE* const fp)
{
    assert(fp);
    
    if (fseek(fp, 0, SEEK_END) != 0)
        UPDATE_ERR(Errors::GETTING_FILE_SIZE_ERR);

    long fileSz = ftell(fp);

    if (fileSz == -1)
        UPDATE_ERR(Errors::GETTING_FILE_SIZE_ERR);
    
    if (fseek(fp, 0, SEEK_SET) != 0)
        UPDATE_ERR(Errors::GETTING_FILE_SIZE_ERR);

    return fileSz;
}

//------------------------------------------------------------------------------------------------

int PutLine(LineType line, FILE* const outStream)
{
    assert(line.line);
    assert(outStream);

    const char* lineIterator = line.line;

    while (*lineIterator != line.lineEnding && *lineIterator != '\0')
    {
        int printingError = putc(*lineIterator, outStream);

        if (printingError == EOF)
            return printingError;
        
        ++lineIterator;
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
    free(text->lines);
    text->lines = nullptr;

    assert(text);
    text->linesCnt = 0;
}

//------------------------------------------------------------------------------------------------

FILE* TryOpenFile(const char* const fileName, const char* const mode)
{
    assert(fileName);
    assert(mode);

    FILE* fp = fopen(fileName, mode);

    if (fp == nullptr)
        UPDATE_ERR(Errors::FILE_OPENING_ERR);

    return fp;
}

//------------------------------------------------------------------------------------------------