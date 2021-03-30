cmake_minimum_required(VERSION 3.15)
project(offline_sim)

set(CMAKE_CXX_STANDARD 14)


add_executable(offline_sim main.cpp src/core/node.cpp src/core/node.h src/network/Node.cpp src/network/Node.h src/network/Link.cpp src/network/Link.h src/network/Network.cpp src/network/Network.h src/network/Network_Builder.cpp src/network/Network_Builder.h src/network/Scenario_Builder.cpp src/network/Scenario_Builder.h src/network/Scenario.h src/network/SubN.cpp src/network/SubN.h src/network/VirN.cpp src/network/VirN.h src/network/SubL.cpp src/network/SubL.h src/network/VirL.cpp src/network/VirL.h src/experiments/Grcnodealgo.cpp src/experiments/Grcnodealgo.h src/experiments/Grclinkalgo.h src/simulation/Grc_simulation.cpp src/simulation/Grc_simulation.h src/simulation/simulationtest/Grc_simulation_test.cpp)

target_link_libraries(offline_sim hiberlite)

add_subdirectory(src)


