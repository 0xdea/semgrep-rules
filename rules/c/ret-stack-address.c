// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_MAX 256

char *getName_bad()
{
	char name[STR_MAX];

	fillInName(name);
	// ruleid: raptor-ret-stack-address
	return name;
}

char *getName_good()
{
	char *name = (char *)malloc(STR_MAX);

	fillInName(name);
	// ok: raptor-ret-stack-address
	return name;
}

char *getName_good2()
{
	static char name[STR_MAX];

	fillInName(name);
	// ok: raptor-ret-stack-address
	return name;
}

char *findF(char *b)
{
	char tmpbuf[1024];
	char *p = tmpbuf;
	memcpy(tmpbuf, b, 1024);

	while (*p != '\0')
	{
		if (*p == 'F')
			// ruleid: raptor-ret-stack-address
			return p;
		p++;
	}
	return NULL;
}

void fillMem()
{
	char a[2048];
	memset(a, 'Z', sizeof(a));
}

void recvStr(char *str)
{
	char *fPtr = findF(str);

	fillMem();
	if (fPtr == NULL)
	{
		printf("No F!");
	}
	else
	{
		printf("F = %s", fPtr);
	}
}

int *f(void)
{
	int local_auto;

	// ruleid: raptor-ret-stack-address
	return &local_auto;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
