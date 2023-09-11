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
