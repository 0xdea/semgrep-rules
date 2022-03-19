// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

int copy_string(char *string)
{
	char buf[BUFSIZE];
	size_t length;

	// ruleid: unsafe-ret-strlcpy-strlcat
	length = strlcpy(buf, string, BUFSIZE);
	buf[length] = 'A';
}

int append_string(char *string)
{
	char buf[BUFSIZE];
	size_t length;

	// ruleid: unsafe-ret-strlcpy-strlcat
	length = strlcat(buf, string, BUFSIZE);
	buf[length] = 'A';
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
