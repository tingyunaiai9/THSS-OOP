
// MFCPatternView.h : interface of the CMFCPatternView class
//

#pragma once


class CMFCPatternView : public CView
{
protected: // create from serialization only
	CMFCPatternView() noexcept;
	DECLARE_DYNCREATE(CMFCPatternView)

// Attributes
public:
	int m_flag;

	CMFCPatternDoc* GetDocument() const;

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
	virtual ~CMFCPatternView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCPatternView.cpp
inline CMFCPatternDoc* CMFCPatternView::GetDocument() const
   { return reinterpret_cast<CMFCPatternDoc*>(m_pDocument); }
#endif

