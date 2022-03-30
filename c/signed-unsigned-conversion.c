// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

// https://pwning.systems/posts/php_filter_var_shenanigans/
static int _php_filter_validate_domain(char * domain, int len, zend_long flags)
{
	char *e, *s, *t;
	size_t l;
	int hostname = flags & FILTER_FLAG_HOSTNAME;
	unsigned char i = 1;

	s = domain;
	// ruleid: raptor-signed-unsigned-conversion
	l = len;
	e = domain + l;
	t = e - 1;

	// ...
}

// ruleid: raptor-signed-unsigned-conversion
unsigned int readdata() 
{
	int amount = 0;

	if (result == ERROR)
		amount = -1;

	return amount;
}

// ruleid: raptor-signed-unsigned-conversion
unsigned int readdata2() 
{
	int amount = 0;

	amount = accessmainframe();

	return amount;
}

int copy_memory() 
{
	int size = 256;

	// ruleid: raptor-signed-unsigned-conversion
	memcpy(destBuf, srcBuf, size);
}

void test_func(int argc, char **argv) 
{
	char path[256];
	char *input;
	int i;
	unsigned int sz;

	i = GetUntrustedInt();

	if (i > 256) {
		DiePainfully("go away!\n");
	}

	// ruleid: raptor-signed-unsigned-conversion
	sz = i;

	// ruleid: raptor-signed-unsigned-conversion
	strncpy(path, input, i);
	path[255] = '\0';
	printf("Path is: %s\n", path);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
