// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

int copy_append_string(char *string1, char *string2)
{
	char buf[BUFSIZE];

	// ruleid: insecure-api-strcpy-stpcpy-strcat
	strcpy(buf, string1);

	// ruleid: insecure-api-strcpy-stpcpy-strcat
	strcat(buf, string2);
}

int copy_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: insecure-api-strcpy-stpcpy-strcat
	stpcpy(buf, string);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
