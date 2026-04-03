// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>

void open_tmpfile1(char *path)
{
	// ruleid: raptor-insecure-api-mktemp-tmpnam-tempnam
	char *filename = mktemp(path);

	FILE *tmp = fopen(filename, "wb+");
	// do something
}

void open_tmpfile2(char *path, char *data, size_t len)
{
	// ok: raptor-insecure-api-mktemp-tmpnam-tempnam
	int fd = mkstemp(path);

	write(fd, data, len);
	// do something
}

int main()
{
	printf("Hello, World!");
	return 0;
}
