// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

int copy_append_string(char *string1, char *string2)
{
	char buf[BUFSIZE];

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	strcpy(buf, string1);

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	strcat(buf, string2);
}

int copy_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	stpcpy(buf, string);
}

int test_func()
{
	struct hostent *clienthp;
	char hostname[MAX_LEN];

	// ...

	int count = 0;
	for (count = 0; count < MAX_CONNECTIONS; count++) {

		int clientlen = sizeof(struct sockaddr_in);
		int clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, &clientlen);

		if (clientsocket >= 0) {
			clienthp = gethostbyaddr((char*) &clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
			// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
			strcpy(hostname, clienthp->h_name);
			logOutput("Accepted client connection from host ", hostname);

			// ...

			close(clientsocket);
		}
	}
	close(serversocket);

	// ...
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
