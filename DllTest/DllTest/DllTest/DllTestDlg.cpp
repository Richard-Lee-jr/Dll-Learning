
// DllTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DllTest.h"
#include "DllTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CDllTestDlg 对话框




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


// CDllTestDlg 消息处理程序

BOOL CDllTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//动态加载DLL动态库
	//m_pDll1 = ::LoadLibrary(_T("Dll1.dll"));

	//m_pAdd = (PADDPROC)::GetProcAddress(m_pDll1, "add");
	//m_pSub = (PSUBPROC)::GetProcAddress(m_pDll1, "sub");
	//m_pTest = (PTESTPROC)::GetProcAddress(m_pDll1, "test");

	//if (!m_pAdd || !m_pSub || !m_pTest)
	//{
	//	AfxMessageBox(_T("加载DLL库函数失败！"));
	//	return TRUE;
	//}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDllTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//想使用动态库中的导出函数
//若本地有实现同名的函数
//extern int add(int a, int b);
//extern int sub(int a, int b);


//#include "Dll1.h"
//using namespace DLL1API;
//#pragma comment(lib, "D:\\vs2010_application\\动态库练习\\DllTest\\DllTest\\lib\\Dll1.lib")
//#include "testMath.h"
#include "Dll2.h"

void CDllTestDlg::OnBnClickedBtnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString strAdd;

	////静态加载调用
	//strAdd.Format(_T("add: %d"), DLL1API::add(2, 3));

	////动态加载调用
	////strAdd.Format(_T("add: %d"), m_pAdd(2, 3));

	//AfxMessageBox(strAdd);

	Shape shape;
	shape.GetType();
	shape.shapeTest();
}


void CDllTestDlg::OnBnClickedBtnSub()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString strSub;

	////静态加载调用
	//strSub.Format(_T("sub: %d"), DLL1API::sub(5, 2));

	////动态加载调用
	////strSub.Format(_T("sub: %d"), m_pSub(5, 2));

	//AfxMessageBox(strSub);
}


void CDllTestDlg::OnBnClickedBtnClassTest()
{
	// TODO: 在此添加控件通知处理程序代码
	/*Point pt;
	pt.output(1, 2);*/
	//pt.test();
}


BOOL CDllTestDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	//对话框销毁前
	//if (m_pDll1)
	//{
	//	::FreeLibrary(m_pDll1);
	//}

	return CDialogEx::DestroyWindow();
}
