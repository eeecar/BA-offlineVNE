//
// Created by weixing on 07.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_NETWORK_H_
#define OFFLINE_SIM_SRC_NETWORK_NETWORK_H_

#include "Node.h"
#include "Link.h"
#include "SubL.h"
#include "SubN.h"
#include "VirN.h"
#include "VirL.h"

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <map>
#include <memory>
class Network {
 private:
  //template<typename Node>
  //std::vector<Node>  m_nodemap;

  //std::vector<Link> m_linkmap;



 public:
  Network();
  ~Network();

  //int num: number of nodes in a network.
  //int sizex:grid length
  //int sizey:grid width
  //float cpu range
  virtual void Set_Nodemap(const int& num,const int& sizex,const int& sizey,const float& cpurng) = 0;

  //float alpha:
  //float beta:
  //float L
  //float bandwidth range
  virtual void Set_Linkmap(const float& alpha,const float& beta, const float& L, const float& bandrng) = 0;
  virtual void Set_Linkmap(std::vector<Node> m_nodemap) = 0;
  virtual void Read_Net(std::string filepath) = 0;
  void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);

};


class SubNet :public Network{
 private:

  std::vector<std::shared_ptr<SubN>> m_nodemap;
  std::vector<std::shared_ptr<SubL>> m_linkmap;
 public:
  SubNet();
  virtual ~SubNet();
  void Set_Nodemap(const int &num, const int &sizex, const int &sizey, const float &cpurng) override;
  void Set_Linkmap(const float &alpha, const float &beta, const float &L, const float &bandrng) override;
  void printinfo();
  void Set_Linkmap(std::vector<Node> m_nodemap) override;
  void Read_Net(std::string filepath) override;
  std::vector<std::shared_ptr<SubN>> Get_Nodemap() const;
  std::vector<std::shared_ptr<SubL>> GetLinkmap() const;
  std::shared_ptr<SubN> Get_Node(int i);
  std::shared_ptr<SubL> Get_Link(int a, int b) ;
  std::shared_ptr<SubL> Get_Link(int id);
  std::shared_ptr<std::vector<std::shared_ptr<SubL>>> Get_Links_For_Node(int i);
  bool Find_Link(int a,int b) const;
  float Get_Ad_Band(int a) const;


};

class VirNet : public Network{
 private:
  std::vector<VirN> m_nodemap;
  std::vector<VirL> m_linkmap;
  int m_vnrid;
  std::map<int,int> m_nodeembedmap;
  std::map<int,std::list<int>> m_linkembedmap;
 public:
  VirNet();
  virtual ~VirNet();
  void Set_Nodemap(const int &num, const int &sizex, const int &sizey, const float &cpurng) override;
  void Set_Linkmap(const float &alpha, const float &beta, const float &L, const float &bandrng) override;
  void Set_Linkmap(std::vector<Node> m_nodemap) override;
  void Read_Net(std::string filepath) override;
  void Set_VNR_Id(int i);
  int Get_VNR_Id();
  void printinfo();
  std::vector<VirN> Get_Nodemap() const;
  std::map<int,int> Get_Nodeembedmap() ;
  std::vector<VirL> GetLinkmap() const;
  std::map<int,std::list<int>> Get_Linkembedmap() const;
  VirN Get_Node(int i) const;
  VirL Get_Link(int a, int b) const;
  VirL Get_Link(int id) const;
  bool Find_Link(int a,int b) const;
  float Get_Ad_Band(int a) const;
  void Add_Nodemap(int vnode, int snode);
  int Get_Nodeembedsize();
  void Add_Linkmap(int vlink, std::list<int> slinks);
  std::map<int,std::list<int>> Get_Linkembedmap();
  int Get_Linkembedsize();

  void printnodeembedmap(){
    if(m_nodeembedmap.size()==0) std::cout<<"nodeembedmap size is 0!"<<std::endl;
    for(auto it :m_nodeembedmap){
      std::cout<<"vnode: "<<it.first<<" snode: "<<it.second<<std::endl;
    }
  }

};

#endif //OFFLINE_SIM_SRC_NETWORK_NETWORK_H_
