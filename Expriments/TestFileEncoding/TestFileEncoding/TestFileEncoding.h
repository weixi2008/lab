
// TestFileEncoding.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestFileEncodingApp:
// �йش����ʵ�֣������ TestFileEncoding.cpp
//

class CTestFileEncodingApp : public CWinAppEx
{
public:
	CTestFileEncodingApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestFileEncodingApp theApp;