#include "tui/app.h"
#include "network/api_client.h"

#include <iostream>
#include <string>
#include <memory>

int main(int argc, char* argv[]) {
    // ── Parse command line arguments ────────────────────────────────────
    std::string host = "localhost";
    int port = 8080;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "--host" || arg == "-H") && i + 1 < argc) {
            host = argv[++i];
        } else if ((arg == "--port" || arg == "-p") && i + 1 < argc) {
            port = std::stoi(argv[++i]);
        } else if (arg == "--help") {
            std::cout << "Usage: vault_client [options]\n"
                      << "  --host, -H <host>  Server host (default: localhost)\n"
                      << "  --port, -p <port>  Server port (default: 8080)\n"
                      << "  --help             Show this help\n";
            return 0;
        }
    }

    // ── Create API client and launch TUI ────────────────────────────────
    auto api = std::make_shared<vault::client::ApiClient>(host, port);
    vault::client::App app(api);

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
