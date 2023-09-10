#include "StringFuncs.h"

const char** BuildPtrArr(const char* text, const char lim, size_t* arrSize)
{
    assert(text);
    assert(arrSize);

    static const size_t STD_SIZE = 256; 

    const char** ptrArr = (const char**) calloc(STD_SIZE, sizeof(*ptrArr));
    size_t posInPtrArr = 0;

    assert(STD_SIZE > 0);
    assert(0 <= posInPtrArr && posInPtrArr < STD_SIZE);

    ptrArr[posInPtrArr] = text;
    ++posInPtrArr;

    size_t ptrArrSz = STD_SIZE;
    while (*text)
    {
        if (*text == lim)
        {
            if (posInPtrArr >= ptrArrSz)
            {
                //printf("HERE1\n");
                ptrArrSz <<= 1;
                //printf("%p\n", ptrArr);
                //printf("%d\n", ptrArrSz);

                /*for (size_t i = 0; i < posInPtrArr; ++i)
                {
                    printf("%d: pointer: %p ", i, ptrArr[i]);
                    MyPuts(ptrArr[i], '\n');
                }*/

                const char** tmp = (const char**) realloc(ptrArr, ptrArrSz * sizeof(*ptrArr));
                //printf("%p\n", tmp);

                if (tmp == nullptr)
                {
                    free(ptrArr);
                    ptrArr = nullptr;
                    *arrSize = 0;
                    return nullptr;
                }

                ptrArr = tmp;

                /*for (size_t i = 0; i < posInPtrArr; ++i)
                {
                    printf("%d: pointer: %p ", i, ptrArr[i]);
                    MyPuts(ptrArr[i], '\n');
                }*/
            }
            //printf("HERE2\n");
            assert(0 <= posInPtrArr && posInPtrArr < ptrArrSz);

            ptrArr[posInPtrArr] = text + 1;
            //printf("%d: %p\n", posInPtrArr, text + 1);
            ++posInPtrArr;

        }
        ++text;
    }
    
    *arrSize = posInPtrArr;
    return ptrArr;
}