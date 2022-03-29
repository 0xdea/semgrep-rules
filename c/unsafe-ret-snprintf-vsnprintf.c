// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256

int copy_string(char *string)
{
	char buf[BUFSIZE];
	size_t length;

	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	length = snprintf(buf, BUFSIZE, "%s", string);

	// use length to access buf
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
