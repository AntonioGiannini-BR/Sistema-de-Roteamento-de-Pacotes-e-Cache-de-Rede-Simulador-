#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10

// Estrutura do pacote de rede
typedef struct Packet {
    int id;
    char ip[50];
    char content[100];
    int priority;
} Packet;

// Nó da lista encadeada
typedef struct HashNode {
    Packet data;
    struct HashNode *next;
} HashNode;

// Estrutura principal da tabela hash
typedef struct {
    HashNode *buckets[TABLE_SIZE];
    int collisions;
} HashTable;

// Funções da tabela hash
void initHashTable(HashTable *table);

int hashFunction(int key);

void insertHash(HashTable *table, Packet packet);

Packet *searchHash(HashTable *table, int id);

void printHashTable(HashTable *table);

void freeHashTable(HashTable *table);

#endif
