#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "q.h"
typedef long long ll;
#define MOD 1000000007

q* createq(){
    q* que=(q*)malloc(sizeof(q));
    assert(que!=NULL);
    que->front=NULL;
    que->rear=NULL;
    que->size=0;
    return que;
}

qnode* createnode(tnode* treenode){
    qnode* node=(qnode*)malloc(sizeof(node));
    assert(node!=NULL);
    node->next=NULL;
    node->treenode=treenode;
    return node;
}

void enque(q* que,tnode* treenode){
    qnode* newnode=createnode(treenode);
    assert(newnode!=NULL);
    if(que->rear==NULL){
        que->rear=newnode;
        que->front=newnode;
        return;
    }
    que->rear->next=newnode;
    que->rear=newnode;
}

tnode* deque(q* que){
    qnode* tempnode;
    if(que==NULL || que->front==NULL){
        // printf("QUEUE IS EMPTY--from deque!\n");
        return NULL;
    }
    tempnode=que->front;

    tnode* tempx = que->front->treenode;
    que->front=que->front->next;
    if(que->front==NULL){
        que->rear=NULL;
    }
    free(tempnode);
    return tempx;
}

tnode* front(q* que){
    if(que==NULL){
        // printf("QUEUE IS EMPTY--from front!\n");
        return NULL;
    }
    if(que->front!=NULL){
        return que->front->treenode;
    }
    return NULL;
}

int isEmpty(q* que){
    return (que->front==NULL && que->rear==NULL);
}
//QUEUE

