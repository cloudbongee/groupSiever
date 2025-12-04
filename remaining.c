
#include<stdio.h>
#include<stdlib.h>
#include "eratosthenes.h"

int main(int argc, char *argv[])
{

	if(argc != 3)
	{
		fprintf(stderr, "Usage: 'remaining [Max-group-size] [Current group]'\n");

		return 1;
	}

	int n  = atoi(argv[1]);
	if(n <= 2)
	{
		fprintf(stderr, "Invalud Max-group-size\n");
		return 1;
	}

	FILE *file = fopen(argv[2], "r"); 
	
	if(file == NULL)
	{
		perror("Could not open file\n");
		return 1;
	}

	int *list = malloc(sizeof(int) * n);
	if(list == NULL)
	{
		fprintf(stderr, "Memory error\n");
		return 1;
	}
	
		
	for(int i = 0; i < n; i++)
	{
		list[i] = i + 1;
	}
	
	char *line = NULL;
	size_t size = 0;
	while(getline(&line, &size, file) > 0)
	{
		if(line[0] == '>')
		{
			int num = 0;
			if(sscanf(line, "> %d", &num) != 1)
			{
				fprintf(stderr, "Format error in file\n");
				return 1;
			}
			if(num <= 0)
			{
				fprintf(stderr, "Invalid number in file\n");
				return 1;
			}

			
			list[num - 1] = -1;
		}
	}
	

	printf("Remaining\n");

	struct primeComplement *L = extendedPrimeSieve(n);
	struct intList *primes = L->primes;

	for(int i = 0; i < primes->len; i++)
	{
		int p = primes->list[i];
		list[p-1] = -1;
	}


	for(int i = 0; i < n; i++)
	{
		if(list[i] != -1)
		{
			printf("%d\n", list[i]);
		}
	}
	
	freePrimeComplements(L);	
	free(line);	
	free(list);	
	fclose(file);
	return 0;
}
