#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

struct HashTable* init_hash_table(int a,int b,int countBucket){
    struct HashTable* T = (struct HashTable*)malloc(sizeof(struct HashTable));
    T->a = a;
    T->b = b;
    T->countBucket = countBucket;
    T->buckets = (struct Bucket*)malloc(sizeof(struct Bucket)*countBucket);
    for(int i=0;i<countBucket;i++){
        T->buckets[i].items = NULL;
    }
    return T;
}

// double insert_op=0;
// double search_op=0;


struct HashTable* insert(struct HashTable* T,int key){
    int hash_key = ((T->a)*key + (T->b))%(T->countBucket);
    // printf("%d\n",hash_key);
    struct Item* head = T->buckets[hash_key].items;
    // printf("key1 %d",head->key);
    int flag=0;
    struct Item* traverse = head;
    // insert_op++;
    while(traverse!=NULL){
        if(traverse->key==key){
            flag=1;
            traverse->frequency++;
            // break;
            return T;
        }
        // insert_op++;
        traverse=traverse->next;
    }
    struct Item* newnode = (struct Item*)malloc(sizeof(struct Item));
    if(!flag){
        newnode->next = head;
        newnode->frequency = 1;
        newnode->key = key;
        T->buckets[hash_key].items = newnode;
        // T->buckets[hash_key].items->next = head;
        // T->buckets[hash_key].items->frequency = 1;
        // T->buckets[hash_key].items->key = key;
        // printf("its four,13 %d\n",key); 
    }
    return T;
}

int search(struct HashTable* T,int key){
    int hash_key = ((T->a)*key + T->b)%T->countBucket;
    struct Item* head = T->buckets[hash_key].items;
    int flag=0;
    struct Item* traverse = head;
    // search_op++;
    while(traverse!=NULL){
        if(traverse->key==key){
            flag=1;
            break;
        }
        // search_op++;
        traverse=traverse->next;
    }
    return flag;
}

struct HashTable* Delete(struct HashTable* T,int key){
    int hash_key = ((T->a)*key +(T->b))%(T->countBucket);
    struct Item* head = T->buckets[hash_key].items;
    struct Item* traverse = head;
    struct Item* temp;
    int flag=0;
    if(traverse==NULL){
        // printf("KEY NOT FOUND!\n");
        return T;
    }
    else if(traverse->key==key){//Key found at first Node;
        if(traverse->frequency>1){
            traverse->frequency--;
        }
        else{
            temp = traverse;
            T->buckets[hash_key].items = traverse->next;
            free(temp);
        }
        return T;
    }
    while(traverse->next!=NULL){
        if(traverse->next->key==key){
            flag=1;
            if((traverse->next->frequency)>1){
                traverse->next->frequency--;
            }
            else{
                temp = traverse->next;
                traverse->next = traverse->next->next;
                free(temp);
            }
            break;
        }
        traverse = traverse->next;
    }
    /*
    if(!flag){// LAST NODE
        if(traverse->next->key==key){
            if((traverse->next->frequency)>1){
                traverse->next->frequency--;
            }
            else{
                temp = traverse->next;
                traverse->next = traverse->next->next;//NULL
                free(temp);
            }
        }
    }
    */
    return T;
}

void print_table(struct HashTable* T){
    struct Item* traverse;
    for(int i=0;i<T->countBucket;i++){
        printf("Bucket %d  :   ",i);
        traverse=T->buckets[i].items;
        while(traverse!=NULL){
            printf("key: %d freq: %d\t",traverse->key,traverse->frequency);
            traverse=traverse->next;
        }
        printf("\n");
    }
}