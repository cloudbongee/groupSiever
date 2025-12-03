
#ifndef _PQSIEVE_H_
#define _PQSIEVE_H_

#include<math.h>
#include "eratosthenes.h"

#ifdef LATEX_OUT
#define PRINT(...) printf("$\\vert G\\vert = %d = %d\\cdot%d \\text{ has a unique }%d\\text{-sylow group}$\n", ##__VA_ARGS__)
#else
#define PRINT(...) printf("%d,%d,%d,%d\n", ##__VA_ARGS__)
#endif


void freeIntList(struct intList *l);

int pqFormGroups(int n);

#endif
