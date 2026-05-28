
#include <stdio.h>
#include <stdlib.h>

#include "../include/history.h"
#include "../include/colors.h"

void initHistory(HistoryList* list) {

    list->head = NULL;
    list->tail = NULL;
    list->totalProcessed = 0;
}

void addHistory(HistoryList* list,
                Packet packet) {

    HistoryNode* newNode =
        (HistoryNode*) malloc(sizeof(HistoryNode));

    newNode->packet = packet;

    newNode->next = NULL;
    newNode->prev = list->tail;

    if(list->tail != NULL) {

        list->tail->next = newNode;
    }

    list->tail = newNode;

    if(list->head == NULL) {

        list->head = newNode;
    }

    list->totalProcessed++;
}

void showHistory(HistoryList* list) {

    printf(MAGENTA
           "\n===================================\n");
    printf("    HISTORICO DE PROCESSAMENTO\n");
    printf("===================================\n"
           RESET);

    HistoryNode* current = list->head;

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

void freeHistory(HistoryList* list) {

    HistoryNode* current = list->head;

    while(current != NULL) {

        HistoryNode* temp = current;

        current = current->next;

        free(temp);
    }
}
