// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

int do_something(char *string)
{
	// ok
	int bug = 0;

	// ruleid: raptor-bad-words
	/* TODO */
	printf("Hello, World!");

	// ruleid: raptor-bad-words
	// this might be insecure
	return 1;
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
