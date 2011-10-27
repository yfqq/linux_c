//main.c
#include <stdio.h>
extern int add(int a, int b);
int main(void)
{
    int result = 2;
    result = add(1, 3);
    printf("result = %d\n", result);
    return 0;
}

