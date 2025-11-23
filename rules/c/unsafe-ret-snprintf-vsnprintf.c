// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define SIZE(x, y) (sizeof(x)((y)(x)))

void copy_string(char *string)
{
	char buf[BUFSIZE];
	size_t length;

	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	length = snprintf(buf, BUFSIZE, "%s", string);

	// use length to access buf
}

void bad()
{
	char buf[1024], *ptr;
	ptr = buf;
	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	ptr += snprintf(ptr, SIZE(buf, ptr), "user: %s\n", username);
	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	ptr += snprintf(ptr, SIZE(buf, ptr), "pass: %s\n", password);
}

#define PRIx64 "llx"

void bad2()
{
	// ...

	// excluded due to the format string regex used to reduce false positives
	// todoruled: raptor-unsafe-ret-snprintf-vsnprintf
	len = snprintf(buf, sizeof(buf) - 1,
				   "Fluent Bit has been running: "
				   " %i day%s, %i hour%s, %i minute%s and %i second%s",
				   days, (days > 1) ? "s" : "", hours,
				   (hours > 1) ? "s" : "", minutes,
				   (minutes > 1) ? "s" : "", seconds,
				   (seconds > 1) ? "s" : "");

	// ...
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
