// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256

void get_string()
{
	char buf[BUFSIZE];

	// ruleid: raptor-insecure-api-gets
	gets(buf);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
