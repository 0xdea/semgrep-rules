// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <stdlib.h>

void bad1()
{
	BarObj *ptr = new BarObj()

		// ruleid: raptor-mismatched-memory-management-cpp
		free(ptr);
}

void good1()
{
	BarObj *ptr = new BarObj()

		// ok: raptor-mismatched-memory-management-cpp
		delete ptr;
}

class A
{
	void bad2();
	void good2();
};

void A::bad2()
{
	int *ptr;
	ptr = (int *)malloc(sizeof(int));

	// ruleid: raptor-mismatched-memory-management-cpp
	delete ptr;
}

void A::good2()
{
	int *ptr;
	ptr = (int *)malloc(sizeof(int));

	// ok: raptor-mismatched-memory-management-cpp
	free(ptr);
}

class B
{
	void bad3(bool);
	void good3();
};

void B::bad3(bool heap)
{
	int localArray[2] = {11, 22};
	int *p = localArray;

	if (heap)
	{
		p = new int[2];
	}

	// ruleid: raptor-mismatched-memory-management-cpp
	delete[] p;
}

void B::good3()
{
	int localArray[2] = {11, 22};
	int *p = localArray;

	p = new (std::nothrow) int[2];

	// ok: raptor-mismatched-memory-management-cpp
	delete[] p;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
