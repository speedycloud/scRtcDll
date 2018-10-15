#ifndef _SCVIDEORENDERINTERFACE_H_
#define _SCVIDEORENDERINTERFACE_H_

#include "scExportDLL.h"
#include "scMediaFormat.h"

//@interface
struct scVideoRenderWindow {
	/**
	Set the render window handle for VideoRenderWindow instance.
	@param wnd Window handle that will be used for rendering.
	*/
	void (*setWindowHandle)(scVideoRenderWindow*, HWND wnd);
	/**
	Get the window handle that will be used for rendering.
	@return Returns the window handle.
	*/
	HWND (*getWindowHandle)(scVideoRenderWindow*);
};

//@interface
SCEXPORTDLL_API scVideoRenderWindow* VideoRenderInit();
//@interface
SCEXPORTDLL_API void VideoRenderUninit(scVideoRenderWindow*);

//@interface
struct scARGBBuffer {
	/// ARGB buffer
	uint8_t* buffer;
	/// Resolution for the ARGB buffer
	scResolution resolution;
};

//@interface
struct scVideoRendererARGBInterface
{
	void *userdata;
	void (*renderFrame)(scVideoRendererARGBInterface*, scARGBBuffer buffer);
};

#endif //_SCVIDEORENDERINTERFACE_H_
