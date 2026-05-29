/*
 * Interface da fila de prioridade responsável por organizar pacotes conforme sua prioridade.
 */

// Evita que este cabeçalho seja incluído mais de uma vez durante a compilação.
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "packet.h"

// Define a estrutura de dados principal usada por este módulo.
typedef struct QueueNode {

    Packet packet;
    struct QueueNode* next;

} QueueNode;

typedef struct {

    QueueNode* front;
    int totalPackets;
    int priorityPackets;

} PriorityQueue;

// Protótipos das funções disponíveis para outros arquivos do projeto.
void initQueue(PriorityQueue* queue);
void enqueue(PriorityQueue* queue, Packet packet);
int dequeue(PriorityQueue* queue, Packet* packet);
void freeQueue(PriorityQueue* queue);

#endif
