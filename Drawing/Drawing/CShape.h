#pragma once
#include <afx.h>
#include"AttributeDialog.h"
enum ElementType {SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };

class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC*pDC) = 0;//����ͼԪ
	virtual bool IsMatched(CPoint pnt) = 0;//���Ƿ�����ͼ���ڲ�
	virtual void Serialize(CArchive& ar) = 0;
	void SetAttribute(int orgX, int orgY,COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType); //�ı�ͼ�����Ա���
	/*virtual void GetShapeValue(AttributeDialog & shapedlg) = 0;
	virtual void SetShapeValue(AttributeDialog & shapedlg) = 0;*/

	ElementType Type;//ͼԪ����
	int OrgX;//ԭ������
	int OrgY;
	int width;
	COLORREF   BorderColor;//�߽���ɫ
	int BorderType;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	int BorderWidth;//�߽���
	COLORREF  FillColor;//�����ɫ
	int FillType;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
};


