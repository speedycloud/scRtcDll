#ifndef _SCVIDEODECODERINTERFACE_H_
#define _SCVIDEODECODERINTERFACE_H_

#include "scMediaFormat.h"
#include "scVideoDecoderInterface.h"

//@interface
struct scVideoEncodedFrame {
	/// Encoded frame buffer
	const uint8_t* buffer;
	/// Encoded frame buffer length
	size_t length;
	/// Frame timestamp (90kHz).
	uint32_t time_stamp;
	/// Key frame flag
	bool is_key_frame;
	/// codec type
	scVideoCodec type;
};

//@interface
struct scVideoDecoderInterface {
	void* userdata;

	/**
	@brief This function initializes the customized video decoder
	@param video_codec Video codec of the encoded video stream
	@return true if successful or false if failed
	*/
	bool (*initDecodeContext)(scVideoDecoderInterface*, scVideoCodec video_codec);
	/**
	@brief This function releases the customized video decoder
	@return true if successful or false if failed
	*/
	bool (*release)(scVideoDecoderInterface*);
	/**
	@brief This function receives the encoded frame for the further decoding
	@param frame Video encoded frame to be decoded
	@return true if successful or false if failed
	*/
	bool (*onEncodedFrame)(scVideoDecoderInterface*, const scVideoEncodedFrame* frame);
	/**
	@brief This function generates the customized decoder for each peer connection
	*/
	scVideoDecoderInterface* (*copy)(scVideoDecoderInterface*);
};

#endif //_SCVIDEODECODERINTERFACE_H_
