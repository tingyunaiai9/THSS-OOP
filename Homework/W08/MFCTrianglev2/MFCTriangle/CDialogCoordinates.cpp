// CDialogCoordinates.cpp : implementation file
//

#include "pch.h"
#include "MFCTriangle.h"
#include "afxdialogex.h"
#include "CDialogCoordinates.h"


// CDialogCoordinates dialog

IMPLEMENT_DYNAMIC(CDialogCoordinates, CDialogEx)

CDialogCoordinates::CDialogCoordinates(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COORDINATES, pParent)
{

}

CDialogCoordinates::~CDialogCoordinates()
{
}

void CDialogCoordinates::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_POINT1_X, m_point1X);
	DDX_Text(pDX, IDC_POINT1_Y, m_point1Y);
	DDX_Text(pDX, IDC_POINT2_X, m_point2X);
	DDX_Text(pDX, IDC_POINT2_Y, m_point2Y);
	DDX_Text(pDX, IDC_POINT3_X, m_point3X);
	DDX_Text(pDX, IDC_POINT3_Y, m_point3Y);
}


BEGIN_MESSAGE_MAP(CDialogCoordinates, CDialogEx)
END_MESSAGE_MAP()


// CDialogCoordinates message handlers
