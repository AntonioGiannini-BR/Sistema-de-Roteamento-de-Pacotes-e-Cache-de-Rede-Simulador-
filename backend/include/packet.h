/*
 * Definição da estrutura Packet, que representa cada pacote trafegando no simulador.
 */

// Evita que este cabeçalho seja incluído mais de uma vez durante a compilação.
#ifndef PACKET_H
#define PACKET_H

// Define a estrutura de dados principal usada por este módulo.
typedef struct Packet {

    int id;
    char destination[50];
    int priority;
    char content[100];

} Packet;

#endif
