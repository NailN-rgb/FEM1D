cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

project(FEM1D)

# Here we need to include all of the compiling .cpp files

set(FDM_SOURCES 
        ${PROJECT_SOURCE_DIR}/start/main.cpp
        ${PROJECT_SOURCE_DIR}/tools/algebra/details/matrix.cpp
        ${PROJECT_SOURCE_DIR}/tools/algebra/details/Mesh1d.cpp
        ${PROJECT_SOURCE_DIR}/tools/algebra/details/UniformMesh.cpp
        ${PROJECT_SOURCE_DIR}/init_equation/details/equation.cpp

        ${PROJECT_SOURCE_DIR}/assembling/details/assembling.cpp
        ${PROJECT_SOURCE_DIR}/assembling/details/boundary_condition.cpp
        ${PROJECT_SOURCE_DIR}/assembling/details/element.cpp
        ${PROJECT_SOURCE_DIR}/assembling/details/fe_method.cpp
        ${PROJECT_SOURCE_DIR}/assembling/details/local_power.cpp
        ${PROJECT_SOURCE_DIR}/assembling/details/local_stiffness.cpp
        )

add_executable(FEM1D ${FDM_SOURCES})
