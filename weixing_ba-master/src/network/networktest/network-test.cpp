//
// Created by weixing on 05.05.20.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
//#include "../Network.h"
#include "../Scenario_Builder.h"

BOOST_AUTO_TEST_SUITE(NETWORK)

  BOOST_AUTO_TEST_CASE(NETWORK)
  {
    //SubNet s1;
    //s1.Read_Net("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
    //s1.Set_Nodemap(3,10,10,5.5);
    //s1.Set_Linkmap(1,1,1,1);
    //s1.printinfo();
    //SubN n(1,2,3);
    //n.printinfo();
    VirNet v;
    v.Read_Net("/home/weixing/network_files/network_files/VNRs/reqs-12-1000-nodesMin-3-nodesMax-10-grid-25/req0.txt");
    v.printinfo();

  }

  BOOST_AUTO_TEST_CASE(SCENARIO)
  {
    Scenario1 s1;
    s1.Substrate_Builder("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
    s1.VNRs_Bilder("/home/weixing/network_files/network_files/VNRs/reqs-12-1000-nodesMin-3-nodesMax-10-grid-25", 3);
    //s1.printinfo();
    std::shared_ptr<std::vector<std::shared_ptr<SubL>>>  L = s1.Get_SubNet()->Get_Links_For_Node(1);

  }

BOOST_AUTO_TEST_SUITE_END()