// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define CMD_MAX 512

int main(int argc, char **argv)
{
	char cmd[CMD_MAX] = "/usr/bin/cat ";
	// ruleid: raptor-argv-envp-access
	strcat(cmd, argv[1]);
	system(cmd);

	return 0;
}
