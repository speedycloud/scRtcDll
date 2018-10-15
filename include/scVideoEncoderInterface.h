#ifndef _SCVIDEOENCODERINTERFACE_H_
#define _SCVIDEOENCODERINTERFACE_H_

#include "scMediaFormat.h"

typedef unsigned int  uint32_t;
//@interface
struct scVideoEncoderInterface
{
	void *userdata;
	/**
	@brief Initialize the customized video encoder
	@param resolution Resolution of frame to be encoded.
	@param fps Estimated frame rate expected.
	@param bitrate_kbps bitrate in kbps the caller expect the encoder to
	output at current resolution and frame rate.
	@param video_codec codec type requested.
	@return Return true if successfully inited the encoder context; Return
	false on failing to init the encoder context.
	*/
	bool (*initEncoderContext)(scVideoEncoderInterface*, scResolution resolution,
		uint32_t fps, uint32_t bitrate_kbps, scVideoCodec video_codec);

	/**
	@brief Retrieve byte buffer from encoder that holds one complete frame.
	@detail The buffer is provided by caller and EncodedOneFrame implementation should
	copy encoded data to this buffer. After return, the caller owns the buffer and
	VideoEncoderInterface implementation should not assume the buffer valid.
	@param buffer Output buffer that holds the encoded data.
	@param key_frame Indicates whether we're requesting an AU representing an key frame.
	@param sequence_num Statistical the ReadFrame called times in client sdk.
	@return Returns true if the encoder successfully returns one frame; returns false
	if the encoder fails to encode one frame.
	*/
	bool (*encodeOneFrame)(scVideoEncoderInterface*, unsigned char* buffer, unsigned long len, bool key_frame, uint64_t sequence_num);

	/**
	@brief Release the resources that current encoder holds.
	@return Return true if successfully released the encoder; return false if
	the release fails.
	*/
	bool (*release)(scVideoEncoderInterface*);
	/**
	@brief Duplicate the VideoEncoderInterface instance.
	@return The newly created VideoEncoderInterface instance.
	*/
	scVideoEncoderInterface (*copy)(scVideoEncoderInterface*);
};

#endif //_SCVIDEOENCODERINTERFACE_H_
