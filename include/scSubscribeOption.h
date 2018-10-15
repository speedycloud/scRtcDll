#ifndef _SCSUBSCRIBEOPTION_H_
#define _SCSUBSCRIBEOPTION_H_

#include "scMediaFormat.h"
//@interface
enum scVideoQualityLevel {
	kBestQuality = 1,
	kBetterQuality,
	kStandard,
	kBetterSpeed,
	kBestSpeed
};

//@interface.
struct scSubscribeOptions {

	scResolution resolution;
	scVideoQualityLevel video_quality_level;
};

#endif //_SCSUBSCRIBEOPTION_H_

