
// DllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DllTest.h"
#include "DllTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDllTestDlg �Ի���




CDllTestDlg::CDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pAdd = NULL;
	m_pSub = NULL;
	m_pTest = NULL;
}

void CDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDllTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CDllTestDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &CDllTestDlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(IDC_BTN_CLASS_TEST, &CDllTestDlg::OnBnClickedBtnClassTest)
END_MESSAGE_MAP()


// CDllTestDlg ��Ϣ�������

BOOL CDllTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//��̬����DLL��̬��
	//m_pDll1 = ::LoadLibrary(_T("Dll1.dll"));

	//m_pAdd = (PADDPROC)::GetProcAddress(m_pDll1, "add");
	//m_pSub = (PSUBPROC)::GetProcAddress(m_pDll1, "sub");
	//m_pTest = (PTESTPROC)::GetProcAddress(m_pDll1, "test");

	//if (!m_pAdd || !m_pSub || !m_pTest)
	//{
	//	AfxMessageBox(_T("����DLL�⺯��ʧ�ܣ�"));
	//	return TRUE;
	//}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDllTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��ʹ�ö�̬���еĵ�������
//��������ʵ��ͬ���ĺ���
//extern int add(int a, int b);
//extern int sub(int a, int b);


//#include "Dll1.h"
//using namespace DLL1API;
//#pragma comment(lib, "D:\\vs2010_application\\��̬����ϰ\\DllTest\\DllTest\\lib\\Dll1.lib")
//#include "testMath.h"
#include "Dll2.h"

void CDllTestDlg::OnBnClickedBtnAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CString strAdd;

	////��̬���ص���
	//strAdd.Format(_T("add: %d"), DLL1API::add(2, 3));

	////��̬���ص���
	////strAdd.Format(_T("add: %d"), m_pAdd(2, 3));

	//AfxMessageBox(strAdd);

	Shape shape;
	shape.GetType();
	shape.shapeTest();
}


void CDllTestDlg::OnBnClickedBtnSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CString strSub;

	////��̬���ص���
	//strSub.Format(_T("sub: %d"), DLL1API::sub(5, 2));

	////��̬���ص���
	////strSub.Format(_T("sub: %d"), m_pSub(5, 2));

	//AfxMessageBox(strSub);
}


void CDllTestDlg::OnBnClickedBtnClassTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*Point pt;
	pt.output(1, 2);*/
	//pt.test();
}


BOOL CDllTestDlg::DestroyWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	//�Ի�������ǰ
	//if (m_pDll1)
	//{
	//	::FreeLibrary(m_pDll1);
	//}

	return CDialogEx::DestroyWindow();
}
