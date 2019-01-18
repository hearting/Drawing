// AttributeDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "Drawing.h"
#include "AttributeDialog.h"
#include "afxdialogex.h"


// AttributeDialog 对话框

IMPLEMENT_DYNAMIC(AttributeDialog, CDialogEx)

AttributeDialog::AttributeDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AttributeDialog, pParent)
	, orgX(0)
	, orgY(0)
	, Width(50)
	, Height(100)
	, textContent(_T("彭文高"))
	, borderWidth(1)
{

}

AttributeDialog::~AttributeDialog()
{
}

void AttributeDialog::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO1, comboxIndex);
	DDX_Control(pDX, IDC_COMBO1, shapeType);
	DDX_Text(pDX, IDC_orgx, orgX);
	DDX_Text(pDX, IDC_orgy, orgY);
	DDX_Text(pDX, IDC_text, textContent);
	DDX_Text(pDX, IDC_width, Width);
	DDX_Text(pDX, IDC_hight, Height);
	DDX_Text(pDX, IDC_biderW, borderWidth);
	DDX_Control(pDX, IDC_fill_T, fillType);
	//DDX_LBIndex(pDX, IDC_fill_T, filltypeIndex);
	DDX_Control(pDX, IDC_boderT, borderType);
	//DDX_LBIndex(pDX, IDC_boderT, borderTypeIndex);

	DDX_Control(pDX, IDC_BUTTON_BORDER_COLOR, borderColorButton);
	//DDX_Text(pDX, IDC_BUTTON_BORDER_COLOR, borderColor);
	DDX_Control(pDX, IDC_BUTTON_FILL_COLOR, fillColorButton);
	//DDX_Text(pDX, IDC_BUTTON_FILL_COLOR, fillColor);
}


BEGIN_MESSAGE_MAP(AttributeDialog, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &AttributeDialog::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &AttributeDialog::OnCbnSelchangeCombo1)
	//ON_EN_CHANGE(IDC_EDIT1, &AttributeDialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &AttributeDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// AttributeDialog 消息处理程序


void AttributeDialog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void AttributeDialog::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

}


//void AttributeDialog::OnEnChangeEdit1()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}

BOOL AttributeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO: 在此处添加实现代码.

	// 初始化列表框中的内容
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_boderT);
	pListBox->InsertString(0, "PS_SOLID");
	pListBox->InsertString(1, "PS_DASH");
	pListBox->InsertString(2, "PS_DOT");
	pListBox->InsertString(3, "PS_DASHDOT");
	pListBox->InsertString(4, "PS_DASHDOTDOT");
	pListBox->InsertString(5, "PS_NULL");
	pListBox->SetCurSel(0);

	pListBox = (CListBox*)GetDlgItem(IDC_fill_T);
	pListBox->InsertString(0, "HS_HORIZONTAL");
	pListBox->InsertString(1, "HS_VERTICAL");
	pListBox->InsertString(2, "HS_FDIAGONAL");
	pListBox->InsertString(3, "HS_BDIAGONAL");
	pListBox->InsertString(4, "HS_CROSS");
	pListBox->InsertString(5, "HS_DIAGCROSS");
	pListBox->SetCurSel(0);
	return TRUE;
}

void AttributeDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	comboxIndex = shapeType.GetCurSel(); // 获取图形类型选项值
	borderTypeIndex = borderType.GetCurSel(); // 获取边框类型选项值
	filltypeIndex = fillType.GetCurSel(); //获取填充类型选项值
	borderColor = borderColorButton.GetColor(); // 获取边框颜色值
	fillColor = fillColorButton.GetColor(); // 获取填充颜色值
}
