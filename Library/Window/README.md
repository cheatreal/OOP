#VARIABLE

   LPCTSTR lpszClass
   INSTANCE g_hInst

#CONSTRUCTOR

   Window(LPCTSTR name)
      - name          : 프로그램 이름

#FUNCTION

   HINSTANCE Window::GethInstance()
      - Result        : 프로그램 인스턴스 핸들 

   int APIENTRY Window::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
      - hInstance     : 프로그램 인스턴스 핸들
      - hPrevInstance : 앞에 실행된 프로그램의 인스턴스 핸들 ( NULL )
      - lpszCmdParam  : 인자값 ( argv )
      - nCmdShow      : 윈도우 상태 옵션