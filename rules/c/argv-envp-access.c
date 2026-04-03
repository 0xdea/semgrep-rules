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

int main(int c, char **v)
{
	char cmd[CMD_MAX] = "/usr/bin/cat ";
	// this should arguably trigger the detection, but it doesn't because the rule is currently extremely
	// simple and only looks for "argv" and "envp" as variable names, not for the actual parameters of main()
	// todoruleid: raptor-argv-envp-access
	strcat(cmd, v[1]);
	system(cmd);

	return 0;
}
