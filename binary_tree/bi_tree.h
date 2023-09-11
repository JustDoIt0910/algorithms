//
// Created by just do it on 2023/9/11.
//

#ifndef ALGORITHM_BI_TREE_H
#define ALGORITHM_BI_TREE_H
#include <stdio.h>

#ifdef __cplusplus
extern "C"
    {
#endif

#define Elem    char
typedef void(*visit_f)(Elem e);

typedef struct BiTreeNode {
    Elem data;
    struct BiTreeNode *left, *right;
} BiTreeNode, *BiTree;

int CreateBiTree(BiTree *root, FILE* fp);
void PreOrderTraverse(BiTree root, visit_f visit);
void InOrderTraverse(BiTree root, visit_f visit);
void PostOrderTraverse(BiTree root, visit_f visit);

void PreOrderTraverse_NonRecursive(BiTree root, visit_f visit);
void InOrderTraverse_NonRecursive(BiTree root, visit_f visit);
void PostOrderTraverse_NonRecursive(BiTree root, visit_f visit);

#ifdef __cplusplus
}
#endif

#endif //ALGORITHM_BI_TREE_H
