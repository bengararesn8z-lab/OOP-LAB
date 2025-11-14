#include <iostream>
#include<stdio.h>
#define USE_HEADER1 0

#ifdef USE_HEADER1
    #include "Header1.h"

#else
    #include "Header2.h"
#endif

int main() {
    f();
    return 0;
}

