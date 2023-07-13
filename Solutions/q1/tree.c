#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "q.h"
typedef long long ll;
#define MOD 1000000007


tnode* makeNode(int x){
    tnode* node = (tnode*)malloc(sizeof(tnode));
    node->x = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void preorder(tnode* tree){
    if(tree==NULL) {return;}
    printf("%d ",tree->x);
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(tnode* tree){
    if(tree==NULL) return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ",tree->x);
}

void Inorder(tnode* tree){
    if(tree==NULL) return;
    Inorder(tree->left);
    printf("%d ",tree->x);
    Inorder(tree->right);
}




// //LEVEL ORDER TRAVERSAL
// void levelorder(tnode* treenode){
//     q* qroot = createq();
//     tnode* temp = treenode;
//     enque(qroot,temp);
//     while(!isEmpty(qroot) && temp!=NULL){
//         temp = front(qroot);
//         if(temp->left!=NULL){
//             enque(qroot,temp->left);
//         }
//         if(temp->right!=NULL){
//             enque(qroot,temp->right);
//         }
//         printf("%d ",temp->x);
//         deque(qroot);
//     }
// }
// //LEVEL ORDER TRAVERSAL


// TREE










