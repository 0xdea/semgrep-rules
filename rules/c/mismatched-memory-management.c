// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

void bad1()
{
	int localArray[2] = {11, 22};
	int *p = localArray;

	// ruleid: raptor-mismatched-memory-management
	free(p);
}

void good1()
{
	int *ptr;
	ptr = (int *)malloc(sizeof(int));

	// ok: raptor-mismatched-memory-management
	free(ptr);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
