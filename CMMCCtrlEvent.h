// CMMCCtrlEvent.h  : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装器类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CMMCCtrlEvent

class CMMCCtrlEvent : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMMCCtrlEvent)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x69C7C394, 0x905C, 0x11D2, { 0x91, 0xAD, 0x0, 0xC0, 0x4F, 0xA3, 0x7E, 0x1F } };
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

	void TaskEnable(long lTaskIndex, long bEnable)
	{
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, lTaskIndex, bEnable);
	}



};
