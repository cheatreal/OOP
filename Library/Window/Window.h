#include <Windows.h>

class Window
{
	private:

		HINSTANCE g_hInst;
		LPCTSTR lpszClass;
	public:
		Window(LPCTSTR);
		int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow);
};