#pragma once
#include "CShape.h"
#include "string.h"
#include"AttributeDialog.h"
class CText :public CShape
{
public:
	CText();
	~CText();
	CSize  pot;
	CText(int orgX, int orgY, CString textContent, int textAngle,int h,int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC* pDC);//绘制文本函数
	bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive& ar);
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
private:
	int angle, height;// 文本的旋转角度
	CString text;// 文本的内容
	DECLARE_SERIAL(CText);//声明类CSquare支持序列化
};

