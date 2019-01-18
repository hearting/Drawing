#pragma once
#include "CShape.h"
#include"AttributeDialog.h"
class CEllipse :public CShape
{
public:
	CEllipse();
	~CEllipse();
	CEllipse(int orgX, int orgY, int hRadius, int vRadius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void GetShapeValue(AttributeDialog& shapedlg);
	void SetShapeValue(AttributeDialog& shapedlg);
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);	//���ص�pnt�Ƿ�����ͼԪ��
	void Serialize(CArchive& ar);//���л�������ͼԪ
	int width,height;
	DECLARE_SERIAL(CEllipse)//������CEllipse֧�����л�
};

