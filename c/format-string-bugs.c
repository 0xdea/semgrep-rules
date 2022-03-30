// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <syslog.h>

#define BUFSIZE 256

int build_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-format-string-bugs
	snprintf(buf, BUFSIZE, string);

	// ok: raptor-format-string-bugs
	snprintf(buf, BUFSIZE, "%s", string);
}

int print_stuff(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-format-string-bugs
	printf(string);

	// ok: raptor-format-string-bugs
	printf("%s\n", string);
}

int log_stuff(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-format-string-bugs
	syslog(LOG_ERR, string);

	// ok: raptor-format-string-bugs
	syslog(LOG_ERR, "%s", string);
}

void printWrapper(char *string) 
{
	// ruleid: raptor-format-string-bugs
	printf(string);
}

int main(int argc, char **argv) 
{
	char buf[5012];
	memcpy(buf, argv[1], 5012);
	printWrapper(argv[1]);
	return 0;
}
