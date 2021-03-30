//
// Created by weixing on 29.04.20.
//

#ifndef OFFLINE_SIM_SRC_CORE_LINK_H_
#define OFFLINE_SIM_SRC_CORE_LINK_H_


#include <tuple>

namespace vne{


template<class ... LRES>
class Link{
 public:
  Link();
  ~Link();


 private:
  std::tuple<LRES...> l_resources;


};




}

#endif //OFFLINE_SIM_SRC_CORE_LINK_H_
