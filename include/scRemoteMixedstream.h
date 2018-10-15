#ifndef _SCREMOTEMIXEDSTREAM_H_
#define _SCREMOTEMIXEDSTREAM_H_

#include "scStream.h"

//@interface
struct scRemoteMixedStreamObserver {
	void* userdata;
	void (*onVideoLayoutChanged)(scRemoteMixedStreamObserver*);
};

//@interface
struct scRemoteMixedStream
{
	scRemoteStream remoteStream;

	void (*addObserver)(scRemoteMixedStream*, scRemoteMixedStreamObserver observer);
	void (*removeObserver)(scRemoteMixedStream*, scRemoteMixedStreamObserver observer);
	const char* (*viewport)(scRemoteMixedStream*);

	scVideoFormat formats[16];
	int size;
};

#endif //_SCREMOTEMIXEDSTREAM_H_
