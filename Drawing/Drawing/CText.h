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
	void Draw(CDC* pDC);//�����ı�����
	bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive& ar);
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
private:
	int angle, height;// �ı�����ת�Ƕ�
	CString text;// �ı�������
	DECLARE_SERIAL(CText);//������CSquare֧�����л�
};

