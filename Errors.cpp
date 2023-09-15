#include "Errors.h"

#ifndef NDEBUG
    #define PrintError(X) fprintf(stderr, RedText(X "\nError occured in file %s in line %d\n"), \
                                  ErrorInfo.fileWithError, ErrorInfo.lineWithError)
#else
    #define PrintError(X) fprintf(stderr, REDTEXT X);
#endif

ErrorInfoType ErrorInfo = {.error = Errors::NO_ERR, .fileWithError = "NO_ERRORS.txt", .lineWithError = -1};

void PrintErrors()
{
    switch(ErrorInfo.error)
    {
        case Errors::MEMORY_ALLOCATION_ERR:
            PrintError("Memory allocation error.");
            break;

        case Errors::GETTING_FILE_SIZE_ERR:
            PrintError("Getting file size with stat() error.");
            break;

        case Errors::FILE_OPENING_ERR:
            PrintError("Can't open the file.");
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
        default:
            return true;
    }
}