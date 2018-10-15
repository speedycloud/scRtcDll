#ifndef _SCDECICEUTILS_H_
#define _SCDECICEUTILS_H_

#include "scExportDLL.h"
#include "scMediaFormat.h"
typedef unsigned short uint16_t;

//@interface
struct scAudioDeviceInfo {
	uint16_t index;
	char name[128];
	char guid[128];
};

//@interface
struct scDeviceId
{
	char name[256];
	char id[256];
	scDeviceId *next;
};

//@interface
struct scResolutionItem
{
	scResolution resolution;
	scResolutionItem *next;
};

//@interface
struct scAudioDeviceItem
{
	scAudioDeviceInfo info;
	scAudioDeviceItem *next;
};

//@interface
struct scDeviceUtils {
	/// Get video capturer IDs.
	scDeviceId* (*videoCapturerIds)();
	scResolutionItem* (*videoCapturerSupportedResolutions)(const char* id);
	scAudioDeviceItem* (*enumerateAudioPlayoutDevices)();
	scAudioDeviceItem* (*enumerateAudioRecordingDevices)();
};

//@interface
SCEXPORTDLL_API scDeviceUtils* DeviceUtilsInit();
//@interface
SCEXPORTDLL_API void DeviceUtilsUninit(scDeviceUtils*);

#endif //_SCDECICEUTILS_H_
