//
// Created by weixing on 14.05.20.
//

#include "VirN.h"

VirN::VirN(int x, int y, float cpu)
{
  m_coordinate=std::make_pair(x,y);
  m_cpu=cpu;
  m_id = 0;
}
int VirN::Get_Id() const {
  return m_id;
}


void VirN::Set_Id(int i) {
  m_id = i;

}
void VirN::printinfo() {
  std::cout<<"x: "<<m_coordinate.first<<" y: "<<m_coordinate.second<<" cpu: "<<m_cpu<<" id: "<<m_id<<std::endl;

}
