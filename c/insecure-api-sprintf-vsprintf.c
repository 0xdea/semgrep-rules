// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

int copy_string(char *string, int number)
{
	char buf[BUFSIZE];
	char fmt[] = "whatever";

	// ruleid: insecure-api-sprintf-vsprintf
	sprintf(buf, "string: %s\n", string);

	// probably ok
	sprintf(buf, "number: %d\n", number);

	// ruleid: insecure-api-sprintf-vsprintf
	sprintf(buf, FMT, string);

	// ruleid: insecure-api-sprintf-vsprintf
	sprintf(buf, fmt, string);

	// ruleid: insecure-api-sprintf-vsprintf
	sprintf(buf, string);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
