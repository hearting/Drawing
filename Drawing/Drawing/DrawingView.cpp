
// DrawingView.cpp: CDrawingView 类的实现
//

#include "stdafx.h"
#include "CSquare.h"
#include"CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CText.h"
#include"CShape.h"
#include "AttributeDialog.h"
#include"DrawingDoc.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"
#include "DrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CScrollView)

BEGIN_MESSAGE_MAP(CDrawingView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CDrawingView 构造/析构

CDrawingView::CDrawingView()
{
	// TODO: 在此处添加构造代码
}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDrawingView 绘图

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO:  在此处为本机数据添加绘制代码
	//我们可以得到图形数组中的对象数量，遍历数组，利用多态性，
	//使用图形基类的父类指针指向数组中的每个图形对象，调用子类中的 Draw() 函数，
	//这样就完成了整个图形的绘制了。
	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		CShape* p = (CShape*)pDoc->m_Elements[i];
		p->Draw(pDC);
	}
}



// CDrawingView 打印

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawingView 诊断

#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView 消息处理程序


void CDrawingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	SetScrollSizes(MM_TEXT, CSize(1500, 1000));
	// TODO: 计算此视图的合计大小
}

//void CDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
//{
//#ifndef SHARED_HANDLERS
//	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE); 注意要注释本行代码
//#endif
//}



void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDrawingDoc* pDoc = GetDocument();//函数GetDocument()用于获取当前文档对象的指针m_pDocument
	//CClientDC类也是CDC类的派生类。
		//它只能在窗口的客户区（即窗口中除了边框、标题栏、菜单栏以及状态栏外的中间部分）中进行绘图，
		//坐标点（0, 0）通常指的是客户区的左上角。
		//它的构造函数调用GegDC函数，而析构函数调用ReleaseDC函数。
		//CClientDC（客户区设备上下文）用于客户区的输出，它在构造函数中封装了GetDC()
		//，在析构函数中封装了ReleaseDC()函数。
		//一般在响应非窗口重画消息（如键盘输入时绘制文本、鼠标绘图）绘图时要用到它。
		//用法是：CClientDC dc(this);
		//this一般指向本窗口或当前活动视图dc.TextOut(10,10,str,str.GetLength());
		//利用dc输出文本，如果是在CScrollView中使用，
	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc); //设置映射模式，确定视口的原点。
	dc.DPtoLP(&pntLogical);//DP->LP进行转换,设备坐标转换为逻辑坐标
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if ((nFlags&MK_CONTROL) == MK_CONTROL)//Ctrl键按下
	{
		ASSERT_VALID(pDoc);//是一个断定宏
		if (!pDoc)	return;//就是肯定pDoc不为空，如果pDoc为NULL就不继续运行的意思
		AttributeDialog dialog;
		//attribute.setorg(pntLogical);
		// ----- 测试代码 begin -----
		//CShape * p = new CSquare(pntLogical.x, pntLogical.y, 100);
		//CShape * p = new CRectangle(pntLogical.x, pntLogical.y, 100,50);
		//CShape * p = new CCircle(pntLogical.x, pntLogical.y, 100);
		//CShape * p = new CEllipse(pntLogical.x, pntLogical.y, 100,50);
		//CShape * p = new CTriangle(pntLogical.x, pntLogical.y, 100);
		//CShape * p = new CText(pntLogical.x, pntLogical.y,"彭文高",300,50,0,250,0,0,255);
		//pDoc->m_Elements.Add(p);
		dialog.orgX = pntLogical.x;
		dialog.orgY = pntLogical.y;
		// 对话框的返回值是否是IDOK
		if (dialog.DoModal() == IDOK)
		{
			//获取图形的属性
			int orgX = dialog.orgX;
			int orgY = dialog.orgY;
			int width = dialog.Width;
			int height = dialog.Height;
			CString textContent = dialog.textContent;
			int textAngle = dialog.Width;
			int borderWidth = dialog.borderWidth;
			int borderType = dialog.borderTypeIndex;
			COLORREF borderColor = dialog.borderColor;
			int fillType = dialog.filltypeIndex;
			int fillColor = dialog.fillColor;			
			int comboxIndex = dialog.comboxIndex;
			switch (comboxIndex)
			{
			case 0:
			{
				// 正方形
				CSquare *p = new CSquare(orgX,orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
				pDoc->m_Elements.Add(p);
				break;
			}
			case 1:
			{
				// 矩形
				CRectangle *p = new CRectangle(orgX, orgY, width, height, borderWidth, borderType, borderColor, fillType, fillColor);
				pDoc->m_Elements.Add(p);
				break;
			}
			case 2:
			{
				// 圆形
				CCircle *p = new CCircle(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
				pDoc->m_Elements.Add(p);
				break;
			}
			case 3:
			{
				// 椭圆形
				CEllipse *p = new CEllipse(orgX, orgY, width, height, borderWidth, borderType, borderColor, fillType, fillColor);
				pDoc->m_Elements.Add(p);
				break;
			}
			case 4:
			{
				// 正三角形
				CTriangle *p = new CTriangle(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
				pDoc->m_Elements.Add(p);
				break;
			}
			case 5:
			{
				// 文本
				CText *p = new CText(orgX, orgY, textContent, textAngle,height,borderWidth, borderType, borderColor, fillType, fillColor);
				pDoc->m_Elements.Add(p);
				break;
			}
			}
		}
	}
		pDoc->SetModifiedFlag();//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化。
		pDoc->UpdateAllViews(NULL); //文档被修改后可调用此函数，把文档被修改的信息通知给每个视图。
		// ----- 测试代码 end -----

	CScrollView::OnLButtonDown(nFlags, point);
}


void CDrawingView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	int i;
	CShape* p;
	CClientDC	dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行坐标转换 

	for (i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		p = (CShape*)pDoc->m_Elements[i];
		if (p->IsMatched(point)) //鼠标点point是否落在图元p之中
		{
			pDoc->m_Elements.RemoveAt(i);//删除图形代码
			pDoc->UpdateAllViews(NULL); //文档被修改后可调用此函数，把文档被修改的信息通知给每个视图。
		}
	}

	CScrollView::OnRButtonDblClk(nFlags, point);
}



void CDrawingView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)	return;
	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行转换
	AttributeDialog dialog;
	CShape* p;
	dialog.orgX = pntLogical.x;
	dialog.orgY = pntLogical.y;
	UpdateData(FALSE);
	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		p = (CShape*)pDoc->m_Elements[i];
		if (p->IsMatched(pntLogical)) //鼠标点point是否落在图元p之中
		{
			//选中图元p，在此编写处理代码
			if (dialog.DoModal() == IDOK);
			//delete  pDoc->m_Elements[i];
			pDoc->m_Elements.RemoveAt(i);

			Invalidate();
		}
	}
	int orgX = dialog.orgX;
	int orgY = dialog.orgY;
	int width = dialog.Width;
	int height = dialog.Height;
	CString textContent = dialog.textContent;
	int textAngle = dialog.Width;
	int borderWidth = dialog.borderWidth;
	int borderType = dialog.borderTypeIndex;
	COLORREF borderColor = dialog.borderColor;
	int fillType = dialog.filltypeIndex;
	int fillColor = dialog.fillColor;
	int comboxIndex = dialog.comboxIndex;
	switch (comboxIndex)
	{
	case 0:
	{
		// 正方形
		CSquare *p = new CSquare(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
		pDoc->m_Elements.Add(p);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
		break;
	}
	case 1:
	{
		// 矩形
		CRectangle *p = new CRectangle(orgX, orgY, width, height, borderWidth, borderType, borderColor, fillType, fillColor);
		pDoc->m_Elements.Add(p);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
		break;
	}
	case 2:
	{
		// 圆形
		CCircle *p = new CCircle(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
		pDoc->m_Elements.Add(p);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
		break;
	}
	case 3:
	{
		// 椭圆形
		CEllipse *p = new CEllipse(orgX, orgY, width, height, borderWidth, borderType, borderColor, fillType, fillColor);
		pDoc->m_Elements.Add(p);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
		break;
	}
	case 4:
	{
		// 正三角形
		CTriangle *p = new CTriangle(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
		pDoc->m_Elements.Add(p);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
		break;
	}
	case 5:
	{
		// 文本
		CText *p = new CText(orgX, orgY, textContent, textAngle, height, borderWidth, borderType, borderColor, fillType, fillColor);
		pDoc->m_Elements.Add(p);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
		break;
	}
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}
