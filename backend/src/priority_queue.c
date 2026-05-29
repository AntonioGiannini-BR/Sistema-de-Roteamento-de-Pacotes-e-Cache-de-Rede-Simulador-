/*
 * Implementação da fila de prioridade.
 * Pacotes com prioridade maior são posicionados antes dos demais.
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/priority_queue.h"

// Inicializa a fila vazia e zera os contadores de pacotes.
void initQueue(PriorityQueue* queue) {

    queue->front = NULL;
    queue->totalPackets = 0;
    queue->priorityPackets = 0;
}

// Insere um pacote mantendo a ordem de prioridade da fila.
void enqueue(PriorityQueue* queue, Packet packet) {

        // Aloca um novo nó para armazenar o pacote recebido.
    QueueNode* newNode =
        (QueueNode*) malloc(sizeof(QueueNode));

    newNode->packet = packet;
    newNode->next = NULL;

    queue->totalPackets++;

        // Conta separadamente os pacotes marcados como prioridade alta.
    if(packet.priority == 1)
        queue->priorityPackets++;

        // Caso a fila esteja vazia ou o novo pacote tenha prioridade maior, ele vira o primeiro.
    if(queue->front == NULL ||
       packet.priority >
       queue->front->packet.priority) {

        newNode->next = queue->front;

        queue->front = newNode;

        return;
    }

    QueueNode* current = queue->front;

        // Percorre a fila até encontrar a posição correta pela prioridade.
    while(current->next != NULL &&
          current->next->packet.priority >=
          packet.priority) {

        current = current->next;
    }

    newNode->next = current->next;

    current->next = newNode;
}

// Remove o pacote da frente da fila e o devolve por referência.
int dequeue(PriorityQueue* queue,
            Packet* packet) {

    if(queue->front == NULL)
        return 0;

    QueueNode* temp = queue->front;

    *packet = temp->packet;

    queue->front = temp->next;

    free(temp);

    return 1;
}

// Libera todos os nós restantes da fila.
void freeQueue(PriorityQueue* queue) {

    QueueNode* current = queue->front;

    while(current != NULL) {

        QueueNode* temp = current;

        current = current->next;

        free(temp);
    }
}
