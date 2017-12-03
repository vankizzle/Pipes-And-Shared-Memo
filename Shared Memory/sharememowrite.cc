#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<tchar.h>
#pragma comment (lib,"user32.lib")
#define BUFF_SIZE 256

TCHAR szName[]=TEXT("Global\\FimeMappingObject");


int _tmain(){
	HANDLE hMapFIle;
	LPCTSTR pBuf;
	
	hMapFile = CreateFileMapping(
				INVALID_HANDLE_VALUE, //use paging file
				NULL,			//default security
				PAGE_READWRITE,		//read/write acess
				0,			//minimum object size ( high-order DWORD)
				BUFF_SIZE,		// maximum object size (low-order DWORD)
				szName);		//name of mapping object

	if(hMapFIle == NULL){
		_tprintf(TEXT("Could not open file mapping object (%d)\n"),GetLastError());
		return 1;
	}
	
	pBuf = (LPTSTR) MapViewOfFile(
				hMapFile,      //handle map object
				FILE_MAP_ALL_ACCESS, //read/write permissions
				0,
				0,
				BUFF_SIZE);

	if(pBuf == NULL){
		_tprintf(TEXT("Could not map view of file(%d)\n"),GetLastError());
		CloseHandle(hMapFIle);
		return 1;
	}
	
	CopyMemory((PVOID)pBuf,szMSG,(_tcslen(szMsg) * sizeof(TCHAR)));
	_getch();
	
	UnmapViewOFFile(pBuff);
	
	CloseHandle(hMapFIle);
	

return 0;
}
