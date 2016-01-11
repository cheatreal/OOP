#include "Hook.h"

bool Hook::cHook(LPCTSTR DllName, LPCSTR FuncName, PROC pFn, PBYTE pBytes)
{
	FARPROC pfnOrg;
	DWORD dwOldProtect, dwAddress;
	BYTE pBuf[5] = { 0xe9, 0, };
	PBYTE pByte;

	// 후킹 API 
	pfnOrg = (FARPROC)GetProcAddress(GetModuleHandle(DllName), FuncName);
	pByte = (PBYTE)pfnOrg;

	// 후킹 상태
	if (pByte[0] == 0xE9) 
		return FALSE; 

	
	// 5바이트 속성 추가
	VirtualProtect((LPVOID)pfnOrg, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// 원본 코드 저장
	memcpy(pBytes, pfnOrg, 5);

	// JMP 주소 계산
	dwAddress = (DWORD)pFn - (DWORD)pfnOrg - 5;
	memcpy(&pBuf[1], &dwAddress, 4);

	// JMP 주소 패치
	memcpy(pfnOrg, pBuf, 5);

	// 메모리 속성 복원
	VirtualProtect((LPVOID)pfnOrg, 5, dwOldProtect, &dwOldProtect);

	return TRUE;
}

bool Hook::UncHook(LPCTSTR DllName, LPCSTR FuncName, PBYTE pBytes)
{
	FARPROC pFunc;
	DWORD dwOldProtect;
	
	// 언훅 API
	pFunc = GetProcAddress(GetModuleHandle(DllName) , FuncName);


	// 5바이트 속성 추가
	VirtualProtect((LPVOID)pFunc, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// 원본 코드 패치
	memcpy(pFunc, pBytes, 5);

	// 메모리 속성 복원
	VirtualProtect((LPVOID)pFunc, 5, dwOldProtect, &dwOldProtect);

	return TRUE;
}