// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

int allocate_memory()
{
	// ruleid: insecure-api-alloca
	alloca(MEMSIZE);

	// do something
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
