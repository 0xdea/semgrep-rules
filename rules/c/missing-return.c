// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

// ok: raptor-missing-return
int bad();

// ok: raptor-missing-return
int baddie(int foo);

// ruleid: raptor-missing-return
int bad1(void)
{
	printf("Hello, World!");
}

// ok: raptor-missing-return
void good1(void)
{
	printf("Hello, World!");
}

// ok: raptor-missing-return
int main(int argc, char **argv)
{
	printf("Hello, World!");
	return 0;
}
