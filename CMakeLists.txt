cmake_minimum_required(VERSION 3.19)

project(hello)

set(VERSION 1.2.3)
set(SOVERSION 102)

include (GNUInstallDirs)

option(BUILD_SHARED_LIBS "Build SHARED library" ON)

add_library(hello hello.cxx)

target_sources(hello
  PUBLIC FILE_SET HEADERS TYPE HEADERS
  FILES hello.h
)

set_target_properties(hello PROPERTIES
  VERSION ${VERSION}
  SOVERSION ${SOVERSION}
)

target_compile_definitions(hello PRIVATE LUAAPI_EXPORTS)

install(TARGETS hello
  LIBRARY
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
  ARCHIVE
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME
    DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

add_library(hello_wrap hello_wrap.cxx)

target_sources(hello_wrap
  PUBLIC FILE_SET HEADERS TYPE HEADERS
  FILES hello_wrap.h
)

set_target_properties(hello_wrap PROPERTIES
  VERSION ${VERSION}
  SOVERSION ${SOVERSION}
)

target_compile_definitions(hello_wrap PRIVATE LUAAPI_EXPORTS)

target_link_libraries(hello_wrap PRIVATE hello)

install(TARGETS hello_wrap
  LIBRARY
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
  ARCHIVE
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME
    DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)
