cmake_minimum_required(VERSION 3.9)
project(Andromeda)

set(CMAKE_CXX_STANDARD 11)
find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})


add_executable(Andromeda main.cpp Model.cpp Model.h Controller.cpp Controller.h Subject.cpp Subject.h Observer.cpp Observer.h View.cpp View.h Image.cpp Image.h Preview.cpp Preview.h)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})