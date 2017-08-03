cmake_minimum_required(VERSION 2.8)
 
project(WriteVTP)
 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
if (ITKVtkGlue_LOADED)
  find_package(VTK REQUIRED)
  include(${VTK_USE_FILE})
else()
  find_package(ItkVtkGlue REQUIRED)
  include(${ItkVtkGlue_USE_FILE})
  set(Glue ItkVtkGlue)
endif()
 
FIND_PATH(ANN_PATH NAMES ANN)
FIND_LIBRARY(ANN_LIB NAMES ann PATHS ${ANN_PATH})

INCLUDE_DIRECTORIES(${ANN_PATH})

add_executable(WriteVTP WriteVTP.cpp)
target_link_libraries(WriteVTP
  ${Glue}  ${VTK_LIBRARIES} ${ITK_LIBRARIES} ${ANN_LIB})





