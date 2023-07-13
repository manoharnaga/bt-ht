#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
typedef long long ll;
#define MOD 1000000007


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

// DELETE TREE
void deleteTree(tnode* root){
    if(root==NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
//MAKE ROOT = NULL AFTER THIS And 
// HERE ONLY THE VALUES STORED ARE FREED NOT THE ADDRESSES THAT ARE POINTED BY LEFT AND RIGHT


// DELETE TREE

// TREE




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


//LEVEL ORDER TRAVERSAL
void levelorder(tnode* treenode){
    q* qroot = createq();
    tnode* temp = treenode;
    enque(qroot,temp);
    while(!isEmpty(qroot) && temp!=NULL){
        temp = front(qroot);
        if(temp->left!=NULL){
            enque(qroot,temp->left);
        }
        if(temp->right!=NULL){
            enque(qroot,temp->right);
        }
        printf("%d ",temp->x);
        deque(qroot);
    }
}
//LEVEL ORDER TRAVERSAL



int maxval_2(int a,int b){
    if(a>=b) return a;
    else return b;
}

int minval_2(int a,int b){
    if(a>=b) return b;
    else return a;
}

int maxval_3(int a,int b,int c){
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c) return b;
    else return c;
}

int minval_3(int a,int b,int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}


struct st{
        int is_bst_inc;
        int is_bst_dec;
        int sum;
};

typedef struct st s;
int ans_val=__INT_MAX__;
struct st defaultstruct;


s max_sum_bst(tnode* root){
    if(root==NULL) return defaultstruct;
    s rootnode;
    s left = max_sum_bst(root->left);
    s right = max_sum_bst(root->right);
    int leftval=0,rightval=0;
    int f1=0,f2=0;
    
    tnode* temp = root;
    if(root->left!=NULL){
        root=root->left;
        f1=1;
    }
    if(f1){
        while(root->right!=NULL){
            root=root->right;
        }
    }
    leftval = root->x;
    root = temp;
    if(root->right!=NULL){
        root=root->right;
        f2=1;
    }
    if(f2){
        while(root->left!=NULL){
            root=root->left;
        }
    }
    rightval = root->x;
    root = temp;
    int check1 = (((leftval<(root->x)) || f1==0) && (((root->x)<rightval) || f2==0));
    int check2 = ((leftval>(root->x)) || f1==0) && (((root->x)>rightval) || f2==0);
    if((check2 && left.is_bst_dec==1 && right.is_bst_dec==1) ||
       (check1 && left.is_bst_inc==1 && right.is_bst_inc==1))
    { 
        rootnode.is_bst_dec=0;
        rootnode.is_bst_inc=0;
        if(check1){
            rootnode.is_bst_inc=1;
        }
        if(check2){
            rootnode.is_bst_dec=1;
        }
        rootnode.sum = (root->x)+(left.sum)+(right.sum);
        ans_val = minval_2(ans_val,rootnode.sum);//MINIMUM FOUND TILL NOW
    }
    else{
        rootnode.is_bst_dec=0;
        rootnode.is_bst_inc=0;
        rootnode.sum = 0;
    }
    return rootnode;
}



int main(){
    // defaultstruct
    defaultstruct.is_bst_inc = 1;
    defaultstruct.is_bst_dec = 1;
    defaultstruct.sum = 0;
    // defaultstruct
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        ans_val=__INT_MAX__;

        scanf("%d",&n);
        int k[n];
        for(int i=0;i<n;i++) scanf("%d",&k[i]);
        tnode* root = makeNode(k[0]); //there is atleast one element in the array;
        q* storeQ = createq();
        enque(storeQ,root);
        tnode* parent = root;
        tnode* leftchild=NULL;
        tnode* rightchild=NULL;
        int i=1;
        while(i<n-1){
            parent = deque(storeQ);
            
            if(k[i]!=0){
                leftchild = makeNode(k[i]);
                parent->left = leftchild;
                enque(storeQ,leftchild);
            }
            if(k[i+1]!=0){
                rightchild = makeNode(k[i+1]);
                parent->right = rightchild;
                enque(storeQ,rightchild);
            }
            i+=2;
        }
        parent = deque(storeQ);
        if(n%2==0){
            if(k[n-1]!=0){
                leftchild = makeNode(k[n-1]);
                parent->left = leftchild;
                enque(storeQ,rightchild);
            }
        }
        while(storeQ->front!=NULL){
            deque(storeQ);
        }
        max_sum_bst(root);
        printf("%d\n",ans_val);

        // DELETE TREE
        deleteTree(root);
        root=NULL;
        // DELETE TREE
        // printf("%p %p %p %d\n",root,root->left,root->right,root->x);
    }
    return 0;
}