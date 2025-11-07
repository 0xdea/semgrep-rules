// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>

void drop_priv_perm()
{
	// ruleid: raptor-unchecked-ret-setuid-seteuid
	setuid(getuid());
}

int drop_priv_perm2()
{
	// ok: raptor-unchecked-ret-setuid-seteuid
	if (!setuid(getuid()))
	{
		// ...
		return 0;
	}
	return -1;
}

void drop_priv_temp()
{
	// ruleid: raptor-unchecked-ret-setuid-seteuid
	seteuid(getuid());
}

int drop_priv_temp2()
{
	// ok: raptor-unchecked-ret-setuid-seteuid
	if (seteuid(getuid()) < 0)
		return -1;

	// ...
}

int main()
{
	printf("Hello, World!");
	return 0;
}
