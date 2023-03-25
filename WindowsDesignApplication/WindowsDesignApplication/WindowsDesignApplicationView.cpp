
// WindowsDesignApplicationView.cpp : implementation of the CWindowsDesignApplicationView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WindowsDesignApplication.h"
#endif

#include "WindowsDesignApplicationDoc.h"
#include "WindowsDesignApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWindowsDesignApplicationView

IMPLEMENT_DYNCREATE(CWindowsDesignApplicationView, CView)

BEGIN_MESSAGE_MAP(CWindowsDesignApplicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWindowsDesignApplicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWindowsDesignApplicationView construction/destruction

CWindowsDesignApplicationView::CWindowsDesignApplicationView() noexcept
{
	EnableActiveAccessibility();
	// TODO: add construction code here

}

CWindowsDesignApplicationView::~CWindowsDesignApplicationView()
{
}

BOOL CWindowsDesignApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CWindowsDesignApplicationView drawing

void CWindowsDesignApplicationView::OnDraw(CDC* /*pDC*/)
{
	CWindowsDesignApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CWindowsDesignApplicationView printing


void CWindowsDesignApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWindowsDesignApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWindowsDesignApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWindowsDesignApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CWindowsDesignApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWindowsDesignApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWindowsDesignApplicationView diagnostics

#ifdef _DEBUG
void CWindowsDesignApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CWindowsDesignApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWindowsDesignApplicationDoc* CWindowsDesignApplicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWindowsDesignApplicationDoc)));
	return (CWindowsDesignApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CWindowsDesignApplicationView message handlers
