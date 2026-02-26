#pragma once

#include "auth/auth_manager.h"
#include "storage/storage_manager.h"

#include <httplib.h>

namespace vault::server {

/// Register all HTTP API routes on the server
void setup_routes(httplib::Server& server,
                  AuthManager& auth,
                  StorageManager& storage);

} // namespace vault::server
