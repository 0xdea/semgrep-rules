// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

int do_something(char *string)
{
	// ok: raptor-bad-words
	int bug = 0;

	// ruleid: raptor-bad-words
	/* XXX */
	printf("Hello, World!");

	if (bug)
	{
		// ruleid: raptor-bad-words
		// TODO: handle condition
	}

	// ruleid: raptor-bad-words
	// this might be insecure
	return 1;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
