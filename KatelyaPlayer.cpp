#include "pch.h"
#include "framework.h"
#include "KatelyaPlayer.h"
#include "KatelyaPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKatelyaPlayerApp

BEGIN_MESSAGE_MAP(CKatelyaPlayerApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CKatelyaPlayerApp 构造
CKatelyaPlayerApp::CKatelyaPlayerApp()
{
    // 支持重新启动管理器
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

// 唯一的 CKatelyaPlayerApp 对象
CKatelyaPlayerApp theApp;

// CKatelyaPlayerApp 初始化
BOOL CKatelyaPlayerApp::InitInstance()
{
    // 如果程序以管理员权限运行，启用 Windows Common Controls 6.0
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();

    AfxEnableControlContainer();

    // 创建 Shell 管理器，以防对话框包含 Shell 控件
    CShellManager* pShellManager = new CShellManager;

    // 设置 MFC 视觉管理器主题
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

    // 标准初始化
    SetRegistryKey(_T("KatelyaPlayer - MFC 音乐播放器"));

    CKatelyaPlayerDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // 用户点击“确定”退出
    }
    else if (nResponse == IDCANCEL)
    {
        // 用户点击“取消”退出
    }

    // 删除 Shell 管理器
    if (pShellManager != nullptr)
    {
        delete pShellManager;
    }

    return FALSE;
}
