#ifndef _SCAUDIOPLAYERINTERFACE_H_
#define _SCAUDIOPLAYERINTERFACE_H_

//@interface
struct scPCMRawBuffer {
	/// PCM raw data
	int16_t* data;
	/// Bits per sample
	int bits_per_sample;
	/// Sample rate
	int sample_rate;
	/// Number of channels
	size_t number_of_channels;
	/// Number of samples per channel
	size_t number_of_frames;
	/// The RTP timestamp of the first sample
	uint32_t timestamp;
};

//@interface
struct scAudioPlayerInterface {

	void *userdata;
	void (*playAudio)(scAudioPlayerInterface*, const scPCMRawBuffer* buffer);
};

#endif //_SCAUDIOPLAYERINTERFACE_H_


