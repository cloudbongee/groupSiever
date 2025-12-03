
#include "pqSieve.h"



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
		
		int p = list[i];
		/*
		 * all of the pq combinations starting p(2)
		 * will most certainly include p^2
		 */ 
		

		for(int j = i+1; p * list[j] <= n && j < primes->len; ++j)
		{

			int q = list[j];
			int pq = p * q;

			int simple = 1;
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
