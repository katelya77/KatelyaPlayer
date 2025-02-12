#include "pch.h"
#include "framework.h"
#include "KatelyaPlayer.h"
#include "KatelyaPlayerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CKatelyaPlayerDlg::CKatelyaPlayerDlg(CWnd* pParent)
    : CDialogEx(IDD_KATELYAPLAYER_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_wmp = nullptr;  // 初始化指针为空
}

void CKatelyaPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_SPEED, m_comboSpeed);
    DDX_Control(pDX, IDC_BTN_OPEN, m_btnOpen);
    DDX_Control(pDX, IDC_BTN_PLAYPAUSE, m_btnPlayPause);
    DDX_Control(pDX, IDC_BTN_PREV, m_btnPrev);
    DDX_Control(pDX, IDC_BTN_NEXT, m_btnNext);
}

BEGIN_MESSAGE_MAP(CKatelyaPlayerDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_OPEN, &CKatelyaPlayerDlg::OnBnClickedBtnOpen)
    ON_BN_CLICKED(IDC_BTN_PLAYPAUSE, &CKatelyaPlayerDlg::OnBnClickedBtnPlayPause)
    ON_BN_CLICKED(IDC_BTN_PREV, &CKatelyaPlayerDlg::OnBnClickedBtnPrev)
    ON_BN_CLICKED(IDC_BTN_NEXT, &CKatelyaPlayerDlg::OnBnClickedBtnNext)
    ON_CBN_SELCHANGE(IDC_COMBO_SPEED, &CKatelyaPlayerDlg::OnCbnSelchangeComboSpeed)
END_MESSAGE_MAP()

BOOL CKatelyaPlayerDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    // 初始化 COM 库
    HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    if (FAILED(hr))
    {
        AfxMessageBox(_T("COM 初始化失败"));
        return FALSE;
    }

    // 获取 WMP ActiveX 控件
    CWnd* pWMPControl = GetDlgItem(IDC_WMP);
    if (pWMPControl)
    {
        LPUNKNOWN pUnknown = pWMPControl->GetControlUnknown();
        if (pUnknown)
        {
            HRESULT hr = pUnknown->QueryInterface(IID_IWMPPlayer4, (void**)&m_wmp);
            if (FAILED(hr))
            {
                AfxMessageBox(_T("无法获取 WMP 控件接口"));
                OutputDebugString(L"Failed to get IWMPPlayer4 interface\n");
                return FALSE;
            }
            else
            {
                OutputDebugString(L"Successfully got IWMPPlayer4 interface\n");
            }
        }
    }
    else
    {
        AfxMessageBox(_T("未找到 WMP 控件"));
        OutputDebugString(L"Cannot find WMP control\n");
        return FALSE;
    }

    if (m_wmp)
    {
        m_wmp->put_uiMode(L"none");  // 隐藏默认 UI
    }

    // 初始化倍速下拉框
    m_comboSpeed.AddString(_T("0.5x"));
    m_comboSpeed.AddString(_T("0.75x"));
    m_comboSpeed.AddString(_T("1.0x"));
    m_comboSpeed.AddString(_T("1.25x"));
    m_comboSpeed.AddString(_T("1.5x"));
    m_comboSpeed.AddString(_T("1.75x"));
    m_comboSpeed.AddString(_T("2.0x"));
    m_comboSpeed.SetCurSel(2);

    return TRUE;
}

void CKatelyaPlayerDlg::OnBnClickedBtnOpen()
{
    CFileDialog fileDlg(TRUE, _T("mp3"), NULL, OFN_FILEMUSTEXIST,
        _T("音频文件 (*.mp3;*.wav;*.wma)|*.mp3;*.wav;*.wma|所有文件 (*.*)|*.*||"));
    if (fileDlg.DoModal() == IDOK && m_wmp)
    {
        CString filePath = fileDlg.GetPathName();
        m_wmp->put_URL(filePath.AllocSysString());  // 播放选中的音频文件
    }
}

void CKatelyaPlayerDlg::OnBnClickedBtnPlayPause()
{
    if (m_wmp)
    {
        WMPPlayState playState;
        m_wmp->get_playState(&playState);
        if (playState == wmppsPaused || playState == wmppsStopped)
        {
            m_wmp->controls->play();
        }
        else if (playState == wmppsPlaying)
        {
            m_wmp->controls->pause();
        }
    }
}

void CKatelyaPlayerDlg::OnBnClickedBtnPrev()
{
    if (m_wmp)
    {
        m_wmp->controls->previous();
    }
}

void CKatelyaPlayerDlg::OnBnClickedBtnNext()
{
    if (m_wmp)
    {
        m_wmp->controls->next();
    }
}

void CKatelyaPlayerDlg::OnCbnSelchangeComboSpeed()
{
    if (!m_wmp)
        return;

    int sel = m_comboSpeed.GetCurSel();
    double rate = 1.0;
    switch (sel)
    {
    case 0: rate = 0.5; break;
    case 1: rate = 0.75; break;
    case 2: rate = 1.0; break;
    case 3: rate = 1.25; break;
    case 4: rate = 1.5; break;
    case 5: rate = 1.75; break;
    case 6: rate = 2.0; break;
    }

    CComPtr<IWMPSettings> settings;
    m_wmp->get_settings(&settings);
    if (settings)
    {
        settings->put_rate(rate);
    }
}

void CKatelyaPlayerDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

HCURSOR CKatelyaPlayerDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}
