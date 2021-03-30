//
// Created by weixing on 14.05.20.
//

#include "SubN.h"
SubN::SubN(int x, int y, float cpu, int i) {
  m_coordinate=std::make_pair(x,y);
  m_cpu=cpu;
  m_id = i;
}
SubN::SubN(){
  m_coordinate=std::make_pair(0,0);
  m_cpu=0;
  m_id = 0;
}
int SubN::Get_Id() const {
  return m_id;
}
void SubN::printinfo() {
  std::cout<<"x: "<<m_coordinate.first<<" y: "<<m_coordinate.second<<" cpu: "<<m_cpu<<" id: "<<m_id<<std::endl;
}



void SubN::Set_Id(int i) {
  m_id = i;

}
SubN::SubN(int x, int y, float cpu) {
  m_coordinate = std::make_pair(x,y);
  m_cpu = cpu;
  m_id = 1;

}
void SubN::Set_CPU(float &cpu) {
  m_cpu = cpu;

}


