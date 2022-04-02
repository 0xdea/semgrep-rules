// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

int read_string(char *string)
{
	char buf[BUFSIZE];
	int number;
	char fmt[] = "whatever";

	// ruleid: raptor-insecure-api-scanf-etc
	scanf("%s", buf);

	// ok: raptor-insecure-api-scanf-etc (probably)
	scanf("%d", &number);

	// ruleid: raptor-insecure-api-scanf-etc
	sscanf(string, "string: %s", buf);

	// ruleid: raptor-insecure-api-scanf-etc
	scanf(FMT, buf);

	// ruleid: raptor-insecure-api-scanf-etc
	scanf(fmt, buf);

	// ruleid: raptor-insecure-api-scanf-etc
	scanf(buf);
}

int test_func()
{
	char last_name[20];
	printf ("Enter your last name: ");
	// ruleid: raptor-insecure-api-scanf-etc
	scanf ("%s", last_name);
}

// https://github.com/pedrib/PoC/blob/master/advisories/Pwn2Own/Tokyo_2019/tokyo_drift/tokyo_drift.md
undefined4 sa_setBlockName(char *block_name,int len)
{
	int scanf_res;
	char *__src;
	char scanf_str [1024];
	undefined4 scanf_int;

	scanf_int = 0;
	scanf_str._0_4_ = 0;
	memset(scanf_str + 4,0,0x3fc);
	print_debug(3,"%s(%d);\n","sa_setBlockName",0x42d);
	if (len != 0) {
		// ruleid: raptor-insecure-api-scanf-etc
		scanf_res = sscanf(block_name,"%d%s",&scanf_int,scanf_str);
		if ((scanf_res == 2) && (__src = strstr(block_name,s_@_000662bc), __src != NULL)) {
			// ...
    		}
  	}
	return 0;
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
