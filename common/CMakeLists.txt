add_library(vault_common STATIC
    crypto/crypto.cpp
    utils/utils.cpp
)

target_include_directories(vault_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(vault_common PUBLIC OpenSSL::SSL OpenSSL::Crypto nlohmann_json::nlohmann_json)
