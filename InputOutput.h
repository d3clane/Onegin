#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>

char* ReadText(char* const text, const size_t fileSize, FILE* const inStream);

void PrintText(const char* const* const ptrArr, const size_t sz);

size_t GetFileSize(const char* const fileName);

void MyPuts(const char *str, const char lim);
