// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

int invoke1(char *string)
{
	char buf[] = "uname -a; id";

	// ok
	system(buf);

	// ok
	system("whoami");

	// ruleid: command-injection
	system(string);
}

int invoke2(char *string)
{
	char buf[] = "uname -a; id";

	// ok
	popen(buf, "r");

	// ok
	popen("whoami", "r");

	// ruleid: command-injection
	popen(string, "r");
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
