// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

int get_length(char *string)
{
	short length;

	// ruleid: unsafe-strlen
	length = strlen(string);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
