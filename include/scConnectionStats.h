#ifndef _SCCONNECTIONSTATS_H_
#define _SCCONNECTIONSTATS_H_

//@interface
/// Define audio sender report
struct scAudioSenderReport {
	/// Audio bytes sent
	int64_t bytes_sent;
	/// Audio packets sent
	int32_t packets_sent;
	/// Audio packets lost during sending
	int32_t packets_lost;
	/// RTT for audio sending with unit of millisecond
	int64_t round_trip_time;
	/// Audio codec name for sending
	char codec_name[128];
};

//@interface
/// Define audio receiver report
struct scAudioReceiverReport {

	int64_t bytes_rcvd;
	/// Audio packets received
	int32_t packets_rcvd;
	/// Audio packets lost during receiving
	int32_t packets_lost;
	/// Audio delay estimated with unit of millisecond
	int32_t estimated_delay;
	/// Audio codec name for receiving
	char codec_name[128];
};

//@interface
/// Define adapt reason
enum scAdaptReason {
	AdaptReasonkUnknown = 0,
	/// Adapt for CPU limitation
	AdaptReasonkCpuLimitation = 1,
	/// Adapt for bandwidth limitation
	AdaptReasonkBandwidthLimitation = 2,
	/// Adapt for view limitation
	AdaptReasonkViewLimitation = 4,
};

//@interface
/// Define video sender report
struct scVideoSenderReport {

	/// Video bytes sent
	int64_t bytes_sent;
	/// Video packets sent
	int32_t packets_sent;
	/// Video packets lost during sending
	int32_t packets_lost;
	/// Number of FIR received
	int32_t fir_count;
	/// Number of PLI received
	int32_t pli_count;
	/// Number of NACK received
	int32_t nack_count;
	/// Video frame resolution sent
	scResolution frame_resolution_sent;
	/// Video framerate sent
	int32_t framerate_sent;
	/// Video adapt reason
	int32_t last_adapt_reason;
	/// Video adapt changes
	int32_t adapt_changes;
	/// RTT for video sending with unit of millisecond
	int64_t round_trip_time;
	/// Video codec name for sending
	char codec_name[128];
};

//@interface
/// Define video receiver report
struct scVideoReceiverReport {
	/// Video bytes received
	int64_t bytes_rcvd;
	/// Video packets received
	int32_t packets_rcvd;
	/// Video packets lost during receiving
	int32_t packets_lost;
	/// Number of FIR sent
	int32_t fir_count;
	/// Number of PLI sent
	int32_t pli_count;
	/// Number of PLI sent
	int32_t nack_count;
	/// Video frame resolution received
	scResolution frame_resolution_rcvd;
	/// Video framerate received
	int32_t framerate_rcvd;
	/// Video framerate output
	int32_t framerate_output;
	/// Current video delay with unit of millisecond
	int32_t delay;
	/// Video codec name for receiving
	char codec_name[128];
	/// Packet Jitter measured in milliseconds
	int32_t jitter;
};

//@interface
/// Define video bandwidth statistics
struct scVideoBandwidthStats {
	/// Available video bandwidth for sending, unit: bps
	int32_t available_send_bandwidth;
	/// Available video bandwidth for receiving, unit: bps
	int32_t available_receive_bandwidth;
	/// Video bitrate of transmit, unit: bps
	int32_t transmit_bitrate;
	/// Video bitrate of retransmit, unit: bps
	int32_t retransmit_bitrate;
	/// Target encoding bitrate, unit: bps
	int32_t target_encoding_bitrate;
	/// Actual encoding bitrate, unit: bps
	int32_t actual_encoding_bitrate;
};

//@interface
/// Define ICE candidate report
struct scIceCandidateReport {
	/// The ID of this report
	char id[128];
	/// The IP address of the candidate
	char ip[16];
	/// The port number of the candidate
	uint16_t port;
	/// Transport protocol.
	scTransportProtocolType protocol;
	/// Candidate type
	scIceCandidateType candidate_type;
	/// Calculated as defined in RFC5245
	int32_t priority;
};

//@interface
/// Define ICE candidate pair report.
struct scIceCandidatePairReport {
	/// The ID of this report.
	char id[128];
	/// Indicate whether transport is active.
	bool is_active;
	/// Local candidate of this pair.
	scIceCandidateReport local_ice_candidate;
	/// Remote candidate of this pair.
	scIceCandidateReport remote_ice_candidate;
};


//@interface
struct scAudioSenderReportItem
{
	scAudioSenderReport report;
	scAudioSenderReportItem *next;
};

//@interface
struct scAudioReceiverReportItem
{
	scAudioReceiverReport report;
	scAudioReceiverReportItem *next;
};

//@interface
struct scVideoSenderReportItem
{
	scVideoSenderReport report;
	scVideoSenderReportItem *next;
};

//@interface
struct scVideoReceiverReportItem
{
	scVideoReceiverReport report;
	scVideoReceiverReportItem *next;
};

//@interface
struct scIceCandidateReportItem
{
	scIceCandidateReport report;
	scIceCandidateReportItem *next;
};

//@interface
struct scIceCandidatePairReportItem
{
	scIceCandidatePairReport report;
	scIceCandidatePairReportItem *next;
};

//@interface
struct scConnectionStats {

	/// Time stamp of connection statistics generation
	unsigned long long time_stamp;
	/// Video bandwidth statistics
	scVideoBandwidthStats video_bandwidth_stats;
	/// Audio sender reports
	scAudioSenderReportItem* audio_sender_reports;
	/// Audio receiver reports
	scAudioReceiverReportItem* audio_receiver_reports;
	/// Video sender reports
	scVideoSenderReportItem* video_sender_reports;
	/// Video receiver reports
	scVideoReceiverReportItem* video_receiver_reports;
	/// Local ICE candidate reports
	scIceCandidateReportItem* local_ice_candidate_reports;
	/// Remote ICE candidate reports
	scIceCandidateReportItem* remote_ice_candidate_reports;
	/// ICE candidate pair reports
	scIceCandidatePairReportItem* ice_candidate_pair_reports;
};

#endif //_SCCONNECTIONSTATS_H_

