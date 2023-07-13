#ifndef _BT_
#define _BT_

// TREE
typedef struct Tnode{
    int x;
    struct Tnode* left;
    struct Tnode* right;
}tnode;


tnode* makeNode(int x);
tnode* insert(tnode* treenode,int x);

//BFS
void levelorder(tnode* treenode);
//DFS
void preorder(tnode* treenode);
void Inorder(tnode* treenode);
void postorder(tnode* treenode);

tnode* findNode(tnode* root,int x);
tnode* deleteNode(tnode* root,int x);
// TREE



#endif