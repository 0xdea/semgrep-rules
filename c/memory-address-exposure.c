// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

int print_address(char *string)
{
	char buf[BUFSIZE];
	char fmt[] = "whatever";

	// ruleid: raptor-memory-address-exposure
	printf("address: %p\n", buf);

	// ruleid: raptor-memory-address-exposure
	sprintf(buf, "address: %x\n", string);

	// ok: raptor-memory-address-exposure (probably)
	sprintf(buf, FMT, string);

	// ok: raptor-memory-address-exposure (probably)
	sprintf(buf, fmt, string);

	// ok: raptor-memory-address-exposure (probably)
	sprintf(buf, string);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
