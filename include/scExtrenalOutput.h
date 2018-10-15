#ifndef _SCEXTRENALOUTPUT_H_
#define _SCEXTRENALOUTPUT_H_

#include "scStream.h"

//@interface
/// Options for external audio output.
struct scExternalAudioOutputOptions {
	/**
	@brief Indicates whether audio will be output.
	@detail If it is false, all other audio options will be ignored.
	*/
	bool enabled /* = false*/;
	/// Codec for video output.
	scAudioCodec codec /*scAudioCodec::OPUS*/;
};

//@interface
/// Options for external video output.
struct scExternalVideoOutputOptions {
	/**
	@brief Indicates whether video will be output.
	@detail If it is false, all other video options will be ignored.
	*/
	bool enabled /* = false*/;
	/// Codec for video output.
	scVideoCodec codec /* = scVideoCodec::H264*/;
	/// Resolution of output stream.
	scResolution resolution /* = {0, 0}*/;
};


//@interface
/// Options for external output.
struct scExternalOutputOptions {
	/// The stream that will be streamed to a specific target.
	scStream* stream /*nullpter*/;
	/// Target URL. If it is "file", the stream will be recorded in MCU.
	char url[256];
	/// Options for external audio output.
	scExternalAudioOutputOptions audio_options;
	/// Options for external video output.
	scExternalVideoOutputOptions video_options;
};


//@interface
/// Ack for starting and updating external output.
struct scExternalOutputAck {
	/// External output streaming URL.
	char url[256];
};

#endif //_SCEXTRENALOUTPUT_H_
