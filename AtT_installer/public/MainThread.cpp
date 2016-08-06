/*

*/

#include<Windows.h>
#include<thread>
#include"_file_.h"
#include"BP_functor.h"

#define windows_mean_and_lean
const wchar_t g_szClassName[] = L"NoErwinusInstaller";

LRESULT CALLBACK WindowProc
(
	_In_ HWND hwnd,
	_In_ UINT uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

int _stdcall WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	WNDCLASSEX win;
	HWND hwnd;
	MSG msg;

	win.cbSize =sizeof(WNDCLASSEX);
	win.style = 0 ;
	win.lpfnWndProc=WindowProc;
	win.cbClsExtra = 0;
	win.cbWndExtra =0 ;
	win.hInstance = hInstance;
	win.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	win.hCursor = LoadCursor(NULL, IDC_ARROW);
	win.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	win.lpszMenuName = NULL;
	win.lpszClassName = g_szClassName;
	win.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, L"Ashan Goes to the TrashCan",
		   WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 200, 200, NULL, NULL, hInstance, NULL);

	if(!RegisterClassEx(&win))
	{
		MessageBox(hwnd, L"Registration Error! Erwin will prevail", L"Error", MB_ICONEXCLAMATION);
		return 0;
	}

	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, hwnd, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}