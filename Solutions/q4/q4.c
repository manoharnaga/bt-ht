#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
// #include "adt.h"

typedef long long ll;
#define MOD 1000000007
typedef struct Node{
    // struct Node* parent;
    struct Node* leftchild;
    struct Node* rightchild;
    char alpha;
    int index;
    // int is_childpar;
    // int check_node;
    // int check_child;
}node;

// int getHash(char s[],int start,int end){
//     ll prime=2;
//     ll sum=0;
//     for(int i=start;i<=end;i++){
//         sum += (s[i]*prime)%MOD;
//         prime=(32*prime)%MOD;
//     }
//     return sum;
// }
char P[1000010];//  PRE-ORDER STRING
int Index=0;

// As the Index is Declared as a Global Variable the preorder Function is used in q4.c only
void preorder(node* tree){
    if(tree==NULL) {return;}
    P[Index] = tree->alpha;
    tree->index = Index;
    Index++;
    preorder(tree->leftchild);
    preorder(tree->rightchild);
}

int main(){
    int n;
    scanf("%d",&n);
    node* h[n+10];
    char temp[n+10];
    scanf("%s",temp);
    for(int i=1;i<=n;i++){
        h[i] = (node*)malloc(sizeof(node));
        // h[i]->parent = NULL;
        h[i]->leftchild = NULL;
        h[i]->rightchild = NULL;
        h[i]->alpha = temp[i-1];
        h[i]->index = -1;
        // h[i]->check_node = 0;
        // h[i]->check_child = 0;
    }
    int a,b,c;
    // tnode* parent=NULL;
    // tnode* leftchild=NULL;
    // tnode* rightchild=NULL;

    for(int i=1;i<=n-1;i++){
        scanf("%d %d %d",&a,&b,&c);
        // h[b]->parent = h[a];
        h[b]->index = 1;
        if(c==1){
            h[a]->leftchild = h[b];
            // h[b]->is_childpar = 1;
            //left child;
        }
        else{
            h[a]->rightchild = h[b];
            // h[b]->is_childpar = 2;
            //right child;
        }
    }

    // PRINT TREE 
    // for(int i=1;i<=n;i++){
    //     printf("%c ",h[i]->alpha);
    //     if(h[i]->leftchild!=NULL){
    //         printf(" left: %c",h[i]->leftchild->alpha);
    //     }
    //     if(h[i]->rightchild!=NULL){
    //         printf(" right: %c",h[i]->rightchild->alpha);
    //     }
    //     printf("\n");
    // }
    // PRINT TREE
    node* root;
    for(int i=1;i<=n;i++){
        if(h[i]->index==-1){
            root = h[i];
            break;
        }
    }
    preorder(root);
    // printf("%s\n",P);
    // for(int i=1;i<=n;i++){
    //     printf("%d ",h[i]->index);
    // }
    // printf("\n");

    
    char s[1000010];
    scanf("%s",s);
    int Q,T,nodeNo,l,r;// QUERIES
    char ch;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&T);
        if(T==1){
            scanf("%d %c",&nodeNo,&ch);
            h[nodeNo]->alpha = ch;
            P[(h[nodeNo]->index)] = ch;
            // printf("%s\n",P);
        }
        else{
            scanf("%d %d %d",&l,&r,&nodeNo);
            // STRNCMP 
            if(strncmp(P+h[nodeNo]->index,s+l-1,r-l+1)==0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            // STRNCMP 
        }
    }
    return 0;
}