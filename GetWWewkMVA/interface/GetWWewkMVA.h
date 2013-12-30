#ifndef GetWWewkMVA_h
#define GetWWewkMVA_h

#include "TMVA/Reader.h"

class GetWWewkMVA {

 public:
  GetWWewkMVA();
  ~GetWWewkMVA();

  void init(std::string methodName, std::string weightsfile);
//   double getValue(double jetpt1,double jetpt2,double detajj,double logmjj,double pt1,double pt2,double ptll,double zeppl1,double zeppl2,double zeppll,double dphilljetjet);
  double getValue(double jetpt1,double jetpt2,double detajj,double logmjj,double zeppl1,double zeppl2,double zeppll);

 private:

  TMVA::Reader* theReader;

  //common variables
  float jetpt1_;
  float jetpt2_;
  float detajj_;
  float logmjj_;
//   float pt1_;
//   float pt2_;
//   float ptll_;
  float zeppl1_;
  float zeppl2_;
  float zeppll_;
//   float dphilljetjet_;

  std::string methodname_;

  bool isInit;

};

#endif