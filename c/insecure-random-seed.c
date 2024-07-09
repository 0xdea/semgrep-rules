#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int example1() {
	// ruleid: raptor-insecure-random-seed
	srand(1234);
	printf("Random number: %d\n", rand());
	return 0;
}

int example2() {
	time_t t;
	time(&t);
	// ruleid: raptor-insecure-random-seed
	srand((unsigned int)t);
	printf("Random number: %d\n", rand());
	return 0;
}


int example3() {
	// ruleid: raptor-insecure-random-seed
	srand((unsigned int)getpid());
	printf("Random number: %d\n", rand());
	return 0;
}

int example4() {
	// ruleid: raptor-insecure-random-seed
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
		printf("Random number: %d\n", rand());
	}
	return 0;
}
int example5() {
	int seed = 42 * 42; 
	// ruleid: raptor-insecure-random-seed
	srand(seed);
	printf("Random number: %d\n", rand());
	return 0;
}

void example6(void) {
	struct timespec ts;
	if (timespec_get(&ts, TIME_UTC) == 0) {
		/* Handle error */
	} else {
		// ruleid: raptor-insecure-random-seed
		srandom(ts.tv_nsec ^ ts.tv_sec);
	for (unsigned int i = 0; i < 10; ++i) {
		printf("%ld, ", random());
	}
}