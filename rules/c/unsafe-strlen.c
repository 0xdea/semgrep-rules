// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

int get_length1(char *string)
{
	short length;

	// ruleid: raptor-unsafe-strlen
	length = strlen(string);

	return length;
}

int get_length2(char *string)
{
	unsigned int length;

	// ok: raptor-unsafe-strlen
	length = strlen(string);

	return length;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
