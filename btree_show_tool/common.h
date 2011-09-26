#ifndef COMMON_H_
#define COMMON_H_ 
typedef struct node node_t, * pnode_t;
struct node{
	int item;
    int x,y;
	pnode_t l, r;
};
pnode_t dequeue(void);
void enqueue(pnode_t t);
int isempty(void);
#endif
