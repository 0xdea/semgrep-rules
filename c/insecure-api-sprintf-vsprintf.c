// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

int copy_string(char *string, int number)
{
	char buf[BUFSIZE];
	char fmt[] = "whatever";

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, "string: %s\n", string);

	// ok: raptor-insecure-api-sprintf-vsprintf (probably)
	sprintf(buf, "number: %d\n", number);

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, FMT, string);

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, fmt, string);

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, string);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
