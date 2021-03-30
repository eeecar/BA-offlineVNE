//
// Created by weixing on 25.05.20.
//

#ifndef OFFLINE_SIM_SRC_EXPERIMENTS_GRCNODEALGO_H_
#define OFFLINE_SIM_SRC_EXPERIMENTS_GRCNODEALGO_H_
#include "../network/Network.h"
#include <memory>
#include <map>
#include <list>
#include <algorithm>

class GrcNodeAlgo {
 public:
  friend class Scenario1;
  GrcNodeAlgo(float s, float d);
  GrcNodeAlgo();
  virtual ~GrcNodeAlgo();
  bool  embeddVNRNodes (std::shared_ptr<SubNet> substrate_network, std::shared_ptr<VirNet> vnr);
  void GRC_Sort_VNRs( std::vector<std::shared_ptr<VirNet>> & vnrs);
  void Resource_Sort_VNRs(std::vector<std::shared_ptr<VirNet>> & vnrs);



 private:
  float sigma;
  float dampingFactor;
  double alpha;
  double beta;

  inline std::map<int, double> matrixMultiplication (std::map<int, std::map<int, double>>& mMat, std::map<int, double>& rVec);
  inline void scalarVecMultiplication (float& scalar, std::map<int, double>& cMat);
  inline double calculateNormOfDifference (std::map<int, double>& Mat1, std::map<int, double>& Mat2);
  inline std::list<std::pair<int, double>> calculateSubstrateGRCVector (std::shared_ptr<SubNet> substrate_network);
  inline std::list<std::pair<int, double>> calculateVNRGRCVector (std::shared_ptr<VirNet> vnr);


  struct sort_order
  {
    bool operator()(const std::pair<int,double>& first, const std::pair<int,double>& second) const
    {
      return ( first.second > second.second );
    }
  };

  struct MYCOM{
    bool operator()(const std::pair<int,float> &v1, const std::pair<int,float> &v2){
      return v1.second>v2.second;
    }
  } mycom;









};

#endif //OFFLINE_SIM_SRC_EXPERIMENTS_GRCNODEALGO_H_
