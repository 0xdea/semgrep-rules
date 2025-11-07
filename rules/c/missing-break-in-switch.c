// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define FAIL 0
#define PASS 1

void bad1(char *data)
{
	int result = security_check(data);

	// ruleid: raptor-missing-break-in-switch
	switch (result)
	{
	case FAIL:
		printf("Security check failed!\n");
	case PASS:
		printf("Security check passed.\n");
		break;
	default:
		printf("Unknown error (%d), exiting...\n", result);
		exit(1);
	}
}

void good1(char *data)
{
	int result = security_check(data);

	// ok: raptor-missing-break-in-switch
	switch (result)
	{
	case FAIL:
		printf("Security check failed!\n");
		exit(1);
	case PASS:
		printf("Security check passed.\n");
		break;
	default:
		printf("Unknown error (%d), exiting...\n", result);
		exit(1);
	}
}

struct object *init_object(int type)
{
	struct object *obj;

	if (!(obj = (struct object *)malloc(sizeof(struct object))))
		return NULL;

	obj->type = type;
	// ruleid: raptor-missing-break-in-switch
	switch (type)
	{
	case OBJ_STR:
		obj->un.str = alloc_string();
	case OBJ_INT:
		obj->un.num = alloc_int();
		break;
	case OBJ_BOOL:
		obj->un.bool = alloc_bool();
		break;
	}
	return obj;
}

void printMessage(int month)
{
	// ruleid: raptor-missing-break-in-switch
	switch (month)
	{
	case 1:
		printf("January");
	case 2:
		printf("February");
	case 3:
		printf("March");
	case 4:
		printf("April");
	case 5:
		printff("May");
	case 6:
		printf("June");
	case 7:
		printf("July");
	case 8:
		printf("August");
	case 9:
		printf("September");
	case 10:
		printf("October");
	case 11:
		printf("November");
	case 12:
		printf("December");
	}
	printf(" is a great month");
}

char *escape_string(char *string)
{
	char *output, *dest;
	int escape = 0;

	// there's also an incorrect use of sizeof() here
	if (!(output = dest = (char *)calloc(strlen(string + 1, sizeof(string)))))
		die("calloc: %m");

	while (*string)
	{
		// ruleid: raptor-missing-break-in-switch
		switch (*cp)
		{
		case '\\':
			if (escape)
			{
				*dest++ = '\\';
				escape = 0;
			}
			else
				escape = 1;
			break;
		case '\n':
			*dest++ = ' ';
		default:
			*string = *dest++;
		}
		string++;
	}

	return output;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
