#include <stdint.h>
#include <stddef.h>
#include "BasicRenderer.h"
#include "cstr.h"
#include "Framebuffer.h"
#include "efiMemory.h"
#include "memory.h"


struct BootInfo
{
	Framebuffer* framebuffer;
	PSF1_FONT* ps1_Font;
	EFI_MEMORY_DESCRIPTOR* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;

	uint64_t mReso;
	uint64_t mResoSize;
	uint64_t mResoDescSize;

} ;