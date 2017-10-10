#if defined(__linux__) || defined(__APPLE__)

#include <cstdlib>

#include "CoreApi.hpp"

string Native::CoreApi::Registry::GetDefaultString() {
  return "Default";
}

int32 Native::CoreApi::Registry::CloseKey(intptr key) {
  return 0;
}

int32 Native::CoreApi::Registry::DeleteValue(intptr key, const string& subkeyName) {
  return 0;
}

int32 Native::CoreApi::Registry::SetValue(intptr key, const string& keyName, Microsoft::Win32::RegistryValueKind type, const byte* data, int32 length) {
  return 0;
}

int32 Native::CoreApi::Registry::Flush(intptr key) {
  return 0;
}

int32 Native::CoreApi::Registry::DeleteTree(intptr key, const string& subkeyName) {
  return 0;
}

int32 Native::CoreApi::Registry::OpenSubKey(intptr rootKey, const string& subKey, intptr& key) {
  return 0;
}

int32 Native::CoreApi::Registry::CreateSubKey(intptr rootKey, const string& subKey, intptr& key) {
  return 0;
}

int32  Native::CoreApi::Registry::EnumKey(intptr key, int32 index, string& subkeyname) {
  return 0;
}

int32 Native::CoreApi::Registry::QueryInfoKey(intptr key,int32& subKey ,int32& value) {
  return 0;
}

int32  Native::CoreApi::Registry::DeleteSubKey(intptr Key,const string& subkeyName) {
  return 0;
}

int32 Native::CoreApi::Registry::GetValue(intptr key, const string& subKey, Microsoft::Win32::RegistryValueKind& type, System::Array<byte>& data) {
  return 0;
}

int32  Native::CoreApi::Registry::GetHandleBaseKey (Microsoft::Win32::RegistryHive reghive, intptr& key) {
  return 0;
}

#endif