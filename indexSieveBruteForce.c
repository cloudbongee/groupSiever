
#include "indexSieveBruteForce.h"

int fact(int n)
{
	if(n == 1)
	{
		return n;
	}

	return n * fact(n-1);
}

void indexSieveBruteForce(int G)
{
	#ifndef SUPRESS_VERBOSE
	printf("Brute force of the Group-subgroup relations\nWhere for 'G, H', a group of size G will have a nontrivial normal subgroup within H\nif there is a subgroup of that size\n");
	#endif
	for(int i = 2; i < G; i++)
	{
		// the size of the subgroup doesn't violate lagrange's theorem
		if(G%i == 0)
		{
			if((fact((int)(G/i))%G != 0))
			{
				printf("%d, %d\n", G, i);
			}	
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		fprintf(stderr ,"Usage: indexSieve [G-size]\n");
		return 1;
	}

	int G = atoi(argv[1]);


	if(G <= 2)
	{
		fprintf(stderr, "Incorrect arguments, too small \n");
		return 1;
	}

	indexSieveBruteForce(G);
	
	return 0;
}
