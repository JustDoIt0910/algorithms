//
// Created by zr on 22-9-21.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H
#include "c-vector/cvector.h"
#include "common.h"
#include <stdlib.h>

#define vector(type) cvector_vector_type(type)
#define NEW_NODE(node, e) (node) = (AVLNode*) malloc(sizeof(AVLNode)); \
                                    (node)->left = NULL;               \
                                    (node)->right = NULL;     \
                                    (node)->height = 1;                     \
                                    (node)->key = e;
#define max(a, b) (a > b ? a: b)

typedef struct AVLNode
{
    struct AVLNode* left;
    struct AVLNode* right;
    elem_t key;
    int height;
}AVLNode, *AVLNode_p;

typedef struct AVLTree
{
    AVLNode* _root;
    int _size;

    METHOD(void)
    (*preOrderTraverse)(struct AVLTree*, vector(elem_t)*);

    METHOD(void)
    (*inOrderTraverse)(struct AVLTree*, vector(elem_t)*);

    METHOD(void)
    (*postOrderTraverse)(struct AVLTree*, vector(elem_t)*);

    METHOD(void)
    (*levelOrderTraverse)(struct AVLTree*, vector(elem_t)*);

    METHOD(void)
    (*clear)(struct AVLTree*);

    METHOD(Bool)
    (*isEmpty)(struct AVLTree*);

    METHOD(int)
    (*height)(struct AVLTree*);

    METHOD(int)
    (*size)(struct AVLTree*);

    METHOD(AVLNode*)
    (*search)(struct AVLTree*, elem_t);

    METHOD(Bool)
    (*insert)(struct AVLTree*, elem_t, AVLNode_p*);

    METHOD(Bool)
    (*remove)(struct AVLTree*, elem_t);

}AVLTree;

GLOBAL(AVLTree*)
CreateAVL(void);

#endif //AVL_AVL_H
