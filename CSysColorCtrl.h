// CSysColorCtrl.h  : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装器类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CSysColorCtrl

class CSysColorCtrl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CSysColorCtrl)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xC47195EB, 0xCD7A, 0x11D1, { 0x8E, 0xA3, 0x0, 0xC0, 0x4F, 0x99, 0x0, 0xD7 } };
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

	CString get_HEXactiveborder()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBactiveborder()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXactivecaption()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBactivecaption()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXappworkspace()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBappworkspace()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXbackground()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBbackground()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXbuttonface()
	{
		CString result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBbuttonface()
	{
		long result;
		InvokeHelper(0xA, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXbuttonhighlight()
	{
		CString result;
		InvokeHelper(0xB, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBbuttonhighlight()
	{
		long result;
		InvokeHelper(0xC, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXbuttonshadow()
	{
		CString result;
		InvokeHelper(0xD, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBbuttonshadow()
	{
		long result;
		InvokeHelper(0xE, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXbuttontext()
	{
		CString result;
		InvokeHelper(0xF, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBbuttontext()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXcaptiontext()
	{
		CString result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBcaptiontext()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXgraytext()
	{
		CString result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBgraytext()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXhighlight()
	{
		CString result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBhighlight()
	{
		long result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXhighlighttext()
	{
		CString result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBhighlighttext()
	{
		long result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXinactiveborder()
	{
		CString result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBinactiveborder()
	{
		long result;
		InvokeHelper(0x1A, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXinactivecaption()
	{
		CString result;
		InvokeHelper(0x1B, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBinactivecaption()
	{
		long result;
		InvokeHelper(0x1C, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXinactivecaptiontext()
	{
		CString result;
		InvokeHelper(0x1D, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBinactivecaptiontext()
	{
		long result;
		InvokeHelper(0x1E, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXinfobackground()
	{
		CString result;
		InvokeHelper(0x1F, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBinfobackground()
	{
		long result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXinfotext()
	{
		CString result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBinfotext()
	{
		long result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXmenu()
	{
		CString result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBmenu()
	{
		long result;
		InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXmenutext()
	{
		CString result;
		InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBmenutext()
	{
		long result;
		InvokeHelper(0x26, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXscrollbar()
	{
		CString result;
		InvokeHelper(0x27, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBscrollbar()
	{
		long result;
		InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXthreeddarkshadow()
	{
		CString result;
		InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBthreeddarkshadow()
	{
		long result;
		InvokeHelper(0x2A, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXthreedface()
	{
		CString result;
		InvokeHelper(0x2B, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBthreedface()
	{
		long result;
		InvokeHelper(0x2C, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXthreedhighlight()
	{
		CString result;
		InvokeHelper(0x2D, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBthreedhighlight()
	{
		long result;
		InvokeHelper(0x2E, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXthreedlightshadow()
	{
		CString result;
		InvokeHelper(0x2F, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBthreedlightshadow()
	{
		long result;
		InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXthreedshadow()
	{
		CString result;
		InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBthreedshadow()
	{
		long result;
		InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXwindow()
	{
		CString result;
		InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBwindow()
	{
		long result;
		InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXwindowframe()
	{
		CString result;
		InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBwindowframe()
	{
		long result;
		InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString get_HEXwindowtext()
	{
		CString result;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	long get_RGBwindowtext()
	{
		long result;
		InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}

	CString ConvertRGBToHex(long rgb)
	{
		CString result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, rgb);
		return result;
	}

	long ConvertHexToRGB(LPCTSTR szHex)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x3A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szHex);
		return result;
	}

	short GetRedFromRGB(long rgb)
	{
		short result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3B, DISPATCH_METHOD, VT_I2, (void*)&result, parms, rgb);
		return result;
	}

	short GetGreenFromRGB(long rgb)
	{
		short result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3C, DISPATCH_METHOD, VT_I2, (void*)&result, parms, rgb);
		return result;
	}

	short GetBlueFromRGB(long rgb)
	{
		short result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x3D, DISPATCH_METHOD, VT_I2, (void*)&result, parms, rgb);
		return result;
	}

	long GetDerivedRGB(LPCTSTR pszFrom, LPCTSTR pszTo, LPCTSTR pszFormat, short nPercent)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I2;
		InvokeHelper(0x3E, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszFrom, pszTo, pszFormat, nPercent);
		return result;
	}

	CString GetDerivedHex(LPCTSTR pszFrom, LPCTSTR pszTo, LPCTSTR pszFormat, short nPercent)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I2;
		InvokeHelper(0x3F, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszFrom, pszTo, pszFormat, nPercent);
		return result;
	}

	long Get3QuarterLightRGB(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	CString Get3QuarterLightHex(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	long GetHalfLightRGB(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	CString GetHalfLightHex(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	long GetQuarterLightRGB(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	CString GetQuarterLightHex(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	long Get3QuarterDarkRGB(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	CString Get3QuarterDarkHex(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	long GetHalfDarkRGB(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	CString GetHalfDarkHex(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	long GetQuarterDarkRGB(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x4A, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}

	CString GetQuarterDarkHex(LPCTSTR pszFrom, LPCTSTR pszFormat)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x4B, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszFrom, pszFormat);
		return result;
	}



};
