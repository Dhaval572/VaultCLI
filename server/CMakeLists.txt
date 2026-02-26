add_executable(vault_server
    main.cpp
    auth/auth_manager.cpp
    storage/storage_manager.cpp
    routes/routes.cpp
)

target_include_directories(vault_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(vault_server PRIVATE vault_common httplib::httplib)

# Platform-specific: link ws2_32 on Windows for httplib sockets
if(WIN32)
    target_link_libraries(vault_server PRIVATE ws2_32)
endif()
