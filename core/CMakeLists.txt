# Core CMakeLists file
# should be in /core/CMakeLists.txt

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# tell CMake to find the Qt libraries
find_package(Qt6 REQUIRED COMPONENTS Core)

# define the library and enable the "Meta-Object Compiler" (MOC)
# MOC is what handles the Q_OBJECT macro and signals
qt_add_library(core STATIC
    types.h
    definitions.h
    character.h character.cpp
    engine.h engine.cpp
    itemregistry.h itemregistry.cpp

)
set_target_properties(core PROPERTIES AUTOMOC ON)

target_sources(core PRIVATE

)

# link the Core library to Qt's Core module
target_link_libraries(core PRIVATE Qt6::Core)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
