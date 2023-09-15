#include "StringFuncs.h"

//------------------------------------------------------------------------------------------------

const char** BuildPtrArr(const char* text, const char separator, size_t* arrSize)
{
    assert(text);
    assert(arrSize);

    size_t linesCnt = CntChrInStr(text, separator) + 1;

    const char** ptrArr = (const char**) calloc(linesCnt, sizeof(*ptrArr));

    if (ptrArr == nullptr)
        return nullptr;
    
    size_t posInPtrArr = 0;

#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(0 <= posInPtrArr && posInPtrArr < linesCnt);
#pragma GCC diagnostic warning "-Wtype-limits"
    ptrArr[posInPtrArr] = text;

    ++posInPtrArr;

    size_t ptrArrSz = linesCnt;
    while (*text)
    {
        if (*text == separator)
        {
            //printf("HERE %d\n", __LINE__);
            //printf("%d, %d\n", posInPtrArr, ptrArrSz);

#pragma GCC diagnostic ignored "-Wtype-limits"
            assert(0 <= posInPtrArr && posInPtrArr < ptrArrSz);     
#pragma GCC diagnostic warning "-Wtype-limits"       
            ptrArr[posInPtrArr] = text + 1;
            
            //printf("%d: %p\n", posInPtrArr, text + 1);
            
            ++posInPtrArr;
        }
        ++text;
    }
    
    *arrSize = posInPtrArr;
    return ptrArr;
}

//------------------------------------------------------------------------------------------------

size_t CntChrInStr(const char* str, const char ch)
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

size_t UniteSymbols(char *str, const char ch)
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