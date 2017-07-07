// UnicodeTestConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UnicodeTestConsole.h"
#include <vector>
#include <iostream>
#include <string>
#include <process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool IsUnicodeFile(const CString &strFile)
{
	bool bUnicode = false;
	CFile file;
	if(file.Open(strFile, CFile::modeRead))
	{
		WORD wBom;
		file.Read(&wBom, sizeof(WORD));
		if(wBom == 0xFEFF)
		{
			bUnicode = true;
		}
		file.Close();
	}

	return bUnicode;
}

bool Filter(const CString &strFile)
{
	int nPos = strFile.ReverseFind(_T('.'));
	if(nPos != -1)
	{
		CString strExt = strFile.Right(strFile.GetLength() - nPos - 1);
		if(strExt.CompareNoCase(_T("cpp")) == 0 
		|| strExt.CompareNoCase(_T("h")) == 0 )
		return true;
	}
	return false;

}

void TestDirectoryUnicode(const CString &strPath)
{
	CFileFind finder;
	BOOL bResult = finder.FindFile(strPath+_T("\\*.*"));
	bool bFindUnUnicode = false;
	while(bResult)
	{
		bResult = finder.FindNextFile();
		if(!finder.IsDots())
		{
			if(finder.IsDirectory())
			{
				TestDirectoryUnicode(finder.GetFilePath());
			}
			else
			{
				CString strFile = finder.GetFilePath();
				if(Filter(strFile))
				{
					if(!IsUnicodeFile(strFile))
					{
						bFindUnUnicode = true;
						std::wcout << LPCTSTR(strFile) << _T("\n");
					}
				}			
			}
		}
	}

	if(bFindUnUnicode)
	std::wcout <<  _T("\n");
}
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		TCHAR szExe[MAX_PATH];
		::GetModuleFileName(NULL,szExe,MAX_PATH);
		CString strPathName = szExe;
		int nPos = strPathName.ReverseFind(_T('\\'));
		if(nPos != -1)
		{
			CString strPath = strPathName.Left(nPos);
			system("cls");
			std::wcout<< (_T("----- Un Unicode Files Start \"*.h; *.cpp\"----- ")) << _T("\n") << _T("\n");
			TestDirectoryUnicode(strPath);
			std::wcout<< (_T("----- Un Unicode Files End   ----- ")) << endl;
			system("pause");
		}		
	}

	return nRetCode;
}
