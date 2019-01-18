#pragma once
#include "CShape.h"
#include "AttributeDialog.h"
class CSquare :public CShape
{
public:
	CSquare();
	~CSquare();
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);	//���ص�pnt�Ƿ�����ͼԪ��
	void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	CSquare(int orgX, int orgY, int Width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	int width;
	DECLARE_SERIAL(CSquare)//������CSquare֧�����л�
};

