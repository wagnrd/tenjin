if(NOT TOOL)
    message(FATAL_ERROR
        "required tool '${TOOL_NAME}' not found - install LLVM tooling "
        "(e.g. 'brew install llvm') and re-run cmake to continue")
endif()
