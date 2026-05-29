/*
 * Interface da tabela hash utilizada como cache de pacotes da rede.
 * Aqui ficam as estruturas e protótipos usados pela implementação em hash_table.c.
 */
// Evita que este cabeçalho seja incluído mais de uma vez durante a compilação.
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "packet.h"

#define TABLE_SIZE 10

// Nó da lista encadeada
// Define a estrutura de dados principal usada por este módulo.
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
// Protótipos das funções disponíveis para outros arquivos do projeto.
void initHashTable(HashTable *table);

int hashFunction(int key);

void insertHash(HashTable *table, Packet packet);

Packet *searchHash(HashTable *table, int id);

void printHashTable(HashTable *table);

void freeHashTable(HashTable *table);

#endif
