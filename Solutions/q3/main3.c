#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"
typedef long long ll;
#define MOD 1000000007

int main(){
    struct HashTable* T = init_hash_table(7,11,2);
    T = insert(T,15);
    T = Delete(T,15);
    T = insert(T,15);
    T = insert(T,11);
    T = insert(T,19);
    T = insert(T,13);
    int key = search(T,13);
    T = insert(T,21);
    key = search(T,15);
    printf("%d\n",key);
    T = Delete(T,12);
    T = Delete(T,19);
    key = search(T,12);
    printf("%d\n",key);
    printf("%d\n",key);
    T = Delete(T,13);
    key = search(T,19);
    printf("%d\n",key);


    // DRIVER CODE
    /*
    // int bucket[4]={2,5,10,20};
    struct HashTable* T = init_hash_table(7,11,2);
    char input[100010];
    int val=0;
    double no_of_insertions=0;
    double no_of_searches=0;
    while(scanf("%s %d",input,&val)!=EOF){
        if(strcmp(input,"INSERT")==0){
            no_of_insertions++;
            T = insert(T,val);
        }
        else if(strcmp(input,"SEARCH")==0){
            no_of_searches++;
            int key = search(T,val);
            // printf("%d\n",key);
        }
        else if(strcmp(input,"DELETE")==0){
            T = Delete(T,val);
        }
        else{
            break;
        }
    }
    // printf("INsert\n");
    printf("%lf\n",(insert_op/no_of_insertions));
    // printf("search\n");
    // printf("%lf\n",(search_op/no_of_searches));
    */
    return 0;
}