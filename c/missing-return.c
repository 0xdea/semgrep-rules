// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

// ruleid: raptor-missing-return
int bad1()
{
	printf("Hello, World!");
}

// ok: raptor-missing-return
void good1()
{
	printf("Hello, World!");
}

// ok: raptor-missing-return
int main() 
{
	printf("Hello, World!");
	return 0;
}
