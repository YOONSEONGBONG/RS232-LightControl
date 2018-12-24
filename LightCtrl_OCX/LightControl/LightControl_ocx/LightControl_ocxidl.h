

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __LightControl_ocxidl_h__
#define __LightControl_ocxidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DLightControl_ocx_FWD_DEFINED__
#define ___DLightControl_ocx_FWD_DEFINED__
typedef interface _DLightControl_ocx _DLightControl_ocx;
#endif 	/* ___DLightControl_ocx_FWD_DEFINED__ */


#ifndef ___DLightControl_ocxEvents_FWD_DEFINED__
#define ___DLightControl_ocxEvents_FWD_DEFINED__
typedef interface _DLightControl_ocxEvents _DLightControl_ocxEvents;
#endif 	/* ___DLightControl_ocxEvents_FWD_DEFINED__ */


#ifndef __LightControl_ocx_FWD_DEFINED__
#define __LightControl_ocx_FWD_DEFINED__

#ifdef __cplusplus
typedef class LightControl_ocx LightControl_ocx;
#else
typedef struct LightControl_ocx LightControl_ocx;
#endif /* __cplusplus */

#endif 	/* __LightControl_ocx_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LightControl_ocxLib_LIBRARY_DEFINED__
#define __LightControl_ocxLib_LIBRARY_DEFINED__

/* library LightControl_ocxLib */
/* [control][helpstring][helpfile][version][uuid] */ 


EXTERN_C const IID LIBID_LightControl_ocxLib;

#ifndef ___DLightControl_ocx_DISPINTERFACE_DEFINED__
#define ___DLightControl_ocx_DISPINTERFACE_DEFINED__

/* dispinterface _DLightControl_ocx */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DLightControl_ocx;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9566B873-B2F4-4E89-AC4E-C519D237560B")
    _DLightControl_ocx : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DLightControl_ocxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DLightControl_ocx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DLightControl_ocx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DLightControl_ocx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DLightControl_ocx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DLightControl_ocx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DLightControl_ocx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DLightControl_ocx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DLightControl_ocxVtbl;

    interface _DLightControl_ocx
    {
        CONST_VTBL struct _DLightControl_ocxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DLightControl_ocx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DLightControl_ocx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DLightControl_ocx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DLightControl_ocx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DLightControl_ocx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DLightControl_ocx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DLightControl_ocx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DLightControl_ocx_DISPINTERFACE_DEFINED__ */


#ifndef ___DLightControl_ocxEvents_DISPINTERFACE_DEFINED__
#define ___DLightControl_ocxEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DLightControl_ocxEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DLightControl_ocxEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E5F440A7-05DB-4AF2-AE96-8607055A3468")
    _DLightControl_ocxEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DLightControl_ocxEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DLightControl_ocxEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DLightControl_ocxEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DLightControl_ocxEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DLightControl_ocxEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DLightControl_ocxEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DLightControl_ocxEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DLightControl_ocxEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DLightControl_ocxEventsVtbl;

    interface _DLightControl_ocxEvents
    {
        CONST_VTBL struct _DLightControl_ocxEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DLightControl_ocxEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DLightControl_ocxEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DLightControl_ocxEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DLightControl_ocxEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DLightControl_ocxEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DLightControl_ocxEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DLightControl_ocxEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DLightControl_ocxEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LightControl_ocx;

#ifdef __cplusplus

class DECLSPEC_UUID("D3DA0BCF-2F14-4D39-9734-AB0151F9358A")
LightControl_ocx;
#endif
#endif /* __LightControl_ocxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


