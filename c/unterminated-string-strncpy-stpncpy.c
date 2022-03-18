// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

int copy_string1(char *string)
{
	char buf[BUFSIZE];

	// ruleid: unterminated-string-strncpy-stpncpy
	strncpy(buf, string, BUFSIZE);
}

int copy_string2(char *string)
{
	char buf[BUFSIZE];

	// ruleid: unterminated-string-strncpy-stpncpy
	stpncpy(buf, string, BUFSIZE);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
