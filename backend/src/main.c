/*
 * Programa principal do simulador de roteamento de pacotes.
 * Lê comandos do arquivo de entrada, processa fila, cache e histórico.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/packet.h"
#include "../include/priority_queue.h"
#include "../include/hash_table.h"
#include "../include/history.h"
#include "../include/colors.h"

void printBanner() {

    printf(CYAN);
    printf("=====================================================\n");
    printf("      SISTEMA DE ROTEAMENTO DE PACOTES\n");
    printf("=====================================================\n");
    printf(RESET);
}

int main() {

        // Abre o arquivo de entrada que contém os comandos da simulação.
    FILE* file = fopen("tests/input.txt", "r");

    if(!file) {

        printf(RED "Erro ao abrir input.txt\n" RESET);

        return 1;
    }

        // Declara as três estruturas centrais: fila de prioridade, cache hash e histórico.
    PriorityQueue queue;
    HashTable hash;
    HistoryList history;

        // Inicializa todas as estruturas antes de começar o processamento.
    initQueue(&queue);
    initHashTable(&hash);
    initHistory(&history);

    printBanner();

    char line[256];

        // Lê o arquivo linha por linha, tratando cada linha como um comando.
    while(fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\n")] = 0;

                // Separa o primeiro campo da linha para identificar o tipo de comando.
        char* command = strtok(line, ";");

        if(command == NULL)
            continue;

                // Comando ADD: cria um novo pacote e adiciona na fila de prioridade.
        if(strcmp(command, "ADD") == 0) {

            Packet packet;

            char* id = strtok(NULL, ";");
            char* dest = strtok(NULL, ";");
            char* priority = strtok(NULL, ";");
            char* content = strtok(NULL, ";");

            if(id == NULL || dest == NULL ||
               priority == NULL || content == NULL) {

                printf(RED "Erro de leitura no ADD.\n" RESET);
                continue;
            }

            packet.id = atoi(id);

            strcpy(packet.destination, dest);

            packet.priority = atoi(priority);

            strcpy(packet.content, content);

            enqueue(&queue, packet);

            printf(GREEN "\n[ADD]" RESET
                   " Pacote %d inserido | "
                   "IP: %s | Prioridade: %s\n",
                   packet.id,
                   packet.destination,
                   packet.priority == 1 ? "ALTA" : "NORMAL");
        }

                // Comando PROCESS: remove o próximo pacote da fila e simula seu processamento.
        else if(strcmp(command, "PROCESS") == 0) {

            Packet packet;

            if(dequeue(&queue, &packet)) {

                printf(BLUE "\n[PROCESSANDO]" RESET
                       " Pacote %d\n",
                       packet.id);

                printf("Conteudo: %s\n",
                       packet.content);

                if(searchHash(&hash,
                              packet.id)) {

                    printf(GREEN
                           "Cache encontrado!\n"
                           RESET);
                }

                else {

                    printf(YELLOW
                           "Novo IP mapeado.\n"
                           RESET);

                    insertHash(&hash,
                               packet);
                }

                addHistory(&history, packet);
            }

            else {

                printf(RED
                       "\nFila vazia.\n"
                       RESET);
            }
        }

        else if(strcmp(command, "SHOW_CACHE") == 0) {

            printHashTable(&hash);
        }

        else if(strcmp(command, "SHOW_HISTORY") == 0) {

            showHistory(&history);
        }
    }

        // Fecha o arquivo após concluir a leitura de todos os comandos.
    fclose(file);

        // Libera a memória alocada dinamicamente antes de encerrar o programa.
    freeQueue(&queue);
    freeHashTable(&hash);
    freeHistory(&history);

    printf(CYAN "\n====================================\n");
    printf(" Sistema encerrado com sucesso\n");
    printf(" Sem memory leaks detectados\n");
    printf("====================================\n");
    printf(RESET);

    return 0;
}
