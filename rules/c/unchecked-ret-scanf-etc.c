// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

static int
parseuid_bad(const char *s, uid_t *uid)
{
	struct passwd *pw;
	const char *errstr;

	if ((pw = getpwnam(s)) != NULL)
	{
		*uid = pw->pw_uid;
		return 0;
	}
#if !defined(__linux__) && !defined(__NetBSD__)
	*uid = strtonum(s, 0, UID_MAX, &errstr);
#else
	// ruleid: raptor-unchecked-ret-scanf-etc
	sscanf(s, "%d", uid);
#endif
	if (errstr)
		return -1;
	return 0;
}

static int
parseuid_good(const char *s, uid_t *uid)
{
	struct passwd *pw;
#if !defined(__linux__) && !defined(__NetBSD__)
	const char *errstr = NULL;
#else
	int status;
#endif

	if ((pw = getpwnam(s)) != NULL)
	{
		*uid = pw->pw_uid;
		return 0;
	}
#if !defined(__linux__) && !defined(__NetBSD__)
	*uid = strtonum(s, 0, UID_MAX, &errstr);
	if (errstr)
		return -1;
#else
	// ok: raptor-unchecked-ret-scanf-etc
	status = sscanf(s, "%d", uid);
	if (status != 1)
		return -1;
#endif
	return 0;
}

int main(int argc, char *argv[])
{
	int i = 0, j = 0;
	printf("Enter two numbers:\n");
	// ruleid: raptor-unchecked-ret-scanf-etc
	scanf("%d %d", &i, &j);
	printf("Result = %d\n", i / j);
	return 0;
}
