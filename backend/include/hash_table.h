
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10

typedef struct HashNode {

    char ip[50];
    int packetId;

    struct HashNode* next;

} HashNode;

typedef struct {

    HashNode* table[TABLE_SIZE];
    int collisions;

} HashTable;

void initHash(HashTable* hash);
int hashFunction(char* ip);
void insertHash(HashTable* hash,
                char* ip,
                int packetId);

int searchHash(HashTable* hash,
               char* ip);

void showHash(HashTable* hash);
void freeHash(HashTable* hash);

#endif
