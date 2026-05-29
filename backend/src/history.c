/*
 * Implementação do histórico de processamento usando lista duplamente encadeada.
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/history.h"
#include "../include/colors.h"

// Prepara a lista de histórico vazia, sem início, sem fim e sem pacotes processados.
void initHistory(HistoryList* list) {

    list->head = NULL;
    list->tail = NULL;
    list->totalProcessed = 0;
}

// Adiciona um pacote processado ao final da lista de histórico.
void addHistory(HistoryList* list,
                Packet packet) {

        // Cria um novo nó para armazenar o pacote no histórico.
    HistoryNode* newNode =
        (HistoryNode*) malloc(sizeof(HistoryNode));

    newNode->packet = packet;

    newNode->next = NULL;
    newNode->prev = list->tail;

        // Se já existe último elemento, conecta o antigo final ao novo nó.
    if(list->tail != NULL) {

        list->tail->next = newNode;
    }

    list->tail = newNode;

    if(list->head == NULL) {

        list->head = newNode;
    }

    list->totalProcessed++;
}

// Exibe todos os pacotes registrados no histórico de processamento.
void showHistory(HistoryList* list) {

    printf(MAGENTA
           "\n===================================\n");
    printf("    HISTORICO DE PROCESSAMENTO\n");
    printf("===================================\n"
           RESET);

    HistoryNode* current = list->head;

        // Percorre a lista do início ao fim imprimindo cada pacote processado.
    while(current != NULL) {

        printf(GREEN
               "[ID:%d | IP:%s]"
               RESET
               " -> ",
               current->packet.id,
               current->packet.destination);

        current = current->next;
    }

    printf("FIM\n");

    printf(YELLOW
           "\nPacotes processados: %d\n"
           RESET,
           list->totalProcessed);
}

// Libera todos os nós da lista de histórico.
void freeHistory(HistoryList* list) {

    HistoryNode* current = list->head;

    while(current != NULL) {

        HistoryNode* temp = current;

        current = current->next;

        free(temp);
    }
}
