//
// Created by weixing on 08.06.20.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
//#include "../Network.h"
#include "../Grc_simulation.h"


BOOST_AUTO_TEST_SUITE(SIMULATION)

BOOST_AUTO_TEST_CASE(GRC_SIMULATION)
{
  Scenario1 s1;
  s1.Substrate_Builder("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
  s1.VNRs_Bilder("/home/weixing/network_files/network_files/VNRs/reqs-12-1000-nodesMin-3-nodesMax-10-grid-25", 5);

  //hiberlite::Database("home/weixing/example.db ") db;
  //hiberlite::Database db;
  std::shared_ptr<hiberlite::Database> db (new hiberlite::Database("/home/weixing/example2.db"));
  //db->open("sample.db");
  db->registerBeanClass<Grc_simulation>();
  db->dropModel();
  db->createModel();

  for(int i =0;i<5;i++){
    Grc_simulation g;
    g.run(s1.Get_SubNet(),s1.Get_VirNet(i));
     db->copyBean(g);

  }

}


BOOST_AUTO_TEST_SUITE_END()