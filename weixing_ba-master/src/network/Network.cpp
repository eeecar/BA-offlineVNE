//
// Created by weixing on 07.05.20.
//


#include "Network.h"
Network::Network() {}
Network::~Network() {

}
void Network::SplitString(const std::string &s, std::vector<std::string> &v, const std::string &c) {
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));

}

SubNet::SubNet() {}
SubNet::~SubNet() {

}
void SubNet::Set_Nodemap(const int &num, const int &sizex, const int &sizey, const float &cpurng) {
  for(int i =0;i<num;i++){

    int seed1 = std::chrono::steady_clock::now().time_since_epoch().count();
    float seed2 = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed1);
    std::default_random_engine r(seed2);

    //std::default_random_engine r;
    //std::default_random_engine t;
    std::uniform_int_distribution<int > x(0,sizex);
    std::uniform_int_distribution<int > y(0,sizey);
    std::uniform_real_distribution<float > cpu(0,cpurng);
    //srand((unsigned)time(NULL));
    int X=x(e);
    int Y=y(e);
    float CPU=cpu(r);
    std::shared_ptr<SubN> n = std::make_shared<SubN>(SubN(X,Y,CPU));
    n->Set_Id(i);
    this->m_nodemap.emplace_back(n);



  }
}
void SubNet::Set_Linkmap(const float &alpha, const float &beta, const float &L, const float &bandrng) {
  int nodenum = m_nodemap.size();
  for(int i =0;i<nodenum;i++){
    int ii=i+1;
    if(i+1==nodenum){
      ii=0;
    }
    SubL* l = new SubL(1.5,i,ii);
    l->Set_Id(i);
    this->m_linkmap.emplace_back(l);
  }


}


void SubNet::printinfo() {
  for(auto & it : m_nodemap){
    it->printinfo();
  }
  for(auto & it :m_linkmap){
    it->printinfo();
  }

}
void SubNet::Set_Linkmap(std::vector<Node> m_nodemap) {

}
void SubNet::Read_Net(std::string filepath) {
  std::ifstream subnet;
  subnet.open(filepath);
  std::string netinfo;
  getline(subnet, netinfo);
  netinfo.c_str();
  std::vector<std::string> info;
  SplitString(netinfo,info," ");
  auto i = info.begin();
  int nodenum = stoi(*i);
  int linknum = stoi(*++i);

  //nodemap
  for(int i = 0;i<nodenum;i++){
    std::string nodeinfo;
    getline(subnet,nodeinfo);
    nodeinfo.c_str();
    std::vector<std::string> noinfo;
    SplitString(nodeinfo,noinfo," ");
    auto count = noinfo.begin();
    int X = stoi(*count);
    int Y = stoi(*++count);
    float CPU = stof(*++count);
    std::shared_ptr<SubN> n = std::make_shared<SubN>(SubN(X,Y,CPU));
    n->Set_Id(i);
    this->m_nodemap.emplace_back(n);


    //std::cout<< *noinfo.begin()<<" ";
  }

  for(int i=0;i<linknum;i++){
    std::string linkinfo;
    getline(subnet,linkinfo);
    linkinfo.c_str();
    std::vector<std::string> liinfo;
    SplitString(linkinfo,liinfo," ");
    auto count = liinfo.begin();
    int node1 = stoi(*count);
    int node2 = stoi(*++count);
    float band = stof(*++count);
    std::shared_ptr<SubL> l = std::make_shared<SubL>(SubL(band,node1,node2));
    l->Set_Id(i);
    this->m_linkmap.emplace_back(l);

  }

  

}
std::vector<std::shared_ptr<SubN>> SubNet::Get_Nodemap() const {
  return m_nodemap;
}
std::shared_ptr<SubN> SubNet::Get_Node(int i) {
  return m_nodemap[i];

}

std::shared_ptr<SubL> SubNet::Get_Link(int a, int b)  {
  for(auto it :m_linkmap){
    if ((a==it->Get_Path().first && b==it->Get_Path().second)||(a==it->Get_Path().second && b==it->Get_Path().first)){
      return it;
    }
  }
}


std::vector<std::shared_ptr<SubL>> SubNet::GetLinkmap() const {
  return m_linkmap;
}
bool SubNet::Find_Link(int a, int b) const {
  for(auto it :m_linkmap){
    if ((a==it->Get_Path().first && b==it->Get_Path().second)||(a==it->Get_Path().second && b==it->Get_Path().first)){
      return true;
    }
  }
  return false;
}
float SubNet::Get_Ad_Band(int a) const {
  float output =0.0;
  for(auto it :m_linkmap){
    if ((a==it->Get_Path().first )||(a==it->Get_Path().second)){
      output += it->Get_Band();
    }
  }
  return output;
}
std::shared_ptr<std::vector<std::shared_ptr<SubL>>> SubNet::Get_Links_For_Node(int i) {
  std::shared_ptr<std::vector<std::shared_ptr<SubL>>> v = std::make_shared<std::vector<std::shared_ptr<SubL>>>();
  for(auto itt = m_linkmap.begin();itt!=m_linkmap.end();itt++){
    if(i == (*itt)->Get_Path().first || i == (*itt)->Get_Path().second){
      v->push_back(*itt);
    }
  }

  return v;
}
std::shared_ptr<SubL> SubNet::Get_Link(int id) {
  return m_linkmap[id];

}

VirNet::VirNet() {

}
VirNet::~VirNet() {

}
void VirNet::Set_Nodemap(const int &num, const int &sizex, const int &sizey, const float &cpurng) {

}
void VirNet::Set_Linkmap(const float &alpha, const float &beta, const float &L, const float &bandrng) {

}
void VirNet::Set_Linkmap(std::vector<Node> m_nodemap) {

}
void VirNet::Read_Net(std::string filepath) {
  std::ifstream virnet;
  virnet.open(filepath);
  std::string netinfo;
  getline(virnet, netinfo);
  netinfo.c_str();
  std::vector<std::string> info;
  SplitString(netinfo,info," ");
  auto i = info.begin();
  int nodenum = stoi(*i);
  int linknum = stoi(*++i);

  //nodemap
  for(int i = 0;i<nodenum;i++){
    std::string nodeinfo;
    getline(virnet,nodeinfo);
    nodeinfo.c_str();
    std::vector<std::string> noinfo;
    SplitString(nodeinfo,noinfo," ");
    auto count = noinfo.begin();
    int X = stoi(*count);
    int Y = stoi(*++count);
    float CPU = stof(*++count);
    VirN * n = new VirN(X,Y,CPU);
    n->Set_Id(i);
    this->m_nodemap.emplace_back(*n);
    if(n!= nullptr){
      delete n;
    }

    //std::cout<< *noinfo.begin()<<" ";
  }

  for(int i=0;i<linknum;i++){
    std::string linkinfo;
    getline(virnet,linkinfo);
    linkinfo.c_str();
    std::vector<std::string> liinfo;
    SplitString(linkinfo,liinfo," ");
    auto count = liinfo.begin();
    int node1 = stoi(*count);
    int node2 = stoi(*++count);
    float band = stof(*++count);
    VirL * l = new VirL(band,node1,node2);
    l->Set_Id(i);
    this->m_linkmap.emplace_back(*l);
    if(l!= nullptr){
      delete l;
    }
  }



}
void VirNet::Set_VNR_Id(int i) {
  m_vnrid = i;

}
void VirNet::printinfo() {
  for(auto it = m_nodemap.begin();it!=m_nodemap.end();it++){
    (*it).printinfo();
  }
  for(auto it = m_linkmap.begin();it!=m_linkmap.end();it++){
    (*it).printinfo();
  }



}
int VirNet::Get_VNR_Id() {
  return m_vnrid;

}
std::vector<VirN> VirNet::Get_Nodemap() const {
  return m_nodemap;
}
std::vector<VirL> VirNet::GetLinkmap() const {
  return m_linkmap;
}
VirN VirNet::Get_Node(int i) const {
  return m_nodemap[i];
}
VirL VirNet::Get_Link(int a, int b) const {
  for(auto it :m_linkmap){
    if ((a==it.Get_Path().first && b==it.Get_Path().second)||(a==it.Get_Path().second && b==it.Get_Path().first)){
      return it;
    }
  }
}
bool VirNet::Find_Link(int a, int b) const {
  for(auto it :m_linkmap){
    if ((a==it.Get_Path().first && b==it.Get_Path().second)||(a==it.Get_Path().second && b==it.Get_Path().first)){
      return true;
    }
  }
  return false;
}
float VirNet::Get_Ad_Band(int a) const {
  float output =0.0;
  for(auto it :m_linkmap){
    if ((a==it.Get_Path().first )||(a==it.Get_Path().second)){
      output += it.Get_Band();
    }
  }
  return output;
}
void VirNet::Add_Nodemap(int vnode, int snode) {
  m_nodeembedmap.insert(std::make_pair(vnode,snode));

}
void VirNet::Add_Linkmap(int vlink, std::list<int> slinks) {
  m_linkembedmap.insert(std::make_pair(vlink,slinks));

}
int VirNet::Get_Nodeembedsize() {
  return m_nodeembedmap.size();
}
std::map<int, int> VirNet::Get_Nodeembedmap()  {
  return m_nodeembedmap;
}
VirL VirNet::Get_Link(int id) const {
  return m_linkmap[id];
}
int VirNet::Get_Linkembedsize() {
  return m_linkembedmap.size();
}
std::map<int, std::list<int>> VirNet::Get_Linkembedmap() const {
  return m_linkembedmap;
}
std::map<int, std::list<int>> VirNet::Get_Linkembedmap() {
  return m_linkembedmap;
}




