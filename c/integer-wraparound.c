// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

int bad1()
{
	img_t table_ptr;
	int num_imgs;

	// ...

	num_imgs = get_num_imgs();
	// ruleid: raptor-integer-wraparound
	table_ptr = (img_t*)malloc(sizeof(img_t)*num_imgs);

	// ...
}

int bad2()
{
	int nresp = packet_get_int();

	if (nresp > 0) {
		// ruleid: raptor-integer-wraparound
		response = malloc(nresp*sizeof(char*));
		for (int i = 0; i < nresp; i++) 
			response[i] = packet_get_string(NULL);
	}
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
