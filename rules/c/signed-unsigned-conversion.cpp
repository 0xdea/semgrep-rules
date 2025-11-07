// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <sys/types.h>

SharedMemory *SharedMemory::New(Plugin *plugin, off_t length)
{
	void *map_addr = NULL;
	// ruleid: raptor-signed-unsigned-conversion
	size_t size = static_cast<size_t>(length);
	NaClHandle handle = nacl::CreateMemoryObject(size);
	struct NaClDescImcShm *imc_desc = reinterpret_cast<struct NaClDescImcShm *>(malloc(sizeof(*imc_desc)));
	struct NaClDesc *desc = reinterpret_cast<struct NaClDesc *>(imc_desc);
	dprintf(("SharedMemory::New(%p, 0x%08x)\n ", plugin, (unsigned)length));
	NaClDescImcShmCtor(imc_desc, handle, length);
	return New(plugin, desc);
}
