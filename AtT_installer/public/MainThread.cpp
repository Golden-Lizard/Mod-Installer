
#include<Windows.h>

#include<thread>
#include<string>
#include<fstream>
#include<vector>

#include"resources.h"
#include"_file_.h"
#include"BP_functor.h"
#include"Hash.h"

#define windows_mean_and_lean
const wchar_t g_szClassName[] = L"NoErwinusInstaller";

void create_file_array(std::fstream file_names, std::vector<_file_> & files);

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
	
	case WM_LBUTTONDOWN:
	{
		Hash_table<std::string> table(10);
		try
		{
			table.Add_item("abc", "abc");
		}
		catch (...)
		{
			MessageBox(hwnd, L"ERROR", L"ERROR", MB_OK);
		}
	}

		break;
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

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX winz;
	HWND hwnd;
	MSG Msg;

	winz.cbSize = sizeof(WNDCLASSEX);
	winz.style = 0;
	winz.lpfnWndProc = WindowProc;
	winz.cbClsExtra = 0;
	winz.cbWndExtra = 0;
	winz.hInstance = hInstance;
	winz.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_TRASHICON));
	winz.hCursor = LoadCursor(NULL, IDC_ARROW);
	winz.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	winz.lpszMenuName = NULL;
	winz.lpszClassName = g_szClassName;
	winz.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&winz))
	{
		MessageBox(NULL, L"ERROR", L"ERWANUS", MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, L"Ashan Goes to the TrashCan",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 200, 200, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(hwnd, L"Registration Error! Erwin will prevail", L"Error", MB_ICONEXCLAMATION);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&Msg, hwnd, 0, 0)>0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return Msg.wParam;
}


void create_file_array(std::fstream file_names, std::vector<_file_> & files)
{
	for (std::string name; std::getline(file_names, name);)
	{
		std::wstring tmp(name.length(), L' ');
		std::copy(name.begin(), name.end(), tmp.begin());
		files.push_back(_file_::_file_(tmp, std::wstring(L""), std::wstring(L""), true));
	}
};

