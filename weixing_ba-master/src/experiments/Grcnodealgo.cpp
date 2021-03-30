//
// Created by weixing on 25.05.20.
//

#include "Grcnodealgo.h"
#include <cassert>


GrcNodeAlgo::GrcNodeAlgo(float s, float d) {
  this->sigma=s;
  this->dampingFactor=d;

}
GrcNodeAlgo::~GrcNodeAlgo() = default;



std::map<int, double> GrcNodeAlgo::matrixMultiplication(std::map<int, std::map<int, double>> &mMat,
                                                        std::map<int, double> &rVec) {
  std::map<int, double> output;
  for(auto it1 = mMat.begin(); it1 != mMat.end(); it1++)
  {
    double row_sum = 0.0;
    for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
    {
      assert(it1->second.size() == rVec.size());
      row_sum += it2->second * rVec[it2->first];
    }
    output[it1->first] = row_sum;
  }
  assert(output.size() == rVec.size());
  return output;
}


void GrcNodeAlgo::scalarVecMultiplication(float &scalar, std::map<int, double> &cMat) {
  for(auto it = cMat.begin(); it != cMat.end(); it++){
    it->second *=scalar;
  }
}



double GrcNodeAlgo::calculateNormOfDifference(std::map<int, double> &Mat1, std::map<int, double> &Mat2) {
  assert (Mat1.size() == Mat2.size());
  double norm = 0.0;
  for ( auto it = Mat1.begin(); it != Mat1.end(); it++)
  {
    assert (Mat2.find(it->first) != Mat2.end());
    norm += it->second - Mat2[it->first];
  }
  return norm;
}



std::list<std::pair<int, double>> GrcNodeAlgo::calculateSubstrateGRCVector(std::shared_ptr<SubNet> substrate_network) {
  std::map<int, double> cMat;
  std::map<int, std::map<int, double>> mMat;

  double sumSubstrateNodeCPU = 0.0;
  int nodemapsize = substrate_network->Get_Nodemap().size();

  for(auto it : substrate_network->Get_Nodemap()){
    sumSubstrateNodeCPU += it->Get_CPU();
  }

  for(int i = 0;i<nodemapsize;i++){
    cMat[i] = substrate_network->Get_Node(i)->Get_CPU()/sumSubstrateNodeCPU;
  }

  //mMat:
  for(int it1= 0;it1<nodemapsize;it1++){
    for(int it2 = 0;it2<nodemapsize;it2++){
      if(substrate_network->Find_Link(it1,it2)){
        mMat[it1][it2] = substrate_network->Get_Link(it1,it2)->Get_Band()/substrate_network->Get_Ad_Band(it2);
      }
      else mMat[it1][it2] = 0.0;
    }
  }

  double delta = 1e8;
  std::map<int, double> current_r = cMat;
  std::map<int, double> next_r;
  float scalar = 1-dampingFactor;
  scalarVecMultiplication(scalar, cMat);

  while (delta>=sigma)
  {
    std::map<int,double> mrMatrix = matrixMultiplication(mMat, current_r);
    scalarVecMultiplication(dampingFactor, mrMatrix);
    assert(mrMatrix.size() == cMat.size());
    for (auto it = cMat.begin(); it != cMat.end(); it++)
    {
      next_r[it->first] = it->second + mrMatrix[it->first];
    }
    delta = calculateNormOfDifference(next_r, current_r);
    current_r = next_r;
  }

  std::list<std::pair<int, double>> output;
  for (auto it = current_r.begin(); it != current_r.end(); it++ )
  {
    output.emplace_back(it->first, it->second);
  }
  output.sort(sort_order());
  return output;




  return std::list<std::pair<int, double>>();
}



std::list<std::pair<int, double>> GrcNodeAlgo::calculateVNRGRCVector(std::shared_ptr<VirNet> vnr) {

  std::map<int, double> cMat;
  std::map<int, std::map<int, double>> mMat;

  double sumSubstrateNodeCPU = 0.0;
  int nodemapsize = vnr->Get_Nodemap().size();

  for(auto it : vnr->Get_Nodemap()){
    sumSubstrateNodeCPU += it.Get_CPU();
  }

  for(int i = 0;i<nodemapsize;i++){
    cMat[i] = vnr->Get_Node(i).Get_CPU()/sumSubstrateNodeCPU;
  }

  //mMat:
  for(int it1= 0;it1<nodemapsize;it1++){
    for(int it2 = 0;it2<nodemapsize;it2++){
      if(vnr->Find_Link(it1,it2)){
        mMat[it1][it2] = vnr->Get_Link(it1,it2).Get_Band()/vnr->Get_Ad_Band(it2);
      }
      else mMat[it1][it2] = 0.0;
    }
  }

  double delta = 1e6;
  std::map<int, double> current_r = cMat;
  std::map<int, double> next_r;
  float scalar = 1-dampingFactor;
  scalarVecMultiplication(scalar, cMat);

  while (delta>=sigma)
  {
    std::map<int,double> mrMatrix = matrixMultiplication(mMat, current_r);
    scalarVecMultiplication(dampingFactor, mrMatrix);
    assert(mrMatrix.size() == cMat.size());
    for (auto it = cMat.begin(); it != cMat.end(); it++)
    {
      next_r[it->first] = it->second + mrMatrix[it->first];
    }
    delta = calculateNormOfDifference(next_r, current_r);
    current_r = next_r;
  }

  std::list<std::pair<int, double>> output;
  for (auto it = current_r.begin(); it != current_r.end(); it++ )
  {
    output.emplace_back(it->first, it->second);
  }
  output.sort(sort_order());
  return output;


  return std::list<std::pair<int, double>>();
}


bool GrcNodeAlgo::embeddVNRNodes(std::shared_ptr<SubNet> substrate_network, std::shared_ptr<VirNet> vnr) {
  std::list<std::pair<int, double>> substrateRmat = calculateSubstrateGRCVector(substrate_network);
  std::list<std::pair<int, double>> virtualRmat = calculateVNRGRCVector(vnr);
  for(auto it1 = virtualRmat.begin();it1 != virtualRmat.end();it1++){
    for(auto it2 = substrateRmat.begin();it2 != substrateRmat.end();it2++){
      if(substrate_network->Get_Node(it2->first)->Get_CPU()>=vnr->Get_Node(it1->first).Get_CPU()){
        vnr->Add_Nodemap(it1->first,it2->first);
        substrateRmat.erase(it2);
        break;

      }

    }

  }

  //std::cout<<"size of virtualRmat: "<<virtualRmat.size()<<std::endl;
  //std::cout<<"size of nodembedmap: "<<vnr->Get_Nodeembedsize()<<std::endl;

  return virtualRmat.size() == vnr->Get_Nodeembedsize();
}
void GrcNodeAlgo::GRC_Sort_VNRs(std::vector<std::shared_ptr<VirNet>> &vnrs) {

  std::vector<std::pair<int, float>> grcvector;
  int id = 0;

  for(auto vnr = vnrs.begin();vnr!=vnrs.end();vnr++){
    std::list<std::pair<int, double>> l = calculateVNRGRCVector(*vnr);
    double grc = 0;
    for(auto itt = l.begin();itt!=l.end();itt++){
      grc+=itt->second;
      std::cout<<" GRC: "<<grc<<" "<<itt->second;
    }
    std::cout<<std::endl;

    grcvector.emplace_back(id,grc);
    id++;
  }
  std::sort(grcvector.begin(),grcvector.end(),mycom);
  for(auto i = grcvector.begin();i!=grcvector.end();i++){
    std::cout<<"id: "<<i->first<<" grc: "<<i->second<<std::endl;
  }


}
void GrcNodeAlgo::Resource_Sort_VNRs(std::vector<std::shared_ptr<VirNet>> &vnrs) {
  std::vector<std::pair<int,float>> demandvector;
  int id = 0;
  for(auto vnr = vnrs.begin();vnr!=vnrs.end();vnr++){
    float cpu = 0;
    float bw = 0;
    for(auto it = (*vnr)->Get_Nodemap().begin();it!=(*vnr)->Get_Nodemap().end();it++){
      cpu+=it->Get_CPU();
    }
    cpu = cpu/(*vnr)->Get_Nodemap().size();
    for(auto it2 = (*vnr)->GetLinkmap().begin();it2!=(*vnr)->GetLinkmap().end();it2++){
      bw+=it2->Get_Band();
    }
    bw = bw/(*vnr)->GetLinkmap().size();
    demandvector.emplace_back(id,cpu+bw);
    id++;
  }
  std::sort(demandvector.begin(),demandvector.end(),mycom);
  std::vector<std::shared_ptr<VirNet>> copy;
  int copyid = 0;


  for(auto i = demandvector.begin();i!=demandvector.end();i++){
    copy.emplace_back(vnrs[i->first]);


    //std::cout<<"id: "<<i->first<<" demand: "<<i->second<<std::endl;
  }
  vnrs = copy;
  for(auto i = vnrs.begin();i!=vnrs.end();i++){
    (*i)->Set_VNR_Id(copyid);
    copyid++;
  }
}
GrcNodeAlgo::GrcNodeAlgo() {
  this->sigma = 0.001;
  this->dampingFactor = 0.2;

}
