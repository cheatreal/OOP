#FUNCTION

   bool cHook(LPCTSTR DllName, LPCSTR FuncName, PROC pFn, PBYTE pBytes)
 
      - DllName   : ��ŷ�� API�� �ִ� DLL
      - FuncName  : ��ŷ�� API
      - pFn       : ��ŷ ���ν���
      - pBytes    : ���� �ڵ�����

   bool UncHook(LPCTSTR DllName, LPCSTR FuncName, PBYTE pBytes)
      
      - DllName   : ���ŵ� API�� �ִ� DLL
      - FuncName  : ���ŵ� API
      - pBytes    : ���� �ڵ�


