
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "packet.h"

typedef struct QueueNode {

    Packet packet;
    struct QueueNode* next;

} QueueNode;

typedef struct {

    QueueNode* front;
    int totalPackets;
    int priorityPackets;

} PriorityQueue;

void initQueue(PriorityQueue* queue);
void enqueue(PriorityQueue* queue, Packet packet);
int dequeue(PriorityQueue* queue, Packet* packet);
void freeQueue(PriorityQueue* queue);

#endif
