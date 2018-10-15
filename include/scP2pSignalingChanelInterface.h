#ifndef _SCP2PSINGNALINGCHANNELINTERFACE_H_
#define _SCP2PSINGNALINGCHANNELINTERFACE_H_

#include "scP2pException.h"

//@interface
struct scP2PSignalingChannelInterfaceObserver {

	void (*onMessage)(scP2PSignalingChannelInterfaceObserver*, const char* message,
		const char* sender);

	void (*onDisconnected)(scP2PSignalingChannelInterfaceObserver*);
};

//@interface
struct scP2PSignalingChannelInterface {
	void* userdata;

	void (*addObserver)(scP2PSignalingChannelInterface*, scP2PSignalingChannelInterfaceObserver* observer);

	void (*removeObserver)(scP2PSignalingChannelInterface*, scP2PSignalingChannelInterfaceObserver* observer);

	void (*connect)(
		scP2PSignalingChannelInterface*,
		const char* token,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	void (*disconnect)(
		scP2PSignalingChannelInterface*,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	void (*sendMessage)(
		scP2PSignalingChannelInterface*,
		const char* message,
		const char* target_id,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));
};

#endif	//_SCP2PSINGNALINGCHANNELINTERFACE_H_


