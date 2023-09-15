#ifndef SORTERS_H
#define SORTERS_H

/// @file
/// @brief Contains functions for sorting texts

#include <ctype.h>

#include "Colors.h"
#include "StringFuncs.h"

//-----------------------------------------------------------------------------

/// @brief realization of qsort for int arrays
///
/// @param [in]arr array to sort
/// @param [in]arrSize number of elements in array 
/// @param [in]left left border of the sorting array (usually 0)
/// @param [in]right right border of the sorting array (usually arrSize - 1)
/// @attention arr[right] is included in sorting, so right have to be less than arrSize
void MyQSort(int arr[], const size_t arrSize, size_t left, size_t right);

//-----------------------------------------------------------------------------

/// @brief realization of qsort for pointers on strings arrays
///
/// @param [in]ptrArr array to sort
/// @param [in]ptrArrSz number of elements in array 
/// @param [in]left left border of the sorting array (usually 0)
/// @param [in]right right border of the sorting array (usually arrSize - 1)
/// @attention ptrArr[right] is included in sorting, so right have to be less than arrSize
void MyQSort(const char** const ptrArr, const size_t ptrArrSz, size_t left, size_t right,
             int (*cmp)(const void* str1, const void* str2));

//-----------------------------------------------------------------------------

/// @brief part of the qsort function. Separates array by the middle element and returns separation border
///
/// @details returns separation border - the index (X) such as for all indexes z < X
/// @details arr[z] <= middle element. Middle element = arr[(left + right) / 2] in the 
/// @details starting array (not sorted);
///
/// @param [in]arr array to separate
/// @param [in]arrSize number of elements in array 
/// @param [in]left left border of the separating array
/// @param [in]right right border of the separating array
/// @return separation border
size_t Partition(int arr[], const size_t arrSize, size_t left, size_t right);

//-----------------------------------------------------------------------------

/// @brief Part of the qsort function. Separates array by the middle element and returns separation border
///
/// @details returns separation border - the index (X) such as for all indexes z < X
/// @details ptrArr[z] <= middle element. Middle element = ptrArr[(left + right) / 2] in the 
/// @details starting array (not sorted);
///
/// @param [in]ptrArr array to separate
/// @param [in]ptrArrSz number of elements in array 
/// @param [in]left left border of the separating array
/// @param [in]right right border of the separating array
/// @param [in]cmp function that compares two strings.
/// Have to return <0 if str1 is less than str2. 0 if str1 equals str2. Otherwise >0
/// @return separation border
size_t Partition(const char** const ptrArr, const size_t arrSize, size_t left, size_t right,
                 int (*cmp)(const void* str1, const void* str2));

//-----------------------------------------------------------------------------

/// @brief Compares two strings in reversed order
///
/// @details While comparing two strings skips non-alpha symbols. 
/// @details In other aspects acts like strcmp, but compares from the end to begginning.
///
/// @param [in]str1 first string
/// @param [in]str2 second string
/// @returns <0 if str1 less than str, 0 if they are equal, otherwise >0
int StrRCmp(const void* str1, const void* str2);

//-----------------------------------------------------------------------------

/// @brief Compares two strings
///
/// @details While comparing two strings skips non-alpha symbols. In other aspects acts like std strcmp.
///
/// @param [in]str1 first string
/// @param [in]str2 second string
/// @returns <0 if str1 less than str, 0 if they are equal, otherwise >0
int StrCmp(const void* str1, const void* str2);

//-----------------------------------------------------------------------------

/// @brief Compares two string
/// 
/// @details this function is used for standard qsort comparison. Acts like StrCmp but in standard qsort
///
/// @param [in]str1 first string
/// @param [in]str2 second string
int qsortStrCmp(const void* str1, const void* str2);

//-----------------------------------------------------------------------------

/// @brief swaps any two elements
/// 
/// @param [out]aVoid pointer to the first element
/// @param [out]bVoid pointer to the second element
/// @param [in]size size of elements to swap in bytes
void Swap(void* aVoid, void* bVoid, const size_t size);

//-----------------------------------------------------------------------------



#endif // SORTERS_H