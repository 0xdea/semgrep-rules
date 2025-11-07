// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define MEMSIZE 256

void bad1()
{
	// ruleid: raptor-insecure-api-access-stat-lstat
	int res = access("/tmp/userfile", R_OK);
	if (res != 0)
		die("access");

	int fd = open("/tmp/userfile", O_RDONLY);
	// ...
}

void bad2(char *file)
{
	struct stat statb;
	int fd;

	errno = 0;

	// ruleid: raptor-insecure-api-access-stat-lstat
	if (lstat(file, &statb) < 0)
		goto out;

	if (!(statb.st_mode & S_IFREG) || statb.st_mode & 077)
		goto out;
	if ((fd = open(file, O_RDWR | O_SYNC, 0)) < 0)
		goto out;
}

void bad3(char *fname)
{
	struct stat stbl;
	int fd = open(fname, O_RDONLY);

	if (fd == -1)
		perror("open");
	// ruleid: raptor-insecure-api-access-stat-lstat
	if (lstat(fname, &stbl) != 0)
		die("file not there");
	if (!S_ISREG(stbl.st_mode))
		die("its a symlink");
	// ...
}

int main()
{
	printf("Hello, World!");
	return 0;
}
