#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<tchar.h>

#define BUFF_SIZE 256
TCHAR szName[]=TEXT("Global\\FimeMappingObject");
TCHAR szMsg[] = TEXT("Message from first process");
int _tmain(){
	HANDLE hMapFIle;
	LPCTSTR pBuf;
	
	hMapFile = OpenFileMapping(
			FILE_MAP_ALL_ACCESS,  //read/write acess
			FALSE,			// do not inherit name
			szName);		//name of mapping object 

	if(hMapFIle == NULL){
		_tprintf(TEXT("Could not open file mapping object (%d)\n"),GetLastError());
		return 1;
	}
	
	pBuf = (LPTSTR) MapViewOfFile(
				hMapFile,	//handle to map object
				FILE_MAP_ALL_ACCESS, //read/write permissions
				0,
				0,
				BUFF_SIZE);

	if(pBuf == NULL){
		_tprintf(TEXT("Could not map view of file(%d)\n"),GetLastError());
		CloseHandle(hMapFIle);
		return 1;
	}
	
	MessageBox(NULL,pBuf,TEXT("Process2"),MB_OK);
	
	UnmapViewOFFile(pBuff);
	
	CloseHandle(hMapFIle);
	

return 0;
}
