#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#define QUEUE_NUM   8
#define QUEUE_MAX   256

#if !defined(QUEUE_LIST_SIZE)
#define QUEUE_LIST_SIZE (sizeof(char)*QUEUE_NUM)
#endif

typedef struct queue_t{
    unsigned short head;
    unsigned short tail;
    char *queue;
    unsigned short size;
}queue_t;


typedef enum QUEUE_ERR{
    QUEUE_ERR_OK = 0,   //OK
    QUEUE_ERR_MAXLEN,   //OVER MAX SIZE
    QUEUE_ERR_OVERLEN,  //OVER LEFT SIZE
    QUEUE_ERR_FULL,     //FULL
    QUEUE_ERR_EMPTY,    //EMPTY
    QUEUE_ERR_MEM,
    QUEUE_ERR_DATA,
}QUEUE_ERR_e;

#endif
