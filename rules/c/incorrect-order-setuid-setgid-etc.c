// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>

void drop_priv_bad()
{
	// ruleid: raptor-incorrect-order-setuid-setgid-etc
	setuid(getuid());
	setgid(getgid());
}

void drop_priv_ok()
{
	// ok: raptor-incorrect-order-setuid-setgid-etc
	setgid(getgid());
	setuid(getuid());
}

void bad1()
{
	// ruleid: raptor-incorrect-order-setuid-setgid-etc
	seteuid(getuid());
	// ...
	setuid(getuid());
}

void good1()
{
	// ok: raptor-incorrect-order-setuid-setgid-etc
	seteuid(getuid());
	// ...
	seteuid(0);
	// ...
	setuid(getuid());
}

void bad2()
{
	int user1 = 500, user2 = 501;

	/* become user1 */
	// ruleid: raptor-incorrect-order-setuid-setgid-etc
	seteuid(user1);
	process_log1();
	/* become user2 */
	seteuid(user2);
	process_log2();
	/* become root again */
	seteuid(0);
}

void good2()
{
	int user1 = 500, user2 = 501;

	/* become user1 */
	// ok: raptor-incorrect-order-setuid-setgid-etc
	seteuid(user1);
	process_log1();
	/* become user2 */
	seteuid(0);
	seteuid(user2);
	process_log2();
	/* become root again */
	seteuid(0);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
