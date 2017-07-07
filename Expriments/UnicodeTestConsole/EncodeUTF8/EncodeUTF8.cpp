// EncodeUTF8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EncodeUTF8.h"
#include <vector>
#include <iostream>
#include <string>
#include <process.h> //system("cls")

#include "StdioFileEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int g_iCountSuccess = 0;
int g_iCountFailed = 0;

CString GetTempEncodingFileName(const CString& strFile)
{
	CString strTempFile;
	int nPos = strFile.ReverseFind(_T('\\'));
	if(nPos != -1)
	{
		CString strPath = strFile.Left(nPos);
		strTempFile = strPath + _T('\\') + _T("temp_encoding.tmp");
	}

	return strTempFile;
}

bool TransFileEncoding(const CString& strFile, UINT fromEncoding, UINT toEncoding)
{
	if(fromEncoding == toEncoding)
		return false;
	CString strFileOut = GetTempEncodingFileName(strFile);
	if(strFile.IsEmpty())
		return false;

	CStdioFileEx fileIn, fileOut;
	fileIn.SetCodePage(fromEncoding);
	fileOut.SetCodePage(toEncoding);
	CString strLine;

	if(fileIn.Open(strFile, CFile::modeRead | CFile::typeBinary))
	{
		if(fileOut.Open(strFileOut, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
		{
			while(fileIn.ReadString(strLine))
			{
				//注意：当前转换有个小问题，就是如果文件末尾无回车换行符的话，在最后一行加入了回车换行符。
				//因为readstring会将最后的回车换行符丢弃，如果判断文件末尾而不加入换行符的话，有些.h文件的编译会出错。 例如other\zip30\revision.h
				fileOut.WriteString(strLine + sNEWLINE);
			}

			fileOut.Close();
		}
		else
		{
			fileIn.Close();
			return false;
		}

		fileIn.Close();
	}
	else
	{
		return false;
	}

	//去除Readonly
	SetFileAttributes(strFile, GetFileAttributes(strFile) & ~FILE_ATTRIBUTE_READONLY);

	if(!DeleteFile(strFile))
	{
		return false;
	}
	if(!MoveFile(strFileOut, strFile))
	{
		return false;
	}

	return true;

}
// The one and only application object

CWinApp theApp;

using namespace std;

bool Filter(const CString &strFile)
{
	int nPos = strFile.ReverseFind(_T('.'));
	if(nPos != -1)
	{
		CString strExt = strFile.Right(strFile.GetLength() - nPos - 1);
		if(strExt.CompareNoCase(_T("cpp")) == 0 
			|| strExt.CompareNoCase(_T("h")) == 0 
			|| strExt.CompareNoCase(_T("hpp")) == 0
			|| strExt.CompareNoCase(_T("c")) == 0)
			return true;
	}

	return false;

}

bool ExcludeFile(const CString& strFile)
{
	int npos = strFile.ReverseFind(_T('\\'));
	if(npos != -1)
	{
		CString strOnlyFileName = strFile.Right(strFile.GetLength() - npos - 1);
		if(strOnlyFileName.CompareNoCase(_T("resource.h")) == 0)
			return true;
	}
	return false;
}

void RecursiveEncode2UTF8(const CString &strPath)
{
	const UINT CurrentAnsiCodepage = CStdioFileEx::GetCurrentLocaleCodePage();
	CFileFind finder;
	BOOL bResult = finder.FindFile(strPath+_T("\\*.*"));
	while(bResult)
	{
		bResult = finder.FindNextFile();
		if(!finder.IsDots())
		{
			if(finder.IsDirectory())
			{
				RecursiveEncode2UTF8(finder.GetFilePath());
			}
			else
			{
				CString strFile = finder.GetFilePath();
				if(Filter(strFile) && !ExcludeFile(strFile))
				{
					bool bSuccess = false;
					//UTF16的codepage为1200, UTF8的codepage为65001
					if(CStdioFileEx::IsFileUnicode(strFile))
					{
						bSuccess = TransFileEncoding(strFile, 1200, CP_UTF8);
					}
					else if(CStdioFileEx::isFileUTF8(strFile))
					{
						continue;
					}
					else //Ansi
					{
						bSuccess = TransFileEncoding(strFile, CurrentAnsiCodepage, CP_UTF8);
					}

					if(bSuccess)
					{
						g_iCountSuccess++;
						std::wcout<< LPCTSTR(strFile) << endl;
					}
					else
					{
						g_iCountFailed++;
						std::wcout<<_T("!Failed:") << LPCTSTR(strFile) << endl;
					}
				}			
			}
		}
	}

}


//此工程仅为一个测试工程，快速实现及转换。慎用。
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
			std::wcout<< (_T("----- Start trans to utf8 \"*.h, *.hpp; *.c, *.cpp\" Exclude resource.h----- ")) << _T("\n");
			RecursiveEncode2UTF8(strPath);
			std::wcout<< (_T("----- Finished: ")) << g_iCountSuccess << _T(" Succeed, ")<< g_iCountFailed << _T(" Failed.----- ")<< endl;
			system("pause");
		}		
	}

	return nRetCode;
}
