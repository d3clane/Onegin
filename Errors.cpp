#include "Errors.h"

#ifndef NDEBUG
    #define PrintErr(X) fprintf(stderr, RedText(X "\nError occured in file %s in line %d\n"), \
                                  ErrorInfo.fileWithError, ErrorInfo.lineWithError)
#else
    #define PrintErr(X) fprintf(stderr, REDTEXT X);
#endif

ErrorInfoType ErrorInfo = {.error = Errors::NO_ERR, .fileWithError = "NO_ERRORS.txt", .lineWithError = -1};

void PrintError()
{
    switch(ErrorInfo.error)
    {
        case Errors::MEMORY_ALLOCATION_ERR:
            PrintErr("Memory allocation error.");
            break;

        case Errors::GETTING_FILE_SIZE_ERR:
            PrintErr("Getting file size error.");
            break;
        case Errors::FILE_OPENING_ERR:
            PrintErr("Can't open the file.");
            break;
        case Errors::PRINTING_TO_FILE_ERR:
            PrintErr("Can't print to the file.");
            break;
        case Errors::NO_ERR:
        default:
            break;
    }
}

bool IsFatalError()
{
    switch(ErrorInfo.error)
    {
        case Errors::NO_ERR:
            return false;
    
        case Errors::FILE_OPENING_ERR:
        case Errors::GETTING_FILE_SIZE_ERR:
        case Errors::MEMORY_ALLOCATION_ERR:
        case Errors::PRINTING_TO_FILE_ERR:
        default:
            return true;
    }
}