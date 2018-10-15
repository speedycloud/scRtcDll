#ifndef _SCCONFERENCECLIENT_H_
#define _SCCONFERENCECLIENT_H_

#include "scExportDLL.h"
#include "scClientConfiguration.h"
#include "scRemoteMixedstream.h"
#include "scConferenceException.h"
#include "scUser.h"
#include "scSubscribeOption.h"
#include "scExtrenalOutput.h"
#include "scConnectionStats.h"

//@interface
struct scConferenceClientConfiguration
{
	scClientConfiguration configure;
};

//@interface
struct scConferenceClientObserver {
	void *userdata;
	/**
	@brief Triggers when a stream is added.
	@param stream The stream which is added.
	*/
	void (*onRemoteCameraStreamAdded)(
		scConferenceClientObserver*,
		scRemoteCameraStream* stream);
	/**
	@brief Triggers when a stream is added.
	@param stream The stream which is added.
	*/
	void (*onRemoteScreenStreamAdded)(
		scConferenceClientObserver*,
		scRemoteScreenStream* stream);
	/**
	@brief Triggers when a stream is added.
	@param stream The stream which is added.
	*/
	void (*onRemoteMixedStreamAdded)(
		scConferenceClientObserver*,
		scRemoteMixedStream* stream);

	/**
	@brief Triggers when a stream is removed.
	@param stream The stream which is removed.
	*/
	void (*onRemoteCameraStreamRemoved)(
		scConferenceClientObserver*,
		scRemoteCameraStream* stream);
	/**
	@brief Triggers when a stream is removed.
	@param stream The stream which is removed.
	*/
	void (*onRemoteScreenStreamRemoved)(
		scConferenceClientObserver*,
		scRemoteScreenStream* stream);
	/**
	@brief Triggers when a stream is removed.
	@param stream The stream which is removed.
	*/
	void (*onRemoteMixedStreamRemoved)(
		scConferenceClientObserver*,
		scRemoteMixedStream* stream);

	/**
	@brief Triggers when an error happened on a stream.
	@detail This event only triggered for a stream that is being published or
	subscribed. SDK will not try to recovery the certain stream when this event
	is triggered. If you still need this stream, please re-publish or
	re-subscribe.
	@param stream The stream which is corrupted. It might be a LocalStream or
	RemoteStream.
	@param exception The exception happened. Currently, exceptions are reported
	by MCU.
	*/
	void (*onStreamError)(
		scConferenceClientObserver*,
		scStream* stream,
		scConferenceException exception);
	/**
	@brief Triggers when a message is received.
	@param sender_id Sender's ID.
	@param message Message received.
	*/
	void (*onMessageReceived)(
		scConferenceClientObserver*,
		const char* sender_id,
		const char* message);
	/**
	@brief Triggers when a user joined conference.
	@param user The user joined.
	*/
	void (*onUserJoined)(
		scConferenceClientObserver*,
		const scUser);
	/**
	@brief Triggers when a user left conference.
	@param user The user left.
	*/
	void (*onUserLeft)(
		scConferenceClientObserver*,
		const scUser);
	/**
	@brief Triggers when server is disconnected.
	*/
	void (*onServerDisconnected)(scConferenceClientObserver*);
};

//@interface
struct scPublishOptions {
	/**
	@brief Max outgoing audio bandwidth, unit: kbps.
	@detail Please be noticed different codecs may support different bitrate
	ranges. If you set a bandwidth limitation which is not supported by selected
	codec, connection will fail. If it is set to 0, associated ConferenceClient's
	max audio bandwidth will be used.
	*/
	int max_audio_bandwidth /* = 0*/;
	/**
	@brief Max outgoing video bandwidth, unit: kbps.
	@detail Please be noticed different codecs may support different bitrate
	ranges. If you set a bandwidth limitation which is not supported by selected
	codec, connection will fail. If it is set to 0, associated ConferenceClient's
	max video bandwidth will be used.
	*/
	int max_video_bandwidth /* = 0*/;
};

//@interface
struct scRemoteMixedStreamItem {
	scRemoteMixedStream *remoteStream;
	scRemoteMixedStreamItem *next;
};

//@interface
struct scConferenceClient
{
	void (*addObserver)(scConferenceClient*, scConferenceClientObserver* observer);
	void (*removeObserver)(scConferenceClient*, scConferenceClientObserver* observer);

	void (*join)(scConferenceClient*,
		const char* token,
		void *ctx,
		void (*on_success)(scUser, void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*publish)(scConferenceClient*,
		scLocalStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*publishAndOptions)(
		scConferenceClient*,
		scLocalStream* stream,
		const scPublishOptions options,
		void *crx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*subscribe)(
		scConferenceClient*,
		scRemoteStream* stream,
		void *ctx,
		void (*on_success)(scRemoteStream*, void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*subscribeAndOptions)(
		scConferenceClient*,
		scRemoteStream* stream,
		const scSubscribeOptions options,
		void *ctx,
		void (*on_success)(scRemoteStream*, void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*unpublish)(
		scConferenceClient*,
		scLocalStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*unsubscribe)(
		scConferenceClient*,
		scRemoteStream *stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*send2All)(
		scConferenceClient*,
		const char* message,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*send)(
		scConferenceClient*,
		const char* message,
		const char* receiver,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*playLocalStreamAudio)(
		scConferenceClient*,
		scLocalStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*pauseLocalStreamAudio)(
		scConferenceClient*,
		scLocalStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*playLocalStreamVideo)(
		scConferenceClient*,
		scLocalStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*pauseLocalStreamVideo)(
		scConferenceClient*,
		scLocalStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*playRemoteStreamAudio)(
		scConferenceClient*,
		scRemoteStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*pauseRemoteStreamAudio)(
		scConferenceClient*,
		scRemoteStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*playRemoteStreamVideo)(
		scConferenceClient*,
		scRemoteStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*pauseRemoteStreamVideo)(
		scConferenceClient*,
		scRemoteStream* stream,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*leave)(
		scConferenceClient*,
		void* ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*getRegion)(
		scConferenceClient*,
		scRemoteStream* stream,
		scRemoteMixedStream* mixed_stream,
		void *ctx,
		void (*on_success)(const char*, void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*setRegion)(
		scConferenceClient*,
		scRemoteStream* stream,
		scRemoteMixedStream* mixed_stream,
		const char* region_id,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*mute)(
		scConferenceClient*,
		scStream* stream,
		bool mute_audio,
		bool mute_video,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*unmute)(
		scConferenceClient*,
		scStream* stream,
		bool unmute_audio,
		bool unmute_video,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*mix)(
		scConferenceClient*,
		scStream* stream,
		scRemoteMixedStreamItem* mixed_stream_list,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*unmix)(
		scConferenceClient*,
		scStream* stream,
		scRemoteMixedStreamItem* mixed_stream_list,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*getConnectionStats)(
		scConferenceClient*,
		scStream* stream,
		void *ctx,
		void (*on_success)(scConnectionStats, void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*addExternalOutput)(
		scConferenceClient*,
		scExternalOutputOptions options,
		void *ctx,
		void (*on_success)(scExternalOutputAck, void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*updateExternalOutput)(
		scConferenceClient*,
		const scExternalOutputOptions options,
		void *ctx,
		void (*on_success)(scExternalOutputAck, void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));

	void (*removeExternalOutput)(
		scConferenceClient*,
		const char* url,
		void *ctx,
		void (*on_success)(void *ctx),
		void (*on_failure)(scConferenceException, void *ctx));
};

//@interface
SCEXPORTDLL_API scConferenceClient*  ConferenceClienInit(const scConferenceClientConfiguration* configuration);

//@interface
SCEXPORTDLL_API void ConferenceClienUninit(scConferenceClient *client);


#endif //_SCCONFERENCECLIENT_H_
