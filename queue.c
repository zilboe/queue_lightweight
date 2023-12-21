#include "queue.h"

static char queue[QUEUE_LIST_SIZE][QUEUE_MAX];

static queue_t queue_fifo[QUEUE_LIST_SIZE];

static char queue_mask = 0;

static queue_t *queue_init(void)
{
    char id = 0;
    while(id<QUEUE_LIST_SIZE)
    {
        if(!((queue_mask>>id)&1))
            break;
        id++;
    }
    if(QUEUE_LIST_SIZE == id)
    {
        printf("there is no queue could be used");
        return NULL;
    }
    queue_mask &= (1<<id);
    queue_t *p_queue = &queue_fifo[id];
    p_queue->queue = queue[id];
    p_queue->head = 0;
    p_queue->tail = 0;
    p_queue->size = 0;
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

static unsigned int queue_pop(queue_t *queue, char *buff, int len)
{
    if(queue->head == queue->tail)
        return QUEUE_ERR_OK;
    int pop_len = (len>queue->size)?queue->size:len;
    for(int i=0; i<pop_len; i++)
    {
        queue->head = (queue->head+1)%QUEUE_MAX;
        buff[i] = queue->queue[queue->head];
    }
    queue->size -= pop_len;
    return pop_len;
}

static unsigned char queeu_uninit(queue_t *queue)
{
    if(!queue)
        return QUEUE_ERR_MEM;
    
}

int main()
{
    /* test */
    queue_t *queue1 = queue_init();
    queue_t *queue2 = queue_init();
    queue_t *queue3 = queue_init();
    queue_t *queue4 = queue_init();
    queue_t *queue5 = queue_init();
    queue_t *queue6 = queue_init();
    queue_t *queue7 = queue_init();
    queue_t *queue8 = queue_init();
    queue_t *queue9 = queue_init();
    queue_t *queue10 = queue_init();
    char buff1[64] = "hello world";
    char buff2[64] = "123456789";
    char buff_pop1[128];
    char buff_pop2[128];
    queue_push(queue1, buff1, sizeof(buff1));
    //printf("%d\n",queue->size);
    queue_push(queue1, buff2, sizeof(buff2));

    queue_pop(queue1, buff_pop1, 64);
    printf("%s\n", buff_pop1);
    queue_pop(queue1, buff_pop2, 64);
    printf("%s\n", buff_pop2);

    return 0;
}
