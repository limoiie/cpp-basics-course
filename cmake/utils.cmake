macro(add_subprojects _base_dir _test_dir)
    # Find all CMakeLists.txt paths
    file(GLOB_RECURSE _cmake_files RELATIVE "${_base_dir}" CMakeLists.txt)
    # Collect all subdirectories containing CMakeLists.txt
    set(_dirs)
    foreach (file_path ${_cmake_files})
        get_filename_component(_dir_path ${file_path} PATH)
        list(APPEND _dirs ${_dir_path})
    endforeach ()

    unset(_cmake_files)
    unset(_dir_path)

    # Add all found directories
    foreach (dir ${_dirs})
        # Ignore CMakeList.txt files from "googletest/*" dirs
        string(FIND "${dir}" ${_test_dir} _out)
        if ("${_out}" EQUAL -1)
            add_subdirectory(${dir})
        endif ()
    endforeach ()
endmacro()

macro(configure_test_target _target_name _src_files _test_files)
    set(__src_files ${_src_files})
    set(__test_files ${_test_files})

    if (DEFINED ${_src_files})
        set(__src_files ${${_src_files}})
    endif ()

    if (DEFINED ${_test_files})
        set(__test_files ${${_test_files}})
    endif ()

    message("${_target_name} __src is ${__src_files}")
    message("${_target_name} __test is ${__test_files}")

    if (__src_files)
        set(_src_part_lib ${_target_name}-src-part)

        # Create utility library to separate src files from test files
        add_library(${_src_part_lib} STATIC ${__src_files})

        # Rename learners main function to prevent overloading or name conflicts
        # It will rename symbols only in files from `__src_files` set
        string(SHA1 _hash _target_name)
        target_compile_definitions(${_src_part_lib} PRIVATE main=main${_hash})
        unset(_hash)
    endif ()

    # Create test executable target
    add_executable(${_target_name} ${__test_files})

    if (__src_files)
        # Add files from `__src_files` set to target
        target_link_libraries(${_target_name} ${_src_part_lib})
    endif ()

    # Add Google Test libraries to target
    target_link_libraries(${_target_name} gtest gtest_main)

    unset(_test_source)
endmacro()