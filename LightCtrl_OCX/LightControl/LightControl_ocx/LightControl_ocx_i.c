

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Dec 17 15:00:26 2018
 */
/* Compiler settings for .\LightControl_ocx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_LightControl_ocxLib,0x76B98E19,0xF820,0x4C65,0x93,0xA2,0x14,0x7E,0x6E,0x31,0xC6,0x6D);


MIDL_DEFINE_GUID(IID, DIID__DLightControl_ocx,0x9566B873,0xB2F4,0x4E89,0xAC,0x4E,0xC5,0x19,0xD2,0x37,0x56,0x0B);


MIDL_DEFINE_GUID(IID, DIID__DLightControl_ocxEvents,0xE5F440A7,0x05DB,0x4AF2,0xAE,0x96,0x86,0x07,0x05,0x5A,0x34,0x68);


MIDL_DEFINE_GUID(CLSID, CLSID_LightControl_ocx,0xD3DA0BCF,0x2F14,0x4D39,0x97,0x34,0xAB,0x01,0x51,0xF9,0x35,0x8A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



