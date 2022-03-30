// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

int copy_string1(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-unterminated-string-strncpy-stpncpy
	strncpy(buf, string, BUFSIZE);
}

int copy_string2(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-unterminated-string-strncpy-stpncpy
	stpncpy(buf, string, BUFSIZE);
}

int test_func()
{
	char longString[] = "String signifying nothing";
	char shortString[16];

	// ruleid: raptor-unterminated-string-strncpy-stpncpy
	strncpy(shortString, longString, 16);
	printf("The last character in shortString is: %c (%1$x)\n", shortString[15]);
	return 0;
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
