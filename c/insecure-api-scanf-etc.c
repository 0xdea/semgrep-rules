// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

int read_string(char *string)
{
	char buf[BUFSIZE];
	int number;
	char fmt[] = "whatever";

	// ruleid: insecure-api-scanf-etc
	scanf("%s", buf);

	// probably ok
	scanf("%d", &number);

	// ruleid: insecure-api-scanf-etc
	sscanf(string, "string: %s", buf);

	// ruleid: insecure-api-scanf-etc
	scanf(FMT, buf);

	// ruleid: insecure-api-scanf-etc
	scanf(fmt, buf);

	// ruleid: insecure-api-scanf-etc
	scanf(buf);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
