#include <cstdint>

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

/*
 * A (possibly) safe way to write to a memory address.
 * Changes the access permissions of the address using VirtualProtect to memset it.
 */
inline bool SafeWriteAddr(uint32_t addr, uint32_t data, size_t size)
{
	// The old access permissions, used later to reset the changes applied.

	DWORD flOldProtect = 0;

	// Change the access permissions to allow memsetting to the given address.

	BOOL changedProtection = VirtualProtect((void*)(size_t)addr, size, PAGE_EXECUTE_READWRITE, &flOldProtect);

	// If the protection change didn't succeed, stop code execution.

	if (!changedProtection)
	{
		return false;
	}

	// memset with the given parameters.

	memset((void*)(size_t)addr, data, size);

	// Reset the access permission changes to the old access permissions.

	VirtualProtect((void*)(size_t)addr, size, flOldProtect, &flOldProtect);

	return true;
}

/*
 * A (possibly) safe way to fill a chunk of memory with NOP. NEVER MIND I'M STUPID NOP IS AN INSTRUCTION
 * Calls SafeWriteAddr with the given parameters.
 */

/*
inline void SafeFillNop(uint32_t addr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		SafeWriteAddr(addr + i, 0x90, 1);
}*/
