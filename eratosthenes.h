#ifndef _ERATOSTHENES_H_
#define _ERATOSTHENES_H_

#include<stdio.h>
#include<stdlib.h>

struct intList
{
        int len;
        int *list;
};

struct intList *primeSieve(int n);

void freeIntList(struct intList *l);

#endif
