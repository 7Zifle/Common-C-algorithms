#ifndef __ALGOS_LL_H__
#define __ALGOS_LL_H__
struct node {
    int value;
    struct node *next;
    struct node *prev;
};

struct node* create(int value);
#endif // !__ALGOS_LL_H__
