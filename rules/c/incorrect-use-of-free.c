// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define SIZE 256

void wrong()
{
	record_t bar[MAX_SIZE];

	/* do something interesting with bar */

	// ruleid: raptor-incorrect-use-of-free
	free(bar);
}

void right()
{
	record_t *bar = (record_t *)malloc(MAX_SIZE * sizeof(record_t));

	/* do something interesting with bar */

	// ok: raptor-incorrect-use-of-free
	free(bar);
}

int check_auth(char *login, char *passwd)
{
	char *cpass;
	char *message;
	int i = 0;
	int stat = STATUS_INVALID;
	struct passwd *pwd;

	if ((pwd = getpwnam(login)) == NULL)
		return (STATUS_UNKNOWN);
	hisuid = pwd->pw_uid;
	haveuid = 1;
	if (hisuid < MIN_UNIX_UID)
		return (STATUS_BLOCKED);
	if (authenticate(login, passwd, &i, &message) == 0)
	{
		stat = STATUS_OK;
	}
	// ruleid: raptor-incorrect-use-of-free
	free(&message);
	return (stat);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
