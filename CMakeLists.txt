cmake_minimum_required(VERSION 3.7)
project(MedAnalysis)

#---------------------------------------#
#------------ DEFAULT FLAGS ------------#
#---------------------------------------#

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#------------------------------------#
#------------ LIBRAIRIES ------------#
#------------------------------------#

#---- Catch Test Framework ----#

# Source files
add_library(Catch INTERFACE)

# Headers
target_include_directories(Catch INTERFACE libs/catch)


#--------------------------------------#
#------------ SUB-PROJECTS ------------#
#--------------------------------------#

#---- APPS ----#

add_subdirectory(Client)
add_subdirectory(Server)

#---- TESTS ----#

add_subdirectory(tests/Client)
add_subdirectory(tests/Server)

enable_testing()
add_test(NAME ClientTests COMMAND ClientTests WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME ServerTests COMMAND ServerTests WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})