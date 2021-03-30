# see https://cmake.org/cmake/help/latest/module/FindBoost.html

set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking


find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
add_executable(simulation_boost Grc_simulation_test.cpp)

#target_link_libraries(network_boost ${Boost_LIBRARIES})
target_link_libraries(simulation_boost networklib embedalgo simulation ${Boost_LIBRARIES})