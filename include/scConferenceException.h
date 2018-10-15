#ifndef _SCCONFERENCEEXCEPTION_H_
#define _SCCONFERENCEEXCEPTION_H_

#include "scException.h"
//@interface
enum scType {
	TypekUnknown = 3001,  // TODO(jianjun): sync with other SDKs.
};

//@interface
struct scConferenceException {

	scException base;
	enum scType type;
};

#endif //_SCCONFERENCEEXCEPTION_H_
