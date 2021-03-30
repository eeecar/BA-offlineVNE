//
// Created by weixing on 15.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_VIRL_H_
#define OFFLINE_SIM_SRC_NETWORK_VIRL_H_
#include "Link.h"
class VirL :public Link{
 public:
  VirL(float band,int node1,int node2);
  int Get_Id() const;
  void Set_Id(int i);
  void printinfo();
 private:
  int m_id;
};




#endif //OFFLINE_SIM_SRC_NETWORK_VIRL_H_
