#ifndef _SCVIDEOSINKINTERFACE_H_
#define _SCVIDEOSINKINTERFACE_H_

#include "scVideoDecoderInterface.h"

//@interface
struct  scVideoSinkInterface
{
	void *userdata;
	/**
	@param frame the Video encoded frame passed to the videosinkinterface to be decoded
	@return true if successful or false if failed
	*/
	bool (*onFrame)(scVideoSinkInterface*, const scVideoEncodedFrame* frame);
};

#endif //_SCVIDEOSINKINTERFACE_H_

