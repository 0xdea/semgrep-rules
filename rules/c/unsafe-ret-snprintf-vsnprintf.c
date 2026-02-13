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

#include <iostream>

int test()
{
	char myname[5];
	// there is an overflow, but the source buffer is constant, so we're not really interested in this case
	// ok: raptor-unsafe-ret-snprintf-vsnprintf
	int ret = snprintf(myname, 10, "0123456789");

	char name2[5] = "1234";
	// ruleid: raptor-unsafe-ret-snprintf-vsnprintf
	int len = snprintf(0, 0, "My name is: %s", name2);
	char *p = (char *)malloc(len);
	snprintf(p, len, "My name is: %s", name2);

	// prints 123
	std::cout << p;

	return 0;
}

char *f(const char *input) {
    char buf[128];
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "%s", input);

    char *out = malloc(len + 1);
    // This isn't technically a vulnerability but it is suspicious:
    // * `snprintf(...)` will not return `-1` because the format string is valid
    // * `buf` will be NUL-terminated, because `128 > 0`
    // * `strncpy(...)` will only copy `max(strlen(buf), len + 1)` characters
    // * `strlen(buf)` is less than `len + 1`, so `out` will be NUL-terminated
    strncpy(out, buf, len + 1);

    // OOB read
    memcpy(out, buf, len + 1);

    return out;
}

char *non_string(const char *input, size_t n) {
    char buf[128];
    // ok: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "%u", n);

    memcpy(out, buf, len + 1);

    return out;
}

char *f(const char *input) {
    char buf[128];
    // there is a length check below
    // todook: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "any_cmd '%s'", input);
    if (len < 0 || len > 128 - 1) {
        return NULL;
    }

    char *out = malloc(len);
    strncpy(out, buf, len);
    return out;
}

char *f(const char *input) {
    char buf[128];
    // there is a length check below
    // todook: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "any_cmd '%s'", input);
    if (len >= sizeof(buf)) {
        return NULL;
    }

    char *out = malloc(len);
    strncpy(out, buf, len);
    return out;
}

char *f(const char *input) {
    char buf[128];
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "any_cmd '%s'", input);
    snprintf(buf, 128 - len, "foo");
}

char *f(const char *input) {
    char buf[128];
    // there is a length check below
    // todook: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "any_cmd '%s'", input);
    if (sizeof(buf) <= len) {
        return NULL;
    }

    char *out = malloc(len);
    strncpy(out, buf, len);
    return out;
}

size_t f(const char *input) {
    char buf[128];
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "input=%s", input);
    return strnlen(buf, len);
}

size_t f() {
    char buf[128];
    // ok: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "foo");
    return strnlen(buf, len);
}

size_t f(const char *input) {
    char buf[128];
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    int len = snprintf(buf, 128, "input=%s", input);
    return strncasecmp(buf, "input=foo", len);
}

void f(const char *input) {
    char buf[128];
    int len = 0;
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    len += snprintf(&buf[len], 128, "input=%s, input");
    return &buf[len] - buf;
}

void wide_strings(const wchar_t *input) {
    wchar_t buf[128];
    int len = 0;
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    len += snprintf(&buf[len], 128, "input=%ls, input");
    return &buf[len] - buf;
}

static char *gen_text(const char *prefix, const char *sub_prefix, char *buf, size_t sz)
{
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    int x = snprintf(buf, sz,  "%s-%s-", prefix, sub_prefix);

    // This isn't sanitized because of the `sz - 1` on the RHS
    for ( ; (size_t)x < sz - 1; x++)
        buf[x] = *prefix;

    buf[x++] = 'x';
    buf[x] = '\0';
    return buf;
}

static char *
int_to_roman(int number, const char *p)
{
    int len;
    // ruleid: raptor-unsafe-ret-snprintf-vsnprintf
    len = snprintf(numstr, sizeof(numstr), "%s", p);

    for (p = numstr; *p != '\0'; p++, --len) {
        foo();
    }

    for (p = numstr; *p != '\0'; p++, len--) {
        foo();
    }

    // TODO: `i < len` is a sanitizer so we can't match on it being used as a
    // loop condition

    for (; i < len;) {
        foo();
    }

    for (i = 0; i < len;) {
        foo();
    }

    for (; i < len; i++) {
        foo();
    }

    for (i = 0; i < len; i++) {
        foo();
    }

    for (int i = 0; i < len;) {
        foo();
    }

    for (int i = 0; i < len; i++) {
        foo();
    }

    for (int i = 0, j = 0; i < len; i++) {
        foo();
    }

    return result;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
