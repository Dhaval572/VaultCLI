#pragma once

#include "network/api_client.h"

#include <string>
#include <memory>

namespace vault::client {

/// Main TUI application using FTXUI
class App {
public:
    explicit App(std::shared_ptr<ApiClient> api);

    /// Run the TUI application (blocks until exit)
    void run();

private:
    std::shared_ptr<ApiClient> api_;
};

} // namespace vault::client
