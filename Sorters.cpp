#include "Sorters.h"

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

void MyQSort(const char** const ptrArr, const size_t ptrArrSz, size_t left, size_t right)
{
    assert(ptrArr);
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
    assert(right < ptrArrSz);
    assert(ptrArrSz > 0);
    assert(left <= right);
    
    //printf(ColorText(GREENTEXT, "%zu - %zu: %zu\n"), left, right, arrSize);
    
    size_t mid = left;
    if (right > left) mid = Partition(ptrArr, ptrArrSz, left, right);

    //printf(ColorText(YELLOWTEXT, "%zu: %zu\n"), mid, left);
    if (left < mid) MyQSort(ptrArr, ptrArrSz, left, mid);

    if (mid + 1 < right) MyQSort(ptrArr, ptrArrSz, mid + 1, right);
}

size_t Partition(int arr[], const size_t arrSize, size_t left, size_t right)
{
    assert(arr);
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
    assert(left <= right);
    assert(right < arrSize);

    //size_t prevLeft = left;
    //size_t prevRight = right;

    //printf(REDCONSOLE "%zu: %zu %zu\n" STDCONSOLE, right, left, right - left + 1);
    //size_t pos = left + rand() % (right - left + 1);

    size_t pos = (left + right) / 2;

    assert(pos <= right);
    assert(pos >= left);

    //printf(RedText("pos: %zu\n"), pos);

    const int midValue = arr[pos];

    //printf(RedText("MiddleValue: %d\n"), midValue);
    /*for (size_t i = left; i <= right; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    */

    while (left < right)
    {
        assert(left < right);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(right < arrSize);

        //printf("left prev: %d  ", left);
        while (left < right && arr[left] < midValue)
        {
            ++left;
            assert(left < arrSize);
        }

        //printf("left after: %zu\n", left);

        assert(left <= right);
        assert(right < arrSize);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"

        //printf("right prev: %d  ", right);

        while (left < right && arr[right] > midValue) //почему ваще меняется результат в зависимости от > vs >= 
        {
            assert(right > 0);
            --right;
        }

        //printf("right after: %zu\n", right);

        if (right <= left)
            break;
        
        assert(right < arrSize);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(left < right);

        //printf("leftVal: %d, rightVal: %d\n", arr[left], arr[right]);

        Swap(&arr[left], &arr[right], sizeof(arr[left]));

        assert(right > 0);
        left++;
        right--;
        assert(left < arrSize);

        //printf("leftVal: %d, rightVal: %d, left: %d, right: %d\n", arr[left], arr[right], left, right);
        /*for (size_t i = prevLeft; i <= prevRight; ++i)
            printf(ColorText(CYANTEXT, "%d "), arr[i]);
        printf("\n");
        */
    }

    /*for (size_t i = prevLeft; i <= prevRight; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    */

    return right;
}

size_t Partition(const char** const ptrArr, const size_t ptrArrSz, size_t left, size_t right)
{
    assert(ptrArr);
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
    assert(right < ptrArrSz);
    assert(left < right);

    //size_t prevLeft = left;
    //size_t prevRight = right;

    const char* const midValue = ptrArr[(left + right) / 2];

    while (left < right)
    {   
        assert(left < right);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(midValue);
        assert(ptrArr[left]);

        while (left < right && StrRCmp(ptrArr[left],  midValue) < 0)
        {
            ++left;
            
            assert(ptrArr[left]);
            assert(left < ptrArrSz);
            assert(midValue);
        }

        //printf("HERE1 left: %d, right: %d\n", left, right);

        assert(left <= right);
        assert(right < ptrArrSz);
        assert(midValue);
        assert(ptrArr[right]);

        while (left < right && StrRCmp(ptrArr[right], midValue) > 0)
        {
            assert(right > 0);
            --right;

            assert(ptrArr[right]);
            assert(midValue);
        }

        if (right <= left)
            break;

        //for (size_t i = prevLeft; i <= prevRight; ++i)
        //    MyPuts(ptrArr[i], '\n');     
       
        //printf("HERE2 left: %d, right: %d\n", left, right);

        assert(ptrArr);
        assert(ptrArr[left]);
        assert(ptrArr[right]);
        assert(left < right);
#pragma GCC diagnostic ignored "-Wtype-limits"
        assert(left >= 0);
#pragma GCC diagnostic warning "-Wtype-limits"
        assert(right < ptrArrSz);

        //for (size_t i = prevLeft; i <= prevRight; ++i)
        //    MyPuts(ptrArr[i], '\n');
        
        const char* tmp = ptrArr[left];
                          ptrArr[left] = ptrArr[right];
                                         ptrArr[right] = tmp;
    
        //Swap((void*) ptrArr[left], (void*) ptrArr[right], sizeof(*ptrArr));

        assert(right > 0);
        ++left;
        --right;
        assert(left < ptrArrSz);

        //printf("HERE3 left: %d, right: %d\n", left, right);
        /*for (size_t i = prevLeft; i <= prevRight; ++i)
            MyPuts(ptrArr[i], '\n');
            //pMrintf(ColorText(CYANTEXT, "%s "), ptrArr[i]);
        printf("\n");*/
    }

    return right;
}

int StrRCmp(const void* str1, const void* str2)
{
    assert(str1);
    assert(str2);

    const char* string1 = (const char*) str1;
    const char* string2 = (const char*) str2;

    assert(string1);
    assert(string2);

    while (*string1 != '\n') 
    {
        //printf("XXX\n");
        ++string1;
    }
    //printf("HERE2\n");
    while (*string2 != '\n') ++string2;

    while (!isalpha(*string1)) --string1;
    while (!isalpha(*string2)) --string2;

    while (isalpha(*string1) && isalpha(*string2) && 
           string1 != (const char*) str1 && 
           string2 != (const char*) str2 && 
           *string1 == *string2)
    {
        --string1;
        --string2;
    }

    if (!isalpha(*string1)) ++string1;
    if (!isalpha(*string2)) ++string2;

    return *string1 - *string2;
}

int StrCmp(const void* str1, const void* str2)
{
    assert(str1);
    assert(str2);

    const char* string1 = (const char*) str1;
    const char* string2 = (const char*) str2;

    assert(string1);
    assert(string2);

    printf("%s\n\n\n\n", string1);
    printf("%s\n\n\n\n", string2);

    while (!isalpha(*string1)) ++string1;
    while (!isalpha(*string2)) ++string2;

    while (isalpha(*string1) && isalpha(*string2) && *string1 == *string2)
    {
        ++string1;
        ++string2;
    }    

    if (!isalpha(*string1)) --string1;
    if (!isalpha(*string2)) --string2;

    printf("HERE\n");
    MyPuts((const char*) str1, '\n');
    MyPuts((const char*) str2, '\n');
    MyPuts(string1, '\n');
    MyPuts(string2, '\n');
    printf("ENDHERE\n");
    return *string1 - *string2;
}

void Swap(void *aVoid, void *bVoid, const size_t size) 
{
    assert(aVoid);
    assert(bVoid);
    assert(aVoid != bVoid);
    assert(size > 0);

    uint8_t* a = (uint8_t*) aVoid;
    uint8_t* b = (uint8_t*) bVoid;

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

    if (size & 4) {
        uint32_t temp = 0;

        assert(sizeof(temp) == 4);

        memcpy(&temp, a, sizeof(temp));
               memcpy(a, b, sizeof(temp));
                  memcpy(b, &temp, sizeof(temp));
        
        a += sizeof(uint32_t);
        b += sizeof(uint32_t);
    }

    if (size & 2) {
        uint16_t temp = 0;

        assert(sizeof(temp) == 2);

        memcpy(&temp, a, sizeof(temp));
               memcpy(a, b, sizeof(temp));
                  memcpy(b, &temp, sizeof(temp));

        a += sizeof(uint16_t);
        b += sizeof(uint16_t);
    }

    if (size & 1) {
        uint8_t temp = 0;
        
        assert(sizeof(temp) == 1);

        memcpy(&temp, a, sizeof(temp));
               memcpy(a, b, sizeof(temp));
                  memcpy(b, &temp, sizeof(temp));
    }
}