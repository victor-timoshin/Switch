#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include <Switch/Microsoft/Win32/Registry.hpp>
#include <Switch/System/Boolean.hpp>
#include <Switch/System/Convert.hpp>
#include "../../include/Switch/System/Windows/Forms/Form.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaFormPanel : NSView
@property (strong) NSCursor* cursor;
@end

@implementation CocoaFormPanel
- (id)initWithFrame:(NSRect)bounds {
  [super initWithFrame:bounds];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}
@end

@interface CocoaForm : NSWindow
@property Native::IWidget* widget;
- (BOOL)windowShouldClose:(id)sender;
@end

@implementation CocoaForm
- (id)initWithTitle:(NSString*)title withBounds:(NSRect)bounds withStyleMask:(NSWindowStyleMask)styleMask withIWidget:(Native::IWidget*)iWidget {
  [super initWithContentRect:bounds styleMask:styleMask backing:NSBackingStoreBuffered defer:NO];
  [self setContentView:[[CocoaFormPanel alloc] initWithFrame:bounds]];
  [self setTitle:title];
  [self setWidget:iWidget];
  return self;
}

- (void)setCursor:(NSCursor*)cursor {[[self contentView] setCursor:cursor];}

- (BOOL)windowShouldClose:(id)sender {
  [self widget]->SendMessage((intptr)[self widget]->Handle(), WM_CLOSE, IntPtr::Zero, IntPtr::Zero);
  return NO;
}
@end

namespace Native {
  class Form : public Widget<CocoaForm> {
  public:
    Form(const string text, const System::Drawing::Rectangle& formBounds, FormStartPosition startPosition, FormBorderStyle formBorderStyle, bool maximizeBox, bool minimizeBox) {
      static Microsoft::Win32::RegistryKey key = Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Gammasoft71").CreateSubKey("Switch").CreateSubKey("Forms");
      static int32 location = as<Int32>(key.GetValue("DefaultLocation", 20));
      // Strangely, on Windows the first location is used 2 times; this boolean simumate it.
      static bool nextLocation = Convert::ToBoolean(as<Int32>(key.GetValue("NextLocation", 1)));

      this->bounds = formBounds;
      switch (startPosition) {
        case FormStartPosition::CenterScreen: this->bounds = System::Drawing::Rectangle((Screen::AllScreens()[0].WorkingArea().Width + Screen::AllScreens()[0].WorkingArea().X - formBounds.Width) / 2, (Screen::AllScreens()[0].WorkingArea().Height + Screen::AllScreens()[0].WorkingArea().Y - formBounds.Height) / 2, formBounds.Width, formBounds.Height); break;
        case FormStartPosition::Manual: this->bounds = formBounds; break;
        case FormStartPosition::WindowsDefaultBounds: this->bounds = System::Drawing::Rectangle(location, location, Screen::AllScreens()[0].WorkingArea().Width / 4 * 3, Screen::AllScreens()[0].WorkingArea().Height / 4 * 3); break;
        case FormStartPosition::CenterParent:
        case FormStartPosition::WindowsDefaultLocation: this->bounds = System::Drawing::Rectangle(location, location, formBounds.Width, formBounds.Height); break;
        default: break;
      }
      
      if (startPosition == FormStartPosition::WindowsDefaultBounds || startPosition == FormStartPosition::CenterParent || startPosition == FormStartPosition::WindowsDefaultLocation) {
        nextLocation = !(nextLocation == true && location == 20);
        if (nextLocation)
          location = location < 180 ? location + 20 : 20;
        key.SetValue("DefaultLocation", as<int32>(location), Microsoft::Win32::RegistryValueKind::DWord);
        key.SetValue("NextLocation", nextLocation, Microsoft::Win32::RegistryValueKind::DWord);
      }
      
      this->handle = [[CocoaForm alloc] initWithTitle:[NSString stringWithUTF8String:text.c_str()] withBounds:NSMakeRect(this->bounds.X, this->bounds.Y, this->bounds.Width, this->bounds.Height) withStyleMask:ToNSWindowStyleMask(formBorderStyle, maximizeBox, minimizeBox) withIWidget:this];
    }
    
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle contentLayoutRect].size.width, [this->handle contentLayoutRect].size.height);}
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setContentSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {}
    void Font(const System::Drawing::Font& font) override {}
    void ForeColor(const System::Drawing::Color& color) override {}
    void IsDefault(bool isDefault) {}
    System::Drawing::Point Location() const {return this->bounds.Location;}
    void Location(IWidget* parent, const System::Drawing::Point& location) override {[this->handle setFrameOrigin:NSMakePoint(location.X + ScreenOffset().Width, location.Y + ScreenOffset().Height)];}
    Native::LocationOffset LocationOffset() const override {return Native::LocationOffset::Form;}
    void RemoveParent() override {}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {[this->handle setFrame:NSMakeRect(0, 0, size.Width, size.Height) display:YES];}
    void Text(const string& text) override {[this->handle setTitle:[NSString stringWithUTF8String:text.c_str()]];}
    NSView* View() override {return [this->handle contentView];}
    void Visible(bool visible) override {[this->handle setIsVisible:visible ? YES : FALSE];}
    
    protected:
    System::Drawing::Size ScreenOffset() {
      return System::Drawing::Size(Screen::AllScreens()[0].WorkingArea().X, Screen::AllScreens()[0].Bounds().Height - Screen::AllScreens()[0].WorkingArea().Y - this->bounds.Height - (this->bounds.Y * 2) - Native::SystemInformationApi::GetCaptionHeight());
    }
    
    static NSWindowStyleMask ToNSWindowStyleMask(FormBorderStyle formBorderStyle, bool maximizeBox, bool minimizeBox) {
      constexpr int CP_NOCLOSE_BUTTON = 0x200;
      NSWindowStyleMask windowStyleMask = NSWindowStyleMaskBorderless;
      
      if (formBorderStyle != FormBorderStyle::None) {
        windowStyleMask |= NSWindowStyleMaskTitled;
        
        if (maximizeBox && (formBorderStyle == FormBorderStyle::Sizable || formBorderStyle == FormBorderStyle::SizableToolWindow))
          windowStyleMask |= NSWindowStyleMaskResizable;
        
        if (minimizeBox)
          windowStyleMask |= NSWindowStyleMaskMiniaturizable;
        
        if (CP_NOCLOSE_BUTTON /*(form.GetCreateParams().ClassStyle | CP_NOCLOSE_BUTTON) == CP_NOCLOSE_BUTTON*/)
          windowStyleMask |= NSWindowStyleMaskClosable;
      }
      
      return windowStyleMask;
    }
    
    System::Drawing::Rectangle bounds;
  };
}

void Native::FormApi::Close(System::Windows::Forms::Form& form) {
  ((IWidget*)form.Handle())->SendMessage((intptr)((IWidget*)form.Handle())->Handle(), WM_CLOSE, IntPtr::Zero, IntPtr::Zero);
}

intptr Native::FormApi::Create(System::Windows::Forms::Form& form) {
  Native::Form* widget = new Native::Form(form.Text, form.Bounds, form.StartPosition, form.FormBorderStyle, form.MaximizeBox, form.MinimizeBox);
  form.Location = widget->Location();
  form.Size= widget->Size();
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = form;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

#endif

