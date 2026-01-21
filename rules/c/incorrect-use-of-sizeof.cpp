// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <cstdint>
#include <cstddef>

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
