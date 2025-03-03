
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
	ON_COMMAND(ID_EDIT_TRIANGLESEGMENT, &CMFCTriangleView::OnEditTrianglesegment)
	ON_UPDATE_COMMAND_UI(ID_EDIT_TRIANGLESEGMENT, &CMFCTriangleView::OnUpdateEditTrianglesegment)
	ON_COMMAND(ID_EDIT_ONE, &CMFCTriangleView::OnEditOne)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ONE, &CMFCTriangleView::OnUpdateEditOne)
	ON_COMMAND(ID_EDIT_TWO, &CMFCTriangleView::OnEditTwo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_TWO, &CMFCTriangleView::OnUpdateEditTwo)
	ON_COMMAND(ID_EDIT_THREE, &CMFCTriangleView::OnEditThree)
	ON_UPDATE_COMMAND_UI(ID_EDIT_THREE, &CMFCTriangleView::OnUpdateEditThree)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCTriangleView construction/destruction

CMFCTriangleView::CMFCTriangleView() noexcept : m_flag(0)
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


void CMFCTriangleView::OnEditOne()
{
	// TODO: Add your command handler code here
	m_flag = 2;
}


void CMFCTriangleView::OnUpdateEditOne(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_flag == 2) ? 1 : 0);
}


void CMFCTriangleView::OnEditTwo()
{
	// TODO: Add your command handler code here
	m_flag = 3;
}


void CMFCTriangleView::OnUpdateEditTwo(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_flag == 3) ? 1 : 0);
}


void CMFCTriangleView::OnEditThree()
{
	// TODO: Add your command handler code here
	m_flag = 4;
}


void CMFCTriangleView::OnUpdateEditThree(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_flag == 4) ? 1 : 0);
}


void CMFCTriangleView::OnEditTrianglesegment()
{
	// TODO: Add your command handler code here
	m_flag = 0;
}


void CMFCTriangleView::OnUpdateEditTrianglesegment(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_flag == 0) ? 1 : 0);
}


void CMFCTriangleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMFCTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if ((m_flag == 0) || (m_flag == 2))
	{
		pDoc->m_triangleSegment.m_point1.m_x = point.x;
		pDoc->m_triangleSegment.m_point1.m_y = point.y;
		Invalidate();
	}
	else if ((m_flag == 1) || (m_flag == 3))
	{
		pDoc->m_triangleSegment.m_point2.m_x = point.x;
		pDoc->m_triangleSegment.m_point2.m_y = point.y;
		Invalidate();
	}
	else if (m_flag == 4)
	{
		pDoc->m_triangleSegment.m_point3.m_x = point.x;
		pDoc->m_triangleSegment.m_point3.m_y = point.y;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCTriangleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMFCTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (m_flag == 0)
	{
		pDoc->m_triangleSegment.m_point2.m_x = point.x;
		pDoc->m_triangleSegment.m_point2.m_y = point.y;
		Invalidate();
	}
	else if (m_flag == 1)
	{
		pDoc->m_triangleSegment.m_point3.m_x = point.x;
		pDoc->m_triangleSegment.m_point3.m_y = point.y;
		Invalidate();
	}

	CView::OnLButtonUp(nFlags, point);
}
