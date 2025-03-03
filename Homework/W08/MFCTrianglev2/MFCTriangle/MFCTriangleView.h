
// MFCTriangleView.h : interface of the CMFCTriangleView class
//

#pragma once


class CMFCTriangleView : public CView
{
protected: // create from serialization only
	CMFCTriangleView() noexcept;
	DECLARE_DYNCREATE(CMFCTriangleView)

// Attributes
public:
	// 10 11 12：鼠标点击输入三个顶点
	// 20 21：鼠标移动最近顶点
	int m_flag; 

	CMFCTriangleDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCTriangleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditDialog();
	afx_msg void OnEditCreate();
	afx_msg void OnUpdateEditCreate(CCmdUI* pCmdUI);
	afx_msg void OnEditMove();
	afx_msg void OnUpdateEditMove(CCmdUI* pCmdUI);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCTriangleView.cpp
inline CMFCTriangleDoc* CMFCTriangleView::GetDocument() const
   { return reinterpret_cast<CMFCTriangleDoc*>(m_pDocument); }
#endif

