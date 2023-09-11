//
// Created by just do it on 2023/9/11.
//
#include "gtest/gtest.h"
#include "stack.h"

TEST(StackTest, TestAll)
{
    sqStack s;
    InitStack(&s);
    EXPECT_EQ(StackLength(&s), 0);
    EXPECT_EQ(StackEmpty(&s), 1);
    for(int i = 0; i < 10; i++)
    {
        EXPECT_EQ(Push(&s, i), 1);
    }
    EXPECT_EQ(StackLength(&s), 10);
    for(int i = 9; i >= 0; i--)
    {
        int x;
        EXPECT_EQ(Pop(&s, &x), 1);
        EXPECT_EQ(x, i);
    }
    EXPECT_EQ(StackLength(&s), 0);
}