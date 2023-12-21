#include <stdio.h>
#define QUEUE_MAX   256
char queue[QUEUE_MAX];
typedef struct queue_t{
    int head;
    int tail;
    char *queue;
    int size;
}queue_t;

queue_t queue_fifo;

enum QUEUE_ERR{
    QUEUE_ERR_OK = 0,   //OK
    QUEUE_ERR_MAXLEN,   //超过存储空间
    QUEUE_ERR_OVERLEN,  //超过剩余空间
    QUEUE_ERR_FULL,     //队列满
    QUEUE_ERR_EMPTY,    //队列空
};

static queue_t *queue_init(void)
{
    queue_t *p_queue = &queue_fifo;
    p_queue->head = 0;
    p_queue->tail = 0;
    p_queue->size = 0;
    p_queue->queue = queue;
    return p_queue;
}

static unsigned char queue_push(queue_t *queue, char *buff, int len)
{
    if(len > QUEUE_MAX-1)
        return QUEUE_ERR_MAXLEN;
    if(queue->head!=queue->tail)
    {
        if(len > (QUEUE_MAX-queue->size-1))
            return QUEUE_ERR_FULL;
    }
    int i=0;
    for(i=0; i<len; i++)
    {
        queue->tail = (queue->tail+1)%QUEUE_MAX;
        queue->queue[queue->tail] = buff[i];
    }
    queue->size += len;
    return QUEUE_ERR_OK;
}

static unsigned char queue_pop(queue_t *queue, char *buff, int len)
{
    if(queue->head == queue->tail)
        return QUEUE_ERR_EMPTY;
    int pop_len = (len>queue->size)?queue->size:len;
    for(int i=0; i<pop_len; i++)
    {
        queue->head = (queue->head+1)%QUEUE_MAX;
        buff[i] = queue->queue[queue->head];
    }
    queue->size -= pop_len;
    return QUEUE_ERR_OK;
}

int main()
{
    queue_t *queue = queue_init();
    char buff1[64] = "hello world";
    char buff2[64] = "123456789";
    char buff_pop1[128];
    char buff_pop2[128];
    queue_push(queue, buff1, sizeof(buff1));
    //printf("%d\n",queue->size);
    queue_push(queue, buff2, sizeof(buff2));

    queue_pop(queue, buff_pop1, 64);
    printf("%s\n", buff_pop1);
    queue_pop(queue, buff_pop2, 64);
    printf("%s\n", buff_pop2);

    return 0;
}
