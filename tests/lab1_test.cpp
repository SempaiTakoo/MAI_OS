#include <gtest/gtest.h>

#include "utils.h"
#include "parent.h"

TEST(TestParent, Input) {
    const char PATH_TO_CHILD1[] = "/home/takoo/Desktop/MAI_OS/build/lab1/child1";
    const char PATH_TO_CHILD2[] = "/home/takoo/Desktop/MAI_OS/build/lab1/child2";
    InitParent(PATH_TO_CHILD1, PATH_TO_CHILD2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}