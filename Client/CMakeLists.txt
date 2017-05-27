cmake_minimum_required(VERSION 3.7)

#----------------------------------------#
#------------ CLIENT LIBRARY ------------#
#----------------------------------------#

set(TARGET_NAME Client)

#---- Source files ----#

file(GLOB_RECURSE SOURCE_FILES "*.cpp")


#---- Headers ----#

get_filename_component(HDR_DIR "./" REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(HDR_CLIENT ${HDR_DIR} CACHE INTERNAL "")


#---- Target ----#

add_library(${TARGET_NAME} ${SOURCE_FILES})
target_include_directories(${TARGET_NAME} PUBLIC ${HDR_SQLITE})