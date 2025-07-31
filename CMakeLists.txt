cmake_minimum_required(VERSION 3.10)

project(wxwidgets_opengl_app)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED COMPONENTS core base gl)

include(${wxWidgets_USE_FILE})

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

set(SOURCES
    src/main.cpp
    src/App.cpp
    src/MainFrame.cpp
    src/GLCanvas.cpp
    src/panels/SidePanel.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${OPENGL_LIBRARIES})