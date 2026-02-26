#pragma once

#include <string>

namespace vault::models {

/// Represents a registered user's stored credentials
struct User {
    std::string username;
    std::string password_hash;
    std::string salt;
};

} // namespace vault::models
