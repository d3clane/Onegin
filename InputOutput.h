#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

/// @file 
/// @brief Contains functions to work with input and output for text input

#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>

#include "Colors.h"
#include "StringFuncs.h"

//------------------------------------------------------------------------------------------------

/// @brief Contains info for working with big texts from the file
struct TextType
{
    const char* const fileName; ///< File to read from (file name)
    
    char *text;                 ///< Dynamic array containing text from file

    const char **ptrArr;        
    ///< Dynamic arr with pointers to the beginnings of the strings in text arr
    size_t ptrArrSz;            ///< number of elements in ptrArr
};

void TextTypeDestructor(TextType* text);

//------------------------------------------------------------------------------------------------

/// @brief reads text from the file with name text->fileName and parses it to the strings.
///
/// @details read text, unite all '\n' symbols that goes in a row in one '\n' and parses this on strings
/// @param [out]text struct that have to contain fileName to read from. fills text->ptrArr and text->text
/// @return 0 if no errors occurred otherwise not 0
/// @attention Creates dynamic arrays
int ReadTextAndParse(TextType* text);

//------------------------------------------------------------------------------------------------

/// @brief reads text from the file with fileName
///
/// @param [in]fileName fileName to open
/// @return pointer to the dynamic array containing text
/// @attention Creates dynamic array
char* ReadText(const char* const fileName);

//------------------------------------------------------------------------------------------------

/// @brief prints text
///
/// @param [in]ptrArr array containing pointers to the strings beginnings
/// @param [in]sz number of elements in ptrArr
/// @return 0 if no errors occured otherwise not 0
int PrintText(const char* const* const ptrArr, const size_t sz);

//------------------------------------------------------------------------------------------------

/// @brief returns size in bytes of the file with fileName
///
/// @param [in]fileName to get size
/// @return -1 if error occurred otherwise file size in bytes
off_t GetFileSize(const char* const fileName);

//------------------------------------------------------------------------------------------------

/// @brief puts strings to the stdout and stops printing on separator symbol. 
///
/// @details function doesn't puts separator symbol at the end of the string. 
/// @details It also puts '\n' symbol at the end                         
/// @param [in]str string to print
/// @param [in]separator separator on which MyPuts will stop printing
int MyPuts(const char* str, const char separator);

//------------------------------------------------------------------------------------------------

#endif // INPUT_OUTPUT_H