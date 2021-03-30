//
// Created by weixing on 29.04.20.
//

#ifndef OFFLINE_SIM_SRC_CORE_NODE_H_
#define OFFLINE_SIM_SRC_CORE_NODE_H_

#include <tuple>

namespace vne{


template<class ... NRES>
class Node{
 public:
  Node();
  ~Node();
  float GetCPUValue();


 private:
  std::tuple<NRES...> n_resources;
  float cpu_value;



 protected:
  std::pair<float,float> coordinate;





};









}


#endif //OFFLINE_SIM_SRC_CORE_NODE_H_
