// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256

void get_string()
{
	char buf[BUFSIZE];

	// ruleid: raptor-insecure-api-gets
	gets(buf);
}

void test_001()
{
	char buf[BUFFER_SIZE];
	// ruleid: raptor-insecure-api-gets
	if (gets(buf) == NULL)
	{
		// ...
	}
}

void foo()
{
	char buf[64];
	// ruleid: raptor-insecure-api-gets
	gets(buf);
}

void foo()
{
	char buf[64];
	// ok: raptor-insecure-api-gets
	fgets(buf, 63, stdin);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
