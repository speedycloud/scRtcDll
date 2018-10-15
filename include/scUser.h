#ifndef _SCUSER_H_
#define _SCUSER_H_

//@interface
struct scPermission {

	bool publish_;
	bool record_;
	bool subscribe_;
};

//@interface
struct scUser {
	char role_[256];
	char name_[256];
	char id_[256];
	scPermission permissions_;
};
#endif //_SCUSER_H_
