#VARIABLE

   char* DllName
      
      - DllName  : DLL �̸�

   char* ProcName

      - ProcName : ���μ��� �̸�
   
#CONSTRUCTOR
   
   Patch(char* ProcName, char* DllName)

      - ProcName : ���μ��� �̸�
      - DllName  : DLL �̸�
  
#FUNCTION

   DWORD GetProcessId() 

      - Result   : ���μ��� ���̵�

   DWORD GetDllBase(DWORD pid)

      - pid	 : ���μ��� ���̵�
      - Result   : Dll ���̽���

   BOOL PatchCode(HANDLE hProc, DWORD Base, DWORD offset, LPCVOID opcode, DWORD bytes, PBYTE pOrgBytes)

      - hProc    : ���μ��� �ڵ�
      - Base     : DLL ���̽���
      - offset   : DLL ������
      - opcode   : ��ġ�� �ڵ�
      - bytes    : ��ġ�� ����
      - pOrgBytes: ���� �ڵ� ����