//
// Created by weixing on 07.05.20.
//

#ifndef OFFLINE_SIM_SRC_NETWORK_NETWORK_BUILDER_H_
#define OFFLINE_SIM_SRC_NETWORK_NETWORK_BUILDER_H_

#include "Network.h"

class Network_Builder {
 public:
  virtual void Nodemap_Builder()=0;
  virtual void Linkmap_Builder()=0;
  virtual Network* Put_Together()=0;
  Network_Builder();
  virtual ~Network_Builder();

};


class Sub_Net_Builder :public Network_Builder{
 public:
  Sub_Net_Builder();
  virtual ~Sub_Net_Builder();
  void Nodemap_Builder() override;
  void Linkmap_Builder() override;
  Network *Put_Together() override;

 private:

};

class VNR_Builder : public Network_Builder{
 public:
  void Nodemap_Builder() override;
  void Linkmap_Builder() override;
  Network *Put_Together() override;
};



#endif //OFFLINE_SIM_SRC_NETWORK_NETWORK_BUILDER_H_
