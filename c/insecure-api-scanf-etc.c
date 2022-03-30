// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

int read_string(char *string)
{
	char buf[BUFSIZE];
	int number;
	char fmt[] = "whatever";

	// ruleid: raptor-insecure-api-scanf-etc
	scanf("%s", buf);

	// ok: raptor-insecure-api-scanf-etc (probably)
	scanf("%d", &number);

	// ruleid: raptor-insecure-api-scanf-etc
	sscanf(string, "string: %s", buf);

	// ruleid: raptor-insecure-api-scanf-etc
	scanf(FMT, buf);

	// ruleid: raptor-insecure-api-scanf-etc
	scanf(fmt, buf);

	// ruleid: raptor-insecure-api-scanf-etc
	scanf(buf);
}

int test_func()
{
	char last_name[20];
	printf ("Enter your last name: ");
	// ruleid: raptor-insecure-api-scanf-etc
	scanf ("%s", last_name);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
