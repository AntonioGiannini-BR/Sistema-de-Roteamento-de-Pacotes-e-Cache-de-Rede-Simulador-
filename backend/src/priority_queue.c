
#include <stdio.h>
#include <stdlib.h>

#include "../include/priority_queue.h"

void initQueue(PriorityQueue* queue) {

    queue->front = NULL;
    queue->totalPackets = 0;
    queue->priorityPackets = 0;
}

void enqueue(PriorityQueue* queue, Packet packet) {

    QueueNode* newNode =
        (QueueNode*) malloc(sizeof(QueueNode));

    newNode->packet = packet;
    newNode->next = NULL;

    queue->totalPackets++;

    if(packet.priority == 1)
        queue->priorityPackets++;

    if(queue->front == NULL ||
       packet.priority >
       queue->front->packet.priority) {

        newNode->next = queue->front;

        queue->front = newNode;

        return;
    }

    QueueNode* current = queue->front;

    while(current->next != NULL &&
          current->next->packet.priority >=
          packet.priority) {

        current = current->next;
    }

    newNode->next = current->next;

    current->next = newNode;
}

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

void freeQueue(PriorityQueue* queue) {

    QueueNode* current = queue->front;

    while(current != NULL) {

        QueueNode* temp = current;

        current = current->next;

        free(temp);
    }
}
