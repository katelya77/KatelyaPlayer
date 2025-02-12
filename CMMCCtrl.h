// CMMCCtrl.h  : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装器类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CMMCCtrl

class CMMCCtrl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMMCCtrl)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x3D5905ED, 0x523C, 0x11D1, { 0x9F, 0xEA, 0x0, 0x60, 0x8, 0x32, 0xDB, 0x4A } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID,
						CCreateContext* pContext = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
				UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
				BSTR bstrLicKey = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey);
	}

// 特性
public:

// 操作
public:

	void TaskNotify(LPCTSTR szClsid, VARIANT * pvArg, VARIANT * pvParam)
	{
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, szClsid, pvArg, pvParam);
	}

	LPDISPATCH GetFirstTask(LPCTSTR szGroupText)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, szGroupText);
		return result;
	}

	LPDISPATCH GetNextTask()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}

	CString GetTitle(LPCTSTR szGroupText)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, szGroupText);
		return result;
	}

	CString GetDescriptiveText(LPCTSTR szGroupText)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, szGroupText);
		return result;
	}

	LPDISPATCH GetBackground(LPCTSTR szGroupText)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, szGroupText);
		return result;
	}

	LPDISPATCH GetListPadInfo(LPCTSTR szGroupText)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, szGroupText);
		return result;
	}



};
