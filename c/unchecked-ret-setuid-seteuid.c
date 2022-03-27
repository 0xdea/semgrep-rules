// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>

int drop_priv_perm()
{
	// ruleid: unchecked-ret-setuid-seteuid
	setuid(getuid());
}

int drop_priv_perm2()
{
	// ok
	if (!setuid(getuid())) {
		// do stuff
		return 0;
	}
	return -1;
}

int drop_priv_temp()
{
	// ruleid: unchecked-ret-setuid-seteuid
	seteuid(getuid());
}

int drop_priv_temp2()
{
	// ok
	if (seteuid(getuid()) < 0)
		return -1;

	// do stuff
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
