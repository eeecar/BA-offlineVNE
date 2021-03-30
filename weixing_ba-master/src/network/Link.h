//
// Created by weixing on 05.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_LINK_H_
#define OFFLINE_SIM_SRC_NETWORK_LINK_H_
#include <utility>
#include <iostream>

enum LTYPE{
  SUBSTRATEL,
  VIRTUALL
};

class Link {
 public:
  Link();
  virtual ~Link();
  float Get_Band();
  std::pair<int,int> Get_Path();

 // Link * Creat_Link(LTYPE,float band,int node1, int node2);

 protected:
  float m_band;
  std::pair<int,int> m_path;
  //int m_node1;
  //int m_node2;
 private:

};

#endif //OFFLINE_SIM_SRC_NETWORK_LINK_H_
