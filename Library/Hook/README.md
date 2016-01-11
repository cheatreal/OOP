#FUNCTION

   bool cHook(LPCTSTR DllName, LPCSTR FuncName, PROC pFn, PBYTE pBytes)
 
      - DllName   : 후킹될 API가 있는 DLL
      - FuncName  : 후킹될 API
      - pFn       : 후킹 프로시저
      - pBytes    : 원본 코드저장

   bool UncHook(LPCTSTR DllName, LPCSTR FuncName, PBYTE pBytes)
      
      - DllName   : 원훅될 API가 있는 DLL
      - FuncName  : 언훅될 API
      - pBytes    : 원본 코드


