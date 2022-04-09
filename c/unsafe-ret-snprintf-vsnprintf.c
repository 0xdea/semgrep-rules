// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define SIZE(x, y) (sizeof(x) ((y) (x)))

int copy_string(char *string)
{
	char buf[BUFSIZE];
	size_t length;

	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	length = snprintf(buf, BUFSIZE, "%s", string);

	// use length to access buf
}

int bad()
{
	char buf[1024], *ptr;
	ptr = buf;
	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	ptr += snprintf(ptr, SIZE(buf, ptr), "user: %s\n", username);
	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	ptr += snprintf(ptr, SIZE(buf, ptr), "pass: %s\n", password);
}

int log(int fd, char *fmt, ...) 
{
	char buffer[BUFSIZE]; 
	int n;
	va_list ap;

	va_start(ap, fmt);

	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	n = vsnprintf(buffer, sizeof(buffer), fmt, ap);

	if (n >= BUFSIZE - 2) 
		buffer[sizeof(buffer) - 2] = '\0';

	strcat(buffer, "\n");

	va_end(ap);

	write_log(fd, buffer, strlen(buffer));

	return 0; 
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
