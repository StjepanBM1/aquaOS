
#include <stdint.h>
#include <stddef.h>
#include "BasicRenderer.h"
#include "cstr.h"

struct BootInfo
{
	Framebuffer* framebuffer;
	PSF1_FONT* ps1_Font;
	void* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;

} ;

extern "C" void _start(BootInfo* bootInfo)
{
	BasicRenderer newRenderer = BasicRenderer(bootInfo->framebuffer, bootInfo->ps1_Font);
	newRenderer.Print("Welcome to aquaOS | Currently running version 0.4");
	newRenderer.Print(" ");
	newRenderer.CursorPosition = {0, 20};
	newRenderer.Print("Visit https://github.com/StjepanBM1/aquaOS for more informations");
	newRenderer.CursorPosition = {0, 25};
	newRenderer.Print("________________________________________________________________");
	newRenderer.CursorPosition = {0, 40};
	newRenderer.Print("*insert some welcoming/usefull text");

    return ;
}