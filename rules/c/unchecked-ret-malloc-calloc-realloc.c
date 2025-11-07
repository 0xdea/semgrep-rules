// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

void alloc_memory()
{
	// ruleid: raptor-unchecked-ret-malloc-calloc-realloc
	char *ptr = (char *)malloc(MEMSIZE);
}

int alloc_memory_and_check1()
{
	// ok: raptor-unchecked-ret-malloc-calloc-realloc
	char *ptr = (char *)malloc(MEMSIZE);
	if (ptr == NULL)
		return -1;

	// ...
	return 0;
}

int alloc_memory_and_check2()
{
	char *ptr;

	// ok: raptor-unchecked-ret-malloc-calloc-realloc
	if ((ptr = (char *)malloc(MEMSIZE)) != NULL)
	{
		// ...
		return 0;
	}
	return -1;
}

int alloc_memory_and_check3()
{
	// ok: raptor-unchecked-ret-malloc-calloc-realloc
	char *ptr = (char *)malloc(MEMSIZE);
	if (!ptr)
		return -1;

	// ...
	return 0;
}

int alloc_memory_and_check4()
{
	char *ptr;

	// ok: raptor-unchecked-ret-malloc-calloc-realloc
	if (!(ptr = (char *)malloc(MEMSIZE)))
		return -1;

	// ...
	return 0;
}

void test_func()
{
	// ruleid: raptor-unchecked-ret-malloc-calloc-realloc
	buf = (char *)malloc(req_size);
	strncpy(buf, xfer, req_size);
}

void test_func2()
{
	// ruleid: raptor-unchecked-ret-malloc-calloc-realloc
	AStruct *s = (AStruct *)malloc(user_len);
	s[user_offset] = 0xff;
}

int append_data(struct databuf *buf, char *src, size_t len)
{
	size_t new_size = buf->used + len + EXTRA;

	if (new_size < len)
		return -1;

	if (new_size > buf->allocated_length)
	{
		// ruleid: raptor-unchecked-ret-malloc-calloc-realloc
		buf->data = (char *)realloc(buf->data, new_size);
		buf->allocated_length = new_size;
	}

	memcpy(buf->data + buf->used, src, len);
	buf->used += len;

	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
