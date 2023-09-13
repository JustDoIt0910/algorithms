//
// Created by just do it on 2023/9/11.
//
#include "bi_tree.h"
#include "../stack/stack.h"
#include <stdlib.h>

int CreateBiTree(BiTree *root, FILE* fp)
{
    char ch;
    fscanf(fp,"%c", &ch);
    if(ch == '#')
        *root = NULL;
    else
    {
        if(!(*root = malloc(sizeof(BiTreeNode))))
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

void PreOrderTraverse_NonRecursive(BiTree root, visit_f visit)
{
    sqStack s;
    InitStack(&s);
    BiTree p = root;
    while(p || !StackEmpty(&s))
    {
        if(p)
        {
            visit(p->data);
            Push(&s, p);
            p = p->left;
        }
        else
        {
            Pop(&s, &p);
            p = p->right;
        }
    }
    DestoryStack(&s);
}

void InOrderTraverse_NonRecursive(BiTree root, visit_f visit)
{
    sqStack s;
    InitStack(&s);
    BiTree p = root;
    while(p || !StackEmpty(&s))
    {
        if(p)
        {
            Push(&s, p);
            p = p->left;
        }
        else
        {
            Pop(&s, &p);
            visit(p->data);
            p = p->right;
        }
    }
    DestoryStack(&s);
}

void PostOrderTraverse_NonRecursive(BiTree root, visit_f visit)
{
    sqStack s;
    InitStack(&s);
    BiTree p = root, r = NULL;
    while(p || !StackEmpty(&s))
    {
        if(p)
        {
            /* p不为空，那就沿着左孩子一路向下 */
            Push(&s, p);
            p = p->left;
        }
        else
        {
            /* p为空有两种情况
             * 1. 当前栈顶结点的左子树遍历完成
             *      此时需要继续遍历栈顶结点的右子树
             * 2. 当前栈顶节点的右子树遍历完成
             *      此时栈顶结点的左右子树都遍历完成，可以弹出并访问栈顶节点
             * 变量r用来区分当前处于上面哪一种情况*/

            Top(&s, &p);
            /* 这里判断需不需要继续遍历栈顶节点的右子树，有三种情况
             * 1. 栈顶节点没有右子树
             *      相当于上面的情况2
             * 2. 栈顶结点的右孩子是上一个弹出的元素
             *      说明是从栈顶节点的右子树返回的，对应上面情况2
             * 3. 有右子树并且还没有遍历过，对应上面情况1 */
            if(p->right && p->right != r)
                p = p->right;
            else
            {
                Pop(&s, &p);
                visit(p->data);
                r = p;
                p = NULL;
            }
        }
    }
    DestoryStack(&s);
}

static ThreadedBiTree pre;

static void InThreading(ThreadedBiTree p)
{
    if(!p) return;
    InThreading(p->left);
    if(!p->left)
    {
        p->lTag = Thread;
        p->left = pre;
    }
    if(!pre->right)
    {
        pre->rTag = Thread;
        pre->right = p;
    }
    pre = p;
    InThreading(p->right);
}

void InOrderThreading(ThreadedBiTree* thread, ThreadedBiTree root)
{
    *thread = malloc(sizeof(ThreadedBiTreeNode));
    (*thread)->lTag = Link;
    (*thread)->rTag = Thread;
    (*thread)->right = *thread;
    if(!root)
        (*thread)->left = *thread;
    else
    {
        (*thread)->left = root;
        pre = *thread;
        InThreading(root);
        pre->right = *thread;
        pre->rTag = Thread;
        (*thread)->right = pre;
    }
}

void InOrderTraverseThreaded(ThreadedBiTree head, visit_f visit)
{
    ThreadedBiTree p = head->left;
    while(p != head)
    {
        while(p->lTag == Link)
            p = p->left;
        visit(p->data);
        while(p->rTag == Thread && p->right != head)
        {
            p = p->right;
            visit(p->data);
        }
        p = p->right;
    }
}

int CreateThreadedBiTree(ThreadedBiTree *root, FILE* fp)
{
    char ch;
    fscanf(fp,"%c", &ch);
    if(ch == '#')
        *root = NULL;
    else
    {
        if(!(*root = malloc(sizeof(ThreadedBiTreeNode))))
            return -1;
        (*root)->data = ch;
        (*root)->lTag = Link;
        CreateThreadedBiTree(&(*root)->left, fp);
        (*root)->rTag = Link;
        CreateThreadedBiTree(&(*root)->right, fp);
    }
    return 0;
}