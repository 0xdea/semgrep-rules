// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

void alloc_and_free1()
{
	int err = 1, bailout = 0;
	char *ptr = (char *)malloc(MEMSIZE);

	// this should be caught but it isn't, due to a documented limitation in semgrep
	// https://semgrep.dev/docs/writing-rules/pattern-syntax/#ellipses-and-statement-blocks
	// todoruleid: raptor-use-after-free
	if (err)
	{
		bailout = 1;
		free(ptr);
	}
	if (bailout)
		fprintf(stderr, "error: %p\n", ptr);

	free(ptr);
	// ruleid: raptor-use-after-free
	fprintf(stderr, "error: %p\n", ptr);
}

void alloc_and_free2()
{
	char *ptr = (char *)malloc(MEMSIZE);

	free(ptr);
	ptr = (char *)malloc(MEMSIZE);
	// ok: raptor-use-after-free
	fprintf(stderr, "error: %p\n", ptr);
}

void uaf(int argc, char **argv)
{
	char *buf1R1;
	char *buf2R1;
	char *buf2R2;
	char *buf3R2;
	buf1R1 = (char *)malloc(BUFSIZER1);
	buf2R1 = (char *)malloc(BUFSIZER1);
	free(buf2R1);
	buf2R2 = (char *)malloc(BUFSIZER2);
	buf3R2 = (char *)malloc(BUFSIZER2);
	// ruleid: raptor-use-after-free
	strncpy(buf2R1, argv[1], BUFSIZER1 - 1);
	free(buf1R1);
	free(buf2R2);
	free(buf3R2);
}

// https://docs.microsoft.com/en-us/cpp/sanitizers/error-heap-use-after-free
int heap_use_after_free()
{
	char *x = (char *)malloc(10 * sizeof(char));
	free(x);

	// ...

	// ruleid: raptor-use-after-free
	return x[5];
}

char test()
{
	char *ptr = (char *)malloc(10 * sizeof(char));
	free(ptr);

	// ruleid: raptor-use-after-free
	return *ptr;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct name
{
	char *myname;
	void (*func)(char *str);
} NAME;

void other_func(char *ignored) {}
void refreencode(char *ignored) {}

int bad_code1()
{
	NAME *var;
	char buf[10];
	var = (NAME *)malloc(sizeof(struct name));
	free(var);
	// ruleid: raptor-use-after-free
	strcpy(buf, (char *)var);
	// ruleid: raptor-use-after-free
	other_func((char *)(*var));
	// ruleid: raptor-use-after-free
	other_func((char *)var[0]);
	// ruleid: raptor-use-after-free
	var->func(var->myname);
	return 0;
}

int bad_code2()
{
	NAME *var;
	char buf[10];
	var = (NAME *)malloc(sizeof(struct name));
	free(var);
	// ruleid: raptor-use-after-free
	strcpy(buf, (char *)*var);
	// ruleid: raptor-use-after-free
	other_func((char *)var);
	// ruleid: raptor-use-after-free
	other_func((char *)var->myname);
	return 0;
}

int okay_code1()
{
	NAME *var;
	var = (NAME *)malloc(sizeof(struct name));
	free(var);
	var = NULL;
	// This will segmentation fault
	// ok: raptor-use-after-free
	other_func((char *)var);
	other_func((char *)var->myname);
	other_func((char *)*var);
	return 0;
}

int okay_code2()
{
	NAME *var;
	var = (NAME *)malloc(sizeof(struct name));
	free(var);
	var = NULL;
	var = (NAME *)malloc(sizeof(struct name));
	// ok: raptor-use-after-free
	other_func((char *)var);
	other_func((char *)var->myname);
	other_func((char *)*var);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct name {
    char *myname;
    void (*func)(char *str);
} NAME;

void other_func(char *ignored) {}

int bad_code1() {
    NAME *var;
    var = (NAME *)malloc(sizeof(struct name));
    free(var);
    // ruleid: raptor-use-after-free
    var->func("use after free");
    return 0;
}

int okay_code1() {
    NAME *var;
    var = (NAME *)malloc(sizeof(struct name));
    free(var);
    var = NULL;
    // This will segmentation fault
    // ok: raptor-use-after-free
    var->func("use after free");
    return 0;
}

int bad_code2() {
    NAME *var;
    var = (NAME *)malloc(sizeof(struct name));
    free(var);
    // ruleid: raptor-use-after-free
    other_func(var->myname);
    return 0;
}

int okay_code2() {
    NAME *var;
    var = (NAME *)malloc(sizeof(struct name));
    free(var);
    var = NULL;
    // This will segmentation fault
    // ok: raptor-use-after-free
    other_func(var->myname);
    return 0;
}

struct NAME {
  char first_name[32];
  int auth;
} s_auth;

int bad_code3(){
    struct NAME *var;
    var = malloc(sizeof(s_auth));
    free(var);
    // ruleid: raptor-use-after-free
    if(var->auth){
        printf("you have logged in already");
    }
    else{
        printf("you do not have the permision to log in.");
    }
    return 0;

}


int ok_code3(){
    struct NAME *var;
    var = malloc(sizeof(s_auth));
    free(var);
    var=NULL;
    // ok: raptor-use-after-free
    if(var->auth){
        printf("you have logged in already");
    }
    else{
        printf("you do not have the permision to log in.");
    }
    return 0;

}

struct lv {
    int length;
    char *value;
} lv;

struct lv2 {
    int length;
    struct lv *lv;
} lv2;


int bad_code4(){
    int initial = 1000;
    struct lv *lv = malloc(sizeof(*lv));
    lv->length = initial;
    lv->value = malloc(initial);
    free(lv);
    // ruleid: raptor-use-after-free
    free(lv->value);
    return 0;
}

int ok_code4(){
    int initial = 1000;
    struct lv *lv = malloc(sizeof(*lv));
    lv->length = initial;
    lv->value = malloc(initial);
    // ok: raptor-use-after-free
    free(lv->value);
    // ok: raptor-use-after-free
    free(lv);
    return 0;
}

int bad_code5(){
    int initial = 1000;
    struct lv *lv = malloc(sizeof(*lv));
    lv->length = initial;
    lv->value = malloc(initial);

    struct lv2 *lv2 = malloc(sizeof(*lv2));
    lv2->length = initial;
    lv2->lv = lv;
    // ok: raptor-use-after-free
    free(lv2->lv);
    // ruleid: raptor-use-after-free
    free(lv2->lv->value);
    // ok: raptor-use-after-free
    free(lv2);
    return 0;
}


int ok_code5(){
    int initial = 1000;
    struct lv *lv = malloc(sizeof(*lv));
    lv->length = initial;
    lv->value = malloc(initial);

    struct lv2 *lv2 = malloc(sizeof(*lv2));
    lv2->length = initial;
    lv2->lv = lv;
    // ok: raptor-use-after-free
    free(lv2->lv->value);
    // ok: raptor-use-after-free
    free(lv2->lv);
    // ok: raptor-use-after-free
    free(lv2);
    return 0;
}

int bad_code6() {
    NAME *var;
    var = (NAME *)malloc(sizeof(struct name));
    free(var);
    // ruleid: raptor-use-after-free
    (*var).func("use after free");
    return 0;
}

int ok_code6() {
    NAME *var;
    var = (NAME *)malloc(sizeof(struct name));
    free(var);
    var = (NAME *)malloc(sizeof(struct name));
    // ok: raptor-use-after-free
    (*var).func("use after free");
    return 0;
}


int bad_code7() {
    char *var;
    char buf[10];
    var = (char *)malloc(100);
    free(var);
    // ruleid: raptor-use-after-free
    char buf[0] = var[0];
    // ruleid: raptor-use-after-free
    strcpy(buf, var);
    return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
