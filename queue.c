#include "queue.h"

static char queue[QUEUE_LIST_SIZE][QUEUE_MAX]; // queuedata
static queue_t queue_fifo[QUEUE_LIST_SIZE];    // queuelist
static unsigned int queue_mask[2];             // MASK

// static void QUEUE_PRI_LOG(queue_t *queue)
// {
//     printf("queue id is [%#x]\n", queue_mask);
//     printf("queue size is [%d]\n", queue->size);
// }

/**
 * @brief 注册一个队列
 * @param null
 * @return 队列指针
 */
queue_t *queue_init(void)
{
    unsigned char id = 0;
    queue_t *p_queue = NULL;
    char flag = 0;
    unsigned int queue_mask_s = 0x0;
    if (!(~queue_mask[0] | 0x0))
    {
        queue_mask_s = queue_mask[1];
        flag = 0;
    }
    else
    {
        queue_mask_s = queue_mask[0];
        flag = 1;
    }
    for (id = 0; id < 32; id++)
    {
        if (!((queue_mask_s >> id) & 1))
            break;
    }
    printf("queue_mask_s = %#x, id = %d\n", queue_mask_s, id);

    if (flag)
        queue_mask[0] |= (1 << id);
    else
        queue_mask[1] |= (1 << id);
    p_queue = &queue_fifo[id];
    p_queue->queue = queue[id];
    p_queue->head = 0;
    p_queue->tail = 0;
    p_queue->size = 0;
    // QUEUE_PRI_LOG(p_queue);
    return p_queue;
}

/**
 * @brief 向队列存储数据
 * @param queue 队列
 * @param buff 存储数据
 * @param len 数据长度
 */
QUEUE_ERR_e queue_push(queue_t *queue, char *buff, int len)
{
    if (!queue || !queue->queue)
        return QUEUE_ERR_MEM;
    if (len > QUEUE_MAX - 1)
        return QUEUE_ERR_MAXLEN;
    if (queue->head != queue->tail)
    {
        if (len > (QUEUE_MAX - queue->size - 1))
            return QUEUE_ERR_FULL;
    }
    int i = 0;
    for (i = 0; i < len; i++)
    {
        queue->tail = (queue->tail + 1) % QUEUE_MAX;
        queue->queue[queue->tail] = buff[i];
    }
    queue->size += len;
    return QUEUE_ERR_OK;
}

/**
 * @brief 从队列中取数据
 * @param queue 队列
 * @param buff 存储取出数据指针
 * @param len 要取出数据长度
 * @return 实际返回长度
 */
unsigned int queue_pop(queue_t *queue, char *buff, int len)
{
    if (!queue || !queue->queue)
        return QUEUE_ERR_OK;
    if (queue->head == queue->tail)
        return QUEUE_ERR_OK;
    int pop_len = (len > queue->size) ? queue->size : len;
    for (int i = 0; i < pop_len; i++)
    {
        queue->head = (queue->head + 1) % QUEUE_MAX;
        buff[i] = queue->queue[queue->head];
    }
    queue->size -= pop_len;
    return pop_len;
}

/**
 * @brief 注销队列
 * @param queue_list    队列
 */
QUEUE_ERR_e queue_uninit(queue_t *queue_list)
{
    unsigned char i = 0;
    unsigned char flag = 0x0;
    if (!queue_list || !queue_list->queue)
        return QUEUE_ERR_MEM;
    if (queue_list->size != 0)
        return QUEUE_ERR_DATA;

    while (i < 32)
    {
        if (queue_list->queue == queue[i])
        {
            queue_mask[0] &= ~(1 << i);
            flag = 1;
            break;
        }
        i++;
    }
    if (!flag)
    {
        i = 0;
        while (i < 32)
        {
            if (queue_list->queue == queue[i])
            {
                queue_mask[1] &= ~(1 << i);
                flag = 1;
                break;
            }
            i++;
        }
    }
    if(!flag)
        return QUEUE_ERR_MEM;

    queue_list->queue = NULL;

    return QUEUE_ERR_OK;
}

int main()
{
    /* 测试 */
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
    queue_t *queue11 = queue_init();
    queue_t *queue12 = queue_init();
    queue_t *queue13 = queue_init();
    queue_t *queue14 = queue_init();
    queue_t *queue15 = queue_init();
    queue_t *queue16 = queue_init();
    queue_t *queue17 = queue_init();
    queue_t *queue18 = queue_init();
    queue_t *queue19 = queue_init();
    queue_t *queue20 = queue_init();
    queue_t *queue21 = queue_init();
    queue_t *queue22 = queue_init();
    queue_t *queue23 = queue_init();
    queue_t *queue24 = queue_init();
    queue_t *queue25 = queue_init();
    queue_t *queue26 = queue_init();
    queue_t *queue27 = queue_init();
    queue_t *queue28 = queue_init();
    queue_t *queue29 = queue_init();
    queue_t *queue30 = queue_init();
    queue_t *queue31 = queue_init();
    queue_t *queue32 = queue_init();
    queue_t *queue33 = queue_init();
    queue_t *queue34 = queue_init();
    queue_t *queue35 = queue_init();
    queue_t *queue36 = queue_init();
    // char buff1[64] = "hello world";
    // char buff2[32] = "123456789";
    // char buff_pop1[128] = {0};
    // char buff_pop2[128] = {0};
    // queue_push(queue9, buff1, sizeof(buff1));
    // queue_push(queue10, buff2, sizeof(buff2));
    // printf("queue9 size [%d]\n", queue9->size);
    // printf("queue10 size [%d]\n", queue10->size);

    // queue_pop(queue9, buff_pop1, 5);
    // queue_pop(queue10, buff_pop2, 6);
    // printf("buff_pop1 is [%s]\n", buff_pop1);
    // printf("buff_pop2 is [%s]\n", buff_pop2);
    // for (int i = 0; i < sizeof(buff_pop1); i++)
    //     buff_pop1[i] = 0;
    // for (int i = 0; i < sizeof(buff_pop2); i++)
    //     buff_pop2[i] = 0;
    // queue_pop(queue9, buff_pop1, sizeof(buff_pop1));
    // queue_pop(queue10, buff_pop2, sizeof(buff_pop2));
    // printf("buff_pop1 is [%s]\n", buff_pop1);
    // printf("buff_pop2 is [%s]\n", buff_pop2);
    printf("queue_mask[0] = %#x, queue_mask[1] = %#x\n", queue_mask[0], queue_mask[1]);
    // queue_uninit(queue34);
    queue_uninit(queue31);
    printf("queue_mask[0] = %#x, queue_mask[1] = %#x\n", queue_mask[0], queue_mask[1]);
    queue_t *queue37 = queue_init();
    printf("queue_mask[0] = %#x, queue_mask[1] = %#x\n", queue_mask[0], queue_mask[1]);
    return 0;
}
