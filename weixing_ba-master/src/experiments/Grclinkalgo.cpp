//
// Created by weixing on 28.05.20.
//

#include "Grclinkalgo.h"
#include <cassert>

Grclinkalgo::Grclinkalgo() {}
Grclinkalgo::~Grclinkalgo() {

}
bool Grclinkalgo::embeddVNRLinkss(std::shared_ptr<SubNet> substrate_network,
                                  std::shared_ptr<VirNet> vnr,
                                  std::map<int, int> nodeembedmap) {

  m_vnrlinknum = vnr->GetLinkmap().size();
  std::map<int,double> usedslbw;

  for (int it = 0 ; it<m_vnrlinknum ; it++){

    VirL currentVL = vnr->Get_Link(it);
    assert(it == currentVL.Get_Id());

    int vnode1 = currentVL.Get_Path().first;
    int vnode2 = currentVL.Get_Path().second;
    double vlBW = currentVL.Get_Band();

    int snode1;
    int snode2;
    auto it1 =nodeembedmap.find(vnode1);
    if(it1 != nodeembedmap.end()) snode1 = it1->second;
    auto it2 =nodeembedmap.find(vnode2);
    if(it2 != nodeembedmap.end()) snode2 = it2->second;

    std::set<int> visitedsubnodes;

    //priority queue
    //pair.first: last visited subnode id
    //pair.second: list of visited sublink ids
    std::list<std::pair<int,std::list<int>>> queue;

    visitedsubnodes.insert(snode1);
    queue.push_back(std::make_pair(snode1,std::list<int>()));

    bool foundnode2 = false;
    std::list<int> shortestpath;

    while(!queue.empty() && !foundnode2){
      int currentsnid = queue.front().first;
      std::list<int> currentpath = queue.front().second;
      queue.pop_front();
      const std::shared_ptr<const std::vector<std::shared_ptr<SubL>>> slofcurrentsn =substrate_network->Get_Links_For_Node(currentsnid);
      for(int i = 0; i<slofcurrentsn->size();i++){
        std::shared_ptr<SubL> currentsl = slofcurrentsn->at(i);
        double residualbw = currentsl->Get_Band();
        std::list<int> currentpathcopy = currentpath;
        if(usedslbw.find(currentsl->Get_Id())!=usedslbw.end())
          residualbw -= usedslbw[currentsl->Get_Id()];
        if(residualbw >= vlBW){
          int nextSNId = -1;
          if(slofcurrentsn->at(i)->Get_Path().first != currentsnid)
            nextSNId = slofcurrentsn->at(i)->Get_Path().first;
          else
            nextSNId = slofcurrentsn->at(i)->Get_Path().second;

          //if the next node is destination
          if(nextSNId == snode2)
          {
            foundnode2 = true;
            currentpathcopy.push_back(currentsl->Get_Id());
            usedslbw[currentsl->Get_Id()]+=vlBW;
            shortestpath = currentpathcopy;

          }

          //if the destination node is not visited
          if(visitedsubnodes.find(nextSNId) == visitedsubnodes.end()){
            visitedsubnodes.insert(nextSNId);
            currentpathcopy.push_back(slofcurrentsn->at(i)->Get_Id());
            usedslbw[currentsl->Get_Id()]+=vlBW;
            queue.emplace_back(nextSNId,currentpathcopy);
          }
        }

      }
    }
    if(queue.empty() && !foundnode2){
      std::cout<<"Link embeeding failed1!"<<"--+--";
      return false;
    }

    vnr->Add_Linkmap(it,shortestpath);

  }

  if(vnr->Get_Linkembedsize()==m_vnrlinknum){
    std::cout<<"Link embeeding successful!"<<"--+--";
    return true;
  }
  std::cout<<"Link embeeding failed2!"<<"--+--";
  return false;

}
