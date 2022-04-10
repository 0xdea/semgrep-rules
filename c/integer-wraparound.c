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

// https://vulncat.fortify.com/
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

u_char *make_table(unsigned int width, unsigned int height, u_char *init_row)
{
	unsigned int n;
	int i;
	u_char *buf;

	n = width * height;

	// ruleid: raptor-integer-wraparound
	buf = (char *)malloc(n); 
	if (!buf)
		return NULL;
   	for (i = 0; i < height; i++)
		memcpy(&buf[i*width], init_row, width);

	return buf; 
}

// http://www.phrack.org/issues/60/10.html#article
int myfunction(int *array, int len){
        int *myarray, i;

	// ruleid: raptor-integer-wraparound
        myarray = malloc(len * sizeof(int));
        if(myarray == NULL){
            return -1;
        }

        for(i = 0; i < len; i++){
            myarray[i] = array[i];
        }

        return myarray;
}

int main() 
{
	printf("Hello, World!");
	return 0;
}
