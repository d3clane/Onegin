#include "UnitTests.h"

void TestAll()
{
    int arr[] = {7, 8, 23, 532, 23, 6, 13, 5, 8, 5, 1, 1};

    MyQSort(arr, sizeof(arr) / sizeof(*arr), 0, sizeof(arr) / sizeof(*arr) - 1);

    for (size_t i = 0; i < sizeof(arr) / sizeof(*arr); ++i)
    {
        printf("%d ", arr[i]);
    }

}