#ifndef _SCLOCALGAMERASTREAMPARAMETER_H_
#define _SCLOCALGAMERASTREAMPARAMETER_H_

#include "scExportDLL.h"


//LocalCameraStreamParameters
//@interface
struct scLocalCameraStreamParameters
{
	void (*setCameraId)(scLocalCameraStreamParameters*, const  char* camera_id);
	void (*setStreamName)(scLocalCameraStreamParameters*, const  char* stream_name);
	void (*resolution)(scLocalCameraStreamParameters*, int width, int height);
	void (*setFps)(scLocalCameraStreamParameters*, int fps);
	const char* (*cameraId)(scLocalCameraStreamParameters*);
	const char* (*streamName)(scLocalCameraStreamParameters*);
	int (*resolutionWidth)(scLocalCameraStreamParameters*);
	int (*resolutionHeight)(scLocalCameraStreamParameters*);
	int (*fps)(scLocalCameraStreamParameters*);
	bool (*videoEnabled)(scLocalCameraStreamParameters*);
	bool (*audioEnabled)(scLocalCameraStreamParameters*);
};

//@interface
SCEXPORTDLL_API scLocalCameraStreamParameters* CameraStreamParametersInit(bool video_enabled, bool audio_enabled);
//@interface
SCEXPORTDLL_API void CameraStreamParametersUnInit(scLocalCameraStreamParameters*);

//@interface
struct scLocalCustomizedStreamParameters {
	/**
	@brief Set the video resolution.

	If the resolution specified is not supported on current device, creation
	will failed.
	@param width The width of the video.
	@param height The height of the video.
	*/
	void (*resolution)(scLocalCustomizedStreamParameters*, int width, int height);
	/** @cond */
	/**
	@brief Set the frame rate.

	If the frame rate specified is not supported on current device, creation
	will failed.
	@param fps The frame rate of the video.
	*/
	void (*setFps)(scLocalCustomizedStreamParameters*, int fps);
	int (*resolutionWidth)(scLocalCustomizedStreamParameters*);
	int (*resolutionHeight)(scLocalCustomizedStreamParameters*);
	int (*fps)(scLocalCustomizedStreamParameters*);
	/**
	@brief Set the bitrate of encoded frame.
	@param bitrate_kbps The bitrate expected for the encoded stream.
	*/
	void (*setBitrate)(scLocalCustomizedStreamParameters*, int bitrate_kbps);
	uint32_t (*bitrate)(scLocalCustomizedStreamParameters*);
	/**
	@brief Get video is enabled or not for this stream.
	@return true or false.
	*/
	bool (*videoEnabled)(scLocalCustomizedStreamParameters*);
	/**
	@brief Get audio is enabled or not for this stream.
	@return true or false.
	*/
	bool (*audioEnabled)(scLocalCustomizedStreamParameters*);
};

//@interface
SCEXPORTDLL_API scLocalCustomizedStreamParameters* CustomizedStreamParametersInit(bool video_enabled, bool audio_enabled);

//@interface
SCEXPORTDLL_API scLocalCustomizedStreamParameters* CustomizedStreamParametersInit_withFormat(bool video_enabled, bool audio_enabled,
	int width, int height, uint32_t fps, uint32_t bitrate_kbps);

//SCEXPORTDLL_API scLocalCustomizedStreamParameters* CustomizedStreamParametersInit_withFormat(bool video_enabled, bool audio_enabled,
//	scResolution resolution, uint32_t fps, uint32_t bitrate_kbps);

//@interface
SCEXPORTDLL_API void CustomizedStreamParametersUninit(scLocalCustomizedStreamParameters*);


//@interface
enum scDesktopCapturePolicy {
	/// Default capture policy.
	kDefault = 0,
	/// With this policy set, on windows, use DirectX for desktop capture if
	/// possisble.
	kEnableDirectX = 1,
	/// With this policy set, enable platform specific window effects if
	/// possible.
	kEnableEffects = 2,
	/// With this policy set, capturer will provide update region information to
	/// caller.
	kEnableUpdateDetection = 4,
	/// With this policy set, capturer can send out scaled captured frame.
	kEnableMagnification = 8
};

//@interface
enum scDesktopSourceType {
	/// Capture from whole screen
	kFullScreen = 1,
	/// Capture from application
	kApplication,
	///Error
	kError,
};

//@interface
struct scLocalDesktopStreamParameters {
	/**
	@brief Get video is enabled or not for this stream.
	@return true or false.
	*/
	bool(*videoEnabled)(scLocalDesktopStreamParameters*);
	/**
	@brief Get audio is enabled or not for this stream.
	@return true or false.
	*/
	bool(*audioEnabled)(scLocalDesktopStreamParameters*);
	/** @cond */
	/**
	@brief Set the frame rate.
	The actual frame rate of window/screen capturing may be lower than this.
	@param fps The frame rate of the captured screen/window.
	*/
	void(*setFps)(scLocalDesktopStreamParameters*, int fps);
	int(*fps)(scLocalDesktopStreamParameters*);

	scDesktopSourceType(*sourceType)(scLocalDesktopStreamParameters*);
	scDesktopCapturePolicy(*capturePolicy)(scLocalDesktopStreamParameters*);
};

//@interface
SCEXPORTDLL_API scLocalDesktopStreamParameters* DesktopStreamParametersInit(
	bool video_enabled,
	bool audio_enabled,
	scDesktopSourceType source_type,
	scDesktopCapturePolicy capture_policy /*= DesktopCapturePolicy::kDefault*/);

//@interface
SCEXPORTDLL_API void DesktopStreamParametersUninit(scLocalDesktopStreamParameters*);

#endif //_SCLOCALGAMERASTREAMPARAMETER_H_

