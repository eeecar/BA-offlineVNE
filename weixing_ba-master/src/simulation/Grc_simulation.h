//
// Created by weixing on 05.06.20.
//

#ifndef OFFLINE_SIM_SRC_SIMULATION_GRC_SIMULATION_H_
#define OFFLINE_SIM_SRC_SIMULATION_GRC_SIMULATION_H_
#include "../experiments/Grcnodealgo.h"
#include "../experiments/Grclinkalgo.h"
#include "../hiberlite-master/include/hiberlite.h"
#include "../network/Scenario_Builder.h"

class Grc_simulation {
 public:
  friend class hiberlite::access;
  template<class Archive>
  void hibernate(Archive & ar)
  {

    ar & HIBERLITE_NVP(alpha);
    ar & HIBERLITE_NVP(beta);
    ar & HIBERLITE_NVP(sigma);
    ar & HIBERLITE_NVP(damping_factor);
    ar & HIBERLITE_NVP(vnr_id);
    ar & HIBERLITE_NVP(total_revenue);
    ar & HIBERLITE_NVP(total_cost);
    ar & HIBERLITE_NVP(result);

  }

  Grc_simulation();
  virtual ~Grc_simulation();

  void run(std::shared_ptr<SubNet> substrate_network, std::shared_ptr<VirNet> vnr);

 private:
  double alpha;
  double beta;
  float sigma;
  float damping_factor;
  int vnr_id;
  double total_revenue=0;
  double total_cost=0;
  int result = 0;             //1 for successful, 0 for failed

  std::shared_ptr<Grclinkalgo> m_grclinkalgo;
  std::shared_ptr<GrcNodeAlgo> m_grcnodealgo;



};

#endif //OFFLINE_SIM_SRC_SIMULATION_GRC_SIMULATION_H_
