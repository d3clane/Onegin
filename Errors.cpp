#include "Errors.h"

#ifndef NDEBUG
    #define PRINT_ERR(X) fprintf(stderr, RED_TEXT(X "\nError occured in file %s in line %d\n"), \
                                 ErrorInfo.fileWithError, ErrorInfo.lineWithError)
#else
    #define PRINT_ERR(X) fprintf(stderr, RED_TEXT(X));
#endif

ErrorInfoType ErrorInfo = {.error = Errors::NO_ERR, .fileWithError = "NO_ERRORS.txt", .lineWithError = -1};

void PrintError()
{
    switch(ErrorInfo.error)
    {
        case Errors::MEMORY_ALLOCATION_ERR:
            PRINT_ERR("Memory allocation error.");
            break;

        case Errors::GETTING_FILE_SIZE_ERR:
            PRINT_ERR("Getting file size error.");
            break;
        case Errors::FILE_OPENING_ERR:
            PRINT_ERR("Can't open the file.");
            break;
        case Errors::PRINTING_TO_FILE_ERR:
            PRINT_ERR("Can't print to the file.");
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