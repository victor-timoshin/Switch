#if defined(__linux__)

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/ColorDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/OpenFileDialog.hpp"
#include "../../include/Switch/System/Windows/Forms/SaveFileDialog.hpp"

extern Glib::RefPtr<Gtk::Application> __application__;

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

bool Native::CommonDialog::RunColorDialog(intptr hwnd, System::Windows::Forms::ColorDialog& colorDialog) {
  Gtk::Window* window = hwnd != IntPtr::Zero ? (Gtk::Window*)hwnd : __application__->get_active_window();
  Gtk::ColorChooserDialog colorChooserDialog("");
  if (window != null) colorChooserDialog.set_transient_for(*window);
  colorChooserDialog.set_modal(true);
  colorChooserDialog.set_rgba(Native::Widget::FromColor(colorDialog.Color));

  if (colorChooserDialog.run() == Gtk::RESPONSE_CANCEL) return false;
  if (colorChooserDialog.get_rgba() != Native::Widget::FromColor(colorDialog.Color)) colorDialog.Color = Native::Widget::ToColor(colorChooserDialog.get_rgba());
  return true;
}

bool Native::CommonDialog::RunOpenFileDialog(intptr hwnd, System::Windows::Forms::OpenFileDialog& openFileDialog) {
  Gtk::FileChooserDialog fileChooserDialog(openFileDialog.Title().c_str(), Gtk::FILE_CHOOSER_ACTION_OPEN);
  fileChooserDialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
  fileChooserDialog.add_button("Open", Gtk::RESPONSE_OK);
  fileChooserDialog.set_current_folder(openFileDialog.InitialDirectory().c_str());
  fileChooserDialog.set_current_name(openFileDialog.FileName().c_str());
  fileChooserDialog.set_show_hidden(openFileDialog.ShowHiddenFiles);
  int32 filterIndex = 1;
  for (System::Collections::Generic::KeyValuePair<string, Array<string>> filter : openFileDialog.__get_filters__()) {
    Glib::RefPtr<Gtk::FileFilter> fileFilter = Gtk::FileFilter::create();
    fileFilter->set_name(filter.Key().c_str());
    for (string pattern : filter.Value())
      fileFilter->add_pattern(pattern.c_str());
    fileChooserDialog.add_filter(fileFilter);
    if (filterIndex++ == openFileDialog.FilterIndex)
      fileChooserDialog.set_filter(fileFilter);
  }
  fileChooserDialog.set_modal(true);
  fileChooserDialog.set_select_multiple(openFileDialog.Multiselect);
  Gtk::Window* window = hwnd != IntPtr::Zero ? (Gtk::Window*)hwnd : __application__->get_active_window();
  if (window != null) fileChooserDialog.set_transient_for(*window);

  if (fileChooserDialog.run() == Gtk::RESPONSE_CANCEL) return false;
  if (!openFileDialog.Multiselect)
    openFileDialog.FileName = fileChooserDialog.get_filename();
  else {
    System::Collections::Generic::List<string> files;
    for (auto file : fileChooserDialog.get_filenames())
      files.Add(file);
    openFileDialog.__set__file_names__(files.ToArray());
  }
  return true;
}

bool Native::CommonDialog::RunSaveFileDialog(intptr hwnd, System::Windows::Forms::SaveFileDialog& saveFileDialog) {
  Gtk::FileChooserDialog fileChooserDialog(saveFileDialog.Title().c_str(), Gtk::FILE_CHOOSER_ACTION_SAVE);
  fileChooserDialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
  fileChooserDialog.add_button("Save", Gtk::RESPONSE_OK);
  fileChooserDialog.set_current_folder(saveFileDialog.InitialDirectory().c_str());
  fileChooserDialog.set_current_name(saveFileDialog.FileName().c_str());
  fileChooserDialog.set_show_hidden(saveFileDialog.ShowHiddenFiles);
  int32 filterIndex = 1;
  for (System::Collections::Generic::KeyValuePair<string, Array<string>> filter : saveFileDialog.__get_filters__()) {
    Glib::RefPtr<Gtk::FileFilter> fileFilter = Gtk::FileFilter::create();
    fileFilter->set_name(filter.Key().c_str());
    for (string pattern : filter.Value())
      fileFilter->add_pattern(pattern.c_str());
    fileChooserDialog.add_filter(fileFilter);
    if (filterIndex++ == saveFileDialog.FilterIndex)
      fileChooserDialog.set_filter(fileFilter);
  }
  fileChooserDialog.set_modal(true);
  Gtk::Window* window = hwnd != IntPtr::Zero ? (Gtk::Window*)hwnd : __application__->get_active_window();
  if (window != null) fileChooserDialog.set_transient_for(*window);

  if (fileChooserDialog.run() == Gtk::RESPONSE_CANCEL) return false;
  return true;
}

#endif
