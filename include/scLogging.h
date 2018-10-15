#ifndef _SCLOGGING_H_
#define _SCLOGGING_H_

#include "scExportDLL.h"

//@interface
enum scLoggingSeverity {
	/// Information which should only be logged with the consent of the user, due to privacy concerns.
	kSensitive = 1,
	/// This level is for data which we do not want to appear in the normal debug log, but should appear in diagnostic logs.
	kVerbose,
	/// Chatty level used in debugging for all sorts of things, the default in debug builds.
	kInfo,
	/// Something that may warrant investigation.
	kWarning,
	/// Something that should not have occurred.
	kError,
	/// Don't log.
	kNone
};

//@interface
struct scLogging {
	/// Set logging severity. All logging messages with higher severity will be
	/// logged.
	void (*setSeverity)(scLoggingSeverity severity);
	/// Get current logging severity.
	scLoggingSeverity (*getSeverity)();
};

//@interface
SCEXPORTDLL_API scLogging* (*LOGGINGINIT)();
//@interface
SCEXPORTDLL_API void (*LOGGINGUNINIT)(scLogging*);

#endif //_SCLOGGING_H_
