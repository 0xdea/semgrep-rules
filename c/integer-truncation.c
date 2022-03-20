// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

int assign_int(int int_var)
{
	// ruleid: integer-truncation
	char char_var = int_var;
	short short_var;

	// ruleid: integer-truncation
	short_var = int_var;
}

int assign_long(long long_var)
{
	short short_var;
	// ruleid: integer-truncation
	int int_var = long_var;

	// ruleid: integer-truncation
	short_var = long_var;
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
