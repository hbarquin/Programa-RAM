#include "Utils.h"

std::string utils::toUppercase (const std::string& str) {
    std::string result = "";
    for (size_t i = 0; i < str.length(); i++) {
        result += toupper(str[i]);
    }
    return result;
}
