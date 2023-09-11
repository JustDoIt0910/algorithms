//
// Created by just do it on 2023/9/11.
//
#include "gtest/gtest.h"
#include "bi_tree.h"
#include <string>

std::string order;
void visit(char e)
{
    order.push_back(e);
}

TEST(BiTreeTest, Test_Traverse_Recursive) {
    BiTree root;
    FILE* in = fopen(R"(F:\CMakeProjects\algorithms\binary_tree\input.data)", "r");
    ASSERT_NE(in, nullptr);
    EXPECT_EQ(CreateBiTree(&root, in), 0);
    ASSERT_NE(root, nullptr);
    PreOrderTraverse(root, visit);
    EXPECT_EQ(order, "ABCDEGF");
    order.clear();
    InOrderTraverse(root, visit);
    EXPECT_EQ(order, "CBEGDFA");
    order.clear();
    PostOrderTraverse(root, visit);
    EXPECT_EQ(order, "CGEFDBA");
    fclose(in);
}

TEST(BiTreeTest, Test_Traverse_NonRecursive) {
    BiTree root;
    FILE* in = fopen(R"(F:\CMakeProjects\algorithms\binary_tree\input.data)", "r");
    ASSERT_NE(in, nullptr);
    EXPECT_EQ(CreateBiTree(&root, in), 0);
    ASSERT_NE(root, nullptr);
    PreOrderTraverse_NonRecursive(root, visit);
    EXPECT_EQ(order, "ABCDEGF");
    order.clear();
    InOrderTraverse_NonRecursive(root, visit);
    EXPECT_EQ(order, "CBEGDFA");
    order.clear();
    PostOrderTraverse_NonRecursive(root, visit);
    EXPECT_EQ(order, "CGEFDBA");
    fclose(in);
}