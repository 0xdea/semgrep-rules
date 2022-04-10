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

int uaf(int argc, char **argv) 
{
	char *buf1R1;
	char *buf2R1;
	char *buf2R2;
	char *buf3R2;
	buf1R1 = (char *) malloc(BUFSIZER1);
	buf2R1 = (char *) malloc(BUFSIZER1);
	// ruleid: raptor-use-after-free
	free(buf2R1);
	buf2R2 = (char *) malloc(BUFSIZER2);
	buf3R2 = (char *) malloc(BUFSIZER2);
	strncpy(buf2R1, argv[1], BUFSIZER1-1);
	free(buf1R1);
	free(buf2R2);
	free(buf3R2);
}

// https://docs.microsoft.com/en-us/cpp/sanitizers/error-heap-use-after-free
int heap-use-after-free()
{
	char *x = (char*)malloc(10 * sizeof(char));
	// ruleid: raptor-use-after-free
	free(x);

	// ...

	return x[5];
}

int main()
{
	printf("Hello, World!");
	return 0;
}
