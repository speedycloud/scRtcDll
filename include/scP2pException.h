#ifndef _SCP2PEXCEPTION_H_
#define _SCP2PEXCEPTION_H_

#include "scException.h"

//@interface
enum p2pExceptionType {
	P2P_kUnknown = 2001,  // TODO(jianjun): sync with other SDKs.
	P2P_kConnAuthFailed = 2121,
	P2P_kMessageTargetUnreachable = 2201,
	P2P_kClientUnsupportedMethod = 2401,
	P2P_kClientInvalidArgument = 2402,  // TODO(jianjun): sync with other SDK.
	P2P_kClientInvalidState = 2403,
};

//@interface
struct scP2PException {

	scException base;
	p2pExceptionType type_;
};

#endif //_SCP2PEXCEPTION_H_
