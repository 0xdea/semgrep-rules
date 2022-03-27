// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

int alloc_memory()
{
	// ruleid: unchecked-ret-malloc-calloc-realloc
	char *ptr = (char *)malloc(MEMSIZE);
}

int alloc_memory_and_check1()
{
	// ok
	char *ptr = (char *)malloc(MEMSIZE);
	if (ptr == NULL) 
		return -1;

	// do stuff
	return 0;
}

int alloc_memory_and_check2()
{
	char *ptr;

	// ok
	if ( (ptr = (char *)malloc(MEMSIZE)) != NULL) {
		// do stuff
		return 0;
	}
	return -1;
}

int alloc_memory_and_check3()
{
	// ok
	char *ptr = (char *)malloc(MEMSIZE);
	if (!ptr) 
		return -1;

	// do stuff
	return 0;
}

int alloc_memory_and_check4()
{
	char *ptr;

	// ok
	if ( !(ptr = (char *)malloc(MEMSIZE)) )
		return -1;

	// do stuff
	return 0;
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
