#pragma once

#include"CShape.h"
#include "afxwin.h"
#include "afxcolorbutton.h"
#include "Resource.h"
// AttributeDialog 对话框

class AttributeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AttributeDialog)

public:
	AttributeDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AttributeDialog();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AttributeDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//void setorg(CPoint pnt);	
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo1();
	virtual BOOL OnInitDialog();
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg void OnEnChangeEdit1();
//自定义变量
public:
	// 图元类型
	CComboBox shapeType;
	// 原点X
	int orgX;
	// 原点Y
	int orgY;
	// 宽度
	int Width;
	// 高度
	int Height;
	// 文本内容
	CString textContent;
	// 边框宽度
	int borderWidth;
	// 边框颜色按钮	// 边框颜色按钮
	CMFCColorButton borderColorButton;
	// 边框颜色
	COLORREF borderColor;
	// 边框类型
	CListBox borderType;
	// 填充类型
	CListBox fillType;
	// 填充颜色按钮	// 填充颜色按钮
	CMFCColorButton fillColorButton;
	// 填充色
	COLORREF fillColor;
	// 选项的索引号
	int comboxIndex;
	int borderTypeIndex;
	int filltypeIndex;
	afx_msg void OnBnClickedOk();
};
