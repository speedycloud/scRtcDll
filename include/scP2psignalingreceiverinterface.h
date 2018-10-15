#ifndef _SCP2PSIGNALINGRECEIVERINTERFACE_H_
#define _SCP2PSIGNALINGRECEIVERINTERFACE_H_

//@interface
struct scP2PSignalingReceiverInterface {
	/// Received signaling message.
	void (*onIncomingSignalingMessage)(const char* message);
};

#endif // _SCP2PSIGNALINGRECEIVERINTERFACE_H_



