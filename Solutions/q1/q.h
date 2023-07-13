#ifndef _QUEUE_H
#define _QUEUE_H

#include "tree.h"
//QUEUE
typedef long long element_type;

typedef struct Qnode{
    tnode* treenode;
    struct Qnode* next;
    struct Qnode* prev;
}qnode;

typedef struct q{
    element_type size;
    qnode* front;
    qnode* rear;
}q;

q* createq();
qnode* createnode(tnode* treenode);
void enque(q* que,tnode* treenode);
tnode* deque(q* que);

tnode* front(q* que);


int isEmpty(q* que);
element_type qsize(q* que);

element_type printr(q* que);
void printq(q* que);
//QUEUE


#endif