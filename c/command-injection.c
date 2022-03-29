// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

int invoke1(char *string)
{
	char buf[] = "uname -a; id";

	// ok: raptor-command-injection
	system(buf);

	// ok: raptor-command-injection
	system("whoami");

	// ruleid: raptor-command-injection
	system(string);
}

int invoke2(char *string)
{
	char buf[] = "uname -a; id";

	// ok: raptor-command-injection
	popen(buf, "r");

	// ok: raptor-command-injection
	popen("whoami", "r");

	// ruleid: raptor-command-injection
	popen(string, "r");
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
