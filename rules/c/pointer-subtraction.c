// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bad1(char *tmp, char *ptr1, char *ptr2)
{
	// ruleid: raptor-pointer-subtraction
	memcpy(tmp, ptr1, (ptr2 - ptr1) - 1);
}

int good1(char *tmp, char *ptr1, char *ptr2)
{
	if (!tmp || !ptr1 || !ptr2)
		return -1;

	if (ptr2 <= ptr1)
		return -1; // negative or zero-length copy

	// the rule should arguably check for this pattern of pointer subtraction with a length check,
	// which is a common pattern for safely handling pointer subtraction
	// todook: raptor-pointer-subtraction
	size_t len = (size_t)(ptr2 - ptr1) - 1;
	if (len == 0)
		return -1;

	memcpy(tmp, ptr1, len);
	return 0;
}

void bad2(char *ptr1, char *ptr2)
{
	// ruleid: raptor-pointer-subtraction
	char *tmp = (char *)malloc(ptr2 - ptr1);
}

struct node
{
	int data;
	struct node *next;
};

int size(struct node *head)
{
	struct node *current = head;
	struct node *tail;

	while (current != NULL)
	{
		tail = current;
		current = current->next;
	}

	// ruleid: raptor-pointer-subtraction
	return tail - head;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
