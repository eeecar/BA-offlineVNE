//
// Created by weixing on 05.06.20.
//

#include "Grc_simulation.h"
Grc_simulation::Grc_simulation() {
  this->alpha = 1;
  this->beta = 1;
  this->sigma = 0.001;
  this->damping_factor = 0.2;
  Grclinkalgo grcl;
  GrcNodeAlgo grcn(sigma,damping_factor);
  m_grclinkalgo = std::make_shared<Grclinkalgo>(grcl);
  m_grcnodealgo = std::make_shared<GrcNodeAlgo>(grcn);
}
Grc_simulation::~Grc_simulation() {

}
void Grc_simulation::run(std::shared_ptr<SubNet> substrate_network, std::shared_ptr<VirNet> vnr) {
  this->vnr_id = vnr->Get_VNR_Id();
  if (m_grcnodealgo->embeddVNRNodes(substrate_network,vnr)){
    if(m_grclinkalgo->embeddVNRLinkss(substrate_network,vnr,vnr->Get_Nodeembedmap())){
      this->result = 1;

      //calculate revenue
      double totalcpu = 0;
      double totalbw = 0;
      for(auto n = vnr->Get_Nodemap().begin();n !=vnr->Get_Nodemap().end();n++){
        totalcpu+= (*n).Get_CPU();
      }
      for(auto b = vnr->GetLinkmap().begin();b !=vnr->GetLinkmap().end();b++){
        totalbw+=(*b).Get_Band();
      }
      this->total_revenue = this->alpha*totalcpu+this->beta*totalbw;

      //calculate cost
      double costbw = 0;
      for(auto f = vnr->Get_Linkembedmap().begin();f != vnr->Get_Linkembedmap().end();f++){
        costbw += vnr->Get_Link(f->first).Get_Band()*f->second.size();
      }
      this->total_cost = totalcpu + costbw;

    }
  }


}

HIBERLITE_EXPORT_CLASS(Grc_simulation)