#ifndef SORTERS_H
#define SORTERS_H

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Colors.h"
#include "StringFuncs.h"

//-----------------------------------------------------------------------------

/// @brief 
///
/// @param arr 
/// @param arrSize 
/// @param left 
/// @param right 
void MyQSort(int arr[], const size_t arrSize, size_t left, size_t right);

//-----------------------------------------------------------------------------

/// @brief 
///
/// @param ptrArr 
/// @param ptrArrSz 
/// @param left 
/// @param right 
void MyQSort(const char** const ptrArr, const size_t ptrArrSz, size_t left, size_t right);

//-----------------------------------------------------------------------------

/// @brief 
///
/// @param arr 
/// @param arrSize 
/// @param left 
/// @param right 
/// @return 
size_t Partition(int arr[], const size_t arrSize, size_t left, size_t right);

//-----------------------------------------------------------------------------

/// @brief 
///
/// @param ptrArr 
/// @param arrSize 
/// @param left 
/// @param right 
/// @return 
size_t Partition(const char** const ptrArr, const size_t arrSize, size_t left, size_t right);

//-----------------------------------------------------------------------------

int StrRCmp(const void* str1, const void* str2);

//-----------------------------------------------------------------------------

int StrCmp(const void* str1, const void* str2);

//-----------------------------------------------------------------------------

/// @brief 
///
/// @param aVoid 
/// @param bVoid 
/// @param size 
void Swap(void* aVoid, void* bVoid, const size_t size);

//-----------------------------------------------------------------------------

#endif // SORTERS_H