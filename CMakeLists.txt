cmake_minimum_required(VERSION 3.24)

project(seb LANGUAGES CXX VERSION 1.0)

    find_path(EFI_HEADER
        NAMES "efi.h"
        PATHS /usr/include/efi
    )

    add_executable(seb.efi
        src/main.cpp
        src/efi-cpp/console.cpp
    )

    target_compile_features(seb.efi
        PUBLIC
            cxx_std_20
    )
    
    target_include_directories(seb.efi
        PUBLIC
            ${EFI_HEADER}
            src
    )

    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

        target_compile_options(seb.efi
            PUBLIC
                -target x86_64-unknown-windows
                -ffreestanding
                -fshort-wchar
                -fno-exceptions
                -mno-red-zone
                -Wall
                -Wwritable-strings
        )

        target_link_options(seb.efi
            PUBLIC
                -target x86_64-unknown-windows
                -nostdlib
                -Wl,-entry:efi_main
                -Wl,-subsystem:efi_application
                -fuse-ld=lld-link
        )

    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(FATAL_ERROR "GNU compiler isn't supported yet.")
    else()
        message(FATAL_ERROR "${CMAKE_CXX_COMPILER_ID} compiler isn't supported.")
    endif()

    find_file(OVMF_FILE
        NAMES "OVMF.fd"
        PATHS /usr/share/OVMF/x64 /usr/share/OVMF/x64
    )

    add_custom_target(machine
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/machine/bios/"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/machine/esp/"
        COMMAND ${CMAKE_COMMAND} -E copy "${OVMF_FILE}" "${CMAKE_BINARY_DIR}/machine/bios/"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_BINARY_DIR}/seb.efi" "${CMAKE_BINARY_DIR}/machine/esp/"
    )

    add_dependencies(machine seb.efi)
