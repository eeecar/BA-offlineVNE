//
// Created by weixing on 07.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_SCENARIO_BUILDER_H_
#define OFFLINE_SIM_SRC_NETWORK_SCENARIO_BUILDER_H_

#include "Network_Builder.h"
#include "Network.h"
#include "Scenario.h"

class Scenario_Builder {
 public:
  virtual void Substrate_Builder(std::string subnetfile)=0;
  virtual void VNRs_Bilder(std::string vnrdir, int vnrnum)=0;
  //virtual IScenario* Get_Scenario()=0;
  Scenario_Builder();
  virtual ~Scenario_Builder();

};


class Scenario1 :public Scenario_Builder{
 public:
  void Substrate_Builder(std::string subnetfile) override;
  void VNRs_Bilder(std::string vnrdir, int vnrnum) override;
  void VNRs_Bilder(std::vector<std::shared_ptr<VirNet>> vnrs);
  std::shared_ptr<SubNet> Get_SubNet();
  std::shared_ptr<VirNet> Get_VirNet(int i);
  std::vector<std::shared_ptr<VirNet>> & Get_VNRs();
  void Sub_Update(int i);
  //IScenario* Get_Scenario() override;
  Scenario1();
  ~Scenario1();
  void printinfo();

 public:
  std::pair<std::shared_ptr<SubNet> ,std::vector<std::shared_ptr<VirNet>>> m_scenario1;
};


#endif //OFFLINE_SIM_SRC_NETWORK_SCENARIO_BUILDER_H_
