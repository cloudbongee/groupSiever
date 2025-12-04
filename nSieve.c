
#include "nSieve.h"

// the nSiever is a generalized Sylow test for simplicity
//
// It tests simplicity for groups of order lesser than n, starting from 2 
int nSieve(int n)
{
	// generate the primes and non primes
	struct primeComplement *L = extendedPrimeSieve(n);	

	struct intList *primes = L->primes;
	struct intList *nonPrimes = L->nonPrimes;

	int p;

	for(int z = 0; z < nonPrimes->len; z++)
	{
		int groupSize = nonPrimes->list[z];




		// for each of the primes
		for(int i = 0; i < primes->len; i++)
		{
			p = primes->list[i];

			// if the prime divides the group size
			if(groupSize%p == 0)
			{
				int flag = 0;	

				// check all possible divisors. This is not the most efficient way but it's the simplest
				for(int k = 2; k <= groupSize; k++)
				{
					// if there is a divisor that also == 1 mod p
					if(groupSize%k == 0 && k%p == 1)
					{
						flag = 1;
						break;
					}
				}
				
				// if it went through all possible divisors and none is equiv to 1 mod p
				if(flag == 0)
				{
					printf("> %d\n", groupSize);
				}
			}
			
		}



	}

	freePrimeComplements(L);
	
	return 0;

}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: nSieve [n_max_group_size]\n");
		return 1;
	}
	
	int n = atoi(argv[1]);
	if(n <= 1)
	{
		fprintf(stderr, "Too small of a group size\n");
		return 1;
	}

	printf("Printing non-simple groups\n");
	nSieve(n);
	return 0;
	

}
