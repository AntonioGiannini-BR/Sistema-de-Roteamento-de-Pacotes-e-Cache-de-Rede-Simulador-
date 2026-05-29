/*
 * Interface da lista duplamente encadeada usada para registrar o histórico de pacotes processados.
 */

// Evita que este cabeçalho seja incluído mais de uma vez durante a compilação.
#ifndef HISTORY_H
#define HISTORY_H

#include "packet.h"

// Define a estrutura de dados principal usada por este módulo.
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

// Protótipos das funções disponíveis para outros arquivos do projeto.
void initHistory(HistoryList* list);
void addHistory(HistoryList* list,
                Packet packet);

void showHistory(HistoryList* list);
void freeHistory(HistoryList* list);

#endif
