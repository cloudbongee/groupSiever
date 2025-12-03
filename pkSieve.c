
#include "pkSieve.h"


int pkSieve(int n)
{
	int m = floor(sqrt(n));
	struct intList *primes = primeSieve(m);

	int count = 0;
	for(int i = 0; i < primes->len; i++)
	{
		int p = primes->list[i];
		for(int u = p*p; u <= n; u*=p)
		{
			printf("%d\n", u);
			count++;
		}
	}
	
	printf("With a count of %d non-simple groups\n", count);
	freeIntList(primes);

	return 0;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	
	return pkSieve(n);	
}
