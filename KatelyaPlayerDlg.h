#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"
#import "wmp.dll" rename_namespace("CWMPLib") named_guids  // 引入 Windows Media Player ActiveX
using namespace CWMPLib;

class CKatelyaPlayerDlg : public CDialogEx
{
public:
    CKatelyaPlayerDlg(CWnd* pParent = nullptr);

    enum { IDD = IDD_KATELYAPLAYER_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()

    HICON m_hIcon;
    CButton m_btnOpen;
    CButton m_btnPlayPause;
    CButton m_btnPrev;
    CButton m_btnNext;
    CComboBox m_comboSpeed;

public:
    CComPtr<IWMPPlayer4> m_wmp;  // Windows Media Player ActiveX 控件的智能指针

    afx_msg void OnBnClickedBtnOpen();
    afx_msg void OnBnClickedBtnPlayPause();
    afx_msg void OnBnClickedBtnPrev();
    afx_msg void OnBnClickedBtnNext();
    afx_msg void OnCbnSelchangeComboSpeed();
};
