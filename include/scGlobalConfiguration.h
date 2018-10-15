#ifndef _SCGLOBALCONFIGURATION_H_
#define _SCGLOBALCONFIGURATION_H_

#include "scExportDLL.h"
#include "scFrameGeneratorInterface.h"
#include "scVideoDecoderInterface.h"

//@interface
struct scAudioProcessingSettings {
	/**
	@brief Auto echo cancellation enabling/disabling. By default enabled.
	@details If set to true, will enable auto echo cancellation.
	*/
	bool AECEnabled;

	/**
	@brief Auto gain control enabling/disabling. By default enabled.
	@details If set to true, will enable auto gain control.
	*/
	bool AGCEnabled;

	/**
	@brief Noise suppression enabling/disabling. By default enabled.
	@details If set to true, will enable AGC.
	*/
	bool NSEnabled;
};

//@interface
struct scGlobalConfiguration {

	void (*setVideoHardwareAccelerationEnabled)(bool enabled);

	void (*setEncodedVideoFrameEnabled)(bool enabled);

	void (*setCustomizedAudioInputEnabled)(
		bool enabled,
		scAudioFrameGeneratorInterface audio_frame_generator);

	void (*setDegradationPreferenceToMaintainResolution)(bool enabled);

	void (*setCustomizedVideoDecoderEnabled)(bool enabled);

	void (*setAECEnabled)(bool enabled);

	void (*setAGCEnabled)(bool enabled);

	void (*setNSEnabled)(bool enabled);

	void (*setAudioPlayoutDeviceIndex)(int16_t device_index);

	void (*setAudioRecordingDeviceIndex)(int16_t device_index);
};

//@interface
SCEXPORTDLL_API scGlobalConfiguration* GlobalConfigurationInit();
//@interface
SCEXPORTDLL_API void GlobalConfigurationUninit(scGlobalConfiguration*);

#endif //_SCGLOBALCONFIGURATION_H_
