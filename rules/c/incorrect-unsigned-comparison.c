// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

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

int good1()
{
	size_t uvar;

	// ok: raptor-incorrect-unsigned-comparison
	if (uvar > 0)
		return 1;

	return 0;
}

struct Context {
	uint64_t l_qseq;
};

int bad_mixed(struct Context *c, int new_l_data)
{
	// ruleid: raptor-incorrect-unsigned-comparison
	if (new_l_data > INT_MAX || (uint64_t)c->l_qseq < 0)
		return 1;

	return 0;
}

int good2()
{
	size_t uvar;
	// ok
	if ((int32_t)uvar >= 0)
		return 1;

	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
