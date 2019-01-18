# Drawing
用MFC做绘图程序
一、课程设计的目的
参加本课程设计的同学已经学习了《C语言程序设计》和《面向对象可视化编程》两门课程，现在需要通过一个相对实际性的开发过程来巩固与鉴定一下学习成效，
可以查看离实际需要还有哪些部分没有完全掌握，需要加强；另外本课程设计可以提供一个稍微具有规模的程序开发的例子，让同学们可以体会到程序的构思、
编码以及调试的完整过程，最后并总结课程设计的过程。
二、课程设计的内容与设计思路 
1.课设内容 
要求：采用单文档方式，文档中存储图形画面的各个图元数据，视图负责图形的绘制。文档支持图形的序列化（连载），提供新建、打开、保存等操作。
视图除了绘制图形，还提供图形交互，能够按住Ctrl键再鼠标左键单击来创建图元，鼠标左键双击编辑修改图元属性，鼠标右键双击删除图元。
图元创建与修改时的参数由参数对话框来编辑。创建时以鼠标左击时光标的所在位置作为基点来创建图元。 
 
2.设计思路
我们的最终目的是显示一个单文档窗口，且可利用从对话框中输入的数据绘制图形。所以，首先建立一个单文档程序。先创建Cshape为基类，
派生出Csquare，Crectangle,CCircle,CEllipse，Ctriangle，CText类，在类中添加数据成员和成员函数。文档序列化满足保存、打开操作。
添加对话框，用来创建与修改图形参数，之后给对话框中的各复选框，编辑框，按钮添加消息响应函数，进行控件关联，并利用枚举型使参数传递。
添加鼠标的消息响应，满足新建、删除和修改等3项功能。从而达到目的，思路图参考如图1，2
 
 

三.程序实现过程或细节
1.函数定义与功能表
1.
功能	操作	类/方法、属性	功能说明	隐含/相关功能
1.编辑图形	包括图形对象的新建、删除和修改等操作
1.1新建图形	Ctrl+鼠标左键单击	CDrawingView::
OnLButtonDown()	在鼠标点击处创建图形（6种）	存储图形
显示图形
设置图形属性
1.2删除图形	鼠标左键双击	CDrawingView::
OnLButtonDblClk()	删除鼠标点击处所选中的图形	选中图形
1.3修改图形	鼠标右键双击	CDrawingView::
OnRButtonDblClk()	修改鼠标点击所选中图形的属性	选中图形
设置图形属性
1.4存储图形	（隐含）	CDrawingDoc类	存储6种图形对象，应分配到文档类中存储	
1.5显示图形	（隐含）	CDrawingView::
OnDraw()	绘制文档内存储的所有图形	6个图形类需分别实现各自的绘图方法Draw()
1.6选中图形	（隐含）	6个图形类的
IsMatched()	判断鼠标点击处是否落在图形内	6个图形类需分别实现IsMatched()
1.7设置图形属性对话框	（隐含）	AttributeDialog类	创建或修改图形时，设置图形属性	
1.8编辑图形后确定	属性框确定	Void Attribute::OnOk()	按下确定键调用	
2.文件操作	实现程序菜单中文件的新建、打开、保存、另存为、关闭等功能。
CDocument已实现并封装了这些功能，只需实现2个函数：Serialize()、DeleteContents()。
另外，在图形的新建、删除和修改时，应调用CDocument::SetModifiedFlag()方法，说明文档已被修改；这样，在文件的新建、打开时会提示：文件已修改，是否保存？
2.1序列化	（隐含）	CDrawingDoc::
Serialize()	文档内图形对象的文件读、写操作	6个图形类需分别实现Serialize()
2.2删除文档内容	（隐含）	CDrawingDoc::
DeleteContents()	在文件的新建、打开时会自动调用，该函数负责清空文档内容（即所有图形对象）	
2.3释放动态内存对象	（隐含）	CDrawingDoc::
~ CDrawingDoc()	关闭程序时，delete删除由new分配的所有对象	
3图形类	设计并实现正方形、矩形、圆、椭圆、正三角形、文本等6个图形类
3.1正方形	（隐含）	CSquare类	包括各自的属性以及构造函数、Draw(CDC*pDC)、Serialize(CArchive &ar)、IsMatched(CPoint pnt)等方法	
3.2矩形	（隐含）	CRectangle类		
3.3圆	（隐含）	CCircle类		
3.4椭圆	（隐含）	CEllipse类		
3.5正三角形	（隐含）	CTriangle类		
3.6文本	（隐含）	CText类		

2.工程新建
打开vs2017新建项目MFC应用程序，工程名为Drawing，解决方案名称为Drawing，点击确定。如图
 
3.新建CShape类及其子类
CShape类要支持序列化要从CObject派生，每个子类的.h文件中包含DECLARE_SERIAL声明，void Draw(CDC*pDC);绘制图形函数，bool IsMatched(CPoint pnt);判断重载点pnt是否落在图元内，void Serialize(CArchive& ar);序列化图元函数，重载函数，自身属性变量变量。
在Shape.h中定义其成员变量和成员函数，注意0nDraw函数应定义为纯虚函数。enum ElementType {SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };枚举，代表各种图形类的编号然后由CShape 类派生其六个子类CSquare，CRectangle，CTriangle，CCirele，CEllipse，CText，继承方式均为public，在子类中也定义其成员函数及变量（以CSquare为例），Draw(CDC* pDC)绘制图形函数，Serialize(CArchive &ar)序列化保存读取文件函数，IsMatched(CPoint pnt)判断正方形重载点pnt是否落在图元内函数。

class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC*pDC) = 0;//绘制图元
	virtual bool IsMatched(CPoint pnt) = 0;//点是否落在图形内部
	virtual void Serialize(CArchive& ar) = 0;
void SetAttribute(int orgX, int orgY,COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);
ElementType Type;//图元类型
	int OrgX;//原点坐标
	int OrgY;
	int width;
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型--实线、虚线、虚点线等
	int BorderWidth;//边界宽度
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型--实心、双对角、十字交叉等
CSquare::CSquare()
{
	Type = (ElementType)0;
}
CSquare::~CSquare()
{
}
void CSquare::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width , OrgY + width);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
} 
IMPLEMENT_SERIAL(CSquare, CShape, 1)//实现类CSquare的序列化，指定版本为1
void CSquare::Serialize(CArchive &ar)
{//保存文件
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
//读取文件
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
	}
}
bool CSquare::IsMatched(CPoint pnt)//正方形重载点pnt是否落在图元内
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - width / 2) 
		&& (pnt.y <= OrgY + width / 2))
		return true;
	else
		return false;
}
CSquare::CSquare(int orgX, int orgY, int Width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)0;
	OrgX = orgX;
	OrgY = orgY;
	width = Width;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}
4.新建对话框
打开资源视图，右击Dialog->插入Dialog。在类向导中添加名为AttributeDialog，ID为IDD_AttributeDialog的MFC类。在对话框中添加工具箱中的控件：
Edit Control：文本编辑框。 
Combo Box：下拉框，可以下拉选择不同的内容。 
List Box：列表框，选项直接显示出来，便于选择。在Data属性中加Square;Rectangle;Circle;Ellipse;Triangle;Text;
Group Box：控件组框，包围多个同组的控件。改变Caption属性
Static Text：静态文本框，常用来显示说明性的文字。改变Caption属性
MFC ColorButton Control：MFC 颜色控件，可以用来选择不同的颜色
属性表：
名称	ID	名称	ID
图元形状	IDC_COMBO1	线宽	IDC_biderW
原点X	IDC_orgx	线型	IDC_biderW
原点Y	IDC_orgy	线框颜色	IDC_BUTTON_BORDER_COLOR
宽度W/半径R/角度A	IDC_width	风格	IDC_fill_T
高度G	IDC_hight	填充颜色	IDC_BUTTON_FILL_COLOR
文字	IDC_text		
 
5.控件关联
（1）在文本编辑框，MFC 颜色控件右击分别添加变量，变量名称如下如下
// 图元类型
	CComboBox shapeType;
	// 原点X
	int orgX;
	// 原点Y
	int orgY;
	// 宽度
	int Width;
	// 高度
	int Height;
	// 文本内容
	CString textContent;
	// 边框宽度
	int borderWidth;
	// 边框颜色按钮	// 边框颜色按钮
	CMFCColorButton borderColorButton;
	// 边框颜色
	COLORREF borderColor;
	// 边框类型
	CListBox borderType;
	// 填充类型
	CListBox fillType;
	// 填充颜色按钮	// 填充颜色按钮
	CMFCColorButton fillColorButton;
	// 填充色
	COLORREF fillColor;
	// 选项的索引号
	int comboxIndex;
	int borderTypeIndex;
	int filltypeIndex;
（2）初始化List Box，在AttributeDialog类中添加名为OnInitDialog的BOOL型成员函数。代码如下：
BOOL AttributeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO: 在此处添加实现代码.
	// 初始化列表框中的内容
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_boderT);
	pListBox->InsertString(0, "PS_SOLID");
	pListBox->InsertString(1, "PS_DASH");
	pListBox->InsertString(2, "PS_DOT");
	pListBox->InsertString(3, "PS_DASHDOT");
	pListBox->InsertString(4, "PS_DASHDOTDOT");
	pListBox->InsertString(5, "PS_NULL");
	pListBox->SetCurSel(0);

	pListBox = (CListBox*)GetDlgItem(IDC_fill_T);
	pListBox->InsertString(0, "HS_HORIZONTAL");
	pListBox->InsertString(1, "HS_VERTICAL");
	pListBox->InsertString(2, "HS_FDIAGONAL");
	pListBox->InsertString(3, "HS_BDIAGONAL");
	pListBox->InsertString(4, "HS_CROSS");
	pListBox->InsertString(5, "HS_DIAGCROSS");
	pListBox->SetCurSel(0);
	return TRUE;
}
（3）初始化编辑框，代码如下。
AttributeDialog::AttributeDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AttributeDialog, pParent)
	, orgX(0)
	, orgY(0)
	, Width(50)
	, Height(100)
	, textContent(_T("彭文高"))
	, borderWidth(1)
{

}
（4）在确定按钮上添加消息响应，用来获取类型和颜色并返回IDOK，双击确定按钮，在AttributeDialog类中加OnBnClickedOk函数，代码如下：
void AttributeDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	comboxIndex = shapeType.GetCurSel(); // 获取图形类型选项值
	borderTypeIndex = borderType.GetCurSel(); // 获取边框类型选项值
	filltypeIndex = fillType.GetCurSel(); //获取填充类型选项值
	borderColor = borderColorButton.GetColor(); // 获取边框颜色值
	fillColor = fillColorButton.GetColor(); // 获取填充颜色值
}
6.定义动态数组
在CDrawingDoc类中加成员m_Elements，Serialize()，DeleteContents()
public属性：CObArray m_Elements;
7.OnDraw()
由于CShape.cpp调用了Draw（）函数，而OnDraw（）函数的定义是在DrawingView.cpp中，故应该在DrawingView.cpp中对Ondraw（）进行调用声明，代码如下：
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
8.鼠标左键单击消息响应函数
同时按下Ctrl和鼠标左键按，弹出对话框，编辑后画出图形。打开类向导在DrawingView类添加名为OnLButtonDown的消息响应函数。双击OnLButtonDown，进入OnLButtonDown的定义模块，先判断是否按下Ctrl键，然后写入新建图元代码。写入以下代码：
void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDrawingDoc* pDoc = GetDocument();//函数GetDocument()用于获取当前文档对象的指针m_pDocument
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
			Invalidate();
		}
	}
	CScrollView::OnLButtonDown(nFlags, point);
}
9.鼠标左键双击消息响应函数
双击左键后弹出对话框，然后可以修改图形的属性。。打开类向导在DrawingView类添加名为OnLButtonDblClk的消息响应函数。双击OnLButtonDblClk，进入OnLButtonDblClk的定义模块，然后写入重绘图元代码。写入以下代码：
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
10.鼠标右键双击消息响应函数
与添加鼠标左键消息相应的方法一样先在ClassTizard中添加，双击进入定义模块，要实现右键双击删除，首先得明白我们基于图元的数据存储在于动态数组mElcments，所以，要删除图元，只需删除该图元对应数组中存储的数据即可，主要代码如下：
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
11.文档的存取
文档的存储主要通过文档类重载成员函数Serialize来实现。
（1）在CDrawingDoc类中加Serialize()，DeleteContents()，~CDrawingDoc()成员函数，代码如下：
void CDrawingDoc::Serialize(CArchive& ar)
{
	m_Elements.Serialize(ar);
}
void CDrawingDoc::DeleteContents()
{
	// TODO:  在此添加专用代码和/或调用基类
	for (int i = 0; i < m_Elements.GetSize(); i++)
	{
		CShape* p = (CShape*)m_Elements[i];
		delete(p);
	}
	m_Elements.RemoveAll();
	CDocument::DeleteContents();
}
CDrawingDoc::~CDrawingDoc()
{
	this->DeleteContents();
}
