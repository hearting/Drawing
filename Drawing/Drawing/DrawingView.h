// DrawingView.h: CDrawingView 类的接口
//
#include "stdafx.h"
#include "CSquare.h"
#include"CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CText.h"
#include"CShape.h"
#include"AttributeDialog.h"
#include"DrawingDoc.h"
#pragma once 

class CDrawingView : public CScrollView
{
protected: // 仅从序列化创建
	CDrawingView() ;
	DECLARE_DYNCREATE(CDrawingView)

// 特性
public:
	CDrawingDoc* GetDocument() const;

// 操作
public:
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate();
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	//AttributeDialog attribute;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawingView.cpp 中的调试版本
inline CDrawingDoc* CDrawingView::GetDocument() const
   { return reinterpret_cast<CDrawingDoc*>(m_pDocument); }
#endif

