// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>

// https://pwning.systems/posts/php_filter_var_shenanigans/
static int _php_filter_validate_domain(char *domain, int len, zend_long flags)
{
	char *e, *s, *t;
	size_t l;
	int hostname = flags & FILTER_FLAG_HOSTNAME;
	unsigned char i = 1;

	s = domain;
	// ruleid: raptor-signed-unsigned-conversion
	l = len;
	e = domain + l;
	t = e - 1;

	// ...
	return 0;
}

// https://blog.quarkslab.com/heap-overflow-in-openbsds-slaacd-via-router-advertisement.html
char *
parse_dnssl(char *data, int datalen)
{
	int len, pos;
	char *nssl, *nsslp;

	// ruleid: raptor-signed-unsigned-conversion
	if ((nssl = calloc(1, datalen + 1)) == NULL)
	{ // false positive
		log_warn("malloc");
		return NULL;
	}
	nsslp = nssl;

	pos = 0;

	do
	{
		len = data[pos];
		if (len > 63 || len + pos + 1 > datalen)
		{
			free(nssl);
			log_warnx("invalid label in DNSSL");
			return NULL;
		}
		if (len == 0)
		{
			if (pos < datalen && data[pos + 1] != 0)
				*nsslp++ = ' ';
			else
				break;
		}
		else
		{
			if (pos != 0 && data[pos - 1] != 0)
				*nsslp++ = '.';
			// ruleid: raptor-signed-unsigned-conversion
			memcpy(nsslp, data + pos + 1, len);
			nsslp += len;
		}
		pos += len + 1;
	} while (pos < datalen);
	if (len != 0)
	{
		free(nssl);
		log_warnx("invalid label in DNSSL");
		return NULL;
	}
	return nssl;
}

// http://www.phrack.org/issues/60/10.html#article
int copy_something(char *buf, int len)
{
	char kbuf[800];

	if (len > sizeof(kbuf))
	{
		return -1;
	}

	// ruleid: raptor-signed-unsigned-conversion
	return memcpy(kbuf, buf, len);
}

// ruleid: raptor-signed-unsigned-conversion
unsigned int readdata()
{
	int amount = 0;

	if (result == ERROR)
		amount = -1;

	return amount;
}

// ruleid: raptor-signed-unsigned-conversion
unsigned int readdata2()
{
	int amount = 0;

	amount = accessmainframe();

	return amount;
}

void copy_memory()
{
	int size = 256;

	// ruleid: raptor-signed-unsigned-conversion
	memcpy(destBuf, srcBuf, size);
}

void test_func(int argc, char **argv)
{
	char path[256];
	char *input;
	int i;
	unsigned int sz;

	i = GetUntrustedInt();

	if (i > 256)
	{
		DiePainfully("go away!\n");
	}

	// ruleid: raptor-signed-unsigned-conversion
	sz = i;

	// ruleid: raptor-signed-unsigned-conversion
	strncpy(path, input, i);
	path[255] = '\0';
	printf("Path is: %s\n", path);
}

void blowup_stack()
{
	int a = 5, b = 6;
	// ruleid: raptor-signed-unsigned-conversion
	size_t len = a - b;
	char buf[len];
}

void disaster()
{
	int len;

	len = get_len_field();
	// ruleid: raptor-signed-unsigned-conversion
	snprintf(dst, len, "%s", src);
}

int watch_dns_ptr()
{
	char *indx;
	int count;
	char nameStr[256];

	// ...
	memset(nameStr, '\0', sizeof(nameStr));
	// ...
	indx = (char *)(pkt + rr_offset);
	count = (char)*indx;

	while (count)
	{
		(char *)indx++;
		// ruleid: raptor-signed-unsigned-conversion
		strncat(nameStr, (char *)indx, count);
		indx += count;
		count = (char)*indx;
		// there's also a strncat() misuse here
		strncat(nameStr, ".", sizeof(nameStr) - strlen(nameStr));
	}
	nameStr[strlen(nameStr) - 1] = '\0';

	return 0;
}

// https://vulncat.fortify.com/
void TypeConvert()
{
	char input[MAX];
	char output[MAX];

	fillBuffer(input);
	int len = getInputLength();

	if (len <= MAX)
	{
		// ruleid: raptor-signed-unsigned-conversion
		memcpy(output, input, len);
	}
	// ...
}

// https://vulncat.fortify.com/
char *processNext(char *strm)
{
	char buf[512];
	int len = *(int *)strm;

	strm += sizeof(len);
	if (len <= 512)
	{
		// ruleid: raptor-signed-unsigned-conversion
		memcpy(buf, strm, len);
		process(buf);
		return strm + len;
	}
	else
	{
		return -1;
	}
}

int main()
{
	printf("Hello, World!");
	return 0;
}
