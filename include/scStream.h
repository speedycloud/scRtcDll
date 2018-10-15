#ifndef _SCSTREAM_H_
#define _SCSTREAM_H_

#include "scExportDLL.h"
#include "scVideoRenderInterface.h"
#include "scAudioPlayerInterface.h"
#include "scFrameGeneratorInterface.h"
#include "scVideoSinkInterface.h"
#include "scLocalCameraStreamParameter.h"
#include "scVideoEncoderInterface.h"
#include "scVideoRenderInterface.h"

//@interface
#define offset_of(type, filed) ((unsigned int)&(((type*)0)->filed))
//@interface
typedef void* scMediaStreamInterface;

//@interface
struct AttributeItem
{
	char key[128];
	char value[128];

	AttributeItem *next;
};

//@interface
struct  scStream
{
	scMediaStreamInterface(*mediaStream)(void* stream);//stream ����������ָ��
	const char* (*id)(void* stream);//stream ����������ָ��

	void (*disableAudio)(void* stream);//stream ����������ָ��
	void (*disableVideo)(void* stream);//stream ����������ָ��
	void (*enableAudio)(void* stream);//stream ����������ָ��
	void (*enableVideo)(void* stream);//stream ����������ָ��
	void (*attachVideoRenderer0)(void* stream, scVideoRendererARGBInterface*);//stream ����������ָ��

	AttributeItem* (*attributes)(void* stream);//stream ����������ָ��

	void (*attachVideoRenderer1)(void* stream, scVideoRenderWindow*);//stream ����������ָ��
	void (*detachVideoRenderer)(void* stream);//stream ����������ָ��
	void (*attachAudioPlayer)(void* stream, scAudioPlayerInterface*);//stream ����������ָ��
	void (*detachAudioPlayer)(void* stream);//stream ����������ָ��

	void (*addRef)(void* stream);
	void(*reduceRef)(void* stream);
	int streamRef;
};

//@interface
enum scStreamDeviceType {
	kStreamDeviceTypeCamera = 101,
	kStreamDeviceTypeScreen,
	kStreamDeviceTypeUnknown = 200
};

//LocalStream
//@interface
struct scLocalStream
{
	scStream stream;  //�н������

	scStreamDeviceType (*getStreamDeviceType)(void* stream);  //stream����������
	void (*setAttribute)(void* stream, const AttributeItem*); //stream����������, AttributeItem����
};

//@interface
struct scRemoteStream
{
	scStream stream;  //�н������
	const char*  (*from)(void* stream);  //stream����������
	void (*attachVideoSink)(void* stream, scVideoSinkInterface* video_sink);//stream����������
	void (*detachVideoSink)(void* stream);//stream����������
};

//@interface
struct scRemoteCameraStream
{
	scRemoteStream remoteStream;
};

//@interface
struct scRemoteScreenStream
{
	scRemoteStream remoteStream;
};

//@interface
struct scLocalCameraStream
{
	scLocalStream localStream;
	void (*close)(scLocalCameraStream* stream);
};

//@interface
SCEXPORTDLL_API scLocalCameraStream* CameraStreamInit(
	scLocalCameraStreamParameters* parameters,
	int* error_code);

//@interface
SCEXPORTDLL_API void CameraStreamUninit(scLocalCameraStream*);

//@interface
struct scLocalCustomizedStream
{
	scLocalStream localStream;
};

//@interface
SCEXPORTDLL_API scLocalCustomizedStream* CustomizedStreamInit0(
	scLocalCustomizedStreamParameters*,
	scVideoFrameGeneratorInterface); //������ֱ�Ӹ��Ƶ÷�ʽ

									 //@interface
SCEXPORTDLL_API scLocalCustomizedStream* CustomizedStreamInit1(
	scLocalCustomizedStreamParameters* parameters,
	scVideoEncoderInterface encoder);

//@interface
SCEXPORTDLL_API void CustomizedStreamUninit(scLocalCustomizedStream *stream);

//@interface
struct scSourceItem
{
	int id;
	char title[128];
	scSourceItem *next;
};

//@interface
struct scLocalScreenStream
{
	scLocalStream localStream;

	//ʧ��ʱ����null
	scSourceItem* (*getCurrentSourceList)(scLocalScreenStream*);
	bool (*setCurrentCaptureSource)(scLocalScreenStream*, int source_id);
};

//@interface
SCEXPORTDLL_API scLocalScreenStream* LocalScreenStreamInit(scLocalDesktopStreamParameters* parameters);

//@interface
SCEXPORTDLL_API void LocalScreenStreamUninit(scLocalScreenStream*);

#endif //_SCSTREAM_H_

