// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int bad1()
{
	double *foo;

	// ruleid: raptor-incorrect-use-of-sizeof
	foo = (double *)malloc(sizeof(foo));
}

int good1()
{
	double *foo;

	// ok: raptor-incorrect-use-of-sizeof
	foo = (double *)malloc(sizeof(*foo));
}

int bad2(char *buf)
{
	size_t size;

	// ruleid: raptor-incorrect-use-of-sizeof
	size = sizeof(buf);
}

int good2()
{
	char buf[256];
	size_t size;
	
	// ok: raptor-incorrect-use-of-sizeof
	size = sizeof(buf);
}

int bad3()
{
	AnObj *o = (AnObj *) malloc(sizeof(AnObj));
	// ruleid: raptor-incorrect-use-of-sizeof
	memset(o, 0x0, sizeof(o));
}

char *read_username(int sockfd) 
{
	char *buffer, *style, userstring[1024]; 
	int i;

	buffer = (char *)malloc(1024);

	if (!buffer) {
		error("buffer allocation failed: %m"); 
		return NULL;
	}

	if (read(sockfd, userstring, sizeof(userstring) - 1) <= 0) { 
		free(buffer);
		error("read failure: %m");
		return NULL;
	}
	userstring[sizeof(userstring) - 1] = '\0';
	style = strchr(userstring, ':'); 

	if (style)
		*style++ = '\0';
	sprintf(buffer, "username=%.32s", userstring);

	if (style)
	// ruleid: raptor-incorrect-use-of-sizeof
		snprintf(buffer, sizeof(buffer) - strlen(buffer) - 1, ", style=%s\n", style);

	return buffer;
}

char *username = "admin";
char *pass = "password";

int AuthenticateUser(char *inUser, char *inPass) 
{
	// ruleid: raptor-incorrect-use-of-sizeof
	printf("Sizeof username = %d\n", sizeof(username));
	// ruleid: raptor-incorrect-use-of-sizeof
	printf("Sizeof pass = %d\n", sizeof(pass));

	// ruleid: raptor-incorrect-use-of-sizeof
	if (strncmp(username, inUser, sizeof(username))) {
		printf("Auth failure of username using sizeof\n");
		return(AUTH_FAIL);
	}

	// ruleid: raptor-incorrect-use-of-sizeof
	if (!strncmp(pass, inPass, sizeof(pass))) {
		printf("Auth success of password using sizeof\n");
		return(AUTH_SUCCESS);
	} else {
		printf("Auth fail of password using sizeof\n");
		return(AUTH_FAIL);
		}
}

int main (int argc, char **argv)
{
	int authResult;

	if (argc < 3) {
		ExitError("Usage: Provide a username and password");
	}
	authResult = AuthenticateUser(argv[1], argv[2]);
	if (authResult != AUTH_SUCCESS) {
		ExitError("Authentication failed");
	} else {
		DoAuthenticatedTask(argv[1]);
	}
}
