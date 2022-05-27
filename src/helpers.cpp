#include <filesystem>
#include "helpers.h"

namespace Helpers
{
    std::string parent_path(){
        auto t = std::filesystem::canonical("/proc/self/exe");
        return t.parent_path().string();
    }
} // namespace Helpers
