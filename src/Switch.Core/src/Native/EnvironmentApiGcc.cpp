#if defined(__linux__) || defined(__APPLE__)

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <time.h>
#include <uuid/uuid.h>
#include <sys/time.h>

#include "Api.hpp"

namespace {
  static string CreateProcess(const string& command) {
    FILE* fs = popen(command.Data(), "r");
    string result;
    while (!feof(fs)) {
      char buf[513];
      int32 l = (int32)fread(buf, 1, 512, fs);
      buf[l] = 0;
      result += buf;
    }
    pclose(fs);
    return result;
  }
}

string Native::EnvironmentApi::NewLine() {
  return "\n";
}

System::PlatformID Native::EnvironmentApi::GetOsPlatformID() {
#if defined(__APPLE__)
  return System::PlatformID::MacOSX;
#else
  return System::PlatformID::Unix;
#endif
}

int32 Native::EnvironmentApi::GetOsVersion(int32& major, int32& minor, int32& build, int32& revision) {
#if defined(__APPLE__)
  System::Array<string> numbers = CreateProcess("_vers -productVersion").Split({'.', '\n'});
#else
  System::Array<string> numbers = CreateProcess("uname -r").Split({'.', '-', '\n'});
#endif
  if (numbers.Length() < 1 || !System::Int32::TryParse(numbers[0], major))
    major = 0;
  if (numbers.Length() < 2 || !System::Int32::TryParse(numbers[1], minor))
    minor = 0;
  if (numbers.Length() < 3 || !System::Int32::TryParse(numbers[2], build))
    build = 0;
  if (numbers.Length() < 4 || !System::Int32::TryParse(numbers[3], revision))
    revision = 0;
  return 0;
}

bool Native::EnvironmentApi::IsOs64Bit() {
  return CreateProcess("uname -m").EndsWith("64");
}

string Native::EnvironmentApi::GetMachineName() {
  return CreateProcess("uname -n");
}

int32 Native::EnvironmentApi::GetTickCount() {
  struct timeval tv;
  if(gettimeofday(&tv, null) != 0)
    return 0;
  return int32((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

string Native::EnvironmentApi::GetUserDomainName() {
  return CreateProcess("uname -n").TrimEnd('\n');
}

string Native::EnvironmentApi::GetUserName() {
  char name[512];
  strcpy(name, getenv("USER"));
  return name;
}

int64 Native::EnvironmentApi::GetWorkingSet() {
  return 0;
}

int32 Native::EnvironmentApi::SetEnv(const string& name, const string& value) {
  return setenv(name.Data, value.Data, 1);
}

int32 Native::EnvironmentApi::UnsetEnv(const string& name) {
  return unsetenv(name.Data);
}

System::Guid Native::EnvironmentApi::NewGuid() {
  byte guid[16];
  uuid_generate(guid);
  return System::Guid(guid);
}

#endif