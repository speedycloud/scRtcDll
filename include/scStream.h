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
	scMediaStreamInterface(*mediaStream)(void* stream);//stream 可以是子类指针
	const char* (*id)(void* stream);//stream 可以是子类指针

	void (*disableAudio)(void* stream);//stream 可以是子类指针
	void (*disableVideo)(void* stream);//stream 可以是子类指针
	void (*enableAudio)(void* stream);//stream 可以是子类指针
	void (*enableVideo)(void* stream);//stream 可以是子类指针
	void (*attachVideoRenderer0)(void* stream, scVideoRendererARGBInterface*);//stream 可以是子类指针

	AttributeItem* (*attributes)(void* stream);//stream 可以是子类指针

	void (*attachVideoRenderer1)(void* stream, scVideoRenderWindow*);//stream 可以是子类指针
	void (*detachVideoRenderer)(void* stream);//stream 可以是子类指针
	void (*attachAudioPlayer)(void* stream, scAudioPlayerInterface*);//stream 可以是子类指针
	void (*detachAudioPlayer)(void* stream);//stream 可以是子类指针

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
	scStream stream;  //有借鉴意义

	scStreamDeviceType (*getStreamDeviceType)(void* stream);  //stream可以是子类
	void (*setAttribute)(void* stream, const AttributeItem*); //stream可以是子类, AttributeItem复制
};

//@interface
struct scRemoteStream
{
	scStream stream;  //有借鉴意义
	const char*  (*from)(void* stream);  //stream可以是子类
	void (*attachVideoSink)(void* stream, scVideoSinkInterface* video_sink);//stream可以是子类
	void (*detachVideoSink)(void* stream);//stream可以是子类
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
	scVideoFrameGeneratorInterface); //这里用直接复制得方式

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

	//失败时返回null
	scSourceItem* (*getCurrentSourceList)(scLocalScreenStream*);
	bool (*setCurrentCaptureSource)(scLocalScreenStream*, int source_id);
};

//@interface
SCEXPORTDLL_API scLocalScreenStream* LocalScreenStreamInit(scLocalDesktopStreamParameters* parameters);

//@interface
SCEXPORTDLL_API void LocalScreenStreamUninit(scLocalScreenStream*);

#endif //_SCSTREAM_H_

