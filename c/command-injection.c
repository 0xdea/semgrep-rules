// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

void invoke1(char *string)
{
	char buf[] = "uname -a; id";

	// ok: raptor-command-injection
	system(buf);

	// ok: raptor-command-injection
	system("whoami");

	// ruleid: raptor-command-injection
	system(string);
}

void invoke2(char *string)
{
	char buf[] = "uname -a; id";

	// ok: raptor-command-injection
	popen(buf, "r");

	// ok: raptor-command-injection
	popen("whoami", "r");

	// ruleid: raptor-command-injection
	popen(string, "r");
}

void invoke2(char *string)
{
	// ok: raptor-command-injection
	execl("/bin/ls", "ls", "-l", "/home", (char *)0);
	// ruleid: raptor-command-injection
	execl("/bin/ls", "ls", "-l", string, (char *)0);

	// ok: raptor-command-injection
	execlp("ls", "ls", "-l", "/home", (char *)0);
	// ruleid: raptor-command-injection
	execlp("ls", "ls", "-l", string, (char *)0);

	char *envp[] = { "MY_VAR=42", NULL };
	// ok: raptor-command-injection
	execle("/bin/ls", "ls", "-l", "/home", (char *)0, envp);
	// ruleid: raptor-command-injection
	execle("/bin/ls", "ls", "-l", string, (char *)0, envp);

	char *envp[] = { "MY_VAR=42", NULL };
	// ok: raptor-command-injection
	execlpe("ls", "ls", "-l", "/home", (char *)0, envp);
	// ruleid: raptor-command-injection
	execlpe("ls", "ls", "-l", string, (char *)0, envp);

	char *argv[] = { "ls", "-l", "/home", NULL };
	// ok: raptor-command-injection
	execv("/bin/ls", argv);
	// ruleid: raptor-command-injection
	char *argv[] = { "ls", "-l", string, NULL };
	execv("/bin/ls", argv);

	char buf[] = "/home"
	// ok: raptor-command-injection
	char *argv[] = { "ls", "-l", buf, NULL };
	execvp("ls", argv);
	// ruleid: raptor-command-injection
	char *argv[] = { "ls", "-l", string, NULL };
	execvp("ls", argv);

	char *argv[] = { "ls", "-l", "/home", NULL };
	char *envp[] = { "MY_VAR=42", NULL };
	// ok: raptor-command-injection
	execve("/bin/ls", argv, envp);

	char *argv[] = { "ls", "-l", string, NULL };
	char *envp[] = { "MY_VAR=42", NULL };
	// ruleid: raptor-command-injection
	execve("/bin/ls", argv, envp);

	char *argv[] = { "ls", "-l", "/home", NULL };
	char *envp[] = { "MY_VAR=42", NULL };
	// ok: raptor-command-injection
	execvpe("ls", argv, envp);

	char *argv[] = { "ls", "-l", string, NULL };
	char *envp[] = { "MY_VAR=42", NULL };
	// ruleid: raptor-command-injection
	execvpe("ls", argv, envp);
}

int send_mail(char *user) 
{
	char buf[1024];
	FILE *fp;

	snprintf(buf, sizeof(buf), "/usr/bin/sendmail -s \"hi\" %s", user);

	// ruleid: raptor-command-injection
   	fp = popen(buf, "w");

   	if (fp == NULL)
	   	return 1;
	// ...
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
