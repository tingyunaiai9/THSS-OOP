
// MFCTriangleView.cpp : implementation of the CMFCTriangleView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTriangle.h"
#endif

#include "MFCTriangleDoc.h"
#include "MFCTriangleView.h"
#include "CDraw2D.h"
#include "CDialogCoordinates.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTriangleView

IMPLEMENT_DYNCREATE(CMFCTriangleView, CView)

BEGIN_MESSAGE_MAP(CMFCTriangleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_DIALOG, &CMFCTriangleView::OnEditDialog)
	ON_COMMAND(ID_EDIT_CREATE, &CMFCTriangleView::OnEditCreate)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CREATE, &CMFCTriangleView::OnUpdateEditCreate)
	ON_COMMAND(ID_EDIT_MOVE, &CMFCTriangleView::OnEditMove)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MOVE, &CMFCTriangleView::OnUpdateEditMove)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCTriangleView construction/destruction

CMFCTriangleView::CMFCTriangleView() noexcept : m_flag(10)
{
	// TODO: add construction code here

}

CMFCTriangleView::~CMFCTriangleView()
{
}

BOOL CMFCTriangleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCTriangleView drawing

void CMFCTriangleView::OnDraw(CDC* pDC)
{
	CMFCTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	gb_draw2D(*pDC, pDoc->m_triangleSegment, PS_SOLID, 0, 0, 0);
}


// CMFCTriangleView printing

BOOL CMFCTriangleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCTriangleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTriangleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCTriangleView diagnostics

#ifdef _DEBUG
void CMFCTriangleView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTriangleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTriangleDoc* CMFCTriangleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTriangleDoc)));
	return (CMFCTriangleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTriangleView message handlers


void CMFCTriangleView::OnEditDialog()
{
	// TODO: Add your command handler code here
	CMFCTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDialogCoordinates d;
	d.m_point1X = pDoc->m_triangleSegment.m_point1.m_x;
	d.m_point1Y = pDoc->m_triangleSegment.m_point1.m_y;
	d.m_point2X = pDoc->m_triangleSegment.m_point2.m_x;
	d.m_point2Y = pDoc->m_triangleSegment.m_point2.m_y;
	d.m_point3X = pDoc->m_triangleSegment.m_point3.m_x;
	d.m_point3Y = pDoc->m_triangleSegment.m_point3.m_y;
	if (IDOK == d.DoModal())
	{
		pDoc->m_triangleSegment.m_point1.m_x = d.m_point1X;
		pDoc->m_triangleSegment.m_point1.m_y = d.m_point1Y;
		pDoc->m_triangleSegment.m_point2.m_x = d.m_point2X;
		pDoc->m_triangleSegment.m_point2.m_y = d.m_point2Y;
		pDoc->m_triangleSegment.m_point3.m_x = d.m_point3X;
		pDoc->m_triangleSegment.m_point3.m_y = d.m_point3Y;
		Invalidate();
	}
	GetParentFrame()->GetMessageBar()
		->SetWindowText(_T("设置线段端点坐标!"));
}


void CMFCTriangleView::OnEditCreate()
{
	// TODO: Add your command handler code here
	m_flag = 10;

	GetParentFrame()->GetMessageBar()
		->SetWindowText(_T("鼠标点击依次设置三个顶点"));
}

void CMFCTriangleView::OnUpdateEditCreate(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_flag < 20) ? 1 : 0);
}

void CMFCTriangleView::OnEditMove()
{
	// TODO: Add your command handler code here
	m_flag = 20;

	GetParentFrame()->GetMessageBar()
		->SetWindowText(_T("鼠标点击移动最近顶点"));
}

void CMFCTriangleView::OnUpdateEditMove(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_flag < 20) ? 0 : 1);
}


void CMFCTriangleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMFCTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (m_flag == 10)
	{
		pDoc->Set3Point(1, point);
		m_flag = 11;
	}
	else if (m_flag == 11)
	{
		pDoc->Set3Point(2, point);
		m_flag = 12;
	}
	else if (m_flag == 12)
	{
		pDoc->Set3Point(3, point);
		m_flag = 10;
	}
	else if (m_flag == 20)
	{ 
		pDoc->CalcNearest(point);
		m_flag = 21;
	}
	
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

void CMFCTriangleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMFCTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (m_flag == 21)
	{
		pDoc->UpdateNearest(point);

		m_flag = 20;
	}

	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}

void CMFCTriangleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//CString trace_info;
	//trace_info.Format(_T("%d, %d \n"), point.x, point.y);
	//TRACE(trace_info);

	CMFCTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (m_flag == 21)
	{
		pDoc->UpdateNearest(point);
	}
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}
