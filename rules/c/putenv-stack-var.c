// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_MAX 256

int putName_bad()
{
	char name[STR_MAX];

	fillInName(name);

	// ruleid: raptor-putenv-stack-var
	putenv(name);

	return 0;
}

int putName_good()
{
	char *name = (char *)malloc(STR_MAX);

	fillInName(name);

	// ok: raptor-putenv-stack-var
	putenv(name);

	return 0;
}

int putName_good2()
{
	static char name[STR_MAX];

	fillInName(name);

	// ok: raptor-putenv-stack-var
	putenv(name);

	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
