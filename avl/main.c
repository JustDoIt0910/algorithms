#include <stdio.h>
#include "avl.h"

int main(int argc, char* argv[]) {

    AVLTree* avl = CreateAVL();
    AVLNode_p exist = NULL;

    avl->insert(avl, 7, &exist);
    avl->insert(avl, 4, &exist);
    avl->insert(avl, 9, &exist);
    avl->insert(avl, 8, &exist);
    avl->insert(avl, 20, &exist);
    avl->insert(avl, 21, &exist);
    avl->insert(avl, 11, &exist);
    avl->insert(avl, 17, &exist);

    if(!avl->insert(avl, 20, &exist))
        printf("key already exists: %d\n", exist->key);

    avl->insert(avl, 14, &exist);
    avl->remove(avl, 20);
    avl->remove(avl, 21);
    avl->remove(avl, 9);
    AVLNode* n = avl->search(avl, 20);
    if(n)
        printf("search result: %d\n", n->key);
    else
        printf("not found\n");
    vector(int) v = NULL;
    //avl->preOrderTraverse(avl, &v);
    avl->levelOrderTraverse(avl, &v);
//    avl->clear(avl);
//    assert(avl->isEmpty(avl));
    if (v)
    {
        elem_t *it;
        for (it = cvector_begin(v); it != cvector_end(v); ++it) {
            printf("%d ", *it);
        }
        printf("\n");
    }
    else
        printf("empty\n");
    cvector_free(v);
}
