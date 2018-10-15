#ifndef _SCPEERCLIENT_H_
#define _SCPEERCLIENT_H_
#include "scExportDLL.h"
#include "scStream.h"
#include "scClientConfiguration.h"
#include "scConnectionStats.h"
#include "scP2pSignalingChanelInterface.h"

//@interface
struct scPeerClientConfiguration {
	scClientConfiguration base;
};

//@interface
struct scPeerClientObserver {
	void *userdata;
	/**
	@brief This function will be invoked when client is disconnected from
	signaling server.
	*/
	void (*onServerDisconnected)(scPeerClientObserver*);
	/**
	@brief This function will be invoked when received a invitation.
	@param remote_user_id Remote user¡¯s ID
	*/
	void (*onInvited)(scPeerClientObserver*, const char* remote_user_id);
	/**
	@brief This function will be invoked when a remote user denied current user's
	invitation.
	@param remote_user_id Remote user¡¯s ID
	*/
	void (*onDenied)(scPeerClientObserver*, const char* remote_user_id);
	/**
	@brief This function will be invoked when a remote user accepted current
	user's
	invitation.
	@param remote_user_id Remote user¡¯s ID
	*/
	void (*onAccepted)(scPeerClientObserver*, const char* remote_user_id);
	/**
	@brief This function will be invoked when a chat is stopped. (This event
	haven't been implemented yet)
	@param remote_user_id Remote user¡¯s ID
	*/
	void (*onChatStopped)(scPeerClientObserver*, const char* remote_user_id);
	/**
	@brief This function will be invoked when a chat is started. (This event
	haven't been implemented yet)
	@param remote_user_id Remote user¡¯s ID
	*/
	void (*onChatStarted)(scPeerClientObserver*, const char* remote_user_id);
	/**
	@brief This function will be invoked when received data from a remote user.
	(This event haven't been implemented yet)
	@param remote_user_id Remote user¡¯s ID
	@param message Message received
	*/
	void (*onDataReceived)(scPeerClientObserver*, const char* remote_user_id,
		const char* message);
	/**
	@brief This function will be invoked when a remote stream is available.
	@param stream The remote stream added.
	*/
	void (*onRemoteCameraStreamAdded)(scPeerClientObserver*,
		scRemoteCameraStream* stream);
	/**
	@brief This function will be invoked when a remote stream is available.
	@param stream The remote stream added.
	*/
	void (*onRemoteScreenStreamAdded)(scPeerClientObserver*,
		scRemoteScreenStream* stream);
	/**
	@brief This function will be invoked when a remote stream is removed.
	@param stream The remote stream removed.
	*/
	void (*onRemoteCameraStreamRemoved)(scPeerClientObserver*,
		scRemoteCameraStream* stream);
	/**
	@brief This function will be invoked when a remote stream is removed.
	@param stream The remote stream removed.
	*/
	void (*onRemoteScreenStreamRemoved)(scPeerClientObserver*,
		scRemoteScreenStream* stream);
};


//@interface
struct scPeerClient {

	/**
	@brief Connect to the signaling server.
	@param token A token used for connection and authentication
	@param on_success Sucess callback will be invoked with current user's ID if
	connect to server successfully.
	@param on_failure Failure callback will be invoked if one of these cases
	happened:
	1. PeerClient is connecting or connected to a server.
	2. Invalid token.
	*/
	void (*onnect)(scPeerClient*, const char* token,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));
	/**
	@brief Disconnect from the signaling server.

	It will stop all active WebRTC sessions.
	@param on_success Sucess callback will be invoked if disconnect from server
	successfully.
	@param on_failure Failure callback will be invoked if one of these cases
	happened:
	1. PeerClient haven't connected to a signaling server.
	*/
	void (*disconnect)(
		scPeerClient*,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Invite a remote user to start a WebRTC session.
	@param target_id Remote user's ID.
	@param on_success Success callback will be invoked if send a invitation
	successfully.
	@param on_failure Failure callback will be invoked if one of the following
	cases
	happened.
	1. PeerClient is disconnected from the server.
	2. Target ID is null or target user is offline.
	*/
	void (*invite)(
		scPeerClient*,
		const char* target_id,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Accept a remote user's request to start a WebRTC session.
	@param target_id Remote user's ID.
	@param on_success Success callback will be invoked if send an acceptance
	successfully.
	@param on_failure Failure callback will be invoked if one of the following
	cases
	happened.
	1. PeerClient is disconnected from the server.
	2. Target ID is null or target user is offline.
	3. Haven't received an invitation from target user.
	*/
	void (*accept)(
		scPeerClient*,
		const char* target_id,
		void* ctx,
		void (*on_success)( void*ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Deny a remote user's request to start a WebRTC session.
	@param target_id Remote user's ID.
	@param on_success Success callback will be invoked if send deny event
	successfully.
	@param on_failure Failure callback will be invoked if one of the following
	cases
	happened.
	1. PeerClient is disconnected from the server.
	2. Target ID is null or target user is offline.
	3. Haven't received an invitation from target user.
	*/
	void (*deny)(
		scPeerClient*,
		const char* target_id,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Stop a WebRTC session.
	@param target_id Remote user's ID.
	@param target_id Success callback will be invoked if send stop event
	successfully.
	@param on_failure Failure callback will be invoked if one of the following
	cases
	happened.
	1. PeerClient is disconnected from the server.
	2. Target ID is null or target user is offline.
	3. There is no WebRTC session with target user.
	*/
	void (*stop)(
		scPeerClient*,
		const char* target_id,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Publish a stream to the remote client.
	@param stream The stream which will be published.
	@param target_id Target user's ID.
	@param on_success Success callback will be invoked it the stream is
	published.
	@param on_failure Failure callback will be invoked if one of these cases
	happened:
	1. PeerClient is disconnected from server.
	2. Target ID is null or user is offline.
	3. Haven't connected to remote client.
	*/
	void (*publish)(
		scPeerClient*,
		const char* target_id,
		scLocalStream* stream,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Unpublish the stream to the remote client.
	@param stream The stream which will be removed.
	@param target_id Target user's ID.
	@param on_success Success callback will be invoked it the stream is
	unpublished.
	@param on_failure Failure callback will be invoked if one of these cases
	happened:
	1. PeerClient is disconnected from server.
	2. Target ID is null or user is offline.
	3. Haven't connected to remote client.
	4. The stream haven't been published.
	*/
	void (*unpublish)(
		scPeerClient*,
		const char* target_id,
		scLocalStream* stream,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Send a message to remote client
	@param target_id Remote user's ID.
	@param message The message to be sent.
	@param on_success Success callback will be invoked if send deny event
	successfully.
	@param on_failure Failure callback will be invoked if one of the following
	cases happened.
	1. PeerClient is disconnected from the server.
	2. Target ID is null or target user is offline.
	3. There is no WebRTC session with target user.
	*/
	void(*send)(
		scPeerClient*,
		const char* target_id,
		const char* message,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/**
	@brief Get the connection statistics with target client.
	@param target_id Remote user's ID.
	@param on_success Success callback will be invoked if get statistics
	information successes.
	@param on_failure Failure callback will be invoked if one of the following
	cases happened.
	1. PeerClient is disconnected from the server.
	2. Target ID is invalid.
	3. There is no WebRTC session with target user.
	*/
	void (*getConnectionStats)(
		scPeerClient*,
		const char* target_id,
		void* ctx,
		void (*on_success)(scConnectionStats, void *ctx),
		void (*on_failure)(scP2PException, void *ctx));

	/*! Add an observer for peer client.
	@param observer Add this object to observer list.
	Do not delete this object until it is removed from observer
	list.
	*/
	void (*addObserver)(scPeerClient*, scPeerClientObserver* observer);

	/*! Remove an observer from peer client.
	@param observer Remove this object from observer list.
	*/
	void (*removeObserver)(scPeerClient*, scPeerClientObserver* observer);
};

//@interface
SCEXPORTDLL_API scPeerClient* PeerClientInit(scPeerClientConfiguration* configuration, scP2PSignalingChannelInterface* signaling_channel);

//@interface
SCEXPORTDLL_API void PeerClientUninit(scPeerClient* handle);


#endif //_SCPEERCLIENT_H_

