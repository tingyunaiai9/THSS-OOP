
// MFCPatternView.cpp : implementation of the CMFCPatternView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCPattern.h"
#endif

#include "MFCPatternDoc.h"
#include "MFCPatternView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CDrawPattern.h"

// CMFCPatternView

IMPLEMENT_DYNCREATE(CMFCPatternView, CView)

BEGIN_MESSAGE_MAP(CMFCPatternView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCPatternView construction/destruction

CMFCPatternView::CMFCPatternView() noexcept
{
	// TODO: add construction code here
	static int i = 0;
	m_flag = i;
	i++;
	if (i >= 4)
		i = 0;
}

CMFCPatternView::~CMFCPatternView()
{
}

BOOL CMFCPatternView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCPatternView drawing

void CMFCPatternView::OnDraw(CDC* pDC)
{
	CMFCPatternDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CPoint2D point1(50,50), point2(250,250), point3(100,300), point4(200,50);
	//CCuboid cuboid(point1, point2, 100);
	//CParallelogram parallelogram(point1, point3, point4);
	//CBow bow(point2, 150);

	//gb_drawCuboid(*pDC, cuboid, PS_SOLID, RGB(19, 17, 36), RGB(48, 47, 75));
	//gb_drawParallelogram(*pDC, parallelogram, PS_SOLID, RGB(198, 223, 200));
	//gb_drawBow(*pDC, bow, PS_SOLID, RGB(249, 215, 112));
	gb_drawGift(*pDC, PS_SOLID, point1, point2, 50, m_flag);
}


// CMFCPatternView printing

BOOL CMFCPatternView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCPatternView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCPatternView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCPatternView diagnostics

#ifdef _DEBUG
void CMFCPatternView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPatternView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPatternDoc* CMFCPatternView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPatternDoc)));
	return (CMFCPatternDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPatternView message handlers
