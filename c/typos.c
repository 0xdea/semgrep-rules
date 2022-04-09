// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int bad1()
{
	char *src, *dst;
	int left;

	while (*src && left) {
   		*dst++=*src++;
		// ruleid: raptor-typos
   		if (left = 0) {
       			die("badlen");
		}
		left--;
	}
}

void
good1(char *path, char *dir, char *obj)
{
	char *last;

	// ok: raptor-typos
   	if ( (last = strrchr(path,'/')) != NULL ) {
		strcpy(obj, last + 1);
      		if (last == path) {
			strcpy(dir, "/");
		} else {
			*last = '\0';
			strcpy(dir, path);
			*last = '/';
		}
   	} else {
		dir[0] = dir[0] = '\0';
	}
}

int bad2(char *username)
{
	int f;
	f = get_security_flags(username);
	
	// ruleid: raptor-typos
	if (f = FLAG_AUTHENTICATED) {
		return LOGIN_OK;
	}
	return LOGIN_FAILED;
}

int bad3(char *src, char *dst)
{
	// ruleid: raptor-typos
	if (get_string(src) &&
		check_for_overflow(src) & copy_string(dst, src)) {
		printf("string safely copied\n");
	}
}

int bad4(char *src, int len)
{
	char dst[256];

	// ruleid: raptor-typos
	if (len > 0 && len <= sizeof(dst)); 
		memcpy(dst, src, len);
}

int bad5(char *src, char *dst)
{
	int i;
	// ruleid: raptor-typos
	for (i == 5; src[i] && i < 10; i++) {
		dst[i - 5] = src[i];
	}
}

int bad6(char *userinput)
{
	// ruleid: raptor-typos
	char buf[040];

	snprintf(buf, 40, "%s", userinput);
}

int bad7()
{
	// ruleid: raptor-typos
	if (frag_len &
		!BUF_MEM_grow_clean(s->init_buf, (int)frag_len +
		DTLS1_HM_HEADER_LENGTH + s->init_num)) {
			SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT, ERR_R_BUF_LIB);
		goto err; 
	}
}

int bad8(int j)
{
	int i = 10;

	// ruleid: raptor-typos
	i =+ j;
}

int isValid(int value) 
{
	// ruleid: raptor-typos
	if (value = 100) {
		printf("Value is valid\n");
		return(1);
	}

	printf("Value is not valid\n");
	return(0);
}

void processString (char *str) 
{
	int i;

	for(i = 0; i < strlen(str); i++) {
		if (isalnum(str[i])){
			processChar(str[i]);
		// ruleid: raptor-typos
		} else if (str[i] = ':') {
			movingToNewInput();
		}
	}
}

#define SIZE 50
int *tos, *p1, stack[SIZE];

void push(int i) 
{
	p1++;
	if (p1 == (tos + SIZE)) {
		printf("Print stack overflow error message and exit\n");
	}
	// ruleid: raptor-typos
	*p1 == i;
}

int pop(void) 
{
	if (p1 == tos) {
		printf("Print stack underflow error message and exit\n");
	}
	p1--;
	return *(p1 + 1);
}

int main(int argc, char *argv[]) 
{
	tos = stack;
	p1 = stack;
	// ...
	return 0;
}
