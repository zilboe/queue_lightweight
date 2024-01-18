#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#define QUEUE_NUM   64
#define QUEUE_MAX   256

#if !defined(QUEUE_LIST_SIZE)
#define QUEUE_LIST_SIZE (sizeof(char)*QUEUE_NUM)
#else 
#define QUEUE_LIST_SIZE 8
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

/**
 * @brief 向队列存储数据
 * @param queue 队列
 * @param buff 存储数据
 * @param len 数据长度
 */
QUEUE_ERR_e queue_push(queue_t *queue, char *buff, int len);
/**
 * @brief 从队列中取数据
 * @param queue 队列
 * @param buff 存储取出数据指针
 * @param len 取出数据长度
 */
unsigned int queue_pop(queue_t *queue, char *buff, int len);

/**
 * @brief 注销队列
 * @param queue_list    队列
 */
QUEUE_ERR_e queue_uninit(queue_t *queue_list);

#endif
