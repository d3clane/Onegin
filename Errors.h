//
// Created by Arman on 21.08.2023.
//

/// \file
/// \brief Contains errors that may occur during the program working.
/// \details Contains errors info and function to print these errors.

#ifndef ERRORS_H
#define ERRORS_H

//#define NDEBUG

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "Colors.h"

//-----------------------------------------------------------------------------------------------

/// \brief Errors than may occur during the program working. 
enum class Errors {
    NO_ERR                 =  0,
    
    GETTING_FILE_SIZE_ERR  =  3,
    FILE_OPENING_ERR       =  1,

    MEMORY_ALLOCATION_ERR  =  2,   
};

//-----------------------------------------------------------------------------------------------

/// \brief max length file name in my directory
const int MAX_MY_FILE_NAME = 64;

//-----------------------------------------------------------------------------------------------

/// \brief Contains info about errors - File with error, line with error, error code. 
/// \warning Have to be updated with UpdateError() only
struct ErrorInfoType {
    Errors error; ///< error code
    char fileWithError[MAX_MY_FILE_NAME]; ///< __FILE__ (file name with error)
    int lineWithError; ///< __LINE__ (line with error)
};

/// \brief global errorInfo constant with error info
/// \warning this variable have to be changes only with UpdateError()
extern ErrorInfoType ErrorInfo;

//-----------------------------------------------------------------------------------------------

#ifndef NDEBUG

/// \brief updates special struct with errors errorInfo 
/// \details copyFileName copy of __FILE__ define at the moment macros is called 
/// \details copyLineNumber __LINE__ define at the moment macros is valled
/// \param [in]ERROR Errors enum with error occurred in program
#define UpdateError(ERROR)                                            \
{                                                                     \
        strncpy(ErrorInfo.fileWithError, __FILE__, MAX_MY_FILE_NAME); \
        ErrorInfo.lineWithError = __LINE__;                           \
        ErrorInfo.error = ERROR;                                      \
}
    
#else

/// \brief updates only error code without debug info
/// \param [in] ERROR Errors enum with error occurred in program
#define UpdateError(ERROR) ErrorInfo.error = ERROR

#endif

//----------------------------------------------------------------------------------------------

/// \brief print errors from special struct with errors errorInfo.
/// \attention errorInfo have to be updated only with UpdateError();
void PrintError();

//-----------------------------------------------------------------------------------------------

/// @brief checks if the error in ErrorInfo is fatal.
/// @returns true if error is fatal and have to leave the program, otherwise false
bool IsFatalError();

//-----------------------------------------------------------------------------------------------

#endif // ERRORS_H