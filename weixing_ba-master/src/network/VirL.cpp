//
// Created by weixing on 15.05.20.
//

#include "VirL.h"

VirL::VirL(float band, int node1, int node2) {
  m_band=band;
  m_path=std::make_pair(node1,node2);
  m_id = 0;

}
int VirL::Get_Id() const {
  return m_id;
}


void VirL::Set_Id(int i) {
  m_id = i;

}
void VirL::printinfo() {
  std::cout<<"node1: "<<m_path.first<<" node2: "<<m_path.second<<" cpu: "<<m_band<<" id: "<<m_id<<std::endl;

}
