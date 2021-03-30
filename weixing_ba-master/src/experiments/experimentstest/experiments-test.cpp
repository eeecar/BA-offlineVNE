//
// Created by weixing on 24.05.20.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
#include "../Grcnodealgo.h"
#include "../../network/Scenario_Builder.h"
#include "../Grclinkalgo.h"
//#include "../Scenario_Builder.h"

BOOST_AUTO_TEST_SUITE(Algo)

BOOST_AUTO_TEST_CASE(GRCPLAIN)
{
  //SubNet s1;
  //s1.Read_Net("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
  //s1.Set_Nodemap(3,10,10,5.5);
  //s1.Set_Linkmap(1,1,1,1);
  //s1.printinfo();
  //SubN n(1,2,3);
  //n.printinfo();
  //VirNet v;
  //v.Read_Net("/home/weixing/network_files/network_files/VNRs/reqs-12-1000-nodesMin-3-nodesMax-10-grid-25/req0.txt");
  //v.printinfo();
  Scenario1 s1;
  s1.Substrate_Builder("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
  s1.VNRs_Bilder("/home/weixing/network_files/network_files/VNRs/reqs-12-1000-nodesMin-3-nodesMax-10-grid-25", 70);
  //s1.printinfo();
  Scenario1 s2;
  s2.Substrate_Builder("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
  s2.VNRs_Bilder(s1.Get_VNRs());
  GrcNodeAlgo g;
  g.Resource_Sort_VNRs(s1.m_scenario1.second);


  for(int i =0;i<70;i++){
    GrcNodeAlgo n(0.001,0.2);
    Grclinkalgo l;
    if(n.embeddVNRNodes(s1.Get_SubNet(),s1.Get_VirNet(i))){
      std::cout<<"successful node embedding"<<"--+--";
      if(l.embeddVNRLinkss(s1.Get_SubNet(),s1.Get_VirNet(i),s1.Get_VirNet(i)->Get_Nodeembedmap())){
        s1.Sub_Update(i);
        std::cout<<"successful embedding"<<std::endl;
      }
      else std::cout<<"embedding failed because of link"<<std::endl;
      //s1.Get_VirNet(i)->printnodeembedmap();
      //s1.Sub_Update(i);
      //s1.Get_SubNet()->printinfo();
      //std::cout<<"successful node embedding"<<std::endl;
    }
    else std::cout<<"embedding failed because of node"<<std::endl;

  }
  std::cout<<"--------------------------second round---------------------------------"<<std::endl;
  for(int i =0;i<70;i++){
    GrcNodeAlgo n;
    Grclinkalgo l;
    if(n.embeddVNRNodes(s1.Get_SubNet(),s1.Get_VirNet(i))){
      std::cout<<"successful node embedding"<<"--+--";
      if(l.embeddVNRLinkss(s1.Get_SubNet(),s1.Get_VirNet(i),s1.Get_VirNet(i)->Get_Nodeembedmap())){
        s1.Sub_Update(i);
        std::cout<<"successful embedding"<<std::endl;
      }
      else std::cout<<"embedding failed because of link"<<std::endl;
      //s1.Get_VirNet(i)->printnodeembedmap();
      //s1.Sub_Update(i);
      //s1.Get_SubNet()->printinfo();
      //std::cout<<"successful node embedding"<<std::endl;
    }
    else std::cout<<"embedding failed because of node"<<std::endl;

  }

}

BOOST_AUTO_TEST_CASE(GRCSMART)
{
  //Scenario1 s1;
  //s1.Substrate_Builder("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
  //s1.VNRs_Bilder("/home/weixing/network_files/network_files/VNRs/reqs-12-1000-nodesMin-3-nodesMax-10-grid-25", 3);
  //s1.printinfo();
  Scenario1 s1;

  s1.Substrate_Builder("/home/weixing/network_files/network_files/SN/vy_substrate_net_n_50_outergrid_25_inner_grid_25.txt");
  s1.VNRs_Bilder("/home/weixing/network_files/network_files/VNRs/reqs-12-1000-nodesMin-3-nodesMax-10-grid-25", 3);
  s1.printinfo();
  GrcNodeAlgo g;
  g.Resource_Sort_VNRs(s1.m_scenario1.second);
  s1.printinfo();

  //s1.printinfo();

}

BOOST_AUTO_TEST_SUITE_END()