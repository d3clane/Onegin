#include <stdio.h>
#include <stdlib.h>

#include "Colors.h"
#include "InputOutput.h"
#include "StringFuncs.h"

int main()
{
    TextType text = 
    {
        .fileName = "Onegin.txt",
        .text = nullptr,
        .ptrArr = nullptr,
        .ptrArrSz = 0,
    };

    if (ReadTextAndParse(&text) != 0)
        return -1;

    if (PrintText(text.ptrArr, text.ptrArrSz) != 0)
    {
        fprintf(stderr, RedText("Error printing to output\n"));
        return -1;
    }
}