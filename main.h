#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#ifdef LATEX_OUT
#define PRINT(...) printf("$\\vert G\\vert = %d = %d\\cdot%d \\text{ has a unique }%d\\text{-sylow group}$\n", ##__VA_ARGS__)
#else
#define PRINT(...) printf("%d,%d,%d,%d\n", ##__VA_ARGS__)
#endif

struct intList
{
        int len;
        int *list;
};

struct intList *primeSieve(int n);

void freeIntList(struct intList *l);

int pqFormGroups(int n);

#endif
