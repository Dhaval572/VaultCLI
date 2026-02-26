add_executable(vault_client
    main.cpp
    network/api_client.cpp
    tui/app.cpp
)

target_include_directories(vault_client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(vault_client PRIVATE
    vault_common
    httplib::httplib
    ftxui::screen
    ftxui::dom
    ftxui::component
)

# Platform-specific: link ws2_32 on Windows for httplib sockets
if(WIN32)
    target_link_libraries(vault_client PRIVATE ws2_32)
endif()
