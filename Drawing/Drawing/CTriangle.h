#pragma once
#include "CShape.h"
#include "AttributeDialog.h"
class CTriangle :public CShape
{
public:
	CTriangle();
	~CTriangle();
	CTriangle(int orgX, int orgY, int Width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);	//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	int width;
	DECLARE_SERIAL(CTriangle)//������CSquare֧�����л�
};

