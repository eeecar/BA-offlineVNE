//
// Created by weixing on 14.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_VIRN_H_
#define OFFLINE_SIM_SRC_NETWORK_VIRN_H_

#include "Node.h"

class VirN :public Node {
 public:
  VirN(int x, int y, float cpu);
  //virtual ~VirN();
  int Get_Id() const;
  //void Set_Id(){m_id+=m_id;}
  void Set_Id(int i);
  void printinfo();
 private:
  int m_id;

};

#endif //OFFLINE_SIM_SRC_NETWORK_VIRN_H_
