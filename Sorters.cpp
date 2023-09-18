#include "Sorters.h"

//------------------------------------------------------------------------------------------------

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
static size_t Partition(int arr[], const size_t arrSize, size_t left, size_t right);

//------------------------------------------------------------------------------------------------

/// @brief Part of the qsort function. Separates array by the middle element and returns separation border
///
/// @details returns separation border - the index (X) such as for all indexes z < X
/// @details linesArr[z] <= middle element. Middle element = linesArr[(left + right) / 2] in the 
/// @details starting array (not sorted);
///
/// @param [in]linesArr array to separate
/// @param [in]linesCnt number of elements in array 
/// @param [in]left left border of the separating array
/// @param [in]right right border of the separating array
/// @param [in]cmp function that compares two strings.
/// Have to return <0 if str1 is less than str2. 0 if str1 equals str2. Otherwise >0
/// @return separation border
static size_t Partition(const char** const linesArr, const size_t linesCnt, size_t left, size_t right,
                 int (*cmp)(const void* str1, const void* str2));

//------------------------------------------------------------------------------------------------

void MyQSort(int arr[], const size_t arrSize, size_t left, size_t right)
{
    assert(arr);
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
    assert(right < arrSize);
    assert(arrSize > 0);
    assert(left <= right);
    
    //printf(ColorText(GREENTEXT, "%zu - %zu: %zu\n"), left, right, arrSize);
    
    size_t mid = left;
    if (right > left) mid = Partition(arr, arrSize, left, right);

    //printf(ColorText(YELLOWTEXT, "%zu: %zu\n"), mid, left);
    if (left < mid) MyQSort(arr, arrSize, left, mid);

    if (mid + 1 < right) MyQSort(arr, arrSize, mid + 1, right);
}

//------------------------------------------------------------------------------------------------

void MyQSort(const char** const linesArr, const size_t linesCnt, size_t left, size_t right,
             int (*cmp)(const void* str1, const void* str2))
{
    assert(linesArr);
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
    assert(right < linesCnt);
    assert(linesCnt > 0);
    assert(left <= right);
    
    //printf(ColorText(GREENTEXT, "%zu - %zu: %zu\n"), left, right, arrSize);
    
    size_t mid = left;
    if (right > left) mid = Partition(linesArr, linesCnt, left, right, cmp);

    //printf(ColorText(YELLOWTEXT, "%zu: %zu\n"), mid, left);
    
    if (left < mid) MyQSort(linesArr, linesCnt, left, mid, cmp);

    if (mid + 1 < right) MyQSort(linesArr, linesCnt, mid + 1, right, cmp);
}

//------------------------------------------------------------------------------------------------

static size_t Partition(const char** const linesArr, const size_t linesCnt, size_t left, size_t right,
                 int (*cmp)(const void* str1, const void* str2))
{
    assert(linesArr);
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
    assert(right < linesCnt);
    assert(left < right);

    const char* const midValue = linesArr[(left + right) / 2];

    while (left < right)
    {   
        assert(left < right);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(midValue);
        assert(linesArr[left]);

        while (left < linesCnt && cmp(&linesArr[left],  &midValue) < 0)
        {
            ++left;
            
            assert(linesArr[left]);
            assert(left < linesCnt);
            assert(midValue);
        }

        assert(right < linesCnt);
        assert(midValue);
        assert(linesArr[right]);

        while (right > 0 && cmp(&linesArr[right], &midValue) > 0)
        {
            assert(right > 0);
            --right;

            assert(linesArr[right]);
            assert(midValue);
        }

        if (right <= left)
            break;  

        assert(linesArr);
        assert(linesArr[left]);
        assert(linesArr[right]);
        assert(left < right);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(right < linesCnt);
        
        const char* tmp = linesArr[left];
                          linesArr[left] = linesArr[right];
                                         linesArr[right] = tmp;

        assert(right > 0);
        ++left;
        --right;
        assert(left < linesCnt);
    }

    return right;    
}

//------------------------------------------------------------------------------------------------

static size_t Partition(int arr[], const size_t arrSize, size_t left, size_t right)
{
    assert(arr);
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
    assert(left <= right);
    assert(right < arrSize);

    size_t pos = (left + right) / 2;

    assert(pos <= right);
    assert(pos >= left);

    const int midValue = arr[pos];

    while (left < right)
    {
        assert(left < right);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(right < arrSize);

        while (left < right && arr[left] < midValue)
        {
            ++left;
            assert(left < arrSize);
        }

        assert(left <= right);
        assert(right < arrSize);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"

        while (left < right && arr[right] > midValue)
        {
            assert(right > 0);
            --right;
        }

        if (right <= left)
            break;
        
        assert(right < arrSize);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(left < right);

        Swap(&arr[left], &arr[right], sizeof(arr[left]));

        assert(right > 0);
        left++;
        right--;
        assert(left < arrSize);
    }

    return right;
}

//------------------------------------------------------------------------------------------------

int StrRCmp(const void* const str1, const void* const str2)
{
    assert(str1);
    assert(str2);

    static const char STR_END = '\n';

    const char* str1Begin = (*(const char* const*) str1);
    const char* str2Begin = (*(const char* const*) str2);

    const char* string1 = str1Begin;
    const char* string2 = str2Begin;


    assert(string1);
    assert(string2);

    while (*string1 != STR_END) ++string1;
    while (*string2 != STR_END) ++string2;

    while (!isalpha(*string1) && string1 != str1Begin) --string1;
    while (!isalpha(*string2) && string2 != str2Begin) --string2;

    while (true)
    {
        if (string1 == str1Begin|| string2 == str2Begin)
            break;
        
        if (!isalpha(*string1))
        {
            --string1;
            continue;
        }

        if (!isalpha(*string2))
        {
            --string2;
            continue;
        }

        if (tolower(*string1) != tolower(*string2))
            break;

        --string1;
        --string2;
    }

    while (!isalpha(*string1) && string1 != str1Begin) --string1;
    while (!isalpha(*string2) && string2 != str2Begin) --string2;

    bool isalphaStr1 = isalpha(*string1);
    bool isalphaStr2 = isalpha(*string2);

    if (!isalphaStr1 && !isalphaStr2)
        return 0;

    if (!isalphaStr1 && isalphaStr2)
        return -1;
    
    if (isalphaStr1 && !isalphaStr2)
        return 1;

    assert(isalphaStr1);
    assert(isalphaStr2);

    return tolower(*string1) - tolower(*string2);
}

//------------------------------------------------------------------------------------------------

int StrCmp(const void* str1, const void* str2)
{
    assert(str1);
    assert(str2);

    static const char STR_END = '\n';
    const char* string1 = *((const char* const*) str1);
    const char* string2 = *((const char* const*) str2);

    assert(string1);
    assert(string2);

    while (!isalpha(*string1) && *string1 != STR_END) ++string1;
    while (!isalpha(*string2) && *string2 != STR_END) ++string2;

    while (true)
    {
        if (*string1 == STR_END || *string2 == STR_END)
            break;
        
        bool isalphaStr1 = isalpha(*string1);

        if (!isalphaStr1)
        {
            ++string1;
            continue;
        }

        bool isalphaStr2 = isalpha(*string2);

        if (!isalphaStr2)
        {
            ++string2;
            continue;
        }

        assert(isalphaStr1);
        assert(isalphaStr2);
        if (tolower(*string1) != tolower(*string2))
            break;

        ++string1;
        ++string2;
    }

    while (!isalpha(*string1) && *string1 != STR_END) ++string1;
    while (!isalpha(*string2) && *string2 != STR_END) ++string2;

    bool isalphaStr1 = isalpha(*string1);
    bool isalphaStr2 = isalpha(*string2);

    if (!isalphaStr1 && !isalphaStr2)
        return 0;

    if (!isalphaStr1 && isalphaStr2)
        return -1;
    
    if (isalphaStr1 && !isalphaStr2)
        return 1;

    assert(isalphaStr1);
    assert(isalphaStr2);
    return tolower(*string1) - tolower(*string2);
}

//------------------------------------------------------------------------------------------------

#define COPY(A, B, TYPE)                      \
{                                             \
    TYPE temp = 0;                            \
                                              \
                                              \
    memcpy(&temp, a, sizeof(temp));           \
           memcpy(a, b, sizeof(temp));        \
              memcpy(b, &temp, sizeof(temp)); \
                                              \
    A += sizeof(uint16_t);                    \
    B += sizeof(uint16_t);                    \
}

void Swap(void *aVoid, void *bVoid, const size_t size) 
{
    assert(aVoid);
    assert(bVoid);
    assert(aVoid != bVoid);
    assert(size > 0);

    uint8_t* a = (uint8_t*) aVoid;
    uint8_t* b = (uint8_t*) bVoid;

    /*
    long a_addr = (long) a;
    intptr_t b_addr = (intptr_t) b;
    */
    uint64_t* a_ll = (uint64_t*) a;
    uint64_t* b_ll = (uint64_t*) b;
    uint64_t tmp = 0;

    assert(sizeof(uint64_t) == 8);

    size_t sizeInQWords = size >> 3;    
    
    for (size_t i = 0; i < sizeInQWords; ++i) {
        memcpy(&tmp, a_ll + i, sizeof(tmp));
              memcpy(a_ll + i, b_ll + i, sizeof(tmp));
                        memcpy(b_ll + i, &tmp, sizeof(tmp));
    }

    a = (uint8_t*) (a_ll + sizeInQWords);
    b = (uint8_t*) (b_ll + sizeInQWords);

    if (size & (uint32_t) 4)
        COPY(a, b, uint32_t);

    if (size & (uint16_t) 2)
        COPY(a, b, uint16_t);

    if (size & (uint8_t) 1)
        COPY(a, b, uint8_t);
}

#undef COPY

//------------------------------------------------------------------------------------------------
