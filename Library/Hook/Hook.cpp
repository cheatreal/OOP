#include "Hook.h"

bool Hook::cHook(LPCTSTR DllName, LPCSTR FuncName, PROC pFn, PBYTE pBytes)
{
	FARPROC pfnOrg;
	DWORD dwOldProtect, dwAddress;
	BYTE pBuf[5] = { 0xe9, 0, };
	PBYTE pByte;

	// ��ŷ API 
	pfnOrg = (FARPROC)GetProcAddress(GetModuleHandle(DllName), FuncName);
	pByte = (PBYTE)pfnOrg;

	// ��ŷ ����
	if (pByte[0] == 0xE9) 
		return FALSE; 

	
	// 5����Ʈ �Ӽ� �߰�
	VirtualProtect((LPVOID)pfnOrg, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// ���� �ڵ� ����
	memcpy(pBytes, pfnOrg, 5);

	// JMP �ּ� ���
	dwAddress = (DWORD)pFn - (DWORD)pfnOrg - 5;
	memcpy(&pBuf[1], &dwAddress, 4);

	// JMP �ּ� ��ġ
	memcpy(pfnOrg, pBuf, 5);

	// �޸� �Ӽ� ����
	VirtualProtect((LPVOID)pfnOrg, 5, dwOldProtect, &dwOldProtect);

	return TRUE;
}

bool Hook::UncHook(LPCTSTR DllName, LPCSTR FuncName, PBYTE pBytes)
{
	FARPROC pFunc;
	DWORD dwOldProtect;
	
	// ���� API
	pFunc = GetProcAddress(GetModuleHandle(DllName) , FuncName);


	// 5����Ʈ �Ӽ� �߰�
	VirtualProtect((LPVOID)pFunc, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// ���� �ڵ� ��ġ
	memcpy(pFunc, pBytes, 5);

	// �޸� �Ӽ� ����
	VirtualProtect((LPVOID)pFunc, 5, dwOldProtect, &dwOldProtect);

	return TRUE;
}