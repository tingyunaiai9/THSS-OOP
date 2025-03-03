#pragma once
#include "afxdialogex.h"


// CDialogCoordinates dialog

class CDialogCoordinates : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogCoordinates)

public:
	CDialogCoordinates(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogCoordinates();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COORDINATES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_point1X;
	double m_point1Y;
	double m_point2X;
	double m_point2Y;
	double m_point3X;
	double m_point3Y;
};
