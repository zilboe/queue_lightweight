#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#define QUEUE_LIST_SIZE sizeof(char)

#define QUEUE_MAX   256

typedef struct queue_t{
    unsigned short head;
    unsigned short tail;
    char *queue;
    unsigned short size;
}queue_t;

#define QUEUE_LIST_ID_MASK 0x7fU

enum QUEUE_ERR{
    QUEUE_ERR_OK = 0,   //OK
    QUEUE_ERR_MAXLEN,   //OVER MAX SIZE
    QUEUE_ERR_OVERLEN,  //OVER LEFT SIZE
    QUEUE_ERR_FULL,     //FULL
    QUEUE_ERR_EMPTY,    //EMPTY
    QUEUE_ERR_MEM,
};

#endif
