add_subdirectory(networktest)

add_library(networklib SHARED
        Network.cpp
        Node.cpp
        SubN.cpp
        Link.cpp
        Network_Builder.cpp
        Scenario_Builder.cpp
        SubL.cpp
        VirL.cpp
        VirN.cpp)

target_link_libraries(networklib ${Boost_LIBRARIES})