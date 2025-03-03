
// MFCTriangleDoc.cpp : implementation of the CMFCTriangleDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTriangle.h"
#endif

#include "MFCTriangleDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCTriangleDoc

IMPLEMENT_DYNCREATE(CMFCTriangleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCTriangleDoc, CDocument)
END_MESSAGE_MAP()


// CMFCTriangleDoc construction/destruction

CMFCTriangleDoc::CMFCTriangleDoc() noexcept : m_triangleSegment(100,100,300,100,300,300)
{
	// TODO: add one-time construction code here

}

CMFCTriangleDoc::~CMFCTriangleDoc()
{
}

BOOL CMFCTriangleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCTriangleDoc serialization

void CMFCTriangleDoc::Serialize(CArchive& ar)
{
	int flag;
	CString cs;
	wchar_t * buf;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		cs.Format(_T("#TriangleSegment begin\n"));
		ar.WriteString(cs);
		cs.Format(_T("%g,%g,%g,%g,%g,%g\n"),
			m_triangleSegment.m_point1.m_x, m_triangleSegment.m_point1.m_y,
			m_triangleSegment.m_point2.m_x, m_triangleSegment.m_point2.m_y, 
			m_triangleSegment.m_point3.m_x, m_triangleSegment.m_point3.m_y);
		ar.WriteString(cs);
		cs.Format(_T("#TriangleSegment end\n"));
		ar.WriteString(cs);
	}
	else
	{
		// TODO: add loading code here
		flag = 0;
		while (ar.ReadString(cs))
		{
			cs.Trim();
			if (flag == 0)
			{
				if (cs.CompareNoCase(_T("#TriangleSegment begin\n")) == 0)
					flag = 1;
			}
			else if (flag == 1)
			{
				buf = cs.GetBuffer();
				swscanf_s(buf,_T(" % lf, % lf, % lf, % lf, % lf, % lf"),
					&(m_triangleSegment.m_point1.m_x), &(m_triangleSegment.m_point1.m_y),
					&(m_triangleSegment.m_point2.m_x), &(m_triangleSegment.m_point2.m_y), 
					&(m_triangleSegment.m_point3.m_x), &(m_triangleSegment.m_point3.m_y));
				break;
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCTriangleDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCTriangleDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCTriangleDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCTriangleDoc diagnostics

#ifdef _DEBUG
void CMFCTriangleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCTriangleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCTriangleDoc commands
