//
// Created by weixing on 07.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_SCENARIO_H_
#define OFFLINE_SIM_SRC_NETWORK_SCENARIO_H_

#include <vector>
#include "Network.h"

class IScenario{
 private:
  Sub_Net_Builder Substrate;
  std::vector<Sub_Net_Builder> VNRs;

 public:
  IScenario() {}
  virtual ~IScenario() {

  }
  void Make_Substrate();
  void Make_VNRs();

};


void IScenario::Make_Substrate() {


}
void IScenario::Make_VNRs() {

}

#endif //OFFLINE_SIM_SRC_NETWORK_SCENARIO_H_
