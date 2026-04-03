// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define SIZE 256

int test1()
{
	// ...
	for (oct_cnt = 1; oct_cnt < 7; oct_cnt++)
	{
		oct = (u_int8_t)retrieve_rand_int(0xFF);
		if (oct_cnt != 1)
			// ruleid: raptor-overlapping-source-destination
			sprintf(eaddr, "%s:%0x", eaddr, oct);
		else
			sprintf(eaddr, "%0x", oct);
	}
	return eaddr;
}

int test2()
{
	char buf[SIZE];

	// ruleid: raptor-overlapping-source-destination
	sprintf(buf, "%s:%s:%s", prepend, buf, append);

	// ruleid: raptor-overlapping-source-destination
	snprintf(buf, SIZE, "%s:%s", prepend, buf);

	// ruleid: raptor-overlapping-source-destination
	sprintf(buf, "%s some further text", buf);

	return 0;
}

int test2_ok(void)
{
	char tmp[SIZE];

	// ok: raptor-overlapping-source-destination
	snprintf(tmp, SIZE, "%s:%s:%s", prepend, buf, append);
	// ok: raptor-overlapping-source-destination
	strlcpy(buf, tmp, SIZE);

	// ok: raptor-overlapping-source-destination
	snprintf(tmp, SIZE, "%s:%s", prepend, buf);
	// ok: raptor-overlapping-source-destination
	strlcpy(buf, tmp, SIZE);

	// ok: raptor-overlapping-source-destination
	snprintf(tmp, SIZE, "%s some further text", buf);
	// ok: raptor-overlapping-source-destination
	strlcpy(buf, tmp, SIZE);

	return 0;
}

int test3(char *buf)
{
	// ruleid: raptor-overlapping-source-destination
	memcpy(buf, buf, 16);

	// ruleid: raptor-overlapping-source-destination
	strcpy(buf, buf);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
