#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>
#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/GroupBox.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace Native;

intptr Native::GroupBoxApi::Create(const System::Windows::Forms::GroupBox& groupBox) {
  HWND handle = CreateWindowEx(WS_EX_CONTROLPARENT, WC_BUTTON, groupBox.Text().w_str().c_str(), WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE | BS_GROUPBOX, groupBox.Left, groupBox.Top, groupBox.Width, groupBox.Height, (HWND)groupBox.Parent()().Handle(), (HMENU)0, GetModuleHandle(NULL), (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  //WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  //PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

System::Drawing::Size Native::GroupBoxApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
}

#endif
