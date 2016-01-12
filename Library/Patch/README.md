#VARIABLE

   char* DllName
      
      - DllName  : DLL 이름

   char* ProcName

      - ProcName : 프로세스 이름
   
#CONSTRUCTOR
   
   Patch(char* ProcName, char* DllName)

      - ProcName : 프로세스 이름
      - DllName  : DLL 이름
  
#FUNCTION

   DWORD GetProcessId() 

      - Result   : 프로세스 아이디

   DWORD GetDllBase(DWORD pid)

      - pid	 : 프로세스 아이디
      - Result   : Dll 베이스값

   BOOL PatchCode(HANDLE hProc, DWORD Base, DWORD offset, LPCVOID opcode, DWORD bytes)

      - hProc    : 프로세스 핸들
      - Base     : DLL 베이스값
      - offset   : DLL 오프셋
      - opcode   : 패치할 코드
      - bytes    : 패치할 길이
