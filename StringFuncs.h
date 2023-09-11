#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InputOutput.h"

const char** BuildPtrArr(const char* text, const char separator, size_t* arrSize);

size_t CntChrInStr(const char* str, const char ch);

#endif // STRING_FUNCS_H