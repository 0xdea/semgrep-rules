// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

void alloc_and_free1()
{
	int err = 1, bailout = 0;
	char *ptr = (char *)malloc(MEMSIZE);

	// this should be caught but it isn't, due to a documented limitation in semgrep
	// https://semgrep.dev/docs/writing-rules/pattern-syntax/#ellipses-and-statement-blocks
	// todoruleid: raptor-use-after-free
	if (err)
	{
		bailout = 1;
		free(ptr);
	}
	if (bailout)
		fprintf(stderr, "error: %p\n", ptr);

	free(ptr);
	// ruleid: raptor-use-after-free
	fprintf(stderr, "error: %p\n", ptr);
}

void alloc_and_free2()
{
	char *ptr = (char *)malloc(MEMSIZE);

	free(ptr);
	ptr = (char *)malloc(MEMSIZE);
	// ok: raptor-use-after-free
	fprintf(stderr, "error: %p\n", ptr);
}

void uaf(int argc, char **argv)
{
	char *buf1R1;
	char *buf2R1;
	char *buf2R2;
	char *buf3R2;
	buf1R1 = (char *)malloc(BUFSIZER1);
	buf2R1 = (char *)malloc(BUFSIZER1);
	free(buf2R1);
	buf2R2 = (char *)malloc(BUFSIZER2);
	buf3R2 = (char *)malloc(BUFSIZER2);
	// ruleid: raptor-use-after-free
	strncpy(buf2R1, argv[1], BUFSIZER1 - 1);
	free(buf1R1);
	free(buf2R2);
	free(buf3R2);
}

// https://docs.microsoft.com/en-us/cpp/sanitizers/error-heap-use-after-free
int heap_use_after_free()
{
	char *x = (char *)malloc(10 * sizeof(char));
	free(x);

	// ...

	// ruleid: raptor-use-after-free
	return x[5];
}

char test()
{
	char *ptr = (char *)malloc(10 * sizeof(char));
	free(ptr);

	// ruleid: raptor-use-after-free
	return *ptr;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
