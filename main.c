
#include "main.h"



/*
 * primeSieve
 *
 * Sieves the primes [2 : n] using the
 * erasthotenes prime sieve algorithm.
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




/*
 *
 *
 * pqFormGroups function
 *
 * finds the valid [G:N(p)] counting the p syllow groups of G
 * when |G| = pq where p and q are prime and not equal
 *
 * Return the count of nonSimple groups 
 */
int pqFormGroups(int n)
{
	// since the smallest pq is going to be 2q < n, then
	// we have to sieve the primes at most [n/2] 
	int m = ceil(n/2);

	struct intList *primes = primeSieve(m);

	int countEvaluated = 0;
	int countNonSimple = 0;
	int * list = primes->list;
	for(int i = 0; i < primes->len; i++)
	{
		
		int p;
		// pq starts as p(1)
		int pq = p = list[i];


		int start = 0;
		/*
		 * all of the pq combinations starting p(2)
		 * will most certainly include p^2
		 */
		for(int j = start; pq <= n && j < primes->len; j++)
		{
			int simple = 1;

			int q = list[j];
			
			// printf("q: %d\n", q);		
			pq = p * q;
			if(p != q)
			{
				
				/* 
				 * if the size of the group is pq
				 * then there we have two things 
				 * we need to lookout for
				 *
				 * p-sylow groups
				 * q-sylow groups
				 *
				 *
				 * n | q and n == 1 (mod p)
				 * n | p and n == 1 (mod q)
				 *
				 */

				if(p%q != 1)
				{
					simple = 0;
					PRINT(pq, p,q,q);
				}

				if(q%p != 1)
				{
					simple = 0;
					PRINT(pq, p,q,p);
				}

				if(simple == 0)
				{
					countNonSimple++;
				}

				countEvaluated++;
			}

		}
		

		 

		// start is used to declare the initialization of the pq loop.
		// It scans the same array as a grid upper triangularly
		// in order to avoid the repetitions gathered from commutation
		start++;
	}
		
	//
	// free the sieved primes
	freeIntList(primes);
	
	#ifdef LATEX_OUT
	printf("There are %d non-simple groups of the form $pq$ out of %d evaluated\\\\\n",countNonSimple, countEvaluated);
	#else
	printf("%d/%d\n", countNonSimple, countEvaluated);
	#endif	

	return countNonSimple;
}


int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "Usage: pqPrimeSieve [int]\n");
		return 1;
	}

	int n = atoi(argv[1]);

	if(n <= 1)
	{
		fprintf(stderr, "Wrong integer %d entered\n", n);
	}

	pqFormGroups(n);
	

	return 0;
}
