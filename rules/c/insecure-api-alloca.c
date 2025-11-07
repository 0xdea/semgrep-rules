// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

void allocate_memory()
{
	// ruleid: raptor-insecure-api-alloca
	alloca(MEMSIZE);

	// ...
}

void allocate_memory2()
{
	int end_limit = get_nmbr_obj_from_db();
	int i;
	int *base = NULL;
	int *p = base;
	for (i = 0; i < end_limit; i++)
	{
		// ruleid: raptor-insecure-api-alloca
		*p = alloca(sizeof(int *));
		p = *p;
	}
}

int main()
{
	printf("Hello, World!");
	return 0;
}
