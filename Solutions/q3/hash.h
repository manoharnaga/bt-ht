#ifndef HASH_H
#define HASH_H

struct Item{
    int key;
    int frequency;
    struct Item* next;
};

struct Bucket{
    struct Item* items;
};

struct HashTable{
    int a,b, countBucket;
    // countBuckets = number of Buckets
    // hash function will be: (a*key+b)%countBucket;
    struct Bucket* buckets;
};

struct HashTable* init_hash_table(int a,int b,int countBucket);

struct HashTable* insert(struct HashTable* T,int key); // function to insert new key in HashTable
    
int search(struct HashTable* T,int key); //return true if element is present in HashTable

struct HashTable* Delete(struct HashTable* T,int key); 
// delete given key from the HashTable. Do Nothing if element is not present inside HashTable

void print_table(struct HashTable* T);
// function should print one line for each bucket.
// A one line bucket output looks like: key_1 freq_1 key_2 freq_2 ... key_m freq_m




#endif