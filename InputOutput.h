#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

/// @file 
/// @brief Contains functions to work with input and output for text input

#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>

#include "Colors.h"
#include "Errors.h"
#include "StringFuncs.h"

//------------------------------------------------------------------------------------------------

/// @brief Contains info for working with big texts from the file
struct TextType
{    
    char *text;                 ///< Dynamic array containing text from file
    size_t textSz;              ///< number of elements in text var
    
    const char **linesArr;      ///< Dynamic arr with pointers to the beginnings of the strings in text arr
    size_t linesCnt;            ///< number of elements in ptrArr
};

void TextTypeDestructor(TextType* text);

//------------------------------------------------------------------------------------------------

/// @brief reads text from the inStream and parses it to the strings.
///
/// @details read text, unite all '\n' symbols that goes in a row in one '\n' and parses this on strings
/// @param [out]text struct to fill.
/// @param [in]inFileName file name to open to read from
/// @return 0 if no errors occurred otherwise not 0
/// @attention Creates dynamic arrays in text structure
int ReadTextAndParse(TextType* text, FILE* const inStream);

//------------------------------------------------------------------------------------------------

/// @brief reads text from the file with fileName
///
/// @param [in]fileName fileName to open
/// @return pointer to the dynamic array containing text
/// @attention Creates dynamic array
char* ReadText(FILE* const inStream);

//------------------------------------------------------------------------------------------------

/// @brief prints text
///
/// @param [in]ptrArr array containing pointers to the strings beginnings
/// @param [in]sz number of elements in ptrArr
/// @param [in]outFileName file name to open to print out
/// @return 0 if no errors occured otherwise not 0
int PrintLines(const char* const* const ptrArr, const size_t sz, FILE* const outStream);

//------------------------------------------------------------------------------------------------

/// @brief prints text to outFile
///
/// @param [in]text text to print
/// @param [in]length number of element in the text to be printed
/// @param [in]outFileName file to open to print out
/// @return number of printed values
size_t PrintText(const char* const text, const size_t length, FILE* const outStream);

//------------------------------------------------------------------------------------------------

/// @brief returns size in bytes of the file with fileName
///
/// @param [in]fileName to get size
/// @return -1 if error occurred otherwise file size in bytes
off_t GetFileSize(const char* const fileName);

//------------------------------------------------------------------------------------------------

/// @brief returns size in bytes of the file in fp
///
/// @param [in]fp file pointer to count bytes in
/// @return 
long GetFileSize(FILE* const fp);

//------------------------------------------------------------------------------------------------

/// @brief puts strings to the stdout and stops printing on separator symbol. 
///
/// @details function doesn't puts separator symbol at the end of the string. 
/// @details It also puts '\n' symbol at the end   
///                      
/// @param [in]str string to print
/// @param [in]separator separator on which MyPuts will stop printing
/// @param [in]outStream stream to print out
/// @return EOF if errors otherwise ASCII code of the last printed symbol
int PutLine(const char* str, const char separator, FILE* const outStream);

//------------------------------------------------------------------------------------------------

/// @brief Wipes off file with fileName
/// @param [in]fileName name of the file to wipe
void WipeFile(const char* const fileName);

//------------------------------------------------------------------------------------------------

/// @brief Print separator in file. Can be used for printing separator
/// @param [in]outStream stream to print out separators
static inline void PrintTextsSeparators(FILE* const outStream)
{
    fprintf(outStream, "\n\n\n\n\n\n\n");
    fprintf(outStream, "-------------------------------------------------------------------------");
    fprintf(outStream, "\n\n\n\n\n\n\n");
}

//------------------------------------------------------------------------------------------------

/// @brief Tries to open file. Updates special ErrorInfo structure on error
/// @param [in]fileName file to open
/// @param [in]mode mode to open file
/// @return pointer to opened file (nullptr if can't open);
FILE* TryOpenFile(const char* const fileName, const char* const mode);

//------------------------------------------------------------------------------------------------

#endif // INPUT_OUTPUT_H