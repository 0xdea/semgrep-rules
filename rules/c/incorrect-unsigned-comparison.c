// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

int bad1()
{
	size_t uvar;

	// ruleid: raptor-incorrect-unsigned-comparison
	if (uvar < 0)
		return 1;

	return 0;
}

int bad2()
{
	size_t uvar;

	// ruleid: raptor-incorrect-unsigned-comparison
	if (uvar <= 0)
		return 1;

	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
