#include <stdio.h>
#include "common.h"

static pnode_t queue[100];
static int head = 0, tail = 0;
pnode_t dequeue(void)
{
    return queue[head++];
}
void enqueue(pnode_t t)
{
    queue[tail++] = t;
}
int isempty(void)
{
    return head == tail;
}
