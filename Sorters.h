#ifndef SORTERS_H
#define SORTERS_H

/// @file
/// @brief Contains functions for sorting texts

#include <stdio.h>
#include <ctype.h>

#include "InputOutput.h"

//-----------------------------------------------------------------------------

/// @brief Implementation of qsort for int arrays
///
/// @param [in]arr array to sort
/// @param [in]arrSize number of elements in array 
/// @param [in]left left border of the sorting array (usually 0)
/// @param [in]right right border of the sorting array (usually arrSize - 1)
/// @attention arr[right] is included in sorting, so right have to be less than arrSize
void MyQSort(int arr[], const size_t arrSize, size_t left, size_t right);

//-----------------------------------------------------------------------------

/// @brief Implementation of qsort for pointers on strings arrays
///
/// @param [in]lines array to sort
/// @param [in]linesCnt number of elements in array 
/// @param [in]left left border of the sorting array (usually 0)
/// @param [in]right right border of the sorting array (usually arrSize - 1)
/// @attention ptrArr[right] is included in sorting, so right have to be less than arrSize
void MyQSort(LineType* lines, const size_t linesCnt, size_t left, size_t right,
             int (*cmp)(const void* str1, const void* str2));

//-----------------------------------------------------------------------------

/// @brief Compares two strings in reversed order
///
/// @details While comparing two strings skips non-alpha symbols. 
/// @details In other aspects acts like strcmp, but compares from the end to begginning.
///
/// @param [in]str1 POINTER TO THE POINTER to the first string
/// @param [in]str2 POINTER TO THE POINTER to the second string
/// @returns <0 if str1 less than str, 0 if they are equal, otherwise >0
int StrRCmp(const void* str1, const void* str2);

//-----------------------------------------------------------------------------

/// @brief Compares two strings
///
/// @details While comparing two strings skips non-alpha symbols. In other aspects acts like std strcmp.
///
/// @param [in]str1 POINTER TO THE POINTER to the first string
/// @param [in]str2 POINTER TO THE POINTER to the second string
/// @returns <0 if str1 less than str, 0 if they are equal, otherwise >0
int StrCmp(const void* str1, const void* str2);

//-----------------------------------------------------------------------------

/// @brief swaps any two elements
/// 
/// @param [out]aVoid pointer to the first element
/// @param [out]bVoid pointer to the second element
/// @param [in]size size of elements to swap in bytes
void Swap(void* aVoid, void* bVoid, const size_t size);

//-----------------------------------------------------------------------------

#endif // SORTERS_H