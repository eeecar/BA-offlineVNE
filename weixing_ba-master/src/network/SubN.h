//
// Created by weixing on 14.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_SUBN_H_
#define OFFLINE_SIM_SRC_NETWORK_SUBN_H_

#include <iostream>
#include "Node.h"

class SubN : public Node {
 public:
  SubN(int x, int y, float cpu, int i);
  SubN();
  SubN(int x, int y, float cpu);
  void printinfo();

  int Get_Id() const;
  void Set_Id(int i);
  void Set_CPU(float &cpu);


 private:
  int m_id;


};


#endif //OFFLINE_SIM_SRC_NETWORK_SUBN_H_
