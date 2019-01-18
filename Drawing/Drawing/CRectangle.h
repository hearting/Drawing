#pragma once
#include"CShape.h"
#include"AttributeDialog.h"
class CRectangle : public CShape
{
public:
	CRectangle();
	~CRectangle();
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);	//���ص�pnt�Ƿ�����ͼԪ��
	void Serialize(CArchive& ar);//���л�������ͼԪ
	CRectangle(int orgX, int orgY, int Width, int Height, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	int width, height;
	DECLARE_SERIAL(CRectangle)//������CSquare֧�����л�
};



