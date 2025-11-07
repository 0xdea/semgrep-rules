// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <syslog.h>

#define BUFSIZE 256

void build_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-format-string-bugs
	snprintf(buf, BUFSIZE, string);

	// ok: raptor-format-string-bugs
	snprintf(buf, BUFSIZE, "%s", string);
}

void print_stuff(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-format-string-bugs
	printf(string);

	// ok: raptor-format-string-bugs
	printf("%s\n", string);
}

void log_stuff(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-format-string-bugs
	syslog(LOG_ERR, string);

	// ok: raptor-format-string-bugs
	syslog(LOG_ERR, "%s", string);
}

void log_error(char *fmt, ...)
{
	char buf[BUFSIZE];
	va_list ap;

	va_start(ap, fmt);
	// ruleid: raptor-format-string-bugs
	vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	// ruleid: raptor-format-string-bugs
	syslog(LOG_NOTICE, buf);
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
