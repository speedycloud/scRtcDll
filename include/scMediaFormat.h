#ifndef _SCMEDIAFORMAT_H
#define _SCMEDIAFORMAT_H

//@interface
enum scAudioCodec {
	OPUS = 1,
	ISAC,
	G722,
	PCMU,
	PCMA,
};

//@interface
enum scVideoCodec {
	VP8 = 1,
	H264,
	VP9,
	H265,
};

//@interface
struct scMediaCodec { 
	/**
	* @brief Preference for video codec. Default is H.264.
	*/
	scVideoCodec video_codec /*scVideoCodec::H264*/;
	/**
	* @brief Preference for audio codec. Default is Opus.
	*/
	scAudioCodec audio_codec /*scAudioCodec::OPUS*/;
};

//@interface
struct scResolution {

	int width /*=0*/;
	int height /*=0*/;
};

/**
* @brief An instance of this class represent a video format
*/
//@interface
struct scVideoFormat {
	/** @endcond */
	scResolution resolution;
};

#endif //_SCMEDIAFORMAT_H

