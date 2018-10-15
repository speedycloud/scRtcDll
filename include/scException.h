#ifndef _SCEXCEPTION_H_
#define _SCEXCEPTION_H_

//@interface
struct scException {
	char message[1024];
};

//@interface
enum scExceptionType {
	ExceptionTypekUnknown = 1100,  // General stream exceptions
	// kLocal* for local stream exceptions
	ExceptionTypekLocalDeviceNotFound = 1102,
	ExceptionTypekLocalInvalidOption = 1104,
	ExceptionTypekLocalNotSupported = 1105,
};

//@interface
struct scStreamException {
	scException base;
	enum scExceptionType type;
};

#endif //_SCEXCEPTION_H_

