
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
	int m_flag; // 0�������߶�12 1�������߶�23 2���ƶ�1�� 3���ƶ�2�� 4���ƶ�3��

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
	afx_msg void OnEditTrianglesegment();
	afx_msg void OnUpdateEditTrianglesegment(CCmdUI* pCmdUI);
	afx_msg void OnEditOne();
	afx_msg void OnUpdateEditOne(CCmdUI* pCmdUI);
	afx_msg void OnEditTwo();
	afx_msg void OnUpdateEditTwo(CCmdUI* pCmdUI);
	afx_msg void OnEditThree();
	afx_msg void OnUpdateEditThree(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCTriangleView.cpp
inline CMFCTriangleDoc* CMFCTriangleView::GetDocument() const
   { return reinterpret_cast<CMFCTriangleDoc*>(m_pDocument); }
#endif

