// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 256

void drop_priv_perm()
{
	// ruleid: raptor-interesting-api-calls
	setuid(getuid());
}

void drop_priv_temp()
{
	// ruleid: raptor-interesting-api-calls
	seteuid(getuid());
}

void copy_append_string(char *string1, char *string2)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	strcpy(buf, string1);

	// ruleid: raptor-interesting-api-calls
	strcat(buf, string2);
}

void copy_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	stpcpy(buf, string);
}

void copy_string1(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	strncpy(buf, string, BUFSIZE);
}

void copy_string2(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	stpncpy(buf, string, BUFSIZE);
}

void get_string()
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	gets(buf);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
