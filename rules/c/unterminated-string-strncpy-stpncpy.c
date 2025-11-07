// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

void copy_string1(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-unterminated-string-strncpy-stpncpy
	strncpy(buf, string, BUFSIZE);
}

void copy_string2(char *string)
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

void test_func2(int argc, char **argv)
{
	char Filename[256];
	char Pattern[32];

	// ...

	// ruleid: raptor-unterminated-string-strncpy-stpncpy
	strncpy(Filename, argv[1], sizeof(Filename));
	// ruleid: raptor-unterminated-string-strncpy-stpncpy
	strncpy(Pattern, argv[2], sizeof(Pattern));

	printf("Searching file: %s for the pattern: %s\n", Filename, Pattern);
	Scan_File(Filename, Pattern);
}

void authenticate(int sockfd)
{
	char user[1024], *buffer;
	size_t size;
	int n, cmd;

	cmd = read_integer(sockfd);
	size = read_integer(sockfd);
	if (size > MAX_PACKET)
		return -1;

	buffer = (char *)calloc(size + 1, sizeof(char));
	if (!buffer)
		return -1;

	read_string(buffer, size);

	switch (cmd)
	{
	case USERNAME:
		// ruleid: raptor-unterminated-string-strncpy-stpncpy
		strncpy(user, buffer, sizeof(user));
		if (!is_username_valid(user))
			goto fail;
		break;
		// ...
	}
}

int process_email(char *email)
{
	char buf[1024], *domain;

	// ruleid: raptor-unterminated-string-strncpy-stpncpy
	strncpy(buf, email, sizeof(buf));

	domain = strchr(buf, '@');
	if (!domain)
		return -1;

	*domain++ = '\0';

	// ...
	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
