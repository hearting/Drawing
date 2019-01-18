#pragma once
#include "CShape.h"
#include"AttributeDialog.h"
class CCircle :public CShape
{
public:
	CCircle();
	~CCircle();
	CCircle(int orgX, int orgY, int radius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);	//���ص�pnt�Ƿ�����ͼԪ��
	void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	int radius;
	DECLARE_SERIAL(CCircle)//������CCircle֧�����л�
};

