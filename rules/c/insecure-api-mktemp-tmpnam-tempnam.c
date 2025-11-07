// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>

void open_tmpfile(char *filename)
{
	// ruleid: raptor-insecure-api-mktemp-tmpnam-tempnam
	mktemp(filename);

	FILE *tmp = fopen(filename, "wb+");
	// do something
}

int main()
{
	printf("Hello, World!");
	return 0;
}
