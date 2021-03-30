//
// Created by weixing on 05.05.20.
//

#include "Link.h"

Link::Link() {}
Link::~Link() {

}
float Link::Get_Band() {
  return m_band;
}
std::pair<int, int> Link::Get_Path() {
  return m_path;
}

//Link *Link::Creat_Link(LTYPE ltype, float band, int node1, int node2) {
  //Link* l;
  //switch(ltype){
    //case SUBSTRATEL:
      //l = new SubL(band,node1,node2);
      //break;
    //case VIRTUALL:
      //l = new VirL(band,node1,node2);
      //break;
    //default:
      //l= nullptr;
  //}
  //return l;
//}
