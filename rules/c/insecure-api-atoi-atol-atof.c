// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

int converter_bad(const char *numstr)
{
	// ruleid: raptor-insecure-api-atoi-atol-atof
	return atoi(numstr);
}

int converter_good(const char *numstr)
{
	// ok: raptor-insecure-api-atoi-atol-atof
	return strtol(numstr, NULL, 10);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
