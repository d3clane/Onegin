#include "StringFuncs.h"

//------------------------------------------------------------------------------------------------

const char** BuildLinesArr(const char* text, const char separator, size_t* arrSize)
{
    assert(text);
    assert(arrSize);

    size_t linesCnt = CountChars(text, separator) + 1;

    const char** linesArr = (const char**) calloc(linesCnt, sizeof(*linesArr));

    if (linesArr == nullptr)
    {
        UPDATE_ERR(Errors::MEMORY_ALLOCATION_ERR);
        return nullptr;
    }

    size_t posInLinesArr = 0;

#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(0 <= posInLinesArr && posInLinesArr < linesCnt);
#pragma GCC diagnostic warning "-Wtype-limits"
    linesArr[posInLinesArr] = text;

    ++posInLinesArr;

    while (*text)
    {
        if (*text == separator)
        {
#pragma GCC diagnostic ignored "-Wtype-limits"
            assert(0 <= posInLinesArr && posInLinesArr < linesCnt);     
#pragma GCC diagnostic warning "-Wtype-limits"       
            linesArr[posInLinesArr] = text + 1;
            
            ++posInLinesArr;
        }
        ++text;
    }
    
    *arrSize = posInLinesArr;
    return linesArr;
}

//------------------------------------------------------------------------------------------------

size_t CountChars(const char* str, const char ch)
{
    size_t cnt = 0;

    if (ch == '\0')
        return 1;
    
    while (true) 
    {
        str = strchr(str, ch);

        if (str == nullptr)
            break;
        
        ++str;
        ++cnt;
    }

    return cnt;
}

//------------------------------------------------------------------------------------------------

size_t UniteChars(char *str, const char ch)
{
    assert(str);

    size_t pos = 0;
    size_t shift = 0;

    while (str[pos])
    {
        assert(pos >= shift);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(pos >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(str);
        str[pos - shift] = str[pos];
        
        bool haveDoneCycle = false;
        while (str[pos] && str[pos] == ch)
        {
            ++pos;
            ++shift;
            haveDoneCycle = true;
        }

        if (haveDoneCycle) //in purpose to place one ch symbol 
            --shift;
        
        if (str[pos] && !haveDoneCycle) ++pos;
    }

    str[pos - shift] = '\0';

    return pos - shift + 1;
}

//------------------------------------------------------------------------------------------------

void Replace(char *str, const char find, const char replace)
{
    assert(str);

    while (*str)
    {  
        assert(str);
        if (*str == find) *str = replace;

        ++str;
    }
}
