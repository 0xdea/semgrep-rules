// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 256

int alloc_and_free1()
{
	int bailout = 1;
	char *ptr = (char *)malloc(MEMSIZE);

	// this should be catched but it isn't, due to a documented limitation in semgrep
	// https://semgrep.dev/docs/writing-rules/pattern-syntax/#ellipses-and-statement-blocks
	if (bailout) 
		free(ptr);

	// ruleid: raptor-double-free
	free(ptr);
	free(ptr);
}

int alloc_and_free2()
{
	char *ptr = (char *)malloc(MEMSIZE);

	// ok: raptor-double-free
	free(ptr);
	ptr = NULL;
	free(ptr);
}

int alloc_and_free3()
{
	char *ptr = (char *)malloc(MEMSIZE);

	// ok: raptor-double-free
	free(ptr);
	ptr = (char *)malloc(MEMSIZE);
	free(ptr);
}

int double_free(int argc, char **argv) 
{
	char *buf1R1;
	char *buf2R1;
	char *buf1R2;
	buf1R1 = (char *) malloc(BUFSIZE2);
	buf2R1 = (char *) malloc(BUFSIZE2);
	free(buf1R1);
	// ruleid: raptor-double-free
	free(buf2R1);
	buf1R2 = (char *) malloc(BUFSIZE1);
	strncpy(buf1R2, argv[1], BUFSIZE1-1);
	free(buf2R1);
	free(buf1R2);
}

int Packet *getNextPacket() 
{
	Packet *y = (Packet *) malloc(1024);
	retval = waitForPacket(y);
	if(retval == OK) {
		return y;
  	} else {
     		return NULL;
  	}
}

int bad()
{
	// ruleid: raptor-double-free
	free(logData);
	pkt = getNextPacket();
	if(!pkt) {
     		return NULL;
	}
	logPktData(pkt);
	free(logData);
	processPacket(pkt);
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
