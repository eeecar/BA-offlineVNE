//
// Created by weixing on 05.05.20.
//

#include "Node.h"

std::pair<int,int>  Node::Get_Coor() const{

  return m_coordinate;
}
//int Node::Get_Id() const {
//  return m_id;
//}
//float Node::Get_Cpu() const {
//  return m_cpu;
//}
Node::~Node() {

}

Node::Node() {

}
float Node::Get_CPU() {
  return m_cpu;
}

//std::ostream &operator<<(std::ostream &os, const Node &node) {
 // os << "m_cpu: " << node.m_cpu << " x: " << node.m_coordinate.first <<" y: "<<node.m_coordinate.second;
  //return os;
//}
//Node * Node::Creat_Node(NTYPE ntype, int x, int y, float cpu) {
  //Node *n = nullptr;

//  switch(ntype){
  //  case SUBSTRATEN:

    //  return new SubN(x,y,cpu);
      //break;
    //case VIRTUALN:
      //VirN* m= new VirN(x,y,cpu);
      //break;
    //default:
      //Node* p = nullptr;
 // }
  //return n;
//}


