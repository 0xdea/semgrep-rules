// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define SIZE 256

int test1()
{
	// ...
	for (oct_cnt = 1; oct_cnt < 7; oct_cnt++) {
		oct = (u_int8_t)retrieve_rand_int(0xFF);
		if (oct_cnt != 1)
			// ruleid: raptor-incorrect-use-of-sprintf-snprintf
			sprintf(eaddr, "%s:%0x", eaddr, oct);
		else
			sprintf(eaddr, "%0x", oct);
	}
	return eaddr;
}

int test2()
{
	char buf[SIZE];

	// ruleid: raptor-incorrect-use-of-sprintf-snprintf
	sprintf(buf, "%s:%s:%s", prepend, buf, append);

	// ruleid: raptor-incorrect-use-of-sprintf-snprintf
	snprintf(buf, SIZE, "%s:%s", prepend, buf);

	// ruleid: raptor-incorrect-use-of-sprintf-snprintf
	sprintf(buf, "%s some further text", buf);

	return 0;
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
