
#include "indexSieveSylow.h"


// modulo factorial. To avoid overflow
long long modFact(int n, int modulo)
{
	long long remainder = 1;
	for(int i = 1;i<=n;i++)
	{
		remainder = (remainder*i)%modulo;
		if(remainder==0)
		{
			return 0;
		}
	}
	return remainder;
}

void indexSieveSylow(int G)
{

	struct intList *primes = primeSieve(G);
	long long maxSylow = -1;

	int p;
	for(int i = 0; i < primes->len; i++)
	{
		
		// if a prime is a factor
		if(G%(p=primes->list[i])==0)
		{
			long long sylow = p;

			// the greatest power of that number
			while(G%(sylow*p)==0 && sylow * p <= G)
			{
				sylow*=p;
			}

			if(sylow>maxSylow)
			{
				maxSylow = sylow;
			}
		}
	}

	if(maxSylow <= 0)
	{
		freeIntList(primes);
		fprintf(stderr, "Error finding prime\n");
		exit(1);
	}

	int index = (int)G/maxSylow;

	if(modFact(index,G) != 0)
	{
		printf("%d is nonsimple with max sylow group order %lld\n", G, maxSylow);
	}
	else
	{
		printf("%d is non-conclusive\n", G);
	}

	freeIntList(primes);
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

	indexSieveSylow(G);
	
	return 0;
}
