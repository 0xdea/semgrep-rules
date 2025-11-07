// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BUFSIZE 256

void bad1(char *string)
{
	char buf[BUFSIZE];

	strncpy(buf, string, BUFSIZE);
	// ruleid: raptor-off-by-one
	buf[BUFSIZE] = '\0';
}

void good1(char *string)
{
	char buf[BUFSIZE];

	strncpy(buf, string, BUFSIZE);
	// ok: raptor-off-by-one
	buf[BUFSIZE - 1] = '\0';
}

void bad2(char *string)
{
	char firstname[20];
	char lastname[20];
	char fullname[40];

	fullname[0] = '\0';

	// ruleid: raptor-off-by-one
	strncat(fullname, firstname, 40);
}

void good2(char *string)
{
	char firstname[20];
	char lastname[20];
	char fullname[40];

	fullname[0] = '\0';

	// ok: raptor-off-by-one
	strncat(fullname, firstname, sizeof(fullname) - strlen(fullname) - 1);
}

void bad3(char *string)
{
	char filename[BUFSIZE];

	// commented-out because of too many false positives: raptor-off-by-one
	for (int i = 0; i <= BUFSIZE; i++)
	{
		char c = getc();
		if (c == 'EOF')
		{
			filename[i] = '\0';
		}
		filename[i] = getc(stdin);
	}
}

void good3(char *string)
{
	char filename[BUFSIZE];

	// ok: raptor-off-by-one
	for (int i = 0; i < BUFSIZE; i++)
	{
		char c = getc();
		if (c == 'EOF')
		{
			filename[i] = '\0';
		}
		filename[i] = getc(stdin);
	}
}

void test_func()
{
	int id_sequence[3];

	id_sequence[0] = 123;
	id_sequence[1] = 234;
	id_sequence[2] = 345;
	// ruleid: raptor-off-by-one
	id_sequence[3] = 456;
}

void processRawStr(uint8_t *s, size_t sz)
{
	uint8_t buf[1024];
	memset(buf, 0x0, sizeof(buf));
	memcpy(buf, s, sizeof(buf));
	// ruleid: raptor-off-by-one
	buf[sizeof(buf)] = '\0';
	// ...
}

void process_string(char *src)
{
	char dest[32];

	// commented-out because of too many false positives: raptor-off-by-one
	for (i = 0; src[i] && (i <= sizeof(dest)); i++)
		dest[i] = src[i];

	// ...

	return;
}

void get_user(char *user)
{
	char buf[1024];

	// ruleid: raptor-off-by-one
	if (strlen(user) > sizeof(buf))
		die("error: user string too long\n");

	strcpy(buf, user);
	// ...
}

int get_mac(int fd, struct session *session)
{
	unsigned int i, n;

	n = read_network_integer(fd);
	if (n > MAX_MAC)
		return 1;

	// commented-out because of too many false positives: raptor-off-by-one
	for (i = 0; i <= n; i++)
		session->mac[i] = read_network_integer(fd);
	return 0;
}

int variant1(int argc, char *argv[])
{
	char buf[10];

	// ruleid: raptor-off-by-one
	*(buf + 10) = 'A';

	return 0;
}

int variant2(int argc, char *argv[])
{
	char bStr[10];
	// commented-out because of too many false positives: raptor-off-by-one
	for (unsigned i = 1; i <= 10; ++i)
	{
		bStr[i] = (char)i + 'a';
	}
	return 0;
}

static LabelText *text_create(char *orig_str, int char_width)
{
	int i, j;
	char line[256]; /* a line should not exceed this length */
	int pos;
	int last_space;
	int new_line;
	LabelText *text = 0;
	char *str = 0;
	text = calloc(1, sizeof(LabelText));

	str = strdup(orig_str);

	if (char_width > 0)
	{
		for (i = 0; i < strlen(str); i++)
			if (str[i] == 10)
				text->count++;

		// ruleid: raptor-off-by-one
		if (str[strlen(str) - 1] != 10)
			text->count++;
	}

	return NULL;
}

void addLineAfter(struct line *whichLine, char *data)
{
	struct line *temp = whichLine->next;
	struct line *newLine = (struct line *)malloc(sizeof(struct line));
	temp->prev = newLine;
	whichLine->next = newLine;
	newLine->next = temp;
	newLine->prev = whichLine;
	// ruleid: raptor-off-by-one
	newLine->data = (char *)malloc(strlen(data));
	strcpy(newLine->data, data);
	newLine->length = strlen(data);
	countTabs(newLine);
	currentBuffer->numLines++;
}

void addLineAfter_fixed(struct line *whichLine, char *data)
{
	struct line *temp = whichLine->next;
	struct line *newLine = (struct line *)malloc(sizeof(struct line));
	temp->prev = newLine;
	whichLine->next = newLine;
	newLine->next = temp;
	newLine->prev = whichLine;
	// ok: raptor-off-by-one
	newLine->data = (char *)malloc(strlen(data) + 1);
	strcpy(newLine->data, data);
	newLine->length = strlen(data);
	countTabs(newLine);
	currentBuffer->numLines++;
}

void flawed_strdup(const char *input)
{
	char *copy;

	// ruleid: raptor-off-by-one
	copy = (char *)malloc(strlen(input));
	strcpy(copy, input);
	return copy;
}

int two_dimensions(int argc, char *argv[])
{
	char buffer[1][256];
	// ruleid: raptor-off-by-one
	buffer[0][256] = '!';
	// ruleid: raptor-off-by-one
	buffer[1][1] = '!';
	// ok: raptor-off-by-one
	buffer[0][255] = '!';
	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
