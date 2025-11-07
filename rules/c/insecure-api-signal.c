// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char *logMessage;

void handler(int sigNum)
{
	syslog(LOG_NOTICE, "%s\n", logMessage);
	free(logMessage);

	sleep(10);
	exit(0);
}

int main(int argc, char *argv[])
{
	logMessage = strdup(argv[1]);

	// ruleid: raptor-insecure-api-signal
	signal(SIGHUP, handler);
	// ruleid: raptor-insecure-api-signal
	signal(SIGTERM, handler);

	sleep(10);

	return 0;
}
