#include "../../../../include/Switch/System/Media/SystemSound.hpp"
#include "../../../Native/Api.hpp"

using namespace System::Media;

void SystemSound::Play() const {
  Native::ApplicationApi::MessageBeep(this->type);
}
