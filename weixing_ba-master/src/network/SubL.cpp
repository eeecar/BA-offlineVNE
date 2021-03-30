//
// Created by weixing on 15.05.20.
//

#include "SubL.h"
SubL::SubL(float band, int node1, int node2) {
  m_band=band;
  m_path=std::make_pair(node1,node2);
  m_id = 0;

}
int SubL::Get_Id() const{
  return m_id;
}
void SubL::Set_Id(int i) {
  m_id = i;

}
void SubL::printinfo() {
  std::cout<<"node1: "<<m_path.first<<" node2: "<<m_path.second<<" cpu: "<<m_band<<" id: "<<m_id<<std::endl;

}
void SubL::Set_Band(float &band) {
  m_band = band;

}


