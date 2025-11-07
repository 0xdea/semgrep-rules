// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

void copy_append_string(char *string1, char *string2)
{
	char buf[BUFSIZE];

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	strcpy(buf, string1);

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	strcat(buf, string2);
}

void copy_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	stpcpy(buf, string);
}

void test_func()
{
	struct hostent *clienthp;
	char hostname[MAX_LEN];

	// ...

	int count = 0;
	for (count = 0; count < MAX_CONNECTIONS; count++)
	{

		int clientlen = sizeof(struct sockaddr_in);
		int clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, &clientlen);

		if (clientsocket >= 0)
		{
			clienthp = gethostbyaddr((char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
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

char *read_command(int sockfd)
{
	char username[32], buffer[1024];
	int n;

	if ((n = read(sockfd, buffer, sizeof(buffer) - 1) <= 0))
		return NULL;
	buffer[n] = '\0';

	switch (buffer[0])
	{
	case 'U':
		// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
		strcpy(username, &buffer[1]);
		break;
		// ...
	}
}

int process_email(char *email)
{
	char username[32], domain[128], *delim;
	int c;

	delim = strchr(email, '@');

	if (!delim)
		return -1;

	*delim++ = '\0';

	if (strlen(email) >= sizeof(username))
		return -1;

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	strcpy(username, email);

	if (strlen(delim) >= sizeof(domain))
		return -1;

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	strcpy(domain, delim);

	if (!strchr(delim, '.'))
		// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
		strcat(domain, default_domain);

	// ...
}

void process_address(int sockfd)
{
	char username[256], domain[256], netbuf[256], *ptr;

	read_data(sockfd, netbuf, sizeof(netbuf));

	ptr = strchr(netbuf, ':');

	if (ptr)
		*ptr++ = '\0';

	// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
	strcpy(username, netbuf);

	if (ptr)
		// ruleid: raptor-insecure-api-strcpy-stpcpy-strcat
		strcpy(domain, ptr);

	// ...
}

int main()
{
	printf("Hello, World!");
	return 0;
}
