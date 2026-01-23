// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <cstdint>
#include <cstddef>
#include <iostream>

struct Foo
{
	uint64_t a;
	uint8_t b;

	size_t get_size() const
	{
		// ruleid: raptor-incorrect-use-of-sizeof
		return sizeof(this);
	}

	size_t get_size() const
	{
		// ok: raptor-incorrect-use-of-sizeof
		return sizeof(*this);
	}
};

void test_001_fn(int arr[])
{
	// ruleid: raptor-incorrect-use-of-sizeof
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		arr[i] = 0;
	}

	// ruleid: raptor-incorrect-use-of-sizeof
	for (size_t i = 0; i < sizeof(arr) / 2; ++i)
	{
		arr[i] = 0;
	}

	// ruleid: raptor-incorrect-use-of-sizeof
	for (size_t i = 0; i < 3 * sizeof(arr); ++i)
	{
		arr[i] = 0;
	}
}

void test_001(int arr[])
{
	// ruleid: raptor-incorrect-use-of-sizeof
	for (size_t i = 0; i < sizeof(arr); ++i)
	{
		arr[i] = 0;
	}
}

void test_002()
{
	const FooType *foo_ptr = get_foo();

	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(foo_ptr);

	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(foo_ptr + 0);

	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(0 + foo_ptr);

	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << (sizeof(foo_ptr) / sizeof(foo_ptr[0]));

	// ok: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(*foo_ptr);
}

void test_002_pad()
{
	int a = 1;
	const FooType *foo_ptr = get_foo();

	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(foo_ptr);

	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << (sizeof(foo_ptr) / sizeof(foo_ptr[0]));

	// ok: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(*foo_ptr);
}

void test_002_atofat()
{
	int a = 1;
	const FooType **foo_ptr = get_foo();

	// ok: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(*foo_ptr);

	// ok: raptor-incorrect-use-of-sizeof
	std::cout << (sizeof(*foo_ptr) / sizeof(foo_ptr[0]));

	// ok: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(**foo_ptr);
}

void test_003(void *foo, int *int_ptr)
{
	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(int_ptr);

	// ruleid: raptor-incorrect-use-of-sizeof
	std::cout << (sizeof(int_ptr) / sizeof(int_ptr[0]));

	// ok: raptor-incorrect-use-of-sizeof
	std::cout << sizeof(*int_ptr);
}

int main()
{
	printf("Hello, World!");
	return 0;
}
