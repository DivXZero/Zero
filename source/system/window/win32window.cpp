
// *****************************************************************************

#include "system/window/win32window.h"

// *****************************************************************************

using namespace Zero;
using namespace System;

// *****************************************************************************

#ifdef WIN32

#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"

// *****************************************************************************

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
        
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
        break;
    }

    return 0;
}

// *****************************************************************************

bool Win32Window::create()
{
    HINSTANCE hModule = GetModuleHandle(0);

    m_wndClass.cbSize = sizeof(WNDCLASSEX);
    m_wndClass.style = 0;
    m_wndClass.lpfnWndProc = WndProc;
    m_wndClass.cbClsExtra = 0;
    m_wndClass.cbWndExtra = 0;
    m_wndClass.hInstance = hModule;
    m_wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    m_wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    m_wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    m_wndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
    m_wndClass.lpszMenuName = NULL;
    m_wndClass.lpszClassName = "ZeroWin32Window";

    if (!RegisterClassEx(&m_wndClass))
        return false;

    m_hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, "ZeroWin32Window", "Zero", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hModule, NULL);

    if (m_hWnd == NULL)
        return false;

    //m_hDC = GetDC(m_hWnd);

    ShowWindow(m_hWnd, 1);
    UpdateWindow(m_hWnd);

    /*
    //while (GetMessage(&m_msg, NULL, 0, 0) > 0)
    while (PeekMessage(&m_msg, NULL, 0, 0, PM_REMOVE))
    {
        // PeekMessage?
        //TranslateMessage(&m_msg);
        DispatchMessage(&m_msg);
        //SwapBuffers(m_hDC);
    }
    */

    m_isOpen = true;
    return true;
}

// *****************************************************************************

void Win32Window::pollEvents()
{
    while (PeekMessage(&m_msg, NULL, 0, 0, PM_REMOVE))
    {
        switch (m_msg.message)
        {
        case WM_QUIT:
            m_isOpen = false;
            break;
        default:
            break;
        }

        DispatchMessage(&m_msg);
    }
}

// *****************************************************************************

#endif  // WIN32