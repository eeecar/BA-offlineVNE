//
// Created by weixing on 28.05.20.
//

#ifndef OFFLINE_SIM_SRC_EXPERIMENTS_GRCLINKALGO_H_
#define OFFLINE_SIM_SRC_EXPERIMENTS_GRCLINKALGO_H_
#include "../network/Network.h"
#include <memory>
#include <map>
#include <list>
#include <set>
#include "../hiberlite-master/include/hiberlite.h"



class Grclinkalgo {
 public:
  Grclinkalgo();
  virtual ~Grclinkalgo();
  bool embeddVNRLinkss (std::shared_ptr<SubNet> substrate_network, std::shared_ptr<VirNet> vnr, std::map<int,int> nodeembedmap);

 private:
  //std::shared_ptr<std::set<int> > m_vnrlinkidset;
  int m_vnrlinknum;
};

#endif //OFFLINE_SIM_SRC_EXPERIMENTS_GRCLINKALGO_H_
