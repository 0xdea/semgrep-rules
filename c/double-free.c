// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

int alloc_and_free1()
{
	int bailout = 1;
	char *ptr = (char *)malloc(MEMSIZE);

	// this should be catched but it isn't, due to a documented limitation in semgrep
	// https://semgrep.dev/docs/writing-rules/pattern-syntax/#ellipses-and-statement-blocks
	if (bailout) 
		free(ptr);

	// ruleid: double-free
	free(ptr);
	free(ptr);
}

int alloc_and_free2()
{
	char *ptr = (char *)malloc(MEMSIZE);

	// ok: double-free
	free(ptr);
	ptr = NULL;
	free(ptr);
}

int alloc_and_free3()
{
	char *ptr = (char *)malloc(MEMSIZE);

	// ok: double-free
	free(ptr);
	ptr = (char *)malloc(MEMSIZE);
	free(ptr);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
