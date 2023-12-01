#include "linked_list.h"
#include <stdlib.h>

struct node* create(int value) {
    struct node* n = (struct node *) malloc(sizeof(struct node));
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void destory(struct node *n) {
    if (n->next != NULL) {
        destory(n->next);
    }

    free(n);
}

