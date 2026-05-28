
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hash_table.h"
#include "../include/colors.h"

void initHash(HashTable* hash) {

    hash->collisions = 0;

    for(int i = 0; i < TABLE_SIZE; i++) {

        hash->table[i] = NULL;
    }
}

int hashFunction(char* ip) {

    int sum = 0;

    for(int i = 0; ip[i] != '\0'; i++) {

        sum += ip[i];
    }

    return sum % TABLE_SIZE;
}

void insertHash(HashTable* hash,
                char* ip,
                int packetId) {

    int index = hashFunction(ip);

    if(hash->table[index] != NULL) {

        printf(YELLOW
               "\n[COLISAO DETECTADA]"
               RESET
               " indice %d ocupado.\n",
               index);

        hash->collisions++;
    }

    HashNode* newNode =
        (HashNode*) malloc(sizeof(HashNode));

    strcpy(newNode->ip, ip);

    newNode->packetId = packetId;

    newNode->next = hash->table[index];

    hash->table[index] = newNode;
}

int searchHash(HashTable* hash,
               char* ip) {

    int index = hashFunction(ip);

    HashNode* current = hash->table[index];

    while(current != NULL) {

        if(strcmp(current->ip, ip) == 0)
            return 1;

        current = current->next;
    }

    return 0;
}

void showHash(HashTable* hash) {

    printf(CYAN
           "\n===================================\n");
    printf("      ESTADO DA TABELA HASH\n");
    printf("===================================\n"
           RESET);

    for(int i = 0; i < TABLE_SIZE; i++) {

        printf(BLUE "[%d] -> " RESET, i);

        HashNode* current =
            hash->table[i];

        while(current != NULL) {

            printf(GREEN
                   "IP:%s(P%d)"
                   RESET
                   " -> ",
                   current->ip,
                   current->packetId);

            current = current->next;
        }

        printf("NULL\n");
    }

    printf(YELLOW
           "\nTotal de colisoes: %d\n"
           RESET,
           hash->collisions);
}

void freeHash(HashTable* hash) {

    for(int i = 0; i < TABLE_SIZE; i++) {

        HashNode* current =
            hash->table[i];

        while(current != NULL) {

            HashNode* temp = current;

            current = current->next;

            free(temp);
        }
    }
}
