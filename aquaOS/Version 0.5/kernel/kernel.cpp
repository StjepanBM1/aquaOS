#include "kernelUtil.h"

/*/
void Info()
{

	Framebuffer->BaseAddress = (void*)BaseAddress;
	Framebuffer->BufferSize = BufferSize;
	Framebuffer->Width = Height;
	Framebuffer->Height = Width;
	Framebuffer->PixelsPerScanLine = PixelsPerScanLine;
}
/*/

extern "C" void _start(BootInfo* bootInfo)
{
	BasicRenderer newRenderer = BasicRenderer(bootInfo->framebuffer, bootInfo->ps1_Font);

	newRenderer.CursorPosition = {0, 0};
	newRenderer.Print("Welcome to aquaOS | Currently running version 0.5");

	newRenderer.CursorPosition = {0, 20};
	newRenderer.Print("(c) 2021 | Visit https://github.com/StjepanBM1/aquaOS for more informations");

	newRenderer.CursorPosition = {0, 40};
	newRenderer.Print("---------------------------------------------------------------------------");

	uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;

	newRenderer.Print(to_string(GetMemorySize(bootInfo->mMap, mMapEntries, bootInfo->mMapDescSize)));

	for (int i = 0; i < mMapEntries; i++)
	{
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)bootInfo->mMap + (i * bootInfo->mMapDescSize));
		newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
		newRenderer.Print(EFI_MEMORY_TYPE_STRINGS[desc->type]);
		newRenderer.Colour = 0xffff00ff;
		newRenderer.Print(" ");
		newRenderer.Print(to_string(desc->numPages * 4096 / 1024));
		newRenderer.Print(" KB");
		newRenderer.Colour = 0xff00ffff;
	}


    while (true)
	{
		asm ("hlt");
	}
}