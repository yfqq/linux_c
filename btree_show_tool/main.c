#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define SIZE 20
int bg[SIZE][SIZE];
int head = 0, tail = 0;
pnode_t create(int item)
{
	pnode_t p = malloc(sizeof(node_t));
	p->item = item;
    p->x = p->y = 0;
	p->l = p->r = NULL;
	return p;
}
int find(char *str)
{
	if(str[0] != '(')
		return -1;
	int flag = 1, ret = 1;
	while(flag != 0){
		if(str[ret] == '(')
			flag++;
		if(str[ret] == ')')
			flag--;
		ret++;
	}
	return ret;
}
pnode_t create_tree(char * str, int len)
{
        pnode_t p = NULL;
	char *strl, *strr;
	int numl, numr, i;
        int item = 0;
	if(len <= 2)
		return NULL;
	for (i = 0; i < len; i++) 
	{
	        printf("%c", str[i]);
	}
        printf("\n");
	if(str[0] == '(' && str[len - 1] == ')'){
		strl = str + 1;
		while(*strl != '('){
                        item = item*10 + (*strl - '0');
                        strl++;
                }
                printf("item = %d\n", item);
                p = create(item);
		numl = find(strl);
		p->l = create_tree(strl, numl);
		strr = strl + numl;
		numr = find(strr);
		p->r = create_tree(strr, numr);
	}
	return p;
}
int in_trave(pnode_t t, int x, int y)
{
        if(!t)
                return x;
        x = in_trave(t->l, x, y + 1);
        x = x + 1;
        t->x = x - 1;
        t->y = y;
        printf("(%d %d):%d ", x - 1, y, t->item);
        x = in_trave(t->r, x, y + 1);
        return x;
}
void print_bg(pnode_t t)
{
    int i, j;
        for (j = 0; j < SIZE; j++) 
        {
                for (i = 0; i < SIZE ; i++) 
                {
                        bg[j][i] = -1;
                }
        }
}
void print_btline(char * line)
{
    int i;
    for (i = 0; i < 20; i++) 
    {
        if(line[i] == '\0')
            break;
            //printf("**");
        if(line[i] == ' ')
            printf("  ");
        else if(line[i] == '-')
            printf("--");
    }
    printf("\n");
}
void print_line(pnode_t t, pnode_t pre)
{
    int i, count;
    if(t->y == pre->y)
        count = t->x - pre->x - 1;
    else
        count = t->x;
    if(t->y == 0)
        count = t->x;
    //printf("\r");
    if(0){
        
        for (i = 0; i < count; i++) 
        {
            printf("  ");
        }
        printf("||");
        printf("\n");
    }
    for (i = 0; i < count; i++) 
    {
        printf("  ");
    }
    printf("%02d", t->item);
    if( 0)
    {
        
        for (i = 0; i < count; i++) 
        {
            printf("  ");
        }
        printf("||");
        printf("\n");
    }
}
void level_travel(pnode_t t)
{
    int line = 0, i;
    char btline[200];
    pnode_t pre;
    memset(btline, ' ', 200);
    enqueue(t);
    while(!isempty()){
        pre = t;
        t = dequeue();
        //printf("(%d %d):%d ", t->x, t->y, t->item);
        if(line != t->y){
            line = t->y;
            printf("\n");
            if(pre->r)
                btline[pre->r->x + 1] = '\0';
            else
                btline[pre->x + 1] = '\0';
            print_btline(btline);
            memset(btline, ' ', 200);
        }
        //else
        {
            if(t->l)
                for(i = t->l->x; i <= t->x; i++ )
                    btline[i] = '-';
            if(t->r)
                for(i = t->x; i <= t->r->x; i++ )
                    btline[i] = '-';
        }
        print_line(t, pre);
        if(t->l)
            enqueue(t->l);
        if(t->r)
            enqueue(t->r);
    }
}
int main(int argc, const char *argv[])
{
	char str[200] = "(83(77(15()(35()()))())(86()(93()())))";
        
        //char str[] = "(15()(35()()))";
	int len ; 
        fgets(str, 200, stdin);
        len = strlen(str);
        pnode_t root;
	root = create_tree(str, len);
        in_trave(root, 0, 0);
        printf("\n");
        level_travel(root);
        printf("\n");
	return 0;
}
