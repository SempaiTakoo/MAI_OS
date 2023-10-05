#include <iostream>

#include "utils.h"
#include "parent.h"

int main() {
    const char PATH_TO_CHILD1[] = "/home/takoo/Desktop/MAI_OS/build/lab1/child1";
    const char PATH_TO_CHILD2[] = "/home/takoo/Desktop/MAI_OS/build/lab1/child2";
    InitParent(PATH_TO_CHILD1, PATH_TO_CHILD2);
    return 0;
}