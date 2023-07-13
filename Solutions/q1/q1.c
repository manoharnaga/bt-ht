#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "q.h"
typedef long long ll;
#define MOD 1000000007


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