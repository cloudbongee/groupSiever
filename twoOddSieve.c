
#include "twoOddSieve.h"

void twoOddSieve(int n)
{
	for(int i = 2 ; i < n; i+=2)
	{
		int val = (int)(i/2);
		if((val & 0x1) == 0x1)
		{
			printf("> %d\n",i);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "Usage: 'twoOddSieve [Max-Group-size]'\n");
		return 1;
	}

	int n = atoi(argv[1]);
	if(n <= 0)
	{
		fprintf(stderr, "Invalid input\n");
		return 1;
	}

	twoOddSieve(n);
	return 0;
}
