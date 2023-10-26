cmake_minimum_required(VERSION 3.16)
project(SpacePig LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Copy media directory to the build directory
file(
    COPY media/
    DESTINATION media/
)

file(GLOB SOURCES "src/*.cpp" "src/*.hpp")

add_executable(SpacePig ${SOURCES})
target_link_libraries(SpacePig PRIVATE sfml-graphics)
target_compile_features(SpacePig PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET SpacePig
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SpacePig>
        VERBATIM)
endif()

install(TARGETS SpacePig)
