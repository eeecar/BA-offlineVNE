//
// Created by weixing on 07.05.20.
//

#include "Scenario_Builder.h"
Scenario_Builder::Scenario_Builder() {}
Scenario_Builder::~Scenario_Builder() {

}




//void Scenario1::Substrate_Builder(std::string subnetfile) {
//  SubNet s1;
 // s1.Set_Nodemap();
  //s1.Set_Linkmap();
  //m_scenario1.first = s1;

//}
//void Scenario1::VNRs_Bilder(std::string vnrdir, int vnrnum) {
  //for(int i =1;i<=vnrnum;i++){
    //VirNet v;
    //v.Set_Nodemap();
    //v.Set_Linkmap();
    //m_scenario1.second.emplace_back(v);

  //}


//}


Scenario1::Scenario1() {

}

Scenario1::~Scenario1() {

}
void Scenario1::Substrate_Builder(std::string subnetfile) {
  SubNet s;
  s.Read_Net(subnetfile);
  m_scenario1.first = std::make_shared<SubNet>(s);


}
void Scenario1::VNRs_Bilder(std::string vnrdir, int vnrnum) {
  std::vector<std::shared_ptr<VirNet>> vv;
  for(int i=0;i<vnrnum;i++){
    VirNet v;
    std::string file = vnrdir;
    file +="/req";
    int seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_int_distribution<int > x(0,3999);
    int randomreq = x(e);
    file += std::to_string(randomreq);
    file += ".txt";
    //file += std::to_string();
    v.Read_Net(file);
    v.Set_VNR_Id(i);
    vv.emplace_back(std::make_shared<VirNet>(v));
  }
  m_scenario1.second = vv;

}
void Scenario1::printinfo() {
  //m_scenario1.first->printinfo();
  for(auto & itt :m_scenario1.second){
    std::cout<<"vnr_id: "<<itt->Get_VNR_Id()<<" ";
    itt->printinfo();

  }

}
std::shared_ptr<SubNet> Scenario1::Get_SubNet() {
  //std::shared_ptr<SubNet> ptr = static_cast<std::shared_ptr<SubNet> >(& m_scenario1.first);
  return m_scenario1.first;
}
std::shared_ptr<VirNet> Scenario1::Get_VirNet(int i) {
  //std::shared_ptr<VirNet> ptr = static_cast<std::shared_ptr<VirNet> >(& m_scenario1.second[i]);
  return m_scenario1.second[i];
}
void Scenario1::Sub_Update(int i) {
  for(auto it :m_scenario1.second[i]->Get_Nodeembedmap()){
    float cpu = m_scenario1.first->Get_Node(it.second)->Get_CPU();
    //std::cout<<cpu<<"  ";
    cpu -= m_scenario1.second[i]->Get_Node(it.first).Get_CPU();
    //std::cout<<cpu<<"  ";
    m_scenario1.first->Get_Node(it.second)->Set_CPU(cpu);
    //std::cout<<m_scenario1.first->Get_Node(it.second)->Get_CPU()<<std::endl;
  }
  for(auto it :m_scenario1.second[i]->Get_Linkembedmap()){
    float usedBW = m_scenario1.second[i]->Get_Link(it.first).Get_Band();
    for(auto itt = it.second.begin();itt != it.second.end();itt++){
      float bw = m_scenario1.first->Get_Link(*itt)->Get_Band();
      bw -= usedBW;
      m_scenario1.first->Get_Link(*itt)->Set_Band(bw);
    }

  }


}
void Scenario1::VNRs_Bilder(std::vector<std::shared_ptr<VirNet>> vnrs) {
  m_scenario1.second = vnrs;

}
std::vector<std::shared_ptr<VirNet>> & Scenario1::Get_VNRs() {
  return m_scenario1.second;
}

