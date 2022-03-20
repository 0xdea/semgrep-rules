// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <syslog.h>

#define BUFSIZE 256

int build_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: format-string-bugs
	snprintf(buf, BUFSIZE, string);

	// ok
	snprintf(buf, BUFSIZE, "%s", string);
}

int print_stuff(char *string)
{
	char buf[BUFSIZE];

	// ruleid: format-string-bugs
	printf(string);

	// ok
	printf("%s\n", string);
}

int log_stuff(char *string)
{
	char buf[BUFSIZE];

	// ruleid: format-string-bugs
	syslog(LOG_ERR, string);

	// ok
	syslog(LOG_ERR, "%s", string);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
