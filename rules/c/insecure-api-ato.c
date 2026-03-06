// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

int converter_bad(const char *numstr)
{
	// ruleid: raptor-insecure-api-ato
	return atoi(numstr);
}

int converter_good(const char *numstr)
{
	// ok: raptor-insecure-api-ato
	return strtol(numstr, NULL, 10);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
