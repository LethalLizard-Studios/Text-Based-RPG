#include <iostream>
#include <windows.h>
#include "factions.h";

//MessageBox(NULL, L"Gas Mask", L"Retrieve Item?", MB_ICONEXCLAMATION | MB_YESNO);

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddControls(HWND);
void AddMenus(HWND);

HMENU hMenu;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	WNDCLASSW wc = { 0 };

	wc.hbrBackground = CreateSolidBrush(RGB(18, 26, 8));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;

	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(L"myWindowClass", L"Терминал x16", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE,
		100, 100, 500, 500, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };

	while (GetMessage((&msg), NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
		case WM_COMMAND:

			switch (wp) {
				case 1:
					MessageBeep(MB_OK);
					break;
				case 2:
					//MessageBox(NULL, L"Save & Quit Game", L"WARNING", MB_ICONWARNING | MB_YESNOCANCEL);
					//DestroyWindow(hWnd);
					break;
			}

			break;
		case WM_CREATE:
			AddControls(hWnd);
			AddMenus(hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_CTLCOLORSTATIC:     
			SetTextColor((HDC)wp, RGB(115, 115, 92));
			SetBkMode((HDC)wp, TRANSPARENT);
			return GetClassLongPtr(hWnd, GCLP_HBRBACKGROUND);
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddControls(HWND hWnd) {
	RECT rect;
	if (GetWindowRect(hWnd, &rect)) {
		HWND textLog = CreateWindowW(L"static", L"[01:22]ADMIN: Welcome to Terminal 16.\n[01:23]ADMIN: We sincerely thank you for investing in our technology.", WS_VISIBLE | WS_CHILD, 20, 120,
			440, 420, hWnd,
			NULL, NULL, NULL);

		LOGFONT logfont;
		ZeroMemory(&logfont, sizeof(LOGFONT));
		logfont.lfCharSet = DEFAULT_CHARSET;
		logfont.lfHeight = -16;
		HFONT hFont = CreateFontIndirect(&logfont);

		SendMessage(textLog, WM_SETFONT, (WPARAM)hFont, TRUE);
	}
}

void AddMenus(HWND hWnd) {
	hMenu = CreateMenu();

	HMENU hFileMenu = CreateMenu();
	AppendMenu(hFileMenu, MF_STRING, 1, L"Settings / Настройки");
	AppendMenu(hFileMenu, MF_STRING, 1, L"Save / Сохранять");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");

	HMENU hEditMenu = CreateMenu();
	AppendMenu(hEditMenu, MF_STRING, 1, L"Persona / личность");
	AppendMenu(hEditMenu, MF_STRING, 1, L"Stats / статистика");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hEditMenu, L"Edit");

	HMENU hViewMenu = CreateMenu();
	AppendMenu(hViewMenu, MF_STRING, 1, L"Stock / запас");
	AppendMenu(hViewMenu, MF_STRING, 1, L"Reputation / репутация");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hViewMenu, L"View");

	AppendMenu(hMenu, MF_STRING, NULL, L"Help");

	SetMenu(hWnd, hMenu);
}