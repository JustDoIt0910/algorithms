//
// Created by just do it on 2023/9/11.
//
#include "bi_tree.h"
#include <stdlib.h>

int CreateBiTree(BiTree *root, FILE* fp)
{
    char ch;
    fscanf(fp,"%c", &ch);
    if(ch == '#')
        *root = NULL;
    else
    {
        if(!(*root = malloc(sizeof(BiTree))))
            return -1;
        (*root)->data = ch;
        CreateBiTree(&(*root)->left, fp);
        CreateBiTree(&(*root)->right, fp);
    }
    return 0;
}

void PreOrderTraverse(BiTree root, visit_f visit)
{
    if(!root)
        return;
    visit(root->data);
    PreOrderTraverse(root->left, visit);
    PreOrderTraverse(root->right, visit);
}

void InOrderTraverse(BiTree root, visit_f visit)
{
    if(!root)
        return;
    InOrderTraverse(root->left, visit);
    visit(root->data);
    InOrderTraverse(root->right, visit);
}

void PostOrderTraverse(BiTree root, visit_f visit)
{
    if(!root)
        return;
    PostOrderTraverse(root->left, visit);
    PostOrderTraverse(root->right, visit);
    visit(root->data);
}