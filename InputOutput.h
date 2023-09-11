#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>

#include "Colors.h"
#include "StringFuncs.h"

int ReadTextAndParse(const char* const fileName,
                     char** text, const char*** ptrArr, size_t* ptrArrSz);

char* ReadText(const char* const fileName);

int PrintText(const char* const* const ptrArr, const size_t sz);

off_t GetFileSize(const char* const fileName);

int MyPuts(const char* str, const char separator);

#endif // INPUT_OUTPUT_H