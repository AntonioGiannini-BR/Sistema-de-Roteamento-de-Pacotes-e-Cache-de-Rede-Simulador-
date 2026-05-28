
#ifndef PACKET_H
#define PACKET_H

typedef struct Packet {

    int id;
    char destination[50];
    int priority;
    char content[100];

} Packet;

#endif
