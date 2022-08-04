
// DllTestDlg.h : ͷ�ļ�
//

#pragma once


// CDllTestDlg �Ի���
class CDllTestDlg : public CDialogEx
{
// ����
public:
	CDllTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnSub();
	afx_msg void OnBnClickedBtnClassTest();
	virtual BOOL DestroyWindow();

	//��̬����DLL
	HMODULE m_pDll1;
	typedef int (_stdcall *PADDPROC)(int , int);
	typedef int (_stdcall *PSUBPROC)(int , int);
	typedef void (_stdcall *PTESTPROC)();
	PADDPROC m_pAdd;
	PSUBPROC m_pSub;
	PTESTPROC m_pTest;
};
