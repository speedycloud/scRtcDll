#ifndef _SCFRAMEGENERATORINTERFACE_H_
#define _SCFRAMEGENERATORINTERFACE_H_

typedef unsigned int uint32_t;
//@interface
struct scAudioFrameGeneratorInterface {
	void *userdata;

	uint32_t (*generateFramesForNext10Ms)(scAudioFrameGeneratorInterface*, uint8_t* buffer,
		const uint32_t capacity);
	/// Get sample rate for frames generated.
	int (*getSampleRate)(scAudioFrameGeneratorInterface*);
	/// Get numbers of channel for frames generated.
	int (*getChannelNumber)(scAudioFrameGeneratorInterface*);
};

//@interface
enum scVideoFrameCodec {
	Codec_I420,
	Codec_VP8,
	Codec_H264,
};

//@interface
struct scVideoFrameGeneratorInterface {

	void *userdata;
	/**
	@brief This function generates one frame data.
	@param buffer Points to the start address for frame data. The memory is
	allocated and owned by SDK. Implementations should fill frame data to the
	memory starts from |buffer|.
	@param capacity Buffer's capacity. It will be equal or greater to expected
	frame buffer size.
	@return The size of actually frame buffer size.
	*/
	uint32_t (*generateNextFrame)(scVideoFrameGeneratorInterface*, uint8_t* buffer,
		const uint32_t capacity);
	/**
	@brief This function gets the size of next video frame.
	*/
	uint32_t (*getNextFrameSize)(scVideoFrameGeneratorInterface*);
	/**
	@brief This function gets the height of video frame.
	*/
	int (*getHeight)(scVideoFrameGeneratorInterface*);
	/**
	@brief This function gets the width of video frame.
	*/
	int (*getWidth)(scVideoFrameGeneratorInterface*);
	/**
	@brief This function gets the fps of video frame generator.
	*/
	int (*getFps)(scVideoFrameGeneratorInterface*);
	/**
	@brief This function gets the video frame type of video frame generator.
	*/
	scVideoFrameCodec (*getType)(scVideoFrameGeneratorInterface*);
};


#endif //_SCFRAMEGENERATORINTERFACE_H_
