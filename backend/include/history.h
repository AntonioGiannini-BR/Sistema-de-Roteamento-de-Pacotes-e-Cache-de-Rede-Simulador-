
#ifndef HISTORY_H
#define HISTORY_H

#include "packet.h"

typedef struct HistoryNode {

    Packet packet;

    struct HistoryNode* prev;
    struct HistoryNode* next;

} HistoryNode;

typedef struct {

    HistoryNode* head;
    HistoryNode* tail;

    int totalProcessed;

} HistoryList;

void initHistory(HistoryList* list);
void addHistory(HistoryList* list,
                Packet packet);

void showHistory(HistoryList* list);
void freeHistory(HistoryList* list);

#endif
