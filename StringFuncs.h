#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "InputOutput.h"

const char** BuildPtrArr(const char* text, const char lim, size_t* arrSize);

#endif // STRING_FUNCS_H