#ifndef _SCNETWORK_H_
#define _SCNETWORK_H_

//@interface
struct UrlAddress
{
	char url[512];
	UrlAddress *next/*=NULL*/;
};

//@interface
struct scIceServer {
	/// URLs for this group of ICE server.
	UrlAddress *url/*=NULL*/; //这是个链表

					 /// Username.
	const char* username/*=NULL*/;
	/// Password.
	const char* password/*=NULL*/;

	scIceServer *next /*=NULL*/;
};

//@interface
enum scIceCandidateType {
	/// Host candidate.
	kHost = 1,
	/// Server reflexive candidate.
	kSrflx,
	/// Peer reflexive candidate.
	kPrflx,
	/// Relayed candidate.
	kRelay,
	/// Unknown.
	kUnknown = 99,
};

//@interface
enum scTransportProtocolType {
	/// TCP.
	sckTcp = 1,
	/// UDP.
	sckUdp,
	/// Unknown.
	sckUnknown = 99,
};

#endif //_SCNETWORK_H_
