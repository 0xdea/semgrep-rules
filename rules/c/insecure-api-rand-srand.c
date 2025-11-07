// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum
{
	len = 12
};

void func_bad(void)
{
	char id[len];
	int r;
	int num;

	// ...

	// ruleid: raptor-insecure-api-rand-srand
	r = rand();
	num = snprintf(id, len, "ID%-d", r);

	// ...
}

void func_good(void)
{
	char id[len];
	int r;
	int num;

	// ...

	struct timespec ts;
	if (timespec_get(&ts, TIME_UTC) == 0)
	{
		/* handle error */
	}
	// ok: raptor-insecure-api-rand-srand
	srandom(ts.tv_nsec ^ ts.tv_sec);

	// ...

	// ok: raptor-insecure-api-rand-srand
	r = random();
	num = snprintf(id, len, "ID%-d", r);

	// ...
}

int main()
{
	printf("Hello, World!");
	return 0;
}
