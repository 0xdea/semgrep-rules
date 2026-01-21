// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void invoke1(char *string)
{
	char buf[] = "uname -a; id";

	// ok: raptor-command-injection
	system(buf);

	// ok: raptor-command-injection
	system("whoami");

	// ruleid: raptor-command-injection
	system(string);
}

void invoke2(char *string)
{
	char buf[] = "uname -a; id";

	// ok: raptor-command-injection
	popen(buf, "r");

	// ok: raptor-command-injection
	popen("whoami", "r");

	// ruleid: raptor-command-injection
	popen(string, "r");
}

int send_mail(char *user)
{
	char buf[1024];
	FILE *fp;

	snprintf(buf, sizeof(buf), "/usr/bin/sendmail -s \"hi\" %s", user);

	// ruleid: raptor-command-injection
	fp = popen(buf, "w");

	if (fp == NULL)
		return 1;
	// ...
}

enum
{
    BUFFERSIZE = 512
};

void test_001(const char *input)
{
    char cmdbuf[BUFFERSIZE];
    int len_wanted = snprintf(cmdbuf, BUFFERSIZE,
                              "any_cmd '%s'", input);
    if (len_wanted >= BUFFERSIZE)
    {
        /* Handle error */
    }
    else if (len_wanted < 0)
    {
        /* Handle error */
    }
    // ruleid: raptor-command-injection
    else if (system(cmdbuf) == -1)
    {
        /* Handle error */
    }
}

void test_002(const char *input)
{
    char cmdbuf[BUFFERSIZE];
    int len_wanted = snprintf(cmdbuf, BUFFERSIZE,
                              "any_cmd '%s'", input);
    // ruleid: raptor-command-injection
    system(cmdbuf);
}

void test_003(const char *input)
{
    // ok: raptor-command-injection
    storer->store_binary(Clocks->system());
}

void test_004(const char *input)
{
    // ok: raptor-command-injection
    storer->store_binary(Clocks::system());

    // ok: raptor-command-injection
    double passed_server_time = max(Clocks::system() - old_server_time, 0.0);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
