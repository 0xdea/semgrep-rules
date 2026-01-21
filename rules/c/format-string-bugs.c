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

namespace basic_tests
{

	void test_001()
	{
		const char *env_001 = getenv("PATH");

		// ruleid: raptor-format-string-bugs
		printf(env_001, 1);

		// ok: raptor-format-string-bugs
		printf("%s", env_001);

		// ruleid: raptor-format-string-bugs
		scanf(env_001, &d);
	}
}

int test_002(int argc, char **argv)
{
	int d = 0;
	// ruleid: raptor-format-string-bugs
	scanf(argv[1], &d);
}

int test_003(int argc, char **argv)
{
	static const size_t n_quads = 300;

	sord_free(NULL); // Shouldn't crash

	SordWorld *world = sord_world_new();

	// ok: raptor-format-string-bugs
	fprintf(stderr, "expected ");

	// ruleid: raptor-format-string-bugs
	fprintf(stderr, argv[1]);

	return finished(world, sord, EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	char buf[5012];
	memcpy(buf, argv[1], 5012);
	printWrapper(argv[1]);
	return 0;
}
