// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

int alloc_and_free1()
{
	int err = 1, bailout = 0;
	char *ptr = (char *)malloc(MEMSIZE);

	// this should be catched but it isn't, due to a documented limitation in semgrep
	// https://semgrep.dev/docs/writing-rules/pattern-syntax/#ellipses-and-statement-blocks
	if (err) {
		bailout = 1;
		free(ptr);
	}
	if (bailout)
		fprintf(stderr, "error: %p\n", ptr);

	// ruleid: raptor-use-after-free
	free(ptr);
	fprintf(stderr, "error: %p\n", ptr);
}

int alloc_and_free2()
{
	char *ptr = (char *)malloc(MEMSIZE);

	// ok: raptor-use-after-free
	free(ptr);
	ptr = (char *)malloc(MEMSIZE);
	fprintf(stderr, "error: %p\n", ptr);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
