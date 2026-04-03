// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

void copy_string1(char *string)
{
	char buf[BUFSIZE];
	size_t length;

	// ruleid: raptor-unsafe-ret-strlcpy-strlcat
	length = strlcpy(buf, string, BUFSIZE);

	// use length to access buf, e.g. with strncat()
}

int copy_string2(const char *string)
{
	char buf[BUFSIZE];

	if (!string)
		return -1;

	// ok: raptor-unsafe-ret-strlcpy-strlcat
	if (strlcpy(buf, string, BUFSIZE) >= BUFSIZE)
		return -1; // truncation

	// safely use buf here, knowing it is complete and null-terminated

	return 0;
}

void append_string(char *string)
{
	char buf[BUFSIZE];
	size_t length;

	// ruleid: raptor-unsafe-ret-strlcpy-strlcat
	length = strlcat(buf, string, BUFSIZE);

	// use length to access buf
}

void qualify_username(char *username)
{
	char buf[1024];
	size_t length;

	// ruleid: raptor-unsafe-ret-strlcpy-strlcat
	length = strlcpy(buf, username, sizeof(buf));
	strncat(buf, "@127.0.0.1", sizeof(buf) - length);
	// ...
}

int main()
{
	printf("Hello, World!");
	return 0;
}
