
#include "eratosthenes.h" 

/*
 * primeSieve
 *
 * Sieves the primes [2 : n] using the
 * eratosthenes prime sieve algorithm.
 *
 * Note:
 * Doing Rabin-miller would be overkill here
 */
struct intList *primeSieve(int n)
{


	int *sieve = calloc(n+1,sizeof(int));
	int p = 2;
	while((p * p) <= n)
	{
		if(sieve[p] == 0)
		{
			for(int i = p * p; i < (n + 1); i+=p)
			{
				sieve[i] = 1;
			}
		}
		p+=1;
	}

	
	// count the primes
	int countPrimes = 0;
	for(p = 2; p < (n+1); p++)
	{
		if(sieve[p] == 0)
		{
			countPrimes++;
		}
	}

	
	int *list = malloc(sizeof(int) * (countPrimes));
	if(list == NULL)
	{
		fprintf(stderr, "Memory error\n");
		exit(1);
	}	
	int index = 0;
	for(p = 2; p < (n+1); p++)
	{
		if(sieve[p] == 0)
		{
			list[index] = p;
			index++;	
		}
	}

	free(sieve);
	
	struct intList *result = malloc(sizeof(struct intList));
	if(result == NULL)
	{
		fprintf(stderr, "Memory error\n");
		exit(1);
	}


	result->len = countPrimes;
	result->list = list;
	
	return result;

}


void freeIntList(struct intList *l)
{
	free(l->list);
	free(l);
}
