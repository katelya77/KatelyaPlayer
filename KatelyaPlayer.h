#pragma once

#ifndef __AFXWIN_H__
#error "Include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"

class CKatelyaPlayerApp : public CWinApp
{
public:
    CKatelyaPlayerApp();

    virtual BOOL InitInstance();

    DECLARE_MESSAGE_MAP()
};

extern CKatelyaPlayerApp theApp;
