// SynergyReturnFixer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SynergyReturnFixer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString g_strTempFile;

bool Process(const CString &strFile)
{
	bool bNeedDeleteReturn = false;
	CFile file;
	CFile fileDest;
	const WORD wReturn = 0x0D;
	if(file.Open(strFile, CFile::modeRead))
	{
		if(fileDest.Open(g_strTempFile, CFile::modeWrite|CFile::modeCreate))
		{
			ULONG uLength = file.GetLength();

			if(uLength >= 2 && (uLength % 2) == 0)
			{
				BYTE* pBuffer = new BYTE[uLength];
				file.Read(pBuffer, uLength);

				if(pBuffer[0] == 0xFF && pBuffer[1] == 0xFE)
				{
					ULONG uLastWriteStartPos = 0;
					for(ULONG i = 2; i < uLength; i += 2)
					{
						if(pBuffer[i] == 0x0A && pBuffer[i+1] == 0x00)
						{
							if(!(pBuffer[i-2] == 0x0D && pBuffer[i-1] == 0x00))
							{
								//Need Fill 0x000D.
								bNeedDeleteReturn = true;
								fileDest.Write(&pBuffer[uLastWriteStartPos], i - uLastWriteStartPos);
								uLastWriteStartPos = i;
								fileDest.Write(&wReturn, sizeof(WORD));
							}
						}
					}

					if(uLastWriteStartPos < uLength)
					{
						if(bNeedDeleteReturn)
						{
							fileDest.Write(&pBuffer[uLastWriteStartPos], uLength - uLastWriteStartPos);
						}
					}

				}
				delete[] pBuffer;
			}

			fileDest.Close();
		}
		file.Close();
	}


	if(bNeedDeleteReturn)
	{
		CFileStatus status;
		if(CFile::GetStatus(strFile, status))
		{
			if((status.m_attribute & CFile::readOnly) != 0)
			{
				status.m_attribute &= ~CFile::readOnly;
				CFile::SetStatus(strFile, status);
			}
		}

		BOOL bSuccess = ::CopyFile(g_strTempFile, strFile, false);
		ASSERT(bSuccess);
		::DeleteFile(g_strTempFile);
	}

	return bNeedDeleteReturn;
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
	bool bNeedReturn = false;
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
					if(Process(strFile))
					{
						bNeedReturn = true;
						std::wcout << LPCTSTR(strFile) << _T("\n");
					}
				}			
			}
		}
	}

	if(bNeedReturn)
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
		TCHAR szTempPath[MAX_PATH];
		::GetTempPath(MAX_PATH, szTempPath);
		g_strTempFile = szTempPath;
		g_strTempFile += _T("SynergyReturnFixer.txt");


		TCHAR szExe[MAX_PATH];
		::GetModuleFileName(NULL,szExe,MAX_PATH);
		CString strPathName = szExe;
		int nPos = strPathName.ReverseFind(_T('\\'));
		if(nPos != -1)
		{
			CString strPath = strPathName.Left(nPos);
			system("cls");
			std::wcout<< (_T("----- Fix Synergy Merge Problem. Start \"*.h; *.cpp\"----- ")) << _T("\n") << _T("\n");
			TestDirectoryUnicode(strPath);
			std::wcout<< (_T("----- End. Change Fixed Files writable. Please Sync.----- ")) << endl;
			system("pause");
		}		
	}

	return nRetCode;
}
