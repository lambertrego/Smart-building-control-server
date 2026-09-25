# Smart-building-control-server
Goal: Building a smart system that can be used for Supervising several virtual plants ( heating, ventilation, lighting) for one or more building.




System Design Idea:

Build a Smart building control server that supervises several virtual plants.

Simulated  field devices : temeprature, humidity, occupancy sensor, boiler, fan, lights.
A controller that keeps a virtual room at a target temperature and humidity using simulated sensors and actuators, but structured like an embedded project.


system requiements:
The system shall log all sensor values at 1‑minute intervals for at least 30 days.
The system shall raise a high‑priority alarm if room temperature < 15 °C or > 30 °C.

# Software Architecture

## Layered View
1.  **Application Layer**: `main.cpp` (System orchestrator, timing).
2.  **Domain Layer**: `Room` (Business logic, PID control).
3.  **Abstraction Layer (HAL)**: `ITemperatureSensor` (Interface for hardware).
4.  **Infrastructure**: `Logger`, `ConfigLoader`.

## Component Diagram
[Sensor Stub] --(reads)--> [HAL] --(provides data)--> [Room Controller] --(commands)--> [Heater Stub]

cmake_minimum_required(VERSION 3.25)

project(SmartBuildingGLT
    VERSION 1.0.0
    LANGUAGES CXX
)

# Enforce C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Warnings (Critical for Embedded/Automotive)
add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)

# Source Files
add_library(DomainLib
    src/domain/Room.cpp
)
target_include_directories(DomainLib PUBLIC src)

add_executable(SmartBuildingServer src/main.cpp)
target_link_libraries(SmartBuildingServer PRIVATE DomainLib)

# Setup Testing (GoogleTest)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)




Project Tree:
└── smart-building-glt
    ├── CMakelists.txt
    ├── README.md
    ├── docs
    │   ├── architecture.md
    │   ├── requirements.md
    │   └── test_plan.md
    ├── filestructure.txt
    ├── src
    │   ├── domain
    │   │   ├── main.cpp
    │   │   ├── room.cpp
    │   │   └── room.hpp
    │   └── hal
    │       └── ITemperatureSensor.hpp
    └── tests
        ├── CMakeLists.txt
        └── test_room.cpp
