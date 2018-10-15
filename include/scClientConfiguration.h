#ifndef _SCLIENTCONFIGURATION_H_
#define _SCLIENTCONFIGURATION_H_

#include "scMediaFormat.h"
#include "scNetWork.h"
//@interface
enum scCandidateNetworkPolicy { kAll = 1, kLowCost };
//@interface
enum scIceTransportPolicy { iceAll = 1, iceRelay, iceNoHost, iceNone };

//@interface
struct scClientConfiguration
{
	/// List of ICE servers
	scIceServer* ice_server; //这是个链表
							 /// Media codec preference
	scMediaCodec media_codec;
	/**
	@brief Max outgoing audio bandwidth, unit: kbps.
	@detail Please be noticed different codecs may support different bitrate
	ranges. If you set a bandwidth limitation which is not supported by selected
	codec, connection will fail.
	*/
	int max_audio_bandwidth /* = 0*/;
	/**
	@brief Max outgoing video bandwidth, unit: kbps.
	@detail Please be noticed different codecs may support different bitrate
	ranges. If you set a bandwidth limitation which is not supported by selected
	codec, connection will fail.
	*/
	int max_video_bandwidth /* = 0*/;
	/**
	@brief Candidate collection policy.
	@detail If you do not want cellular network when WiFi is available, please
	use CandidateNetworkPolicy::kLowCost. Using low cost policy may not have good
	network experience. Default policy is collecting all candidates.
	*/
	scCandidateNetworkPolicy candidate_network_policy /* = scCandidateNetworkPolicy::kAll*/;

	/**
	@brief Ice transport policy.
	@detail If you allow all ICE candidate types, please use IceTransportPolicy::kAll.
	Default policy is allow all ICE candidate types.
	*/
	scIceTransportPolicy ice_transport_policy /* = scIceTransportPolicy::iceAll*/;
};

#endif //_SCLIENTCONFIGURATION_H_

