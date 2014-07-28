#include "WWewkMvaInCMSSW/GetWWewkMVA/interface/GetWWewkMVA.h"

GetWWewkMVA::GetWWewkMVA():isInit(false){
//  init(
//    "MLP",
//  getenv("CMSSW_BASE")+std::string("/src/WWewkMvaInCMSSW/GetWWewkMVA/data/TMVA_WWewk_MLP.weights.xml")
//      );
 init(
   "BDTG",
 getenv("CMSSW_BASE")+std::string("/src/WWewkMvaInCMSSW/GetWWewkMVA/data/TMVA_WWewk_BDTG.weights.xml")
     );
}

GetWWewkMVA::~GetWWewkMVA(){
 delete theReader;
}

void GetWWewkMVA::init(std::string methodName, std::string weightsfile){

 if (isInit) return;

 theReader = new TMVA::Reader();

 theReader->AddVariable("jetpt1",       &jetpt1_);
 theReader->AddVariable("jetpt2",       &jetpt2_);
 theReader->AddVariable("detajj",       &detajj_);
 theReader->AddVariable("log(mjj)",     &logmjj_);
//  theReader->AddVariable("pt1",          &pt1_);
//  theReader->AddVariable("pt2",          &pt2_);
//  theReader->AddVariable("ptll",         &ptll_);

 theReader->AddVariable("abs(eta1-(jeteta1+jeteta2)/2)/detajj", &zeppl1_);
 theReader->AddVariable("abs(eta2-(jeteta1+jeteta2)/2)/detajj", &zeppl2_);
//  theReader->AddVariable("abs(yll-(jeteta1+jeteta2)/2)/detajj",  &zeppll_);
//  theReader->AddVariable("dphilljetjet",    &dphilljetjet_);

 theReader->AddVariable( "sqrt((Ml1j1-100)*(Ml1j1-100)+(Ml1j2-100)*(Ml1j2-100))" , &Ml1jradius_);
 theReader->AddVariable( "sqrt((Ml2j1-100)*(Ml2j1-100)+(Ml2j2-100)*(Ml2j2-100))" , &Ml2jradius_);

 theReader->BookMVA(methodName,weightsfile);

 methodname_ = methodName;
 isInit = true;
}


double GetWWewkMVA::getValue(
   double jetpt1,
   double jetpt2,
   double detajj,
   double logmjj,
//    double pt1,
//    double pt2,
//    double ptll,
   double zeppl1,
   double zeppl2,
//    double zeppll,
   double Ml1jradius,
   double Ml2jradius
//    double dphilljetjet
                          ){

    if (!isInit) {
     std::cerr << "MVA reader not initialized!" << std::endl;
     return -999.;
    }

    jetpt1_ = jetpt1;
    jetpt2_ = jetpt2;
    detajj_ = detajj;
    logmjj_ = logmjj;
//     pt1 = pt1_;
//     pt2 = pt2_;
//     ptll = ptll_;
    zeppl1_ = zeppl1;
    zeppl2_ = zeppl2;
//     zeppll_ = zeppll;
//     dphilljetjet = dphilljetjet_; 

    Ml1jradius_ = Ml1jradius;
    Ml2jradius_ = Ml2jradius;

    return theReader->EvaluateMVA( methodname_ );

}

