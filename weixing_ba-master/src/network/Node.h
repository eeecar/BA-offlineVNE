//
// Created by weixing on 05.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_NODE_H_
#define OFFLINE_SIM_SRC_NETWORK_NODE_H_


#include <utility>

#include <iostream>
enum NTYPE{
  SUBSTRATEN,
  VIRTUALN
};

class Node {
 public:
  Node();
  virtual ~Node();
  //float Get_Cpu() const;
  std::pair<int,int>  Get_Coor() const;
  virtual void printinfo() = 0;
  float Get_CPU();
  //friend std::ostream &operator<<(std::ostream &os, const Node &node);
  //int Get_Id() const;


  //Node * Creat_Node(NTYPE, float x, float y, float cpu);
  //Node * Creat_Node(NTYPE, int x, int y, float cpu);


 private:


  //int m_id;


 protected:
  float m_cpu;
  std::pair<int,int> m_coordinate;

};









#endif //OFFLINE_SIM_SRC_NETWORK_NODE_H_
