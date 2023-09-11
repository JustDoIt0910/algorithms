//
// Created by zr on 22-9-22.
//

#include "avl.h"
#include <stdio.h>


LOCAL(int)
getHeight(AVLNode_p root)
{
    if(!root)
        return 0;
    return root->height;
}

LOCAL(AVLNode_p)
getMax(AVLNode_p root)
{
    if(!root)
        return NULL;
    AVLNode* node = root;
    while(node->right)
        node = node->right;
    return node;
}

LOCAL(AVLNode_p)
getMin(AVLNode_p root)
{
    if(!root)
        return NULL;
    AVLNode* node = root;
    while(node->left)
        node = node->left;
    return node;
}

LOCAL(AVLNode_p)
leftRotate(AVLNode_p root)
{
    AVLNode* subR = root->right;
    AVLNode* subRL = subR->left;
    root->right = subRL;
    subR->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    subR->height = max(getHeight(subR->left), getHeight(subR->right)) + 1;
    return subR;
}

LOCAL(AVLNode_p)
rightRotate(AVLNode_p root)
{
    AVLNode* subL = root->left;
    AVLNode* subLR = subL->right;
    root->left = subLR;
    subL->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    subL->height = max(getHeight(subL->left), getHeight(subL->right)) + 1;
    return subL;
}

LOCAL(Bool)
_insert(AVLNode_p* root, elem_t e, AVLNode_p* exist)
{
    if(!(*root))
    {
        NEW_NODE(*root, e);
        return true;
    }
    else if((*root)->key == e)
    {
        *exist = *root;
        return false;
    }
    else if(e < (*root)->key)
    {
        if(!_insert(&(*root)->left, e, exist))
            return false;
        if(getHeight((*root)->left) - getHeight((*root)->right) > 1)
        {
            if(e < (*root)->left->key)
                (*root) = rightRotate(*root);
            else
            {
                (*root)->left = leftRotate((*root)->left);
                (*root) = rightRotate(*root);
            }
        }
    }
    else
    {
        if(!_insert(&(*root)->right, e, exist))
            return false;
        if(getHeight((*root)->right) - getHeight((*root)->left) > 1)
        {
            if(e > (*root)->right->key)
                (*root) = leftRotate(*root);
            else
            {
                (*root)->right = rightRotate((*root)->right);
                (*root) = leftRotate(*root);
            }
        }
    }
    (*root)->height = max(getHeight((*root)->left), getHeight((*root)->right)) + 1;
    return true;
}

LOCAL(Bool)
_remove(AVLNode_p* root, elem_t e)
{
    if(!(*root))
        return false;
    if((*root)->key == e)
    {
         if((*root)->left && (*root)->right)
         {
            if(getHeight((*root)->left) > getHeight((*root)->right))
            {
                AVLNode* lmax = getMax((*root)->left);
                (*root)->key = lmax->key;
                _remove(&(*root)->left, lmax->key);
            }
            else
            {
                AVLNode* rmin = getMin((*root)->right);
                (*root)->key = rmin->key;
                _remove(&(*root)->right, rmin->key);
            }
         }
         else
         {
             AVLNode* tmp = *root;
             *root = (*root)->left ? (*root)->left : (*root)->right;
             free(tmp);
         }
    }
    else if(e < (*root)->key)
    {
        if(!_remove(&(*root)->left, e))
            return false;
        if(getHeight((*root)->right) - getHeight((*root)->left) > 1)
        {
            AVLNode* right = (*root)->right;
            if(getHeight(right->right) > getHeight(right->left))
                (*root) = leftRotate(*root);
            else
            {
                (*root)->right = rightRotate((*root)->right);
                (*root) = leftRotate(*root);
            }
        }
    }
    else
    {
        if(!_remove(&(*root)->right, e))
            return false;
        if(getHeight((*root)->left) - getHeight((*root)->right) > 1)
        {
            AVLNode* left = (*root)->left;
            if(getHeight(left->left) > getHeight(left->right))
                (*root) = rightRotate(*root);
            else
            {
                (*root)->left = leftRotate((*root)->right);
                (*root) = rightRotate(*root);
            }
        }
    }
    if(*root)
        (*root)->height = max(getHeight((*root)->left), getHeight((*root)->right)) + 1;
    return true;
}

LOCAL(AVLNode_p)
_search(AVLNode_p root, elem_t e)
{
    if(!root)
        return NULL;
    if(root->key == e)
        return root;
    AVLNode* ls = _search(root->left, e);
    return ls ? ls : _search(root->right, e);
}

LOCAL(void)
_preOrderTraverse(AVLNode_p root, vector(elem_t)* v)
{
    if(!root)
        return;
    cvector_push_back((*v), root->key);
    _preOrderTraverse(root->left, v);
    _preOrderTraverse(root->right, v);
}

LOCAL(void)
_inOrderTraverse(AVLNode_p root, vector(elem_t)* v)
{
    if(!root)
        return;
    _inOrderTraverse(root->left, v);
    cvector_push_back((*v), root->key);
    _inOrderTraverse(root->right, v);
}

LOCAL(void)
_postOrderTraverse(AVLNode_p root, vector(elem_t)* v)
{
    if(!root)
        return;
    _postOrderTraverse(root->left, v);
    _postOrderTraverse(root->right, v);
    cvector_push_back((*v), root->key);
}

LOCAL(void)
_clear(AVLNode_p root)
{
    if(!root)
        return;
    _clear(root->left);
    _clear(root->right);
    free(root);
}

/************************************** methods ******************************************/

METHODDEF(Bool)
isEmpty(AVLTree* this)
{
    return (!this || this->_size == 0);
}

METHODDEF(int)
size(AVLTree* this)
{
    return this->_size;
}

METHODDEF(void)
clear(AVLTree* this)
{
    _clear(this->_root);
    this->_root = NULL;
    this->_size = 0;
}

METHODDEF(Bool)
insert(AVLTree* this, elem_t e, AVLNode_p* exist)
{
    if(_insert(&this->_root, e, exist))
    {
        this->_size++;
        return true;
    }
    return false;
}

METHODDEF(Bool)
remove_(AVLTree* this, elem_t e)
{
    if(_remove(&this->_root, e))
    {
        this->_size--;
        return true;
    }
    return false;
}

METHODDEF(int)
height(AVLTree* this)
{
    AVLNode_p root = this->_root;
    if(!root)
        return 0;
    return root->height;
}

METHODDEF(void)
preOrderTraverse(AVLTree* this, vector(elem_t)* v)
{
    AVLNode_p root = this->_root;
    _preOrderTraverse(root, v);
}

METHODDEF(void)
inOrderTraverse(AVLTree* this, vector(elem_t)* v)
{
    AVLNode_p root = this->_root;
    _inOrderTraverse(root, v);
}

METHODDEF(void)
postOrderTraverse(AVLTree* this, vector(elem_t)* v)
{
    AVLNode_p root = this->_root;
    _postOrderTraverse(root, v);
}

METHODDEF(void)
levelOrderTraverse(AVLTree* this, vector(elem_t)* v)
{
    AVLNode* root = this->_root;
    if(!root)
        return;
    vector(AVLNode_p) q = NULL;
    cvector_insert(q, 0, root);
    while(!cvector_empty(q))
    {
        AVLNode* n = q[cvector_size(q) - 1];
        cvector_push_back(*v, n->key);
        cvector_pop_back(q);
        if(n->left)
            cvector_insert(q, 0, n->left);
        if(n->right)
            cvector_insert(q, 0, n->right);
    }
    cvector_free(q);
}

METHODDEF(AVLNode_p)
search(AVLTree* this, elem_t e)
{
    return _search(this->_root, e);
}


GLOBAL(AVLTree*)
CreateAVL(void)
{
    AVLTree* avl = (AVLTree*) malloc(sizeof(AVLTree));
    avl->_size = 0;
    avl->_root = NULL;

    avl->insert = insert;
    avl->remove = remove_;
    avl->height = height;
    avl->preOrderTraverse = preOrderTraverse;
    avl->inOrderTraverse = inOrderTraverse;
    avl->postOrderTraverse = postOrderTraverse;
    avl->levelOrderTraverse = levelOrderTraverse;
    avl->isEmpty = isEmpty;
    avl->size =  size;
    avl->clear = clear;
    avl->search = search;
    return avl;
}
