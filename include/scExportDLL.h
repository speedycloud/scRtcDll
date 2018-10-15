#ifndef _SCEXPORTDLL_H_
#define _SCEXPORTDLL_H_

#ifdef __cplusplus

#ifdef SCPURERTCDLL_EXPORTS
#define SCEXPORTDLL_API extern "C" __declspec(dllexport)
#else
#define SCEXPORTDLL_API extern "C" __declspec(dllimport)
#endif

#else

#ifdef DLL_EXPORTS
#define SCEXPORTDLL_API __declspec(dllexport)
#else
#define SCEXPORTDLL_API __declspec(dllimport)
#endif

#endif // __cplusplus



#endif //_SCEXPORTDLL_H_
