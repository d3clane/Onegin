#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

/// @file
/// @brief Contains functions to work with strings containing text

#include <stdlib.h>
#include <string.h>

#include "InputOutput.h"

//------------------------------------------------------------------------------------------------

/// @brief builds array containing pointers to the strings in text array and returns it
///
/// @details strings are separated by separator. pointers points to the starts of each string
/// @param [in]text text to parse on strings
/// @param [in]separator separator to separate strings
/// @param [out]arrSize - number of elements in returned pointers array. 
/// @return dynamic array containg pointers to the strings in text array
/// @attention Creates dynamic array 
const char** BuildPtrArr(const char* text, const char separator, size_t* arrSize);

//------------------------------------------------------------------------------------------------

/// @brief counts number of char (ch) in string (str)
///
/// @param [in]str string to count chars in
/// @param [in]ch char to count in str
/// @return number of char (ch) in string (str)
size_t CntChrInStr(const char* str, const char ch);

//------------------------------------------------------------------------------------------------

/// @brief Unites all symbols ch in one in str 
///
/// @param [out]str string to change
/// @param [in]ch char to unite in one
/// @return new size of the strings after union
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// UniteSymbols(str, '\n') // str = "abc\n\n\nde\nf\n\n"
/// //after function str = "abc\nde\nf\n"
/// UniteSymbols will return strlen of new str + 1;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
size_t UniteSymbols(char *str, const char ch);

//------------------------------------------------------------------------------------------------

#endif // STRING_FUNCS_H