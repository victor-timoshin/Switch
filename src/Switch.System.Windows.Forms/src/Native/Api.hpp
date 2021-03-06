#pragma once

#include <Switch/Static.hpp>
#include <Switch/System/EventHandler.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include "WindowMessage.hpp"
#include "WindowMessageKey.hpp"

namespace Switch {
  namespace System {
    namespace Drawing {
      class Font;
      class Point;
      class Rectangle;
      class Size;
    }
  }
}

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        enum class ArrangeDirection;
        enum class ArrangeStartingPosition;
        enum class BootMode;
        class Button;
        class ButtonBase;
        class CheckBox;
        class ColorDialog;
        class Control;
        class Cursor;
        enum class DialogResult;
        class FolderBrowserDialog;
        class FontDialog;
        class Form;
        class GroupBox;
        class Label;
        struct Message;
        enum class MessageBoxButtons;
        enum class MessageBoxIcon;
        enum class MessageBoxDefaultButton;
        enum class MessageBoxOptions;
        class OpenFileDialog;
        enum class Orientation;
        class Panel;
        class ProgressBar;
        class RadioButton;
        class SaveFileDialog;
        class Screen;
        class TabControl;
        class TabPage;
        class TrackBar;
      }
    }
  }
}

namespace Native {
  class ApplicationApi static_ {
  public:
    static void EnableVisualStyles() { visualStylesEnabled = true; }
    static void Exit();
    static bool HasVisualStylesEnabled() { return visualStylesEnabled; }
    static void MessageLoop(const System::Windows::Forms::Form& mainForm, System::EventHandler idle);
    static System::Windows::Forms::DialogResult ShowMessageBox(intptr owner, const string& message, const string& caption, System::Windows::Forms::MessageBoxButtons buttons, System::Windows::Forms::MessageBoxIcon icon, System::Windows::Forms::MessageBoxDefaultButton defaultButton, System::Windows::Forms::MessageBoxOptions options, bool displayHelpButton);
    static void Start();
    static void Stop();

  private:
    static bool visualStylesEnabled;
  };

  class ButtonApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::Button& button);
    static System::Drawing::Size GetDefaultSize();
    static void SetIsDefault(const System::Windows::Forms::ButtonBase& button);
  };

  class CheckBoxApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::CheckBox& checkBox);
    static System::Drawing::Size GetDefaultSize();
    static void SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox);
    static void SetChecked(const System::Windows::Forms::CheckBox& checkBox);
  };

  class ClipboardApi static_ {
  public:
    static int32 RegisterFormat(const string& format);
    static string GetFormatName(int32 id);
    static int32 GetIdBitmap();
    static int32 GetIdDib();
    static int32 GetIdDif();
    static int32 GetIdEnhancedMetafile();
    static int32 GetIdFileDrop();
    static int32 GetIdLocale();
    static int32 GetIdMetafilePict();
    static int32 GetIdOemText();
    static int32 GetIdPalette();
    static int32 GetIdPenData();
    static int32 GetIdRiff();
    static int32 GetIdSymbolicLink();
    static int32 GetIdText();
    static int32 GetIdTiff();
    static int32 GetIdUnicodeText();
    static int32 GetIdWaveAudio();
  };

  class CommonDialogApi static_ {
  public:
    static bool RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog& colorDialog);
    static bool RunFolderBrowserDialog(intptr hwnd, System::Windows::Forms::FolderBrowserDialog& folderBrowserDialog);
    static bool RunFontDialog(intptr hwnd, System::Windows::Forms::FontDialog& fontDialog);
    static bool RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog& openFileDialog);
    static bool RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog& saveFileDialog);
  };

  class ControlApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::Control& control);
    static void DefWndProc(System::Windows::Forms::Message& message);
    static void Destroy(const System::Windows::Forms::Control& control);
    static intptr GetHandleWindowFromDeviceContext(intptr hdc);
    static System::Drawing::Size GetTextSize(const System::Windows::Forms::Control& control);
    static void Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren);
    static void Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren);
    static System::Drawing::Point PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point);
    static System::Drawing::Point PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point);
    static intptr SendMessage(intptr handle, int32 msg, intptr wparam, intptr lparam);
    static void SetBackColor(intptr hdc);
    static void SetBackColor(const System::Windows::Forms::Control& control);
    static void SetClientSize(System::Windows::Forms::Control& control);
    static void SetCursor(const System::Windows::Forms::Control& control);
    static void SetEnabled(const System::Windows::Forms::Control& control);
    static bool SetFocus(const System::Windows::Forms::Control& control);
    static void SetFont(const System::Windows::Forms::Control& control);
    static void SetForeColor(intptr hdc);
    static void SetForeColor(const System::Windows::Forms::Control& control);
    static void SetLocation(const System::Windows::Forms::Control& control);
    static void SetParent(const System::Windows::Forms::Control& control);
    static void SetSize(System::Windows::Forms::Control& control);
    static void SetTabStop(const System::Windows::Forms::Control& control);
    static void SetText(const System::Windows::Forms::Control& control);
    static void SetVisible(const System::Windows::Forms::Control& control);

    // For debug...
    static string MessageToString(int32 id) {
      static System::Collections::Generic::Dictionary<int32, string> ids = { { WM_NULL, "WM_NULL" }, { WM_CREATE, "WM_CREATE" }, { WM_DESTROY, "WM_DESTROY" }, { WM_MOVE, "WM_MOVE" }, { WM_SIZE, "WM_SIZE" }, { WM_ACTIVATE, "WM_ACTIVATE" }, { WM_SETFOCUS, "WM_SETFOCUS" }, { WM_KILLFOCUS, "WM_KILLFOCUS" }, { WM_ENABLE, "WM_ENABLE" }, { WM_SETREDRAW, "WM_SETREDRAW" }, { WM_SETTEXT, "WM_SETTEXT" }, { WM_GETTEXT, "WM_GETTEXT" }, { WM_GETTEXTLENGTH, "WM_GETTEXTLENGTH" }, { WM_PAINT, "WM_PAINT" }, { WM_CLOSE, "WM_CLOSE" }, { WM_QUERYENDSESSION, "WM_QUERYENDSESSION" }, { WM_QUIT, "WM_QUIT" }, { WM_QUERYOPEN, "WM_QUERYOPEN" }, { WM_ERASEBKGND, "WM_ERASEBKGND" }, { WM_SYSCOLORCHANGE, "WM_SYSCOLORCHANGE" }, { WM_ENDSESSION, "WM_ENDSESSION" }, { WM_SHOWWINDOW, "WM_SHOWWINDOW" }, { WM_WININICHANGE, "WM_WININICHANGE" }, { WM_DEVMODECHANGE, "WM_DEVMODECHANGE" }, { WM_ACTIVATEAPP, "WM_ACTIVATEAPP" }, { WM_FONTCHANGE, "WM_FONTCHANGE" }, { WM_TIMECHANGE, "WM_TIMECHANGE" }, { WM_CANCELMODE, "WM_CANCELMODE" }, { WM_SETCURSOR, "WM_SETCURSOR" }, { WM_MOUSEACTIVATE, "WM_MOUSEACTIVATE" }, { WM_CHILDACTIVATE, "WM_CHILDACTIVATE" }, { WM_QUEUESYNC, "WM_QUEUESYNC" }, { WM_GETMINMAXINFO, "WM_GETMINMAXINFO" }, { WM_PAINTICON, "WM_PAINTICON" }, { WM_ICONERASEBKGND, "WM_ICONERASEBKGND" }, { WM_NEXTDLGCTL, "WM_NEXTDLGCTL" }, { WM_SPOOLERSTATUS, "WM_SPOOLERSTATUS" }, { WM_DRAWITEM, "WM_DRAWITEM" }, { WM_MEASUREITEM, "WM_MEASUREITEM" }, { WM_DELETEITEM, "WM_DELETEITEM" }, { WM_VKEYTOITEM, "WM_VKEYTOITEM" }, { WM_CHARTOITEM, "WM_CHARTOITEM" }, { WM_SETFONT, "WM_SETFONT" }, { WM_GETFONT, "WM_GETFONT" }, { WM_SETHOTKEY, "WM_SETHOTKEY" }, { WM_GETHOTKEY, "WM_GETHOTKEY" }, { WM_QUERYDRAGICON, "WM_QUERYDRAGICON" }, { WM_COMPAREITEM, "WM_COMPAREITEM" }, { WM_GETOBJECT, "WM_GETOBJECT" }, { WM_COMPACTING, "WM_COMPACTING" }, { WM_COMMNOTIFY, "WM_COMMNOTIFY" }, { WM_WINDOWPOSCHANGING, "WM_WINDOWPOSCHANGING" }, { WM_WINDOWPOSCHANGED, "WM_WINDOWPOSCHANGED" }, { WM_POWER, "WM_POWER" }, { WM_COPYDATA, "WM_COPYDATA" }, { WM_CANCELJOURNAL, "WM_CANCELJOURNAL" }, { WM_NOTIFY, "WM_NOTIFY" }, { WM_INPUTLANGCHANGEREQUEST, "WM_INPUTLANGCHANGEREQUEST" }, { WM_INPUTLANGCHANGE, "WM_INPUTLANGCHANGE" }, { WM_TCARD, "WM_TCARD" }, { WM_HELP, "WM_HELP" }, { WM_USERCHANGED, "WM_USERCHANGED" }, { WM_NOTIFYFORMAT, "WM_NOTIFYFORMAT" }, { WM_CONTEXTMENU, "WM_CONTEXTMENU" }, { WM_STYLECHANGING, "WM_STYLECHANGING" }, { WM_STYLECHANGED, "WM_STYLECHANGED" }, { WM_DISPLAYCHANGE, "WM_DISPLAYCHANGE" }, { WM_GETICON, "WM_GETICON" }, { WM_SETICON, "WM_SETICON" }, { WM_NCCREATE, "WM_NCCREATE" }, { WM_NCDESTROY, "WM_NCDESTROY" }, { WM_NCCALCSIZE, "WM_NCCALCSIZE" }, { WM_NCHITTEST, "WM_NCHITTEST" }, { WM_NCPAINT, "WM_NCPAINT" }, { WM_NCACTIVATE, "WM_NCACTIVATE" }, { WM_GETDLGCODE, "WM_GETDLGCODE" }, { WM_SYNCPAINT, "WM_SYNCPAINT" }, { WM_NCMOUSEMOVE, "WM_NCMOUSEMOVE" }, { WM_NCLBUTTONDOWN, "WM_NCLBUTTONDOWN" }, { WM_NCLBUTTONUP, "WM_NCLBUTTONUP" }, { WM_NCLBUTTONDBLCLK, "WM_NCLBUTTONDBLCLK" }, { WM_NCRBUTTONDOWN, "WM_NCRBUTTONDOWN" }, { WM_NCRBUTTONUP, "WM_NCRBUTTONUP" }, { WM_NCRBUTTONDBLCLK, "WM_NCRBUTTONDBLCLK" }, { WM_NCMBUTTONDOWN, "WM_NCMBUTTONDOWN" }, { WM_NCMBUTTONUP, "WM_NCMBUTTONUP" }, { WM_NCMBUTTONDBLCLK, "WM_NCMBUTTONDBLCLK" }, { WM_NCXBUTTONDOWN, "WM_NCXBUTTONDOWN" }, { WM_NCXBUTTONUP, "WM_NCXBUTTONUP" }, { WM_NCXBUTTONDBLCLK, "WM_NCXBUTTONDBLCLK" }, { WM_INPUT_DEVICE_CHANGE, "WM_INPUT_DEVICE_CHANGE" }, { WM_INPUT, "WM_INPUT" }, { WM_KEYDOWN, "WM_KEYDOWN" }, { WM_KEYUP, "WM_KEYUP" }, { WM_CHAR, "WM_CHAR" }, { WM_DEADCHAR, "WM_DEADCHAR" }, { WM_SYSKEYDOWN, "WM_SYSKEYDOWN" }, { WM_SYSKEYUP, "WM_SYSKEYUP" }, { WM_SYSCHAR, "WM_SYSCHAR" }, { WM_SYSDEADCHAR, "WM_SYSDEADCHAR" }, { WM_KEYLAST, "WM_KEYLAST" }, { WM_INITDIALOG, "WM_INITDIALOG" }, { WM_COMMAND, "WM_COMMAND" }, { WM_SYSCOMMAND, "WM_SYSCOMMAND" }, { WM_TIMER, "WM_TIMER" }, { WM_HSCROLL, "WM_HSCROLL" }, { WM_VSCROLL, "WM_VSCROLL" }, { WM_INITMENU, "WM_INITMENU" }, { WM_INITMENUPOPUP, "WM_INITMENUPOPUP" }, { WM_GESTURE, "WM_GESTURE" }, { WM_GESTURENOTIFY, "WM_GESTURENOTIFY" }, { WM_MENUSELECT, "WM_MENUSELECT" }, { WM_MENUCHAR, "WM_MENUCHAR" }, { WM_ENTERIDLE, "WM_ENTERIDLE" }, { WM_MENURBUTTONUP, "WM_MENURBUTTONUP" }, { WM_MENUDRAG, "WM_MENUDRAG" }, { WM_MENUGETOBJECT, "WM_MENUGETOBJECT" }, { WM_UNINITMENUPOPUP, "WM_UNINITMENUPOPUP" }, { WM_MENUCOMMAND, "WM_MENUCOMMAND" }, { WM_CHANGEUISTATE, "WM_CHANGEUISTATE" }, { WM_UPDATEUISTATE, "WM_UPDATEUISTATE" }, { WM_QUERYUISTATE, "WM_QUERYUISTATE" }, { WM_CTLCOLORMSGBOX, "WM_CTLCOLORMSGBOX" }, { WM_CTLCOLOREDIT, "WM_CTLCOLOREDIT" }, { WM_CTLCOLORLISTBOX, "WM_CTLCOLORLISTBOX" }, { WM_CTLCOLORBTN, "WM_CTLCOLORBTN" }, { WM_CTLCOLORDLG, "WM_CTLCOLORDLG" }, { WM_CTLCOLORSCROLLBAR, "WM_CTLCOLORSCROLLBAR" }, { WM_CTLCOLORSTATIC, "WM_CTLCOLORSTATIC" }, { MN_GETHMENU, "MN_GETHMENU" }, { WM_MOUSEMOVE, "WM_MOUSEMOVE" }, { WM_LBUTTONDOWN, "WM_LBUTTONDOWN" }, { WM_LBUTTONUP, "WM_LBUTTONUP" }, { WM_LBUTTONDBLCLK, "WM_LBUTTONDBLCLK" }, { WM_RBUTTONDOWN, "WM_RBUTTONDOWN" }, { WM_RBUTTONUP, "WM_RBUTTONUP" }, { WM_RBUTTONDBLCLK, "WM_RBUTTONDBLCLK" }, { WM_MBUTTONDOWN, "WM_MBUTTONDOWN" }, { WM_MBUTTONUP, "WM_MBUTTONUP" }, { WM_MBUTTONDBLCLK, "WM_MBUTTONDBLCLK" }, { WM_MOUSEWHEEL, "WM_MOUSEWHEEL" }, { WM_XBUTTONDOWN, "WM_XBUTTONDOWN" }, { WM_XBUTTONUP, "WM_XBUTTONUP" }, { WM_XBUTTONDBLCLK, "WM_XBUTTONDBLCLK" }, { WM_MOUSEHWHEEL, "WM_MOUSEHWHEEL" }, { WM_PARENTNOTIFY, "WM_PARENTNOTIFY" }, { WM_ENTERMENULOOP, "WM_ENTERMENULOOP" }, { WM_EXITMENULOOP, "WM_EXITMENULOOP" }, { WM_NEXTMENU, "WM_NEXTMENU" }, { WM_SIZING, "WM_SIZING" }, { WM_CAPTURECHANGED, "WM_CAPTURECHANGED" }, { WM_MOVING, "WM_MOVING" }, { WM_POWERBROADCAST, "WM_POWERBROADCAST" }, { WM_DEVICECHANGE, "WM_DEVICECHANGE" }, { WM_MDICREATE, "WM_MDICREATE" }, { WM_MDIDESTROY, "WM_MDIDESTROY" }, { WM_MDIACTIVATE, "WM_MDIACTIVATE" }, { WM_MDIRESTORE, "WM_MDIRESTORE" }, { WM_MDINEXT, "WM_MDINEXT" }, { WM_MDIMAXIMIZE, "WM_MDIMAXIMIZE" }, { WM_MDITILE, "WM_MDITILE" }, { WM_MDICASCADE, "WM_MDICASCADE" }, { WM_MDIICONARRANGE, "WM_MDIICONARRANGE" }, { WM_MDIGETACTIVE, "WM_MDIGETACTIVE" }, { WM_MDISETMENU, "WM_MDISETMENU" }, { WM_ENTERSIZEMOVE, "WM_ENTERSIZEMOVE" }, { WM_EXITSIZEMOVE, "WM_EXITSIZEMOVE" }, { WM_DROPFILES, "WM_DROPFILES" }, { WM_MDIREFRESHMENU, "WM_MDIREFRESHMENU" }, { WM_POINTERDEVICECHANGE, "WM_POINTERDEVICECHANGE" }, { WM_POINTERDEVICEINRANGE, "WM_POINTERDEVICEINRANGE" }, { WM_POINTERDEVICEOUTOFRANGE, "WM_POINTERDEVICEOUTOFRANGE" }, { WM_TOUCH, "WM_TOUCH" }, { WM_NCPOINTERUPDATE, "WM_NCPOINTERUPDATE" }, { WM_NCPOINTERDOWN, "WM_NCPOINTERDOWN" }, { WM_NCPOINTERUP, "WM_NCPOINTERUP" }, { WM_POINTERUPDATE, "WM_POINTERUPDATE" }, { WM_POINTERDOWN, "WM_POINTERDOWN" }, { WM_POINTERUP, "WM_POINTERUP" }, { WM_POINTERENTER, "WM_POINTERENTER" }, { WM_POINTERLEAVE, "WM_POINTERLEAVE" }, { WM_POINTERACTIVATE, "WM_POINTERACTIVATE" }, { WM_POINTERCAPTURECHANGED, "WM_POINTERCAPTURECHANGED" }, { WM_TOUCHHITTESTING, "WM_TOUCHHITTESTING" }, { WM_POINTERWHEEL, "WM_POINTERWHEEL" }, { WM_POINTERHWHEEL, "WM_POINTERHWHEEL" }, { DM_POINTERHITTEST, "DM_POINTERHITTEST" }, { WM_IME_SETCONTEXT, "WM_IME_SETCONTEXT" }, { WM_IME_NOTIFY, "WM_IME_NOTIFY" }, { WM_IME_CONTROL, "WM_IME_CONTROL" }, { WM_IME_COMPOSITIONFULL, "WM_IME_COMPOSITIONFULL" }, { WM_IME_SELECT, "WM_IME_SELECT" }, { WM_IME_CHAR, "WM_IME_CHAR" }, { WM_IME_REQUEST, "WM_IME_REQUEST" }, { WM_IME_KEYDOWN, "WM_IME_KEYDOWN" }, { WM_IME_KEYUP, "WM_IME_KEYUP" }, { WM_MOUSEENTER, "WM_MOUSEENTER" }, { WM_MOUSEHOVER, "WM_MOUSEHOVER" }, { WM_MOUSELEAVE, "WM_MOUSELEAVE" }, { WM_NCMOUSEHOVER, "WM_NCMOUSEHOVER" }, { WM_NCMOUSELEAVE, "WM_NCMOUSELEAVE" }, { WM_WTSSESSION_CHANGE, "WM_WTSSESSION_CHANGE" }, { WM_TABLET_FIRST, "WM_TABLET_FIRST" }, { WM_TABLET_LAST, "WM_TABLET_LAST" }, { WM_DPICHANGED, "WM_DPICHANGED" }, { WM_CUT, "WM_CUT" }, { WM_COPY, "WM_COPY" }, { WM_PASTE, "WM_PASTE" }, { WM_CLEAR, "WM_CLEAR" }, { WM_UNDO, "WM_UNDO" }, { WM_RENDERFORMAT, "WM_RENDERFORMAT" }, { WM_RENDERALLFORMATS, "WM_RENDERALLFORMATS" }, { WM_DESTROYCLIPBOARD, "WM_DESTROYCLIPBOARD" }, { WM_DRAWCLIPBOARD, "WM_DRAWCLIPBOARD" }, { WM_PAINTCLIPBOARD, "WM_PAINTCLIPBOARD" }, { WM_VSCROLLCLIPBOARD, "WM_VSCROLLCLIPBOARD" }, { WM_SIZECLIPBOARD, "WM_SIZECLIPBOARD" }, { WM_ASKCBFORMATNAME, "WM_ASKCBFORMATNAME" }, { WM_CHANGECBCHAIN, "WM_CHANGECBCHAIN" }, { WM_HSCROLLCLIPBOARD, "WM_HSCROLLCLIPBOARD" }, { WM_QUERYNEWPALETTE, "WM_QUERYNEWPALETTE" }, { WM_PALETTEISCHANGING, "WM_PALETTEISCHANGING" }, { WM_PALETTECHANGED, "WM_PALETTECHANGED" }, { WM_HOTKEY, "WM_HOTKEY" }, { WM_PRINT, "WM_PRINT" }, { WM_PRINTCLIENT, "WM_PRINTCLIENT" }, { WM_APPCOMMAND, "WM_APPCOMMAND" }, { WM_THEMECHANGED, "WM_THEMECHANGED" }, { WM_CLIPBOARDUPDATE, "WM_CLIPBOARDUPDATE" }, { WM_DWMCOMPOSITIONCHANGED, "WM_DWMCOMPOSITIONCHANGED" }, { WM_DWMNCRENDERINGCHANGED, "WM_DWMNCRENDERINGCHANGED" }, { WM_DWMCOLORIZATIONCOLORCHANGED, "WM_DWMCOLORIZATIONCOLORCHANGED" }, { WM_DWMWINDOWMAXIMIZEDCHANGE, "WM_DWMWINDOWMAXIMIZEDCHANGE" }, { WM_DWMSENDICONICTHUMBNAIL, "WM_DWMSENDICONICTHUMBNAIL" }, { WM_DWMSENDICONICLIVEPREVIEWBITMAP, "WM_DWMSENDICONICLIVEPREVIEWBITMAP" }, { WM_GETTITLEBARINFOEX, "WM_GETTITLEBARINFOEX" }, { WM_HANDHELDFIRST, "WM_HANDHELDFIRST" }, { WM_HANDHELDLAST, "WM_HANDHELDLAST" }, { WM_AFXFIRST, "WM_AFXFIRST" }, { WM_AFXLAST, "WM_AFXLAST" }, { WM_PENWINFIRST, "WM_PENWINFIRST" }, { WM_PENWINLAST, "WM_PENWINLAST" }, { WM_USER, "WM_USER" }, { WM_APP, "WM_APP" } };
      if (ids.ContainsKey(id))
        return ids[id];
      return System::Int32(id).ToString();
    }
  };

  class CursorApi static_ {
  public:
    static intptr Create();
    static void Destroy(intptr handle);
    static System::Drawing::Point GetPosition();
    static void Hide();
    static void SetPosition(const System::Drawing::Point& poisition);
    static void Show();
  };

  class CursorsApi static_ {
  public:
    static intptr AppStarting();
    static intptr Arrow();
    static intptr CloseHand();
    static intptr ContextualMenu();
    static intptr Cross();
    static intptr Default();
    static intptr DisappearingItem();
    static intptr DragCopy();
    static intptr DragLink();
    static intptr Hand();
    static intptr Help();
    static intptr HSplit();
    static intptr IBeam();
    static intptr No();
    static intptr NoMove2D();
    static intptr NoMoveHoriz();
    static intptr NoMoveVert();
    static intptr OpenHand();
    static intptr PanEast();
    static intptr PanNE();
    static intptr PanNorth();
    static intptr PanNW();
    static intptr PanSE();
    static intptr PanSouth();
    static intptr PanSW();
    static intptr PanWest();
    static intptr SizeAll();
    static intptr SizeNESW();
    static intptr SizeNS();
    static intptr SizeNWSE();
    static intptr SizeWE();
    static intptr UpArrow();
    static intptr VIBeam();
    static intptr VSplit();
    static intptr WaitCursor();
  };

  class FormApi static_ {
  public:
    static void Close(System::Windows::Forms::Form& form);
    static intptr Create(System::Windows::Forms::Form& form, bool withClientsize);
    static System::Drawing::Size GetDefaultSize();
  };

  class GroupBoxApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::GroupBox& groupBox);
    static System::Drawing::Size GetDefaultSize();
  };

  class LabelApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::Label& label);
    static System::Drawing::Size GetDefaultSize();
    static void SetBorderStyle(const System::Windows::Forms::Label& label);
    static void SetTextAlign(const System::Windows::Forms::Label& label);
  };

  class PanelApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::Panel& panel);
    static System::Drawing::Size GetDefaultSize();
    static void SetBorderStyle(const System::Windows::Forms::Panel& panel);
  };

  class ProgressBarApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::ProgressBar& progressBar);
    static System::Drawing::Size GetDefaultSize();
    static void SetMaximum(const System::Windows::Forms::ProgressBar& progressBar);
    static void SetMinimum(const System::Windows::Forms::ProgressBar& progressBar);
    static void SetMarquee(const System::Windows::Forms::ProgressBar& progressBar);
    static void SetValue(const System::Windows::Forms::ProgressBar& progressBar);
  };

  class RadioButtonApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::RadioButton& radioButton);
    static System::Drawing::Size GetDefaultSize();
    static void SetChecked(const System::Windows::Forms::RadioButton& radioButton);
    static void SetGroup(const System::Windows::Forms::RadioButton& radioButton);
  };

  class ScreenApi static_ {
  public:
    static System::Array<System::Windows::Forms::Screen> GetScreens();
  };

  class SystemInformationApi static_ {
  public:
    static int32 GetActiveWindowTrackingDelay();
    static System::Windows::Forms::ArrangeDirection GetArrangeDirection();
    static System::Windows::Forms::ArrangeStartingPosition GetArrangeStartingPosition();
    static System::Windows::Forms::BootMode GetBootMode();
    static System::Drawing::Size GetBorder3DSize();
    static int32 GetBorderMultiplierFactor();
    static System::Drawing::Size GetBorderSize();
    static System::Drawing::Size GetCaptionButtonSize();
    static int32 GetCaptionHeight();
    static int32 GetCaretBlinkTime();
    static int32 GetCaretWidth();
    static System::Drawing::Size GetCursorSize();
    static bool GetDbcsEnabled();
    static bool GetDebugOS();
    static System::Drawing::Size GetDoubleClickSize();
    static int32 GetDoubleClickTime();
    static bool GetDragFullWindows();
    static System::Drawing::Size GetDragSize();
    static System::Drawing::Size GetFixedFrameBorderSize();
    static int32 GetFontSmoothingContrast();
    static int32 GetFontSmoothingType();
    static System::Drawing::Size GetFrameBorderSize();
    static bool GetHighContrast();
    static int32 GetHorizontalFocusThickness();
    static int32 GetHorizontalResizeBorderThickness();
    static int32 GetHorizontalScrollBarArrowWidth();
    static int32 GetHorizontalScrollBarHeight();
    static int32 GetHorizontalScrollBarThumbWidth();
    static int32 GetIconHorizontalSpacing();
    static System::Drawing::Size GetIconSize();
    static System::Drawing::Size GetIconSpacingSize();
    static int32 GetIconVerticalSpacing();
    static bool GetIsActiveWindowTrackingEnabled();
    static bool GetIsComboBoxAnimationEnabled();
    static bool GetIsDropShadowEnabled();
    static bool GetIsFlatMenuEnabled();
    static bool GetIsFontSmoothingEnabled();
    static bool GetIsHotTrackingEnabled();
    static bool GetIsIconTitleWrappingEnabled();
    static bool GetIsKeyboardPreferred();
    static bool GetIsListBoxSmoothScrollingEnabled();
    static bool GetIsMenuAnimationEnabled();
    static bool GetIsMenuFadeEnabled();
    static bool GetIsMinimizeRestoreAnimationEnabled();
    static bool GetIsSelectionFadeEnabled();
    static bool GetIsSnapToDefaultEnabled();
    static bool GetIsTitleBarGradientEnabled();
    static bool GetIsToolTipAnimationEnabled();
    static int32 GetKanjiWindowHeight();
    static int32 GetKeyboardDelay();
    static int32 GetKeyboardSpeed();
    static System::Drawing::Size GetMaxWindowTrackSize();
    static bool GetMenuAccessKeysUnderlined();
    static System::Drawing::Size GetMenuBarButtonSize();
    static System::Drawing::Size GetMenuButtonSize();
    static System::Drawing::Size GetMenuCheckSize();
    static System::Drawing::Font GetMenuFont();
    static int32 GetMenuHeight();
  };

  class TabControlApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::TabControl& tabControl);
    static System::Drawing::Size GetDefaultSize();
    static int32 GetSelectedTabPageIndex(const System::Windows::Forms::TabControl& tabControl);
    static System::Drawing::Rectangle GetTabPageRectangle(const System::Windows::Forms::TabControl& tabControl);
    static void SetAlignment(const System::Windows::Forms::TabControl& tabControl);
    static void InsertTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage);
    static void RemoveTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage);
  };

  class TabPageApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::TabPage& tabPage);
    static void SetBorderStyle(const System::Windows::Forms::TabPage& panel);
  };

  class TimerApi static_ {
  public:
    static intptr Create(int32 interval, delegate<void> tick);
    static void Destroy(intptr handle);
  };

  class TrackBarApi static_ {
  public:
    static intptr Create(const System::Windows::Forms::TrackBar& trackBar);
    static System::Drawing::Size GetDefaultSize(System::Windows::Forms::Orientation orientation);
    static void SetLargeChange(const System::Windows::Forms::TrackBar& trackBar);
    static void SetMaximum(const System::Windows::Forms::TrackBar& trackBar);
    static void SetMinimum(const System::Windows::Forms::TrackBar& trackBar);
    static void SetOrientation(const System::Windows::Forms::TrackBar& trackBar);
    static void SetSmallChange(const System::Windows::Forms::TrackBar& trackBar);
    static void SetTickFrequency(const System::Windows::Forms::TrackBar& trackBar);
    static void SetTickStyle(const System::Windows::Forms::TrackBar& trackBar);
    static int32 GetValue(const System::Windows::Forms::TrackBar& trackBar);
    static void SetValue(const System::Windows::Forms::TrackBar& trackBar);
  };
}

