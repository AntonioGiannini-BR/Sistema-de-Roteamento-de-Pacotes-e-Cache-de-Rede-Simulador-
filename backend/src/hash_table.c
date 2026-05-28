#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hash_table.h"

// Inicializa a tabela hash
void initHashTable(HashTable *table) {

    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }

    table->collisions = 0;
}

// Função hash
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Inserção usando encadeamento separado
void insertHash(HashTable *table, Packet packet) {

    int index = hashFunction(packet.id);

    // Detecta colisão
    if (table->buckets[index] != NULL) {
        table->collisions++;
    }

    // Cria novo nó
    HashNode *newNode = malloc(sizeof(HashNode));

    if (newNode == NULL) {
        printf("Erro de alocação de memória\n");
        return;
    }

    newNode->data = packet;

    // Insere no início da lista
    newNode->next = table->buckets[index];

    table->buckets[index] = newNode;
}

// Busca um pacote na tabela hash
Packet *searchHash(HashTable *table, int id) {

    int index = hashFunction(id);

    HashNode *current = table->buckets[index];

    // Percorre lista encadeada
    while (current != NULL) {

        if (current->data.id == id) {
            return &current->data;
        }

        current = current->next;
    }

    return NULL;
}

// Exibe tabela hash
void printHashTable(HashTable *table) {

    printf("\n========== TABELA HASH ==========\n");

    for (int i = 0; i < TABLE_SIZE; i++) {

        printf("[%d] -> ", i);

        HashNode *current = table->buckets[i];

        while (current != NULL) {

            printf("ID:%d -> ",
                   current->data.id);

            current = current->next;
        }

        printf("NULL\n");
    }

    printf("\nTotal de colisões: %d\n",
           table->collisions);
}

// Libera memória
void freeHashTable(HashTable *table) {

    for (int i = 0; i < TABLE_SIZE; i++) {

        HashNode *current = table->buckets[i];

        while (current != NULL) {

            HashNode *temp = current;

            current = current->next;

            free(temp);
        }
    }
}
