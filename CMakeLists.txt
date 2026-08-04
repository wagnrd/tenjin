cmake_minimum_required(VERSION 4.0)
project(Tenjin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE TENJIN_SOURCES CONFIGURE_DEPENDS
     src/*.cpp src/*.c src/*.hpp src/*.h
)

add_executable(tenjin ${TENJIN_SOURCES})

target_include_directories(tenjin PRIVATE vendor/glm)

find_program(CLANG_FORMAT clang-format
    HINTS /Library/Developer/CommandLineTools/usr/bin
          /opt/homebrew/opt/llvm/bin
          /usr/local/opt/llvm/bin
)
find_program(CLANG_TIDY clang-tidy
    HINTS /opt/homebrew/opt/llvm/bin
          /usr/local/opt/llvm/bin
)

if(CLANG_FORMAT)
    add_custom_target(format
        COMMAND ${CLANG_FORMAT} --style=file -i ${TENJIN_SOURCES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting sources with clang-format"
        VERBATIM
    )
    add_custom_target(format-check
        COMMAND ${CLANG_FORMAT} --style=file --dry-run --Werror ${TENJIN_SOURCES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Checking formatting with clang-format"
        VERBATIM
    )
else()
    message(STATUS "clang-format not found - 'format' and 'format-check' targets unavailable")
endif()

if(APPLE)
    execute_process(
        COMMAND xcrun --show-sdk-path
        OUTPUT_VARIABLE APPLE_SDK_PATH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()

set(TENJIN_LINT_SOURCES)
foreach(TENJIN_SOURCE IN LISTS TENJIN_SOURCES)
    if(TENJIN_SOURCE MATCHES "\\.(cpp|c|cc|cxx)$")
        list(APPEND TENJIN_LINT_SOURCES ${TENJIN_SOURCE})
    endif()
endforeach()

if(CLANG_TIDY)
    set(CLANG_TIDY_EXTRA_ARGS)
    if(APPLE AND APPLE_SDK_PATH)
        list(APPEND CLANG_TIDY_EXTRA_ARGS --extra-arg=-isysroot${APPLE_SDK_PATH})
    endif()
    add_custom_target(lint
        COMMAND ${CLANG_TIDY} -p ${CMAKE_BINARY_DIR} --quiet
                ${CLANG_TIDY_EXTRA_ARGS}
                ${TENJIN_LINT_SOURCES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-tidy"
        VERBATIM
    )
else()
    message(STATUS "clang-tidy not found - 'lint' target unavailable (brew install llvm)")
endif()
