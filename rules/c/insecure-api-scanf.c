// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

void read_string(char *string)
{
	char buf[BUFSIZE];
	int number;
	char fmt[] = "whatever";

	// ruleid: raptor-insecure-api-scanf
	scanf("%s", buf);

	// ok: raptor-insecure-api-scanf
	scanf("%d", &number);

	// ruleid: raptor-insecure-api-scanf
	sscanf(string, "string: %s", buf);

	// ruleid: raptor-insecure-api-scanf
	scanf(FMT, buf);

	// ruleid: raptor-insecure-api-scanf
	scanf(fmt, buf);

	// ruleid: raptor-insecure-api-scanf
	scanf(buf);
}

void test_func()
{
	char last_name[20];
	printf("Enter your last name: ");
	// ruleid: raptor-insecure-api-scanf
	scanf("%s", last_name);
}

int read_ident(int sockfd)
{
	int sport, cport;
	char user[32], rtype[32], addinfo[32];
	char buffer[1024];

	if (read(sockfd, buffer, sizeof(buffer)) <= 0)
	{
		perror("read: %m");
		return 1;
	}

	buffer[sizeof(buffer) - 1] = '\0';
	// ruleid: raptor-insecure-api-scanf
	sscanf(buffer, "%d:%d:%s:%s:%s", &sport, &cport, rtype, user, addinfo);
	// ...
}

// https://github.com/pedrib/PoC/blob/master/advisories/Pwn2Own/Tokyo_2019/tokyo_drift/tokyo_drift.md
undefined4 sa_setBlockName(char *block_name, int len)
{
	int scanf_res;
	char *__src;
	char scanf_str[1024];
	undefined4 scanf_int;

	scanf_int = 0;
	scanf_str._0_4_ = 0;
	memset(scanf_str + 4, 0, 0x3fc);
	print_debug(3, "%s(%d);\n", "sa_setBlockName", 0x42d);
	if (len != 0)
	{
		// ruleid: raptor-insecure-api-scanf
		scanf_res = sscanf(block_name, "%d%s", &scanf_int, scanf_str);
		/* if ((scanf_res == 2) && (__src = strstr(block_name, s), __src != NULL)) {
			// ...
		} */
	}
	return 0;
}

// https://www.synacktiv.com/en/publications/pwn2own-austin-2021-defeating-the-netgear-r6700v3.html
int updating_database(int a1, const char *update_server)
{
	// ...
	char line[1020];		   // [sp+894h] [bp-4FCh] BYREF
	char db_checksum_val[256]; // [sp+D94h] [bp+4h] BYREF
	char db_checksum[256];	   // [sp+E94h] [bp+104h] BYREF
							   // ...
	v7 = fopen("/tmp/circleinfo.txt", "r");
	if (v7)
	{
		line[0] = 0;
		while (fgets(line, 1024, v7))
		{
			// ruleid: raptor-insecure-api-scanf
			if (sscanf(line, "%s %s", db_checksum, db_checksum_val) == 2 && !strcmp(db_checksum, "db_checksum"))
			{
				// ...
				break;
			}
		}
	}
	return 0;
}

void test_003(void)
{
	char buf[BUFFER_SIZE];
	// ruleid: raptor-insecure-api-scanf
	if (1 != fscanf(stdin, "%s", buf))
	{
		// ...
	}
}

void test_003_valist(void)
{
	char buf[BUFFER_SIZE];
	// ruleid: raptor-insecure-api-scanf
	if (1 != fscanf(stdin, "%d%d%s", 1, 2, buf))
	{
		// ...
	}
}

void test_003_stmt(void)
{
	char buf[BUFFER_SIZE];
	// ruleid: raptor-insecure-api-scanf
	fscanf(stdin, "%d%d%s", 1, 2, buf);
}

void test_004(void)
{
	char buf[BUFFER_SIZE];
	// ok: raptor-insecure-api-scanf
	if (1 != fscanf(stdin, "%d", buf))
	{
		// ...
	}
}

void test_007(wchar_t *name)
{
	char filename[128];
	// ruleid: raptor-insecure-api-scanf
	fwscanf(stdin, L"foo%sbar", filename);
}

void foo()
{
	char buf[128];
	int n;
	// ruleid: raptor-insecure-api-scanf
	fscanf(stdin, "%dfoo%sbar", n, buf);
	// ruleid: raptor-insecure-api-scanf
	fscanf(stdin, "%sbar", n, buf);
	// ruleid: raptor-insecure-api-scanf
	fscanf(stdin, "foo%s", n, buf);
}

void foo()
{
	char buf[128];
	int n;
	// ok: raptor-insecure-api-scanf
	fscanf(stdin, "%dfoo%10sbar", n, buf);
}

void foo()
{
	char buf[128];
	int n;
	// sized format specifiers aren't parsed yet
	// todoruleid: raptor-insecure-api-scanf
	fscanf(stdin, "%dfoo%1024sbar", n, buf);
}

void foo()
{
	char buf[128];
	// ruleid: raptor-insecure-api-scanf
	fscanf(stdin, "%sfoo%%s", buf);

	// ruleid: raptor-insecure-api-scanf
	fscanf(stdin, "%sfoo%%%s", buf);
}

void foo()
{
	char buf[64];
	va_list ap;
	va_start(ap, buf);
	// ruleid: raptor-insecure-api-scanf
	vscanf("%s", ap);
	va_end(ap);
}

void foo()
{
	char buf[64];
	va_list ap;
	va_start(ap, buf);
	// ruleid: raptor-insecure-api-scanf
	vfscanf(stdin, "%s", ap);
	va_end(ap);
}

void foo(char *str)
{
	char buf[0];
	// ruleid: raptor-insecure-api-scanf
	sscanf(str, "%s", buf);

	// ok: raptor-insecure-api-scanf
	sscanf("constant string", "%s", buf);

	va_list ap;
	va_start(ap, fmt);
	// ruleid: raptor-insecure-api-scanf
	vsscanf(str, "%s", buf);
	va_end(ap);

	va_list ap;
	va_start(ap, fmt);
	// ok: raptor-insecure-api-scanf
	vsscanf("constant string", "%s", buf);
	va_end(ap);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
