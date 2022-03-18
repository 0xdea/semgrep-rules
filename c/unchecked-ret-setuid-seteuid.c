// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>

int drop_priv_perm()
{
	// ruleid: unchecked-ret-setuid-seteuid
	setuid(getuid());
}

int drop_priv_temp()
{
	// ruleid: unchecked-ret-setuid-seteuid
	seteuid(getuid());
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
