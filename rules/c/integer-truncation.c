// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

void assign_int(int int_var)
{
	// ruleid: raptor-integer-truncation
	char char_var = int_var;
	short short_var;
	int int_var2;

	// ruleid: raptor-integer-truncation
	short_var = int_var;

	// ok: raptor-integer-truncation
	int_var2 = int_var + 1;
}

void assign_long(long long_var)
{
	short short_var;
	// ruleid: raptor-integer-truncation
	int int_var = long_var + 1;

	// ruleid: raptor-integer-truncation
	short_var = long_var;

	// ok: raptor-integer-truncation
	long long_var2 = long_var + 1;
}

void test_func()
{
	int intPrimitive;
	short shortPrimitive;
	intPrimitive = (int)(~((int)0) ^ (1 << (sizeof(int) * 8 - 1)));
	// ruleid: raptor-integer-truncation
	shortPrimitive = intPrimitive;
	printf("Int MAXINT: %d\nShort MAXINT: %d\n", intPrimitive, shortPrimitive);
}

// ruleid: raptor-integer-truncation
char func(void)
{
	int a = 42;
	return a;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
