
cmake_minimum_required(VERSION 2.8)
 
PROJECT(DistancePolyDataFilter)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(DistancePolyDataFilter MACOSX_BUNDLE DistancePolyDataFilter.cxx )
 
target_link_libraries(DistancePolyDataFilter ${VTK_LIBRARIES})
