// Marco Ivaldi <raptor@0xdeadbeef.info>

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

int main()
{
	printf("Hello, World!");
	return 0;
}
