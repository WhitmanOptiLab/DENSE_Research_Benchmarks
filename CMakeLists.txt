#Would prefer to make this 3.1, as it makes C++ dialect selection automatic.
cmake_minimum_required (VERSION 3.9)



if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release
RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

set(DENSE_PATH "${CMAKE_SOURCE_DIR}/DENSE1" CACHE FILEPATH "Path to the DENSE project")

if (NOT EXISTS ${DENSE_PATH}/CMakeLists.txt)
  message( FATAL_ERROR "Cannot find DENSE directory: make sure the git
  submodule was checked out or set the variable DENSE_PATH" )
endif (NOT EXISTS ${DENSE_PATH}/CMakeLists.txt)

project (StochSimMethods CXX C)

#add the DENSE library functions for building simulations
add_subdirectory(${DENSE_PATH} DENSE EXCLUDE_FROM_ALL)

#declare a few simulations to build for different models

#declare the custom functions to build the experiments using DENSE
function(MAKE_EXPERIMENTS localname simdir)
  SIMULATION(${localname} ${simdir} ${simdir}/main.cpp)
endfunction(MAKE_EXPERIMENTS localname simdir)

MAKE_EXPERIMENTS(scale_experiment ${CMAKE_SOURCE_DIR}/Scale_Experiment)

MAKE_EXPERIMENTS(density_experiment ${CMAKE_SOURCE_DIR}/Density_Experiment)

MAKE_EXPERIMENTS(overhead_experiment ${CMAKE_SOURCE_DIR}/Overhead_Experiment)

MAKE_EXPERIMENTS(skew_experiment ${CMAKE_SOURCE_DIR}/Skew_Experiment)

MAKE_EXPERIMENTS(exponential_experiment ${CMAKE_SOURCE_DIR}/Exponential_Experiment)

MAKE_EXPERIMENTS(oscillating_experiment ${CMAKE_SOURCE_DIR}/Oscillating_Experiment)

add_executable(run_experiment run_experiments.cpp)
