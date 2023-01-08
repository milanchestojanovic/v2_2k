// -*- C++ -*-
//
// Package:    vn_10Qum/Qnana
// Class:      Qnana
//
/**\class Qnana Qnana.cc vn_10Qum/Qnana/plugins/Qnana.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Milan Stojanovic
//         Created:  Wed, 20 Jan 2021 21:13:04 GMT
//
//


// system include files
#include <memory>
#include <vector>
#include <complex>

// user include files
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
//#include "DataFormats/TrackReco/interface/Track.h"
//#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/HeavyIonEvent/interface/CentralityBins.h"
#include "DataFormats/HeavyIonEvent/interface/Centrality.h"
#include <DataFormats/VertexReco/interface/Vertex.h>
#include <DataFormats/VertexReco/interface/VertexFwd.h>

//#include "2018PbPb_TrackingEfficiencies_Jan272020_Final/trackingEfficiency2018PbPb.h"

#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TF1.h>
#include "TComplex.h"
#include <TTree.h>

#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.

#define maxmult 100000

using reco::TrackCollection;

class Qnana : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit Qnana(const edm::ParameterSet&);
      ~Qnana();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
      static bool vtxSort( const reco::Vertex &  a, const reco::Vertex & b );


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      void initHistos(const edm::Service<TFileService> & fs);
      bool passesTrackCuts(const reco::Track & track, const reco::VertexCollection&, double chi2n);

      // ----------member data ---------------------------


//      std::vector<std::vector<TVector3> > event;//(2);
/*
Double_t phi_ref[maxmult];
Double_t eff_ref[maxmult];
Double_t weight[maxmult];

std::vector<std::vector< std::complex <Float_t> > > Q, Q2, Q3, Q4, Q5;
std::vector <std::vector <Double_t>> W2Two, W4Four, W6Six, W8Eight, W10Ten;
std::vector <std::vector <Double_t>> SumW2Two, SumW22Two, SumW24Two, SumW26Two, SumW28Two, SumW210Two, SumW2TwoW2Two;
std::vector <std::vector <Double_t>> SumW4Four, SumW24Four, SumW44Four, SumW46Four, SumW48Four, SumW410Four, SumW2TwoW4Four, SumW4FourW4Four;
std::vector <std::vector <Double_t>> SumW6Six, SumW26Six, SumW46Six, SumW66Six, SumW68Six, SumW610Six, SumW2TwoW6Six, SumW4FourW6Six, SumW6SixW6Six;
std::vector <std::vector <Double_t>> SumW8Eight, SumW28Eight, SumW48Eight, SumW68Eight, SumW88Eight, SumW810Eight, SumW2TwoW8Eight, SumW4FourW8Eight, SumW6SixW8Eight, SumW8EightW8Eight;
std::vector <std::vector <Double_t>> SumW10Ten, SumW210Ten, SumW410Ten,
SumW610Ten, SumW810Ten, SumW1010Ten, SumW2TwoW10Ten,
SumW4FourW10Ten, SumW6SixW10Ten, SumW8EightW10Ten, SumW10TenW10Ten;
std::vector <std::vector <Double_t>> AveTwo, AveFour, AveSix, AveEight, AveTen;
std::vector <std::vector <Double_t>> VarAveTwo, VarAveFour, VarAveSix, VarAveEight, VarAveTen;
std::vector <std::vector <Double_t>> CovAveTwoAveFour, CovAveTwoAveSix, CovAveTwoAveEight, CovAveTwoAveTen, CovAveFourAveSix, CovAveFourAveEight, CovAveFourAveTen, CovAveSixAveEight, CovAveSixAveTen, CovAveEightAveTen;
std::vector <std::vector <Double_t>> CumTwo, Two_v, ErrTwo_v;
std::vector <std::vector <Double_t>> CumFour, Four_v, ErrFour_v;
std::vector <std::vector <Double_t>> CumSix, Six_v, ErrSix_v;
std::vector <std::vector <Double_t>> CumEight, Eight_v, ErrEight_v;
std::vector <std::vector <Double_t>> CumTen, Ten_v, ErrTen_v;

std::vector<Double_t> W2, W22, W24, W26, W28, W210, W4, W44, W46, W48, W410, W6, W66, W68, W610, W8, W88, W810, W10, W1010;

//efficiency

std::vector <std::vector<std::complex<Double_t>>> Qt, Qt_3, Qt_5, Qt_7, Qt_9, Qt2, Qt2_4, Qt2_6, Qt2_8, Qt3, Qt3_5, Qt3_7, Qt4, Qt4_6, Qt5;

std::vector <std::vector <Double_t>> W2Twot, W4Fourt, W6Sixt, W8Eightt, W10Tent;

std::vector <std::vector <Double_t>> SumW2Twot, SumW22Twot, SumW24Twot, SumW26Twot, SumW28Twot, SumW210Twot, SumW2TwoW2Twot;

std::vector <std::vector <Double_t>> SumW4Fourt, SumW24Fourt, SumW44Fourt, SumW46Fourt, SumW48Fourt, SumW410Fourt, SumW2TwoW4Fourt, SumW4FourW4Fourt;

std::vector <std::vector <Double_t>> SumW6Sixt, SumW26Sixt, SumW46Sixt, SumW66Sixt, SumW68Sixt, SumW610Sixt, SumW2TwoW6Sixt, SumW4FourW6Sixt, SumW6SixW6Sixt;

std::vector <std::vector <Double_t>> SumW8Eightt, SumW28Eightt, SumW48Eightt, SumW68Eightt, SumW88Eightt, SumW810Eightt, SumW2TwoW8Eightt, SumW4FourW8Eightt, SumW6SixW8Eightt, SumW8EightW8Eightt;

std::vector <std::vector <Double_t>> SumW10Tent, SumW210Tent, SumW410Tent,
SumW610Tent, SumW810Tent, SumW1010Tent, SumW2TwoW10Tent,
SumW4FourW10Tent, SumW6SixW10Tent, SumW8EightW10Tent, SumW10TenW10Tent;

std::vector <std::vector <Double_t>> AveTwot, AveFourt, AveSixt, AveEightt, AveTent;

std::vector <std::vector <Double_t>> VarAveTwot, VarAveFourt, VarAveSixt, VarAveEightt, VarAveTent;

std::vector <std::vector <Double_t>> CovAveTwoAveFourt, CovAveTwoAveSixt, CovAveTwoAveEightt, CovAveTwoAveTent, CovAveFourAveSixt, CovAveFourAveEightt, CovAveFourAveTent, CovAveSixAveEightt, CovAveSixAveTent, CovAveEightAveTent;

std::vector <std::vector <Double_t>> CumTwot, Two_vt, ErrTwo_vt;
std::vector <std::vector <Double_t>> CumFourt, Four_vt, ErrFour_vt;
std::vector <std::vector <Double_t>> CumSixt, Six_vt, ErrSix_vt;
std::vector <std::vector <Double_t>> CumEightt, Eight_vt, ErrEight_vt;
std::vector <std::vector <Double_t>> CumTent, Ten_vt, ErrTen_vt;

std::vector<Double_t> Mt, Mt2, M2t, M2t2, MM2t, M3t, M3t2, MM3t, M2M3t, M4t, M4t2, MM4t, M2M4t, M3M4t, M5t, M5t2, MM5t, M2M5t, M3M5t, M4M5t;

std::vector<Double_t> S11, S12, S13, S14, S15, S16, S17, S18, S19, S110;
std::vector<Double_t> S21, S22, S23, S24, S25;
std::vector<Double_t> S31, S32, S33;
std::vector<Double_t> S41, S42;
std::vector<Double_t> S51, S52;
std::vector<Double_t> S61;
std::vector<Double_t> S71;
std::vector<Double_t> S81;
std::vector<Double_t> S101;



  Double_t multEv[16];	
*/

Int_t Low, High;
int   centDefault, centNominal, centUp, centDown;

      TH1D *h_hiHF;
      TH1D *h_hiHFdown;
      TH1D *h_hiHFup;

      TTree* VertexCompositeNtuple;
/*
      TH3D *h_eff;

      TH1D *h_multEv;

      TH1D *h_W2; TH1D *h_W22; TH1D *h_W24; TH1D *h_W26; TH1D *h_W28; TH1D *h_W210; TH1D *h_W4; TH1D *h_W44; TH1D *h_W46; TH1D *h_W48; TH1D *h_W410; TH1D *h_W6; TH1D *h_W66; TH1D *h_W68; TH1D *h_W610; TH1D *h_W8; TH1D *h_W88; TH1D *h_W810; TH1D *h_W10; TH1D *h_W1010;

TH2D *h_W2Two; TH2D *h_W4Four; TH2D *h_W6Six; TH2D *h_W8Eight; TH2D *h_W10Ten;
TH2D *h_SumW2Two; TH2D *h_SumW22Two; TH2D *h_SumW24Two; TH2D *h_SumW26Two; TH2D *h_SumW28Two; TH2D *h_SumW210Two; TH2D *h_SumW2TwoW2Two;
TH2D *h_SumW4Four; TH2D *h_SumW24Four; TH2D *h_SumW44Four; TH2D *h_SumW46Four; TH2D *h_SumW48Four; TH2D *h_SumW410Four; TH2D *h_SumW2TwoW4Four; TH2D *h_SumW4FourW4Four;
TH2D *h_SumW6Six; TH2D *h_SumW26Six; TH2D *h_SumW46Six; TH2D *h_SumW66Six; TH2D *h_SumW68Six; TH2D *h_SumW610Six; TH2D *h_SumW2TwoW6Six; TH2D *h_SumW4FourW6Six; TH2D *h_SumW6SixW6Six;
TH2D *h_SumW8Eight; TH2D *h_SumW28Eight; TH2D *h_SumW48Eight; TH2D *h_SumW68Eight; TH2D *h_SumW88Eight; TH2D *h_SumW810Eight; TH2D *h_SumW2TwoW8Eight; TH2D *h_SumW4FourW8Eight; TH2D *h_SumW6SixW8Eight; TH2D *h_SumW8EightW8Eight;
TH2D *h_SumW10Ten; TH2D *h_SumW210Ten; TH2D *h_SumW410Ten;
TH2D *h_SumW610Ten; TH2D *h_SumW810Ten; TH2D *h_SumW1010Ten; TH2D *h_SumW2TwoW10Ten;
TH2D *h_SumW4FourW10Ten; TH2D *h_SumW6SixW10Ten; TH2D *h_SumW8EightW10Ten; TH2D *h_SumW10TenW10Ten;
TH2D *h_AveTwo; TH2D *h_AveFour; TH2D *h_AveSix; TH2D *h_AveEight; TH2D *h_AveTen;
TH2D *h_VarAveTwo; TH2D *h_VarAveFour; TH2D *h_VarAveSix; TH2D *h_VarAveEight; TH2D *h_VarAveTen;
TH2D *h_CovAveTwoAveFour; TH2D *h_CovAveTwoAveSix; TH2D *h_CovAveTwoAveEight; TH2D *h_CovAveTwoAveTen; TH2D *h_CovAveFourAveSix; TH2D *h_CovAveFourAveEight; TH2D *h_CovAveFourAveTen; TH2D *h_CovAveSixAveEight; TH2D *h_CovAveSixAveTen; TH2D *h_CovAveEightAveTen;
TH2D *h_CumTwo; TH2D *h_Two_v; TH2D *h_ErrTwo_v;
TH2D *h_CumFour; TH2D *h_Four_v; TH2D *h_ErrFour_v;
TH2D *h_CumSix; TH2D *h_Six_v; TH2D *h_ErrSix_v;
TH2D *h_CumEight; TH2D *h_Eight_v; TH2D *h_ErrEight_v;
TH2D *h_CumTen; TH2D *h_Ten_v; TH2D *h_ErrTen_v;

//efficiency
TH1D *h_Mt; TH1D *h_Mt2; TH1D *h_M2t; TH1D *h_M2t2; TH1D *h_MM2t; TH1D *h_M3t; TH1D *h_M3t2; TH1D *h_MM3t; TH1D *h_M2M3t; TH1D *h_M4t; TH1D *h_M4t2; TH1D *h_MM4t; TH1D *h_M2M4t; TH1D *h_M3M4t; TH1D *h_M5t; TH1D *h_M5t2; TH1D *h_MM5t; TH1D *h_M2M5t; TH1D *h_M3M5t; TH1D *h_M4M5t;
 TH1D *h_S11; TH1D *h_S12; TH1D *h_S13; TH1D *h_S14; TH1D *h_S15; TH1D *h_S16; TH1D *h_S17; TH1D *h_S18; TH1D *h_S19; TH1D *h_S110;
 TH1D *h_S21; TH1D *h_S22; TH1D *h_S23; TH1D *h_S24; TH1D *h_S25;
 TH1D *h_S31; TH1D *h_S32; TH1D *h_S33;
 TH1D *h_S41; TH1D *h_S42;
 TH1D *h_S51; TH1D *h_S52;
 TH1D *h_S61;
 TH1D *h_S71;
 TH1D *h_S81;
 TH1D *h_S101;

TH2D *h_W2Twot; TH2D *h_W4Fourt; TH2D *h_W6Sixt; TH2D *h_W8Eightt; TH2D *h_W10Tent;
TH2D *h_SumW2Twot; TH2D *h_SumW22Twot; TH2D *h_SumW24Twot; TH2D *h_SumW26Twot; TH2D *h_SumW28Twot; TH2D *h_SumW210Twot; TH2D *h_SumW2TwoW2Twot;
TH2D *h_SumW4Fourt; TH2D *h_SumW24Fourt; TH2D *h_SumW44Fourt; TH2D *h_SumW46Fourt; TH2D *h_SumW48Fourt; TH2D *h_SumW410Fourt; TH2D *h_SumW2TwoW4Fourt; TH2D *h_SumW4FourW4Fourt;
TH2D *h_SumW6Sixt; TH2D *h_SumW26Sixt; TH2D *h_SumW46Sixt; TH2D *h_SumW66Sixt; TH2D *h_SumW68Sixt; TH2D *h_SumW610Sixt; TH2D *h_SumW2TwoW6Sixt; TH2D *h_SumW4FourW6Sixt; TH2D *h_SumW6SixW6Sixt;
TH2D *h_SumW8Eightt; TH2D *h_SumW28Eightt; TH2D *h_SumW48Eightt; TH2D *h_SumW68Eightt; TH2D *h_SumW88Eightt; TH2D *h_SumW810Eightt; TH2D *h_SumW2TwoW8Eightt; TH2D *h_SumW4FourW8Eightt; TH2D *h_SumW6SixW8Eightt; TH2D *h_SumW8EightW8Eightt;
TH2D *h_SumW10Tent; TH2D *h_SumW210Tent; TH2D *h_SumW410Tent;
TH2D *h_SumW610Tent; TH2D *h_SumW810Tent; TH2D *h_SumW1010Tent; TH2D *h_SumW2TwoW10Tent;
TH2D *h_SumW4FourW10Tent; TH2D *h_SumW6SixW10Tent; TH2D *h_SumW8EightW10Tent; TH2D *h_SumW10TenW10Tent;
TH2D *h_AveTwot; TH2D *h_AveFourt; TH2D *h_AveSixt; TH2D *h_AveEightt; TH2D *h_AveTent;
TH2D *h_VarAveTwot; TH2D *h_VarAveFourt; TH2D *h_VarAveSixt; TH2D *h_VarAveEightt; TH2D *h_VarAveTent;
TH2D *h_CovAveTwoAveFourt; TH2D *h_CovAveTwoAveSixt; TH2D *h_CovAveTwoAveEightt; TH2D *h_CovAveTwoAveTent; TH2D *h_CovAveFourAveSixt; TH2D *h_CovAveFourAveEightt; TH2D *h_CovAveFourAveTent; TH2D *h_CovAveSixAveEightt; TH2D *h_CovAveSixAveTent; TH2D *h_CovAveEightAveTent;
TH2D *h_CumTwot; TH2D *h_Two_vt; TH2D *h_ErrTwo_vt;
TH2D *h_CumFourt; TH2D *h_Four_vt; TH2D *h_ErrFour_vt;
TH2D *h_CumSixt; TH2D *h_Six_vt; TH2D *h_ErrSix_vt;
TH2D *h_CumEightt; TH2D *h_Eight_vt; TH2D *h_ErrEight_vt;
TH2D *h_CumTent; TH2D *h_Ten_vt; TH2D *h_ErrTen_vt;
//////
*/
      bool useCentrality_;

      edm::EDGetTokenT<int> centralitySrc_;
      edm::EDGetTokenT<reco::Centrality> tok_centSrc_;
      edm::EDGetTokenT<reco::VertexCollection> vertexSrc_;
      edm::EDGetTokenT<TrackCollection> tracksToken_;  //used to select what tracks to read from configuration file
      edm::EDGetTokenT<edm::View<pat::PackedCandidate>  > srcPFcand_;
      edm::InputTag chi2MapLabel_;
      edm::EDGetTokenT<edm::ValueMap<float>> chi2Map_;

      //std::vector<int> algoParameters_;
      bool applyVertexZCut_;
      double vertexZMax_, vertexZMin_;
      bool applyTrackCuts_;

      std::string qualityString_;
//      std::string effTable_;
      double dxyErrMax_;
      double dzErrMax_;
      double ptErrMax_;
      int    nhitsMin_;
      double chi2nMax_;
//      double chi2nMax_pixel_;
//      double dzErrMax_pixel_;
//      double dxyErrMax_pixel_;
//      float trkMva;


       Int_t Ntrk=0;
       //TrkEff2018PbPb trkEff =  TrkEff2018PbPb("general", false, "");

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
Qnana::Qnana(const edm::ParameterSet& iConfig)
 :
  useCentrality_(iConfig.getParameter<bool>("useCentrality")),
  centralitySrc_(consumes<int>(iConfig.getParameter<edm::InputTag>("centralitySrc"))),
  tok_centSrc_ (consumes<reco::Centrality>(iConfig.getParameter<edm::InputTag>("centralitySrc1"))),
  vertexSrc_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertexSrc"))),
  tracksToken_(consumes<TrackCollection>(iConfig.getUntrackedParameter<edm::InputTag>("TrackCollection"))),
  srcPFcand_(consumes<edm::View<pat::PackedCandidate> >(iConfig.getParameter<edm::InputTag>("srcPFcand"))),
  chi2MapLabel_(iConfig.getParameter<edm::InputTag>("chi2Map")),
  chi2Map_(consumes<edm::ValueMap<float>>(chi2MapLabel_)),
  //algoParameters_(iConfig.getParameter<std::vector<int> >("algoParameters")),
  applyVertexZCut_(iConfig.getParameter<bool>("applyVertexZCut")),
  vertexZMax_(iConfig.getParameter<double>("vertexZMax")),
  vertexZMin_(iConfig.getParameter<double>("vertexZMin")),
  applyTrackCuts_(iConfig.getParameter<bool>("applyTrackCuts")),
  qualityString_(iConfig.getParameter<std::string>("qualityString")),
  //effTable_(iConfig.getParameter<std::string>("effTable")),
  dxyErrMax_(iConfig.getParameter<double>("dxyErrMax")),
  dzErrMax_(iConfig.getParameter<double>("dzErrMax")),
  ptErrMax_(iConfig.getParameter<double>("ptErrMax")),
  nhitsMin_(iConfig.getParameter<int>("nhitsMin")),
  chi2nMax_(iConfig.getParameter<double>("chi2nMax"))

{
   //now do what ever initialization is needed
/*
 Q.resize(5), Q2.resize(5), Q3.resize(5), Q4.resize(5), Q5.resize(5);
 W2Two.resize(5), W4Four.resize(5), W6Six.resize(5), W8Eight.resize(5), W10Ten.resize(5);
 SumW2Two.resize(5), SumW22Two.resize(5), SumW24Two.resize(5), SumW26Two.resize(5), SumW28Two.resize(5), SumW210Two.resize(5), SumW2TwoW2Two.resize(5);
 SumW4Four.resize(5), SumW24Four.resize(5), SumW44Four.resize(5), SumW46Four.resize(5), SumW48Four.resize(5), SumW410Four.resize(5), SumW2TwoW4Four.resize(5), SumW4FourW4Four.resize(5);
 SumW6Six.resize(5), SumW26Six.resize(5), SumW46Six.resize(5), SumW66Six.resize(5), SumW68Six.resize(5), SumW610Six.resize(5), SumW2TwoW6Six.resize(5), SumW4FourW6Six.resize(5), SumW6SixW6Six.resize(5);
 SumW8Eight.resize(5), SumW28Eight.resize(5), SumW48Eight.resize(5), SumW68Eight.resize(5), SumW88Eight.resize(5), SumW810Eight.resize(5), SumW2TwoW8Eight.resize(5), SumW4FourW8Eight.resize(5), SumW6SixW8Eight.resize(5), SumW8EightW8Eight.resize(5);
 SumW10Ten.resize(5), SumW210Ten.resize(5), SumW410Ten.resize(5),
 SumW610Ten.resize(5), SumW810Ten.resize(5), SumW1010Ten.resize(5), SumW2TwoW10Ten.resize(5),
 SumW4FourW10Ten.resize(5), SumW6SixW10Ten.resize(5), SumW8EightW10Ten.resize(5), SumW10TenW10Ten.resize(5);
 AveTwo.resize(5), AveFour.resize(5), AveSix.resize(5), AveEight.resize(5), AveTen.resize(5);
 VarAveTwo.resize(5), VarAveFour.resize(5), VarAveSix.resize(5), VarAveEight.resize(5), VarAveTen.resize(5);
 CovAveTwoAveFour.resize(5), CovAveTwoAveSix.resize(5), CovAveTwoAveEight.resize(5), CovAveTwoAveTen.resize(5), CovAveFourAveSix.resize(5), CovAveFourAveEight.resize(5), CovAveFourAveTen.resize(5), CovAveSixAveEight.resize(5), CovAveSixAveTen.resize(5), CovAveEightAveTen.resize(5);
 CumTwo.resize(5), Two_v.resize(5), ErrTwo_v.resize(5);
 CumFour.resize(5), Four_v.resize(5), ErrFour_v.resize(5);
 CumSix.resize(5), Six_v.resize(5), ErrSix_v.resize(5);
 CumEight.resize(5), Eight_v.resize(5), ErrEight_v.resize(5);
 CumTen.resize(5), Ten_v.resize(5), ErrTen_v.resize(5);
 W2.resize(16), W22.resize(16), W24.resize(16), W26.resize(16), W28.resize(16), W210.resize(16), W4.resize(16), W44.resize(16), W46.resize(16), W48.resize(16), W410.resize(16), W6.resize(16), W66.resize(16), W68.resize(16), W610.resize(16), W8.resize(16), W88.resize(16), W810.resize(16), W10.resize(16), W1010.resize(16);

//efficiency
 Qt.resize(5), Qt_3.resize(5), Qt_5.resize(5), Qt_7.resize(5), Qt_9.resize(5), Qt2.resize(5), Qt2_4.resize(5), Qt2_6.resize(5), Qt2_8.resize(5), Qt3.resize(5), Qt3_5.resize(5), Qt3_7.resize(5), Qt4.resize(5), Qt4_6.resize(5), Qt5.resize(5); 
 W2Twot.resize(5), W4Fourt.resize(5), W6Sixt.resize(5), W8Eightt.resize(5), W10Tent.resize(5);
 SumW2Twot.resize(5), SumW22Twot.resize(5), SumW24Twot.resize(5), SumW26Twot.resize(5), SumW28Twot.resize(5), SumW210Twot.resize(5), SumW2TwoW2Twot.resize(5);
 SumW4Fourt.resize(5), SumW24Fourt.resize(5), SumW44Fourt.resize(5), SumW46Fourt.resize(5), SumW48Fourt.resize(5), SumW410Fourt.resize(5), SumW2TwoW4Fourt.resize(5), SumW4FourW4Fourt.resize(5);
 SumW6Sixt.resize(5), SumW26Sixt.resize(5), SumW46Sixt.resize(5), SumW66Sixt.resize(5), SumW68Sixt.resize(5), SumW610Sixt.resize(5), SumW2TwoW6Sixt.resize(5), SumW4FourW6Sixt.resize(5), SumW6SixW6Sixt.resize(5);
 SumW8Eightt.resize(5), SumW28Eightt.resize(5), SumW48Eightt.resize(5), SumW68Eightt.resize(5), SumW88Eightt.resize(5), SumW810Eightt.resize(5), SumW2TwoW8Eightt.resize(5), SumW4FourW8Eightt.resize(5), SumW6SixW8Eightt.resize(5), SumW8EightW8Eightt.resize(5);
 SumW10Tent.resize(5), SumW210Tent.resize(5), SumW410Tent.resize(5),
 SumW610Tent.resize(5), SumW810Tent.resize(5), SumW1010Tent.resize(5), SumW2TwoW10Tent.resize(5),
 SumW4FourW10Tent.resize(5), SumW6SixW10Tent.resize(5), SumW8EightW10Tent.resize(5), SumW10TenW10Tent.resize(5);
 AveTwot.resize(5), AveFourt.resize(5), AveSixt.resize(5), AveEightt.resize(5), AveTent.resize(5);
 VarAveTwot.resize(5), VarAveFourt.resize(5), VarAveSixt.resize(5), VarAveEightt.resize(5), VarAveTent.resize(5);
 CovAveTwoAveFourt.resize(5), CovAveTwoAveSixt.resize(5), CovAveTwoAveEightt.resize(5), CovAveTwoAveTent.resize(5), CovAveFourAveSixt.resize(5), CovAveFourAveEightt.resize(5), CovAveFourAveTent.resize(5), CovAveSixAveEightt.resize(5), CovAveSixAveTent.resize(5), CovAveEightAveTent.resize(5);
 CumTwot.resize(5), Two_vt.resize(5), ErrTwo_vt.resize(5);
 CumFourt.resize(5), Four_vt.resize(5), ErrFour_vt.resize(5);
 CumSixt.resize(5), Six_vt.resize(5), ErrSix_vt.resize(5);
 CumEightt.resize(5), Eight_vt.resize(5), ErrEight_vt.resize(5);
 CumTent.resize(5), Ten_vt.resize(5), ErrTen_vt.resize(5);

 Mt.resize(16), Mt2.resize(16), M2t.resize(16), M2t2.resize(16), MM2t.resize(16), M3t.resize(16), M3t2.resize(16), MM3t.resize(16), M2M3t.resize(16), M4t.resize(16), M4t2.resize(16), MM4t.resize(16), M2M4t.resize(16), M3M4t.resize(16), M5t.resize(16), M5t2.resize(16), MM5t.resize(16), M2M5t.resize(16), M3M5t.resize(16), M4M5t.resize(16);

 S11.resize(16), S12.resize(16), S13.resize(16), S14.resize(16), S15.resize(16), S16.resize(16), S17.resize(16), S18.resize(16), S19.resize(16), S110.resize(16);
 S21.resize(16), S22.resize(16), S23.resize(16), S24.resize(16), S25.resize(16);
 S31.resize(16), S32.resize(16), S33.resize(16);
 S41.resize(16), S42.resize(16);
 S51.resize(16), S52.resize(16);
 S61.resize(16);
 S71.resize(16);
 S81.resize(16);
 S101.resize(16);
////


  for (Int_t k=0; k<5; k++){ //over multiplicity bins
 Q[k].resize(16), Q2[k].resize(16), Q3[k].resize(16), Q4[k].resize(16), Q5[k].resize(16);
 W2Two[k].resize(16), W4Four[k].resize(16), W6Six[k].resize(16), W8Eight[k].resize(16), W10Ten[k].resize(16);
 SumW2Two[k].resize(16), SumW22Two[k].resize(16), SumW24Two[k].resize(16), SumW26Two[k].resize(16), SumW28Two[k].resize(16), SumW210Two[k].resize(16), SumW2TwoW2Two[k].resize(16);
 SumW4Four[k].resize(16), SumW24Four[k].resize(16), SumW44Four[k].resize(16), SumW46Four[k].resize(16), SumW48Four[k].resize(16), SumW410Four[k].resize(16), SumW2TwoW4Four[k].resize(16), SumW4FourW4Four[k].resize(16);
 SumW6Six[k].resize(16), SumW26Six[k].resize(16), SumW46Six[k].resize(16), SumW66Six[k].resize(16), SumW68Six[k].resize(16), SumW610Six[k].resize(16), SumW2TwoW6Six[k].resize(16), SumW4FourW6Six[k].resize(16), SumW6SixW6Six[k].resize(16);
 SumW8Eight[k].resize(16), SumW28Eight[k].resize(16), SumW48Eight[k].resize(16), SumW68Eight[k].resize(16), SumW88Eight[k].resize(16), SumW810Eight[k].resize(16), SumW2TwoW8Eight[k].resize(16), SumW4FourW8Eight[k].resize(16), SumW6SixW8Eight[k].resize(16), SumW8EightW8Eight[k].resize(16);
 SumW10Ten[k].resize(16), SumW210Ten[k].resize(16), SumW410Ten[k].resize(16),
 SumW610Ten[k].resize(16), SumW810Ten[k].resize(16), SumW1010Ten[k].resize(16), SumW2TwoW10Ten[k].resize(16),
 SumW4FourW10Ten[k].resize(16), SumW6SixW10Ten[k].resize(16), SumW8EightW10Ten[k].resize(16), SumW10TenW10Ten[k].resize(16);
 AveTwo[k].resize(16), AveFour[k].resize(16), AveSix[k].resize(16), AveEight[k].resize(16), AveTen[k].resize(16);
 VarAveTwo[k].resize(16), VarAveFour[k].resize(16), VarAveSix[k].resize(16), VarAveEight[k].resize(16), VarAveTen[k].resize(16);
 CovAveTwoAveFour[k].resize(16), CovAveTwoAveSix[k].resize(16), CovAveTwoAveEight[k].resize(16), CovAveTwoAveTen[k].resize(16), CovAveFourAveSix[k].resize(16), CovAveFourAveEight[k].resize(16), CovAveFourAveTen[k].resize(16), CovAveSixAveEight[k].resize(16), CovAveSixAveTen[k].resize(16), CovAveEightAveTen[k].resize(16);
 CumTwo[k].resize(16), Two_v[k].resize(16), ErrTwo_v[k].resize(16);
 CumFour[k].resize(16), Four_v[k].resize(16), ErrFour_v[k].resize(16);
 CumSix[k].resize(16), Six_v[k].resize(16), ErrSix_v[k].resize(16);
 CumEight[k].resize(16), Eight_v[k].resize(16), ErrEight_v[k].resize(16);
 CumTen[k].resize(16), Ten_v[k].resize(16), ErrTen_v[k].resize(16);

//efficiancy
 Qt[k].resize(16), Qt_3[k].resize(16), Qt_5[k].resize(16), Qt_7[k].resize(16), Qt_9[k].resize(16), Qt2[k].resize(16), Qt2_4[k].resize(16), Qt2_6[k].resize(16), Qt2_8[k].resize(16), Qt3[k].resize(16), Qt3_5[k].resize(16), Qt3_7[k].resize(16), Qt4[k].resize(16), Qt4_6[k].resize(16), Qt5[k].resize(16);
 W2Twot[k].resize(16), W4Fourt[k].resize(16), W6Sixt[k].resize(16), W8Eightt[k].resize(16), W10Tent[k].resize(16);
 SumW2Twot[k].resize(16), SumW22Twot[k].resize(16), SumW24Twot[k].resize(16), SumW26Twot[k].resize(16), SumW28Twot[k].resize(16), SumW210Twot[k].resize(16), SumW2TwoW2Twot[k].resize(16);
 SumW4Fourt[k].resize(16), SumW24Fourt[k].resize(16), SumW44Fourt[k].resize(16), SumW46Fourt[k].resize(16), SumW48Fourt[k].resize(16), SumW410Fourt[k].resize(16), SumW2TwoW4Fourt[k].resize(16), SumW4FourW4Fourt[k].resize(16);
 SumW6Sixt[k].resize(16), SumW26Sixt[k].resize(16), SumW46Sixt[k].resize(16), SumW66Sixt[k].resize(16), SumW68Sixt[k].resize(16), SumW610Sixt[k].resize(16), SumW2TwoW6Sixt[k].resize(16), SumW4FourW6Sixt[k].resize(16), SumW6SixW6Sixt[k].resize(16);
 SumW8Eightt[k].resize(16), SumW28Eightt[k].resize(16), SumW48Eightt[k].resize(16), SumW68Eightt[k].resize(16), SumW88Eightt[k].resize(16), SumW810Eightt[k].resize(16), SumW2TwoW8Eightt[k].resize(16), SumW4FourW8Eightt[k].resize(16), SumW6SixW8Eightt[k].resize(16), SumW8EightW8Eightt[k].resize(16);
 SumW10Tent[k].resize(16), SumW210Tent[k].resize(16), SumW410Tent[k].resize(16),
 SumW610Tent[k].resize(16), SumW810Tent[k].resize(16), SumW1010Tent[k].resize(16), SumW2TwoW10Tent[k].resize(16),
 SumW4FourW10Tent[k].resize(16), SumW6SixW10Tent[k].resize(16), SumW8EightW10Tent[k].resize(16), SumW10TenW10Tent[k].resize(16);
 AveTwot[k].resize(16), AveFourt[k].resize(16), AveSixt[k].resize(16), AveEightt[k].resize(16), AveTent[k].resize(16);
 VarAveTwot[k].resize(16), VarAveFourt[k].resize(16), VarAveSixt[k].resize(16), VarAveEightt[k].resize(16), VarAveTent[k].resize(16);
 CovAveTwoAveFourt[k].resize(16), CovAveTwoAveSixt[k].resize(16), CovAveTwoAveEightt[k].resize(16), CovAveTwoAveTent[k].resize(16), CovAveFourAveSixt[k].resize(16), CovAveFourAveEightt[k].resize(16), CovAveFourAveTent[k].resize(16), CovAveSixAveEightt[k].resize(16), CovAveSixAveTent[k].resize(16), CovAveEightAveTent[k].resize(16);
 CumTwot[k].resize(16), Two_vt[k].resize(16), ErrTwo_vt[k].resize(16);
 CumFourt[k].resize(16), Four_vt[k].resize(16), ErrFour_vt[k].resize(16);
 CumSixt[k].resize(16), Six_vt[k].resize(16), ErrSix_vt[k].resize(16);
 CumEightt[k].resize(16), Eight_vt[k].resize(16), ErrEight_vt[k].resize(16);
 CumTent[k].resize(16), Ten_vt[k].resize(16), ErrTen_vt[k].resize(16);

////


  }


  for (Int_t l=0; l<16; l++){ //over multiplicity bins

      multEv[l] = 0;

   W2[l]=0.0, W22[l]=0.0, W24[l]=0.0, W26[l]=0.0, W28[l]=0.0, W210[l]=0.0, W4[l]=0.0, W44[l]=0.0, W46[l]=0.0, W48[l]=0.0, W410[l]=0.0, W6[l]=0.0, W66[l]=0.0, W68[l]=0.0, W610[l]=0.0, W8[l]=0.0, W88[l]=0.0, W810[l]=0.0, W10[l]=0.0, W1010[l]=0.0;

//efficancy
  Mt[l]=0.0, Mt2[l]=0.0, M2t[l]=0.0, M2t2[l]=0.0, MM2t[l]=0.0, M3t[l]=0.0, M3t2[l]=0.0, MM3t[l]=0.0, M2M3t[l]=0.0, M4t[l]=0.0, M4t2[l]=0.0, MM4t[l]=0.0, M2M4t[l]=0.0, M3M4t[l]=0.0, M5t[l]=0.0, M5t2[l]=0.0, MM5t[l]=0.0, M2M5t[l]=0.0, M3M5t[l]=0.0, M4M5t[l]=0.0;

 S11[l]=0.0, S12[l]=0.0, S13[l]=0.0, S14[l]=0.0, S15[l]=0.0, S16[l]=0.0, S17[l]=0.0, S18[l]=0.0, S19[l]=0.0, S110[l]=0.0;
 S21[l]=0.0, S22[l]=0.0, S23[l]=0.0, S24[l]=0.0, S25[l]=0.0;
 S31[l]=0.0, S32[l]=0.0, S33[l]=0.0;
 S41[l]=0.0, S42[l]=0.0;
 S51[l]=0.0, S52[l]=0.0;
 S61[l]=0.0;
 S71[l]=0.0;
 S81[l]=0.0;
 S101[l]=0.0;
////

   for (Int_t k=0; k<5; k++){ //over harmonics
     SumW2Two[k][l]=0.0, SumW22Two[k][l]=0.0, SumW24Two[k][l]=0.0, SumW26Two[k][l]=0.0, SumW28Two[k][l]=0.0, SumW210Two[k][l]=0.0, SumW2TwoW2Two[k][l]=0.0;
     SumW4Four[k][l]=0.0, SumW24Four[k][l]=0.0, SumW44Four[k][l]=0.0, SumW46Four[k][l]=0.0, SumW48Four[k][l]=0.0, SumW410Four[k][l]=0.0, SumW2TwoW4Four[k][l]=0.0, SumW4FourW4Four[k][l]=0.0;
     SumW6Six[k][l]=0.0, SumW26Six[k][l]=0.0, SumW46Six[k][l]=0.0, SumW66Six[k][l]=0.0, SumW68Six[k][l]=0.0, SumW610Six[k][l]=0.0, SumW2TwoW6Six[k][l]=0.0, SumW4FourW6Six[k][l]=0.0, SumW6SixW6Six[k][l]=0.0;
     SumW8Eight[k][l]=0.0, SumW28Eight[k][l]=0.0, SumW48Eight[k][l]=0.0, SumW68Eight[k][l]=0.0, SumW88Eight[k][l]=0.0, SumW810Eight[k][l]=0.0, SumW2TwoW8Eight[k][l]=0.0, SumW4FourW8Eight[k][l]=0.0, SumW6SixW8Eight[k][l]=0.0, SumW8EightW8Eight[k][l]=0.0;
     SumW10Ten[k][l]=0.0, SumW210Ten[k][l]=0.0, SumW410Ten[k][l]=0.0, SumW610Ten[k][l]=0.0, SumW810Ten[k][l]=0.0, SumW1010Ten[k][l]=0.0, SumW2TwoW10Ten[k][l]=0.0, SumW4FourW10Ten[k][l]=0.0, SumW6SixW10Ten[k][l]=0.0, SumW8EightW10Ten[k][l]=0.0, SumW10TenW10Ten[k][l]=0.0;

//eff
     SumW2Twot[k][l]=0.0, SumW22Twot[k][l]=0.0, SumW24Twot[k][l]=0.0, SumW26Twot[k][l]=0.0, SumW28Twot[k][l]=0.0, SumW210Twot[k][l]=0.0, SumW2TwoW2Twot[k][l]=0.0;
     SumW4Fourt[k][l]=0.0, SumW24Fourt[k][l]=0.0, SumW44Fourt[k][l]=0.0, SumW46Fourt[k][l]=0.0, SumW48Fourt[k][l]=0.0, SumW410Fourt[k][l]=0.0, SumW2TwoW4Fourt[k][l]=0.0, SumW4FourW4Fourt[k][l]=0.0;
     SumW6Sixt[k][l]=0.0, SumW26Sixt[k][l]=0.0, SumW46Sixt[k][l]=0.0, SumW66Sixt[k][l]=0.0, SumW68Sixt[k][l]=0.0, SumW610Sixt[k][l]=0.0, SumW2TwoW6Sixt[k][l]=0.0, SumW4FourW6Sixt[k][l]=0.0, SumW6SixW6Sixt[k][l]=0.0;
     SumW8Eightt[k][l]=0.0, SumW28Eightt[k][l]=0.0, SumW48Eightt[k][l]=0.0, SumW68Eightt[k][l]=0.0, SumW88Eightt[k][l]=0.0, SumW810Eightt[k][l]=0.0, SumW2TwoW8Eightt[k][l]=0.0, SumW4FourW8Eightt[k][l]=0.0, SumW6SixW8Eightt[k][l]=0.0, SumW8EightW8Eightt[k][l]=0.0;
     SumW10Tent[k][l]=0.0, SumW210Tent[k][l]=0.0, SumW410Tent[k][l]=0.0, SumW610Tent[k][l]=0.0, SumW810Tent[k][l]=0.0, SumW1010Tent[k][l]=0.0, SumW2TwoW10Tent[k][l]=0.0, SumW4FourW10Tent[k][l]=0.0, SumW6SixW10Tent[k][l]=0.0, SumW8EightW10Tent[k][l]=0.0, SumW10TenW10Tent[k][l]=0.0;
//////
   }
 }
*/
   edm::Service<TFileService> fs;
   initHistos(fs);


}


Qnana::~Qnana()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
Qnana::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace reco;
   using namespace std;

//   TrkEff2018PbPb trkEff =  TrkEff2018PbPb("general", false, "");

/*
  Double_t pT;
  Double_t eta;
  Double_t pT_ref[maxmult]; 
  //Double_t weight[maxmult];
  Double_t M=0;
  Double_t Ntr=0;
  //Int_t Mi=0;
*/
  Double_t HFsumET;

   int occ=0;
   int cbin=0;
   if( useCentrality_ )
   {
     edm::Handle<reco::Centrality> cent;
     iEvent.getByToken(tok_centSrc_, cent);

     edm::Handle<int> centralityBin;
     iEvent.getByToken(centralitySrc_, centralityBin);
     cbin = *centralityBin;
     occ = cbin;
     //if ( occ < centMin_*2 || occ >= centMax_*2 ) return;
     HFsumET = cent->EtHFtowerSum();
     if (HFsumET > 5199.95) return; 
     centDefault = occ; 
     centNominal = 200 - h_hiHF->FindBin(HFsumET);
     centDown    = 200 - h_hiHFdown->FindBin(HFsumET);
     centUp      = 200 - h_hiHFup->FindBin(HFsumET);
   //  cout<<occ <<" " <<cbin<<endl;
     //if ( occ >= 180 ) return;
   }
   //if (occ <60 || occ>=70) return;

   Handle<reco::VertexCollection> vertex;
   iEvent.getByToken(vertexSrc_, vertex);
   VertexCollection vsorted = *vertex;
   const VertexCollection *recoV = vertex.product();
   std::sort( vsorted.begin(), vsorted.end(), Qnana::vtxSort );
   if( vsorted.size() == 0) return;
   if( applyVertexZCut_)
   {
     if( fabs(vsorted[0].z()) > vertexZMax_ ) return;
     if( fabs(vsorted[0].z()) < vertexZMin_ ) return;
   }
   //std::cout<<"z position = "<<vsorted[0].z()<<endl;
   VertexCompositeNtuple->Fill();
        
/*
   edm::Handle<edm::View<pat::PackedCandidate>> pfCandidates;
   iEvent.getByToken(srcPFcand_,pfCandidates);

   edm::Handle<edm::ValueMap<float>> chi2Map;
   iEvent.getByToken(chi2Map_,chi2Map);

//    Handle<TrackCollection> tracks;
//    iEvent.getByToken(tracksToken_, tracks);
//    for(TrackCollection::const_iterator itTrack = tracks->begin();
//        itTrack != tracks->end();
//        ++itTrack) {
    for(unsigned int i = 0, n = pfCandidates->size(); i < n; ++i){
     const pat::PackedCandidate &pf = (*pfCandidates)[i];
      if(!(pf.hasTrackDetails()))continue;
       const reco::Track  &itTrack = pf.pseudoTrack();

	pT = itTrack.pt();
	eta = itTrack.eta();
        double chi2n=(*chi2Map)[pfCandidates->ptrAt(i)];
	if (pT>3.0) continue;
        if (pT<0.5) continue;
        if (fabs(eta)>2.4) continue;
        if ( itTrack.charge() == 0  ) continue;
        if ( ! passesTrackCuts(itTrack, vsorted, chi2n) ) continue;
        weight[int(Ntr)] = trkEff.getCorrection(itTrack.pt(), itTrack.eta(), occ);
	eff_ref[int(Ntr)] = 1.0/trkEff.getCorrection(itTrack.pt(), itTrack.eta(), occ);
	//eff_ref[int(Ntr)] = 0.6;
	phi_ref[int(Ntr)] = itTrack.phi();

        //pT_ref[int(Ntr)] = itTrack->pt();
	//if (itTrack.ptError()/pT>0.1) std::cout <<" eta = "<<eta<<" "<<itTrack.ptError()/pT<<" "<<phi_ref<<std::endl;
	M++;//=weight[int(Ntr)];
	//if (occ > 120) 
	//cout<<" eff check "<<weight[int(Ntr)]<<" "<<occ<<endl;
	Ntr++;
    }

        Ntrk=Ntr;
	//VertexCompositeNtuple->Fill();
	if (Ntr <11) return;
	int l =0;
	l = occ/2/5;

       multEv[l]++;
     //std::cout <<W22[l]<<std::endl;
       W2[l] += M*(M-1); 
       W22[l] += M*(M-1)*M*(M-1); W24[l] += M*(M-1)*M*(M-1)*(M-2)*(M-3); W26[l] += M*(M-1)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5); W28[l] += M*(M-1)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7); W210[l] += M*(M-1)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9);
       W4[l] += M*(M-1)*(M-2)*(M-3); W44[l] += M*(M-1)*(M-2)*(M-3)*M*(M-1)*(M-2)*(M-3); W46[l] += M*(M-1)*(M-2)*(M-3)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5); W48[l] += M*(M-1)*(M-2)*(M-3)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7); W410[l] += M*(M-1)*(M-2)*(M-3)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9);
       W6[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5); W66[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5); W68[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7); W610[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9);
       W8[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7); W88[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7); W810[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9);
       W10[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9); W1010[l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9)*M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9);
  
       for (Int_t k=0; k<5; k++){//over harmonics
	 Q[k][l]=std::complex(0.0,0.0), Q2[k][l]=std::complex(0.0,0.0), Q3[k][l]=std::complex(0.0,0.0), Q4[k][l]=std::complex(0.0,0.0), Q5[k][l]=std::complex(0.0,0.0);
	 Qt[k][l]=std::complex(0.0,0.0), Qt_3[k][l]=std::complex(0.0,0.0), Qt_5[k][l]=std::complex(0.0,0.0), Qt_7[k][l]=std::complex(0.0,0.0), Qt_9[k][l]=std::complex(0.0,0.0), Qt2[k][l]=std::complex(0.0,0.0), Qt2_4[k][l]=std::complex(0.0,0.0), Qt2_6[k][l]=std::complex(0.0,0.0), Qt2_8[k][l]=std::complex(0.0,0.0), Qt3[k][l]=std::complex(0.0,0.0), Qt3_5[k][l]=std::complex(0.0,0.0), Qt3_7[k][l]=std::complex(0.0,0.0), Qt4[k][l]=std::complex(0.0,0.0), Qt4_6[k][l]=std::complex(0.0,0.0), Qt5[k][l]=std::complex(0.0,0.0);
       }

     S11[l]=0.0, S12[l]=0.0, S13[l]=0.0, S14[l]=0.0, S15[l]=0.0, S16[l]=0.0, S17[l]=0.0, S18[l]=0.0, S19[l]=0.0, S110[l]=0.0;
     S21[l]=0.0, S22[l]=0.0, S23[l]=0.0, S24[l]=0.0, S25[l]=0.0;
     S31[l]=0.0, S32[l]=0.0, S33[l]=0.0;
     S41[l]=0.0, S42[l]=0.0;
     S51[l]=0.0, S52[l]=0.0;
     S61[l]=0.0;
     S71[l]=0.0;
     S81[l]=0.0;
     S101[l]=0.0;

//efficiancy
       for (Int_t j=0; j<Ntr; j++){
	 S11[l] += 1.0/eff_ref[j];
	 S12[l] += pow(1.0/eff_ref[j],2);
	 S13[l] += pow(1.0/eff_ref[j],3);
	 S14[l] += pow(1.0/eff_ref[j],4);
	 S15[l] += pow(1.0/eff_ref[j],5);
	 S16[l] += pow(1.0/eff_ref[j],6);
	 S17[l] += pow(1.0/eff_ref[j],7);
	 S18[l] += pow(1.0/eff_ref[j],8);
	 S19[l] += pow(1.0/eff_ref[j],9);
	 S110[l] += pow(1.0/eff_ref[j],10);
	 S21[l] += 1.0/eff_ref[j];
	 S22[l] += pow(1.0/eff_ref[j],2);
	 S23[l] += pow(1.0/eff_ref[j],3);
	 S24[l] += pow(1.0/eff_ref[j],4);
	 S25[l] += pow(1.0/eff_ref[j],5);
	 S31[l] += 1.0/eff_ref[j];
	 S32[l] += pow(1.0/eff_ref[j],2);
	 S33[l] += pow(1.0/eff_ref[j],3);
	 S41[l] += 1.0/eff_ref[j];
	 S42[l] += pow(1.0/eff_ref[j],2);
	 S51[l] += 1.0/eff_ref[j];
	 S52[l] += pow(1.0/eff_ref[j],2);
	 S61[l] += 1.0/eff_ref[j];
	 S71[l] += 1.0/eff_ref[j];
	 S81[l] += 1.0/eff_ref[j];
	 S101[l] += 1.0/eff_ref[j];
	 
	 for (Int_t k=0; k<5; k++){
           Q[k][l] += exp(std::complex(0.0, (k+1)*phi_ref[j]));
           Q2[k][l] += exp(std::complex(0.0, 2*(k+1)*phi_ref[j]));
           Q3[k][l] += exp(std::complex(0.0, 3*(k+1)*phi_ref[j]));
           Q4[k][l] += exp(std::complex(0.0, 4*(k+1)*phi_ref[j]));
           Q5[k][l] += exp(std::complex(0.0, 5*(k+1)*phi_ref[j]));

           Qt[k][l] += exp(std::complex(0.0, (k+1)*phi_ref[j]))/eff_ref[j];
           Qt_3[k][l] += exp(std::complex(0.0, (k+1)*phi_ref[j]))/pow(eff_ref[j],3);
           Qt_5[k][l] += exp(std::complex(0.0, (k+1)*phi_ref[j]))/pow(eff_ref[j],5);
           Qt_7[k][l] += exp(std::complex(0.0, (k+1)*phi_ref[j]))/pow(eff_ref[j],7);
           Qt_9[k][l] += exp(std::complex(0.0, (k+1)*phi_ref[j]))/pow(eff_ref[j],9);
           Qt2[k][l] += exp(std::complex(0.0, 2*(k+1)*phi_ref[j]))/pow(eff_ref[j],2);
           Qt2_4[k][l] += exp(std::complex(0.0, 2*(k+1)*phi_ref[j]))/pow(eff_ref[j],4);
           Qt2_6[k][l] += exp(std::complex(0.0, 2*(k+1)*phi_ref[j]))/pow(eff_ref[j],6);
           Qt2_8[k][l] += exp(std::complex(0.0, 2*(k+1)*phi_ref[j]))/pow(eff_ref[j],8);
           Qt3[k][l] += exp(std::complex(0.0, 3*(k+1)*phi_ref[j]))/pow(eff_ref[j],3);
           Qt3_5[k][l] += exp(std::complex(0.0, 3*(k+1)*phi_ref[j]))/pow(eff_ref[j],5);
           Qt3_7[k][l] += exp(std::complex(0.0, 3*(k+1)*phi_ref[j]))/pow(eff_ref[j],7);
           Qt4[k][l] += exp(std::complex(0.0, 4*(k+1)*phi_ref[j]))/pow(eff_ref[j],4);
           Qt4_6[k][l] += exp(std::complex(0.0, 4*(k+1)*phi_ref[j]))/pow(eff_ref[j],6);
           Qt5[k][l] += exp(std::complex(0.0, 5*(k+1)*phi_ref[j]))/pow(eff_ref[j],5);

	 }
       }

       Mt[l] += S21[l]*S21[l] - S12[l];
       Mt2[l] += pow(S21[l]*S21[l] - S12[l],2.0);

       //std::cout<<" S21 = "<<S21[l] << " S12 = "<<S12[l]<<" Mt = "<<Mt[l]<<std::endl;
       
       M2t[l] += pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l];
       M2t2[l] += pow(pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l],2.0);
       MM2t[l] += (S21[l]*S21[l] - S12[l])*(pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l]);
       
       M3t[l] += pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l];
       M3t2[l] +=  pow(pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l],2.0);
       MM3t[l] += (S21[l]*S21[l] - S12[l])*(pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l]);
       M2M3t[l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*(pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l]);
       
       M4t[l] += 1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8);
       M4t2[l] += pow(1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8),2.0);
       MM4t[l] += (S21[l]*S21[l] - S12[l])*(1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8));
       M2M4t[l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*(1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8));
       M3M4t[l] += (pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l])*(1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8));
       
       M5t[l] += 22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l];
       M5t2[l] += pow(22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l],2.0);
       MM5t[l] += (S21[l]*S21[l] - S12[l])*(22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l]);
       M2M5t[l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*(22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l]);
       M3M5t[l] += (pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l])*(22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l]);
       M4M5t[l] += (1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8))*(22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l]);
////      

       for (Int_t k=0; k<5; k++){//over harmonics
	 W2Twot[k][l] = abs(Qt[k][l]*conj(Qt[k][l]))-S12[l];
	 W2Two[k][l] = abs(Q[k][l]*conj(Q[k][l]))-M;
	 SumW2Twot[k][l] += W2Twot[k][l];
	 SumW2Two[k][l] += W2Two[k][l];
	 SumW22Two[k][l] += M*(M-1)*W2Two[k][l];
	 SumW22Twot[k][l] += (S21[l]*S21[l] - S12[l])*W2Twot[k][l];
	 SumW24Two[k][l] += M*(M-1)*(M-2)*(M-3)*W2Two[k][l];
	 SumW24Twot[k][l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*W2Twot[k][l];
	 SumW26Two[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*W2Two[k][l];
	 SumW26Twot[k][l] += (pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l])*W2Twot[k][l];
	 SumW28Two[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*W2Two[k][l];
	 SumW28Twot[k][l] += (1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8))*W2Twot[k][l];
	 SumW210Two[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9)*W2Two[k][l];
	 SumW210Twot[k][l] += (22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l])*W2Twot[k][l];
	 SumW2TwoW2Two[k][l] += pow(W2Two[k][l],2);
	 SumW2TwoW2Twot[k][l] += pow(W2Twot[k][l],2);

	 W4Fourt[k][l] = pow(abs(Qt[k][l]*conj(Qt[k][l])),2) + abs(Qt2[k][l]*conj(Qt2[k][l])) - 2*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])) + 8*real(Qt_3[k][l]*conj(Qt[k][l])) - 4*S12[l]*abs(Qt[k][l]*conj(Qt[k][l])) - 6*S14[l] + 2*pow(S22[l],2);
	 W4Four[k][l] = pow(abs(Q[k][l]*conj(Q[k][l])),2) + abs(Q2[k][l]*conj(Q2[k][l])) - 2*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) - 4*(M-2)*abs(Q[k][l]*conj(Q[k][l])) + 2*M*(M-3);
	 SumW4Fourt[k][l] += W4Fourt[k][l];
	 SumW4Four[k][l] += W4Four[k][l];
	 SumW24Four[k][l] += M*(M-1)*W4Four[k][l];
	 SumW24Fourt[k][l] += (S21[l]*S21[l] - S12[l])*W4Fourt[k][l];
	 SumW44Four[k][l] += M*(M-1)*(M-2)*(M-3)*W4Four[k][l];
	 SumW44Fourt[k][l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*W4Fourt[k][l];
	 SumW46Four[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*W4Four[k][l];
	 SumW46Fourt[k][l] += (pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l])*W4Fourt[k][l];
	 SumW48Four[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*W4Four[k][l];
	 SumW48Fourt[k][l] += (1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8))*W4Fourt[k][l];
	 SumW410Four[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9)*W4Four[k][l];
	 SumW410Fourt[k][l] += (22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l])*W4Fourt[k][l];
	 SumW2TwoW4Four[k][l] += W2Two[k][l]*W4Four[k][l];
	 SumW2TwoW4Fourt[k][l] += W2Twot[k][l]*W4Fourt[k][l];
	 SumW4FourW4Four[k][l] += pow(W4Four[k][l],2);
	 SumW4FourW4Fourt[k][l] += pow(W4Fourt[k][l],2);

	 W6Sixt[k][l] = pow(abs(Qt[k][l]*conj(Qt[k][l])),3) - 6*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 9*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt2[k][l]*conj(Qt2[k][l])) - 9*S12[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)
	   + 18*S12[l]*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])) - 9*S12[l]*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 18*pow(S22[l],2)*abs(Qt[k][l]*conj(Qt[k][l])) - 6*pow(S32[l],3) + 4*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 12*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l])) + 4*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   + 36*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l])) - 36*real(Qt_3[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   - 72*S12[l]*real(Qt_3[k][l]*conj(Qt[k][l])) + 36*abs(Qt_3[k][l]*conj(Qt_3[k][l])) - 36*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 36*real(Qt2_4[k][l]*conj(Qt2[k][l])) - 54*S14[l]*abs(Qt[k][l]*conj(Qt[k][l])) + 54*S12[l]*S14[l]
	   + 144*real(Qt_5[k][l]*conj(Qt[k][l])) - 120*S16[l];
	 W6Six[k][l] = pow(abs(Q[k][l]*conj(Q[k][l])),3) + 9*abs(Q2[k][l]*conj(Q2[k][l]))*abs(Q[k][l]*conj(Q[k][l])) - 6*real(Q2[k][l]*abs(Q[k][l]*conj(Q[k][l]))*conj(Q[k][l])*conj(Q[k][l])) + 4*(real(Q3[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) - 3*real(Q3[k][l]*conj(Q2[k][l])*conj(Q[k][l]))) + 2*(9*(M-4)*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) + 2*abs(Q3[k][l]*conj(Q3[k][l]))) - 9*(M-4)*(pow(abs(Q[k][l]*conj(Q[k][l])),2) + abs(Q2[k][l]*conj(Q2[k][l]))) + 18*(M-2)*(M-5)*abs(Q[k][l]*conj(Q[k][l])) - 6*M*(M-4)*(M-5);

	 SumW6Sixt[k][l] += W6Sixt[k][l];
	 SumW6Six[k][l] += W6Six[k][l];
	 SumW26Six[k][l] += M*(M-1)*W6Six[k][l];
	 SumW26Sixt[k][l] += (S21[l]*S21[l] - S12[l])*W6Sixt[k][l];
	 SumW46Six[k][l] += M*(M-1)*(M-2)*(M-3)*W6Six[k][l];
	 SumW46Sixt[k][l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*W6Sixt[k][l];
	 SumW66Six[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*W6Six[k][l];
	 SumW66Sixt[k][l] += (pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l])*W6Sixt[k][l];
	 SumW68Six[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*W6Six[k][l];
	 SumW68Sixt[k][l] += (1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8))*W6Sixt[k][l];
	 SumW610Six[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9)*W6Six[k][l];
	 SumW610Sixt[k][l] += (22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l])*W6Sixt[k][l];
	 SumW2TwoW6Six[k][l] += W2Two[k][l]*W6Six[k][l];
	 SumW2TwoW6Sixt[k][l] += W2Twot[k][l]*W6Sixt[k][l];
	 SumW4FourW6Six[k][l] += W4Four[k][l]*W6Six[k][l];
	 SumW4FourW6Sixt[k][l] += W4Fourt[k][l]*W6Sixt[k][l];
	 SumW6SixW6Sixt[k][l] += pow(W6Sixt[k][l],2);
	 SumW6SixW6Six[k][l] += pow(W6Six[k][l],2);

	 W8Eightt[k][l] = -5040*S18[l]
	   + 5760*real(Qt_7[k][l]*conj(Qt[k][l]))
	   + 1920*S12[l]*S16[l]
	   + 1440*real(Qt2_6[k][l]*conj(Qt2[k][l]))
	   - 1920*S16[l]*abs(Qt[k][l]*conj(Qt[k][l]))
	   - 1440*real(Qt2_6[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 2304*real(Qt_5[k][l]*conj(Qt_3[k][l]))
	   + 384*real(Qt3_5[k][l]*conj(Qt3[k][l]))
	   - 2304*S12[l]*real(Qt_5[k][l]*conj(Qt[k][l]))
	   - 1152*real(Qt_5[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   - 576*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 1152*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_5[k][l]*conj(Qt[k][l]))
	   + 192*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 648*pow(S24[l],2)
	   + 576*abs(Qt2_4[k][l]*conj(Qt2_4[k][l]))
	   + 36*abs(Qt4[k][l]*conj(Qt4[k][l]))
	   - 1728*S14[l]*real(Qt[k][l]*conj(Qt_3[k][l]))
	   - 1152*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   - 384*real(Qt2_4[k][l]*Qt[k][l]*conj(Qt3[k][l]))
	   - 96*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt3[k][l]))
	   + 864*S12[l]*S14[l]*abs(Qt[k][l]*conj(Qt[k][l]))
	   + 432*S14[l]*real(Qt[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   + 576*S12[l]*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 576*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_4[k][l]*conj(Qt2[k][l]))
	   + 72*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 216*S14[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)
	   - 192*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 12*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 576*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt_3[k][l]*conj(Qt_3[k][l]))
	   + 288*real(Qt_3[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 192*real(Qt3[k][l]*conj(Qt_3[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 64*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   - 576*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   - 288*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   - 96*real(Qt2[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 64*S12[l]*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 96*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 96*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 16*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 72*pow(S22[l],2)*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)
	   + 6*real(Qt2[k][l]*Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 96*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 36*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   - 16*S12[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),3)
	   - 12*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 1*pow(abs(Qt[k][l]*conj(Qt[k][l])),4)
	   + 24*pow(S42[l],4)
	   + 72*pow(S22[l],2)*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 9*pow(abs(Qt2[k][l]*conj(Qt2[k][l])),2)
	   - 432*S14[l]*pow(S22[l],2)
	   - 216*S14[l]*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   - 576*S12[l]*real(Qt2_4[k][l]*conj(Qt2[k][l]))
	   - 36*real(Qt4[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   - 576*S12[l]*abs(Qt_3[k][l]*conj(Qt_3[k][l]))
	   - 288*real(Qt_3[k][l]*Qt_3[k][l]*conj(Qt2[k][l]))
	   - 192*real(Qt3[k][l]*conj(Qt_3[k][l])*conj(Qt2[k][l]))
	   - 64*S12[l]*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   + 576*pow(S22[l],2)*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 576*S12[l]*real(Qt_3[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   + 288*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 192*S12[l]*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 48*real(Qt3[k][l]*Qt[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   - 96*pow(S32[l],3)*abs(Qt[k][l]*conj(Qt[k][l]))
	   - 144*pow(S22[l],2)*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 144*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   - 36*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]));
	 
	 W8Eight[k][l] = pow(abs(Q[k][l]*conj(Q[k][l])),4) - 12*pow(abs(Q[k][l]*conj(Q[k][l])),2)*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) + 6*real(Q2[k][l]*Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) + 16*abs(Q[k][l]*conj(Q[k][l]))*real(Q3[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) - 96*abs(Q[k][l]*conj(Q[k][l]))*real(Q3[k][l]*conj(Q[k][l])*conj(Q2[k][l])) - 12*real(Q4[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) - 36*abs(Q2[k][l]*conj(Q2[k][l]))*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) + 72*real(Q4[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q2[k][l])) + 48*real(Q3[k][l]*Q[k][l]*conj(Q2[k][l])*conj(Q2[k][l])) - 96*real(Q4[k][l]*conj(Q[k][l])*conj(Q3[k][l])) - 36*real(Q4[k][l]*conj(Q2[k][l])*conj(Q2[k][l])) + 36*abs(Q4[k][l]*conj(Q4[k][l])) + 64*abs(Q[k][l]*conj(Q[k][l]))*abs(Q3[k][l]*conj(Q3[k][l])) + 9*pow(abs(Q2[k][l]*conj(Q2[k][l])),2) + 36*abs(Q2[k][l]*conj(Q2[k][l]))*pow(abs(Q[k][l]*conj(Q[k][l])),2) + 96*(M-6)*abs(Q[k][l]*conj(Q[k][l]))*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) - 64*(M-6)*real(Q3[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) + 192*(M-6)*real(Q3[k][l]*conj(Q2[k][l])*conj(Q[k][l])) - 64*(M-6)*abs(Q3[k][l]*conj(Q3[k][l])) - 144*(M-6)*abs(Q2[k][l]*conj(Q2[k][l]))*abs(Q[k][l]*conj(Q[k][l]))- 16*(M-6)*pow(abs(Q[k][l]*conj(Q[k][l])),3) - 144*(M-4)*(M-7)*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) + 72*(M-4)*(M-7)*(abs(Q2[k][l]*conj(Q2[k][l])) + pow(abs(Q[k][l]*conj(Q[k][l])),2)) - 96*(M-2)*(M-6)*(M-7)*abs(Q[k][l]*conj(Q[k][l])) + 24*M*(M-5)*(M-6)*(M-7);
	 SumW8Eight[k][l] += W8Eight[k][l];
	 SumW8Eightt[k][l] += W8Eightt[k][l];
	 SumW28Eight[k][l] += M*(M-1)*W8Eight[k][l];
	 SumW28Eightt[k][l] += (S21[l]*S21[l] - S12[l])*W8Eightt[k][l];
	 SumW48Eight[k][l] += M*(M-1)*(M-2)*(M-3)*W8Eight[k][l];
	 SumW48Eightt[k][l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*W8Eightt[k][l];
	 SumW68Eight[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*W8Eight[k][l];
	 SumW68Eightt[k][l] += (pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l])*W8Eightt[k][l];
	 SumW88Eight[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*W8Eight[k][l];
	 SumW88Eightt[k][l] += (1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8))*W8Eightt[k][l];
	 SumW810Eight[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9)*W8Eight[k][l];
	 SumW810Eightt[k][l] += (22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l])*W8Eightt[k][l];
	 SumW2TwoW8Eight[k][l] += W2Two[k][l]*W8Eight[k][l];
	 SumW2TwoW8Eightt[k][l] += W2Twot[k][l]*W8Eightt[k][l];
	 SumW4FourW8Eight[k][l] += W4Four[k][l]*W8Eight[k][l];
	 SumW4FourW8Eightt[k][l] += W4Fourt[k][l]*W8Eightt[k][l];
	 SumW6SixW8Eight[k][l] += W6Six[k][l]*W8Eight[k][l];
	 SumW6SixW8Eightt[k][l] += W6Sixt[k][l]*W8Eightt[k][l];
	 SumW8EightW8Eight[k][l] += pow(W8Eight[k][l],2);
	 SumW8EightW8Eightt[k][l] += pow(W8Eightt[k][l],2);

	 W10Tent[k][l] = 1*pow(abs(Qt[k][l]*conj(Qt[k][l])),5)
	   - 120*pow(S52[l],5)
	   + 1200*pow(S32[l],3)*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 225*abs(Qt[k][l]*conj(Qt[k][l]))*pow(abs(Qt2[k][l]*conj(Qt2[k][l])),2)
	   + 3600*abs(Qt_3[k][l]*conj(Qt_3[k][l]))*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 7200*S12[l]*real(Qt_3[k][l]*Qt_3[k][l]*conj(Qt2[k][l]))
	   + 600*pow(S42[l],4)*abs(Qt[k][l]*conj(Qt[k][l]))
	   - 600*pow(S32[l],3)*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 7200*pow(S22[l],2)*abs(Qt_3[k][l]*conj(Qt_3[k][l]))
	   - 225*S12[l]*pow(abs(Qt2[k][l]*conj(Qt2[k][l])),2)
	   + 1800*pow(S22[l],2)*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 900*S12[l]*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 1200*real(Qt3[k][l]*Qt_3[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   + 7200*pow(S22[l],2)*real(Qt2_4[k][l]*conj(Qt2[k][l]))
	   + 400*abs(Qt2[k][l]*conj(Qt2[k][l]))*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   - 1800*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt[k][l]*Qt_3[k][l]*conj(Qt2[k][l]))
	   - 600*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 3600*S14[l]*pow(S32[l],3)
	   + 14400*abs(Qt_3[k][l]*conj(Qt_3[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 1800*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt2_4[k][l]*conj(Qt2[k][l]))
	   + 900*S12[l]*real(Qt4[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   - 600*pow(S32[l],3)*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)
	   - 150*S12[l]*real(Qt2[k][l]*Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 4800*pow(S32[l],3)*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 800*pow(S22[l],2)*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   - 7200*pow(S22[l],2)*real(Qt_3[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   - 2400*pow(S22[l],2)*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 4800*S12[l]*real(Qt3[k][l]*conj(Qt_3[k][l])*conj(Qt2[k][l]))
	   - 7200*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*Qt_3[k][l]*conj(Qt2[k][l]))
	   - 7200*abs(Qt_3[k][l]*conj(Qt_3[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 7200*S12[l]*real(Qt_3[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 2400*S12[l]*real(Qt2[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 1200*S12[l]*real(Qt3[k][l]*Qt[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   + 7200*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   - 14400*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt_3[k][l]*conj(Qt_3[k][l]))
	   - 900*S12[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 7200*pow(S22[l],2)*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   - 7200*S12[l]*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   - 1200*pow(S22[l],2)*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 5400*S12[l]*S14[l]*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 3600*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   - 300*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 2400*real(Qt3[k][l]*Qt_3[k][l]*conj(Qt2[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 4800*real(Qt3[k][l]*conj(Qt_3[k][l])*conj(Qt_3[k][l])*conj(Qt[k][l]))
	   + 600*real(Qt_3[k][l]*Qt[k][l]*Qt[k][l]*Qt[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   + 21600*S14[l]*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   + 7200*S14[l]*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 4800*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3[k][l]*conj(Qt_3[k][l])*conj(Qt2[k][l]))
	   - 4800*S12[l]*real(Qt3[k][l]*conj(Qt_3[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 3200*abs(Qt3[k][l]*conj(Qt3[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 800*pow(S22[l],2)*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 600*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3[k][l]*Qt[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   - 16200*S12[l]*pow(S24[l],2)
	   - 2400*S14[l]*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   - 21600*S14[l]*abs(Qt_3[k][l]*conj(Qt_3[k][l]))
	   - 800*abs(Qt3[k][l]*conj(Qt3[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 400*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 1600*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   - 10800*S12[l]*S14[l]*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 2400*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 10800*S14[l]*pow(S22[l],2)*abs(Qt[k][l]*conj(Qt[k][l]))
	   + 43200*S12[l]*S14[l]*real(Qt_3[k][l]*conj(Qt[k][l]))
	   - 28800*real(Qt_5[k][l]*Qt_3[k][l]*conj(Qt2[k][l]))
	   - 2400*real(Qt4[k][l]*conj(Qt_3[k][l])*conj(Qt3[k][l]))
	   + 14400*real(Qt2_4[k][l]*Qt[k][l]*conj(Qt_3[k][l])*conj(Qt2[k][l]))
	   + 14400*real(Qt2_4[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 14400*real(Qt3_5[k][l]*conj(Qt_3[k][l])*conj(Qt2[k][l]))
	   - 3600*real(Qt4[k][l]*conj(Qt2[k][l])*conj(Qt2_4[k][l]))
	   + 3600*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt_3[k][l])*conj(Qt2[k][l]))
	   - 14400*real(Qt2_4[k][l]*conj(Qt_3[k][l])*conj(Qt_3[k][l]))
	   - 9600*real(Qt2_4[k][l]*Qt_3[k][l]*conj(Qt3[k][l]))
	   - 9600*real(Qt2[k][l]*Qt_5[k][l]*conj(Qt3[k][l]))
	   + 4800*real(Qt2_4[k][l]*Qt2[k][l]*conj(Qt[k][l])*conj(Qt3[k][l]))
	   + 1200*real(Qt4[k][l]*Qt[k][l]*conj(Qt2[k][l])*conj(Qt3[k][l]))
	   - 1800*real(Qt2_4[k][l]*Qt[k][l]*Qt[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   + 28800*pow(S22[l],2)*real(Qt_5[k][l]*conj(Qt[k][l]))
	   - 57600*S12[l]*real(Qt_5[k][l]*conj(Qt_3[k][l]))
	   + 28800*S12[l]*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   + 14400*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt_5[k][l]*conj(Qt[k][l]))
	   - 7200*pow(S22[l],2)*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 9600*S12[l]*real(Qt2_4[k][l]*Qt[k][l]*conj(Qt3[k][l]))
	   - 1800*S12[l]*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 9600*S12[l]*real(Qt3_5[k][l]*conj(Qt3[k][l]))
	   + 28800*S12[l]*real(Qt_5[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   - 21600*S14[l]*real(Qt2_4[k][l]*conj(Qt2[k][l]))
	   - 14400*S12[l]*abs(Qt2_4[k][l]*conj(Qt2_4[k][l]))
	   - 900*S12[l]*abs(Qt4[k][l]*conj(Qt4[k][l]))
	   + 2400*S12[l]*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt3[k][l]))
	   - 3600*abs(Qt2[k][l]*conj(Qt2[k][l]))*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 900*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt4[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   - 14400*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_4[k][l]*conj(Qt2[k][l]))
	   - 5400*S14[l]*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 400*real(Qt3[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 3600*real(Qt3_5[k][l]*Qt[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   - 960*real(Qt5[k][l]*conj(Qt2[k][l])*conj(Qt3[k][l]))
	   - 3600*real(Qt4_6[k][l]*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   + 720*real(Qt5[k][l]*conj(Qt[k][l])*conj(Qt2[k][l])*conj(Qt2[k][l]))
	   + 1600*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   + 2400*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 14400*S12[l]*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 400*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*abs(Qt3[k][l]*conj(Qt3[k][l]))
	   + 100*pow(abs(Qt[k][l]*conj(Qt[k][l])),3)*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   - 24000*S16[l]*pow(S22[l],2)
	   + 3600*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*abs(Qt_3[k][l]*conj(Qt_3[k][l]))
	   - 600*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 30*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2[k][l]*Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 36000*S12[l]*real(Qt2_6[k][l]*conj(Qt2[k][l]))
	   - 12000*S16[l]*abs(Qt2[k][l]*conj(Qt2[k][l]))
	   + 200*pow(S22[l],2)*pow(abs(Qt[k][l]*conj(Qt[k][l])),3)
	   - 1200*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt_3[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   + 300*S12[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 2400*S12[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt_3[k][l]*conj(Qt[k][l]))
	   - 4800*real(Qt2_4[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 600*real(Qt2_4[k][l]*Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 40*real(Qt3[k][l]*Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 1200*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   + 3600*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt2_4[k][l]))
	   + 16200*pow(S24[l],2)*abs(Qt[k][l]*conj(Qt[k][l]))
	   - 2400*S14[l]*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 21600*S14[l]*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 14400*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt2_4[k][l]*conj(Qt2_4[k][l]))
	   + 900*abs(Qt[k][l]*conj(Qt[k][l]))*abs(Qt4[k][l]*conj(Qt4[k][l]))
	   - 1200*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt3[k][l]))
	   + 3600*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt2_4[k][l]*conj(Qt2[k][l]))
	   - 400*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 14400*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   - 4800*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_4[k][l]*Qt[k][l]*conj(Qt3[k][l]))
	   - 21600*S14[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 4800*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 5400*S12[l]*S14[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)
	   - 400*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 3600*S14[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 57600*real(Qt_5[k][l]*Qt[k][l]*conj(Qt2_4[k][l]))
	   - 7200*real(Qt3_5[k][l]*Qt[k][l]*conj(Qt4[k][l]))
	   - 72000*real(Qt2_6[k][l]*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   + 57600*abs(Qt_5[k][l]*conj(Qt_5[k][l]))
	   + 14400*abs(Qt3_5[k][l]*conj(Qt3_5[k][l]))
	   - 4800*real(Qt2[k][l]*Qt_5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 9600*real(Qt_5[k][l]*Qt[k][l]*Qt[k][l]*conj(Qt3[k][l]))
	   - 1440*real(Qt5[k][l]*conj(Qt[k][l])*conj(Qt4[k][l]))
	   - 28800*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt2_4[k][l]))
	   + 28800*real(Qt_5[k][l]*Qt_3[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 576*abs(Qt5[k][l]*conj(Qt5[k][l]))
	   - 24000*real(Qt2_6[k][l]*Qt[k][l]*conj(Qt3[k][l]))
	   + 14400*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt_3[k][l]))
	   + 72000*real(Qt2_6[k][l]*conj(Qt2_4[k][l]))
	   - 480*real(Qt5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 960*real(Qt5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt3[k][l]))
	   + 72000*S14[l]*S16[l]
	   + 36000*S12[l]*real(Qt2_6[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 9600*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3_5[k][l]*conj(Qt3[k][l]))
	   - 4800*S12[l]*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 300*S12[l]*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 14400*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_5[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   + 24000*S16[l]*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 57600*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_5[k][l]*conj(Qt_3[k][l]))
	   - 7200*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 86400*S14[l]*real(Qt_5[k][l]*conj(Qt[k][l]))
	   + 600*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt2[k][l]))
	   - 96000*S16[l]*real(Qt[k][l]*conj(Qt_3[k][l]))
	   - 28800*S12[l]*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_5[k][l]*conj(Qt[k][l]))
	   + 48000*S12[l]*S16[l]*abs(Qt[k][l]*conj(Qt[k][l]))
	   + 403200*real(Qt_9[k][l]*conj(Qt[k][l]))
	   + 100800*real(Qt2_8[k][l]*conj(Qt2[k][l]))
	   - 9600*real(Qt4_6[k][l]*conj(Qt[k][l])*conj(Qt3[k][l]))
	   - 43200*real(Qt3_7[k][l]*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 28800*real(Qt3_7[k][l]*conj(Qt3[k][l]))
	   + 7200*real(Qt4_6[k][l]*conj(Qt4[k][l]))
	   - 1200*real(Qt4_6[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 362880*S110[l]
	   + 48*real(Qt5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 100800*real(Qt2_8[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 72000*real(Qt_7[k][l]*Qt[k][l]*conj(Qt2[k][l]))
	   + 14400*real(Qt3_7[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 7200*real(Qt4_6[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt2[k][l]))
	   + 144000*real(Qt_7[k][l]*conj(Qt_3[k][l]))
	   - 60*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt4[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 72000*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt_7[k][l]*conj(Qt[k][l]))
	   + 36000*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_6[k][l]*conj(Qt2[k][l]))
	   + 4800*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt_5[k][l]*conj(Qt[k][l]))
	   + 200*pow(abs(Qt[k][l]*conj(Qt[k][l])),3)*real(Qt_3[k][l]*conj(Qt[k][l]))
	   + 126000*S12[l]*S18[l]
	   - 600*S14[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),3)
	   - 600*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt2_4[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 1200*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt3_5[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 144000*S12[l]*real(Qt_7[k][l]*conj(Qt[k][l]))
	   - 20*pow(abs(Qt[k][l]*conj(Qt[k][l])),3)*real(Qt2[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   + 40*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)*real(Qt3[k][l]*conj(Qt[k][l])*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 12000*S16[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),2)
	   - 25*S12[l]*pow(abs(Qt[k][l]*conj(Qt[k][l])),4)
	   - 12000*abs(Qt[k][l]*conj(Qt[k][l]))*real(Qt2_6[k][l]*conj(Qt[k][l])*conj(Qt[k][l]))
	   - 126000*S18[l]*abs(Qt[k][l]*conj(Qt[k][l]));
	 
	 W10Ten[k][l] = norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l]) -20*norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l])*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) +100*norm(Q2[k][l])*norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l]) +30*norm(Q[k][l])*real(Q2[k][l]*Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) +225*norm(Q2[k][l])*norm(Q2[k][l])*norm(Q[k][l]) -300*norm(Q2[k][l])*norm(Q[k][l])*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) +40*norm(Q[k][l])*norm(Q[k][l])*real(Q3[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) +600*norm(Q[k][l])*real(Q3[k][l]*Q[k][l]*conj(Q2[k][l])*conj(Q2[k][l])) -400*norm(Q[k][l])*norm(Q[k][l])*real(Q3[k][l]*conj(Q[k][l])*conj(Q2[k][l])) +400*norm(Q3[k][l])*norm(Q[k][l])*norm(Q[k][l]) +400*norm(Q2[k][l])*real(Q3[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) -40*real(Q3[k][l]*Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) -600*norm(Q2[k][l])*real(Q3[k][l]*conj(Q[k][l])*conj(Q2[k][l])) +400*norm(Q3[k][l])*norm(Q2[k][l]) -800*norm(Q3[k][l])*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) -60*norm(Q[k][l])*real(Q4[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) +600*norm(Q[k][l])*real(Q4[k][l]*conj(Q2[k][l])*conj(Q[k][l])*conj(Q[k][l])) -900*norm(Q[k][l])*real(Q4[k][l]*conj(Q2[k][l])*conj(Q2[k][l])) -1200*norm(Q[k][l])*real(Q4[k][l]*conj(Q3[k][l])*conj(Q[k][l])) +1200*real(Q4[k][l]*Q[k][l]*conj(Q2[k][l])*conj(Q3[k][l])) +900*norm(Q4[k][l])*norm(Q[k][l]) +48*real(Q5[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) +720*real(Q5[k][l]*conj(Q[k][l])*conj(Q2[k][l])*conj(Q2[k][l])) -480*real(Q5[k][l]*conj(Q2[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) +960*real(Q5[k][l]*conj(Q3[k][l])*conj(Q[k][l])*conj(Q[k][l])) +576*norm(Q5[k][l]) -960*real(Q5[k][l]*conj(Q3[k][l])*conj(Q2[k][l])) -1440*real(Q5[k][l]*conj(Q[k][l])*conj(Q4[k][l])) +300*(M-8)*norm(Q[k][l])*norm(Q[k][l])*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) -25*(M-8)*norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l]) -900*(M-8)*norm(Q2[k][l])*norm(Q[k][l])*norm(Q[k][l]) -150*(M-8)*real(Q2[k][l]*Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) +900*(M-8)*norm(Q2[k][l])*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) -225*(M-8)*norm(Q2[k][l])*norm(Q2[k][l]) -400*(M-8)*norm(Q[k][l])*real(Q3[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) +2400*(M-8)*norm(Q[k][l])*real(Q3[k][l]*conj(Q[k][l])*conj(Q2[k][l])) +300*(M-8)*real(Q4[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) -1200*(M-8)*real(Q3[k][l]*Q[k][l]*conj(Q2[k][l])*conj(Q2[k][l])) -1600*(M-8)*norm(Q3[k][l])*norm(Q[k][l]) -1800*(M-8)*real(Q4[k][l]*conj(Q2[k][l])*conj(Q[k][l])*conj(Q[k][l])) +900*(M-8)*real(Q4[k][l]*conj(Q2[k][l])*conj(Q2[k][l])) +2400*(M-8)*real(Q4[k][l]*conj(Q[k][l])*conj(Q3[k][l])) -900*(M-8)*norm(Q4[k][l]) +200*(M-6)*(M-9)*norm(Q[k][l])*norm(Q[k][l])*norm(Q[k][l]) -1200*(M-6)*(M-9)*norm(Q[k][l])*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) +1800*(M-6)*(M-9)*norm(Q2[k][l])*norm(Q[k][l]) +800*(M-6)*(M-9)*real(Q3[k][l]*conj(Q[k][l])*conj(Q[k][l])*conj(Q[k][l])) -2400*(M-6)*(M-9)*real(Q3[k][l]*conj(Q[k][l])*conj(Q2[k][l])) +800*(M-6)*(M-9)*norm(Q3[k][l]) +1200*(M-4)*(M-8)*(M-9)*real(Q2[k][l]*conj(Q[k][l])*conj(Q[k][l])) -600*(M-4)*(M-8)*(M-9)*norm(Q[k][l])*norm(Q[k][l]) -600*(M-4)*(M-8)*(M-9)*norm(Q2[k][l]) +600*(M-2)*(M-7)*(M-8)*(M-9)*norm(Q[k][l]) -120*M*(M-6)*(M-7)*(M-8)*(M-9);
	 SumW10Ten[k][l] += W10Ten[k][l];
	 SumW10Tent[k][l] += W10Tent[k][l];
	 SumW210Ten[k][l] += M*(M-1)*W10Ten[k][l];
	 SumW210Tent[k][l] += (S21[l]*S21[l] - S12[l])*W10Tent[k][l];
	 SumW410Ten[k][l] += M*(M-1)*(M-2)*(M-3)*W10Ten[k][l];
	 SumW410Tent[k][l] += (pow(S41[l],4) - 6*S12[l]*pow(S21[l],2) +8*S13[l]*S11[l] +3*pow(S22[l],2) - 6*S14[l])*W10Tent[k][l];
	 SumW610Ten[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*W10Ten[k][l];
	 SumW610Tent[k][l] += (pow(S61[l],6) - 120*S16[l] - 15*pow(S32[l],3)
	 + 40*pow(S23[l],2) + 45*pow(S21[l],2)*pow(S22[l],2)
	 + 144*S11[l]*S15[l] + 90*S12[l]*S14[l]
	 - 15*S12[l]*pow(S41[l],4) - 90*pow(S21[l],2)*S14[l]
	 + 40*S13[l]*pow(S31[l],3) - 120*S11[l]*S12[l]*S13[l])*W10Tent[k][l];
	 SumW810Ten[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*W10Ten[k][l];
	 SumW810Tent[k][l] += (1120*pow(S21[l],2)*pow(S23[l],2) - 1120*S12[l]*pow(S23[l],2) - 420*pow(S21[l],2)*pow(S32[l],3) - 1260*pow(S22[l],2)*S14[l]
	 + 210*pow(S22[l],2)*pow(S41[l],4) + 5760*S11[l]*S17[l] + 3360*S12[l]*S16[l] - 28*S12[l]*pow(S61[l],6) - 3360*pow(S21[l],2)*S16[l]
	 + 2688*S13[l]*S15[l] + 112*S13[l]*pow(S51[l],5) + 1344*pow(S31[l],3)*S15[l] - 420*S14[l]*pow(S41[l],4)
	 + 1680*S11[l]*S13[l]*pow(S22[l],2) - 4032*S11[l]*S12[l]*S15[l] - 3360*S11[l]*S13[l]*S14[l] + 2520*S12[l]*pow(S21[l],2)*S14[l]
	 - 1120*S12[l]*S13[l]*pow(S31[l],3) + 1260*pow(S24[l],2) + 105*pow(S42[l],4) - 5040*S18[l] + pow(S81[l],8))*W10Tent[k][l];
	 SumW1010Ten[k][l] += M*(M-1)*(M-2)*(M-3)*(M-4)*(M-5)*(M-6)*(M-7)*(M-8)*(M-9)*W10Ten[k][l];
	 SumW1010Tent[k][l] += (22400*S11[l]*pow(S33[l],3) - 56700*S12[l]*pow(S24[l],2) + 56700*pow(S21[l],2)*pow(S24[l],2) + 4725*pow(S21[l],2)*pow(S42[l],4)
	 + 25200*pow(S22[l],2)*pow(S23[l],2) - 50400*S14[l]*pow(S23[l],2) + 18900*S14[l]*pow(S32[l],3) + 8400*pow(S23[l],2)*pow(S41[l],4)
	 - 3150*pow(S32[l],3)*pow(S41[l],4) - 75600*pow(S22[l],2)*S16[l] + 630*pow(S22[l],2)*pow(S61[l],6) + 403200*S11[l]*S19[l]
	 + 226800*S12[l]*S18[l] - 45*S12[l]*pow(S81[l],8) - 226800*pow(S21[l],2)*S18[l] + 172800*S13[l]*S17[l] + 240*S13[l]*pow(S71[l],7)
	 + 86400*pow(S31[l],3)*S17[l] + 151200*S14[l]*S16[l] - 1260*S14[l]*pow(S61[l],6) - 25200*pow(S41[l],4)*S16[l] + 6048*S15[l]*pow(S51[l],5)
	 - 25200*S11[l]*S13[l]*pow(S32[l],3) - 50400*S12[l]*pow(S21[l],2)*pow(S23[l],2) + 90720*S11[l]*pow(S22[l],2)*S15[l]
	 - 56700*pow(S21[l],2)*pow(S22[l],2)*S14[l] + 25200*S13[l]*pow(S22[l],2)*pow(S31[l],3) - 259200*S11[l]*S12[l]*S17[l]
	 - 201600*S11[l]*S13[l]*S16[l] - 181440*S11[l]*S14[l]*S15[l] + 151200*S12[l]*pow(S21[l],2)*S16[l] - 120960*S12[l]*S13[l]*S15[l]
	 - 5040*S12[l]*S13[l]*pow(S51[l],5) - 60480*S12[l]*pow(S31[l],3)*S15[l] + 18900*S12[l]*S14[l]*pow(S41[l],4)
	 + 120960*pow(S21[l],2)*S13[l]*S15[l] - 50400*S13[l]*pow(S31[l],3)*S14[l] + 72576*pow(S25[l],2) - 945*pow(S52[l],5)
	 + 1*pow(S101[l],10) - 362880*S110[l] + 151200*S11[l]*S12[l]*S13[l]*S14[l])*W10Tent[k][l];
	 SumW2TwoW10Ten[k][l] += W2Two[k][l]*W10Ten[k][l];
	 SumW2TwoW10Tent[k][l] += W2Twot[k][l]*W10Tent[k][l];
	 SumW4FourW10Ten[k][l] += W4Four[k][l]*W10Ten[k][l];
	 SumW4FourW10Tent[k][l] += W4Fourt[k][l]*W10Tent[k][l];
	 SumW6SixW10Ten[k][l] += W6Six[k][l]*W10Ten[k][l];
	 SumW6SixW10Tent[k][l] += W6Sixt[k][l]*W10Tent[k][l];
	 SumW8EightW10Ten[k][l] += W8Eight[k][l]*W10Ten[k][l];
	 SumW8EightW10Tent[k][l] += W8Eightt[k][l]*W10Tent[k][l];
	 SumW10TenW10Ten[k][l] += pow(W10Ten[k][l],2);
	 SumW10TenW10Tent[k][l] += pow(W10Tent[k][l],2);
       }





*/

#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif

#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void
Qnana::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
Qnana::endJob()
{
/*
   for (int l=0; l<16; l++) {
        h_multEv->SetBinContent(l+1,multEv[l]);

	h_W2->SetBinContent(l+1,W2[l]);
        h_W22->SetBinContent(l+1,W22[l]);
        h_W24->SetBinContent(l+1,W24[l]);
        h_W26->SetBinContent(l+1,W26[l]);
        h_W28->SetBinContent(l+1,W28[l]);
        h_W210->SetBinContent(l+1,W210[l]);

        h_W4->SetBinContent(l+1,W4[l]);
        h_W44->SetBinContent(l+1,W44[l]);
        h_W46->SetBinContent(l+1,W46[l]);
        h_W48->SetBinContent(l+1,W48[l]);
        h_W410->SetBinContent(l+1,W410[l]);

        h_W6->SetBinContent(l+1,W6[l]);
        h_W66->SetBinContent(l+1,W66[l]);
        h_W68->SetBinContent(l+1,W68[l]);
        h_W610->SetBinContent(l+1,W610[l]);

        h_W8->SetBinContent(l+1,W8[l]);
        h_W88->SetBinContent(l+1,W88[l]);
        h_W810->SetBinContent(l+1,W810[l]);

        h_W10->SetBinContent(l+1,W10[l]);
        h_W1010->SetBinContent(l+1,W1010[l]);

//efff
        h_Mt->SetBinContent(l+1,Mt[l]);
        h_Mt2->SetBinContent(l+1,Mt2[l]);
        
        h_M2t->SetBinContent(l+1,M2t[l]);
        h_M2t2->SetBinContent(l+1,M2t2[l]);
        h_MM2t->SetBinContent(l+1,MM2t[l]);
        
        h_M3t->SetBinContent(l+1,M3t[l]);
        h_M3t2->SetBinContent(l+1,M3t2[l]);
        h_MM3t->SetBinContent(l+1,MM3t[l]);
        h_M2M3t->SetBinContent(l+1,M2M3t[l]);
        
        h_M4t->SetBinContent(l+1,M4t[l]);
        h_M4t2->SetBinContent(l+1,M4t2[l]);
        h_MM4t->SetBinContent(l+1,MM4t[l]);
        h_M2M4t->SetBinContent(l+1,M2M4t[l]);
        h_M3M4t->SetBinContent(l+1,M3M4t[l]);
        
        h_M5t->SetBinContent(l+1,M5t[l]);
        h_M5t2->SetBinContent(l+1,M5t2[l]);
        h_MM5t->SetBinContent(l+1,MM5t[l]);
        h_M2M5t->SetBinContent(l+1,M2M5t[l]);
        h_M3M5t->SetBinContent(l+1,M3M5t[l]);
        h_M4M5t->SetBinContent(l+1,M4M5t[l]);
/////

	for(int k=0; k<5; k++) {

  h_W2Two->SetBinContent(k+1,l+1,W2Two[k][l]);  h_W4Four->SetBinContent(k+1,l+1,W4Four[k][l]);  h_W6Six->SetBinContent(k+1,l+1,W6Six[k][l]);  h_W8Eight->SetBinContent(k+1,l+1,W8Eight[k][l]);  h_W10Ten->SetBinContent(k+1,l+1,W10Ten[k][l]);
  h_SumW2Two->SetBinContent(k+1,l+1,SumW2Two[k][l]);  h_SumW22Two->SetBinContent(k+1,l+1,SumW22Two[k][l]);  h_SumW24Two->SetBinContent(k+1,l+1,SumW24Two[k][l]);  h_SumW26Two->SetBinContent(k+1,l+1,SumW26Two[k][l]);  h_SumW28Two->SetBinContent(k+1,l+1,SumW28Two[k][l]);  h_SumW210Two->SetBinContent(k+1,l+1,SumW210Two[k][l]);  h_SumW2TwoW2Two->SetBinContent(k+1,l+1,SumW2TwoW2Two[k][l]);
  h_SumW4Four->SetBinContent(k+1,l+1,SumW4Four[k][l]);  h_SumW24Four->SetBinContent(k+1,l+1,SumW24Four[k][l]);  h_SumW44Four->SetBinContent(k+1,l+1,SumW44Four[k][l]);  h_SumW46Four->SetBinContent(k+1,l+1,SumW46Four[k][l]);  h_SumW48Four->SetBinContent(k+1,l+1,SumW48Four[k][l]);  h_SumW410Four->SetBinContent(k+1,l+1,SumW410Four[k][l]);  h_SumW2TwoW4Four->SetBinContent(k+1,l+1,SumW2TwoW4Four[k][l]);  h_SumW4FourW4Four->SetBinContent(k+1,l+1,SumW4FourW4Four[k][l]);
  h_SumW6Six->SetBinContent(k+1,l+1,SumW6Six[k][l]);  h_SumW26Six->SetBinContent(k+1,l+1,SumW26Six[k][l]);  h_SumW46Six->SetBinContent(k+1,l+1,SumW46Six[k][l]);  h_SumW66Six->SetBinContent(k+1,l+1,SumW66Six[k][l]);  h_SumW68Six->SetBinContent(k+1,l+1,SumW68Six[k][l]);  h_SumW610Six->SetBinContent(k+1,l+1,SumW610Six[k][l]);  h_SumW2TwoW6Six->SetBinContent(k+1,l+1,SumW2TwoW6Six[k][l]);  h_SumW4FourW6Six->SetBinContent(k+1,l+1,SumW4FourW6Six[k][l]);  h_SumW6SixW6Six->SetBinContent(k+1,l+1,SumW6SixW6Six[k][l]);
  h_SumW8Eight->SetBinContent(k+1,l+1,SumW8Eight[k][l]);  h_SumW28Eight->SetBinContent(k+1,l+1,SumW28Eight[k][l]);  h_SumW48Eight->SetBinContent(k+1,l+1,SumW48Eight[k][l]);  h_SumW68Eight->SetBinContent(k+1,l+1,SumW68Eight[k][l]);  h_SumW88Eight->SetBinContent(k+1,l+1,SumW88Eight[k][l]);  h_SumW810Eight->SetBinContent(k+1,l+1,SumW810Eight[k][l]);  h_SumW2TwoW8Eight->SetBinContent(k+1,l+1,SumW2TwoW8Eight[k][l]);  h_SumW4FourW8Eight->SetBinContent(k+1,l+1,SumW4FourW8Eight[k][l]);  h_SumW6SixW8Eight->SetBinContent(k+1,l+1,SumW6SixW8Eight[k][l]);  h_SumW8EightW8Eight->SetBinContent(k+1,l+1,SumW8EightW8Eight[k][l]);
  h_SumW10Ten->SetBinContent(k+1,l+1,SumW10Ten[k][l]);  h_SumW210Ten->SetBinContent(k+1,l+1,SumW210Ten[k][l]);  h_SumW410Ten->SetBinContent(k+1,l+1,SumW410Ten[k][l]);
  h_SumW610Ten->SetBinContent(k+1,l+1,SumW610Ten[k][l]);  h_SumW810Ten->SetBinContent(k+1,l+1,SumW810Ten[k][l]);  h_SumW1010Ten->SetBinContent(k+1,l+1,SumW1010Ten[k][l]);  h_SumW2TwoW10Ten->SetBinContent(k+1,l+1,SumW2TwoW10Ten[k][l]);
  h_SumW4FourW10Ten->SetBinContent(k+1,l+1,SumW4FourW10Ten[k][l]);  h_SumW6SixW10Ten->SetBinContent(k+1,l+1,SumW6SixW10Ten[k][l]);  h_SumW8EightW10Ten->SetBinContent(k+1,l+1,SumW8EightW10Ten[k][l]);  h_SumW10TenW10Ten->SetBinContent(k+1,l+1,SumW10TenW10Ten[k][l]);
  h_AveTwo->SetBinContent(k+1,l+1,AveTwo[k][l]);  h_AveFour->SetBinContent(k+1,l+1,AveFour[k][l]);  h_AveSix->SetBinContent(k+1,l+1,AveSix[k][l]);  h_AveEight->SetBinContent(k+1,l+1,AveEight[k][l]);  h_AveTen->SetBinContent(k+1,l+1,AveTen[k][l]);
  h_VarAveTwo->SetBinContent(k+1,l+1,VarAveTwo[k][l]);  h_VarAveFour->SetBinContent(k+1,l+1,VarAveFour[k][l]);  h_VarAveSix->SetBinContent(k+1,l+1,VarAveSix[k][l]);  h_VarAveEight->SetBinContent(k+1,l+1,VarAveEight[k][l]);  h_VarAveTen->SetBinContent(k+1,l+1,VarAveTen[k][l]);
  h_CovAveTwoAveFour->SetBinContent(k+1,l+1,CovAveTwoAveFour[k][l]);  h_CovAveTwoAveSix->SetBinContent(k+1,l+1,CovAveTwoAveSix[k][l]);  h_CovAveTwoAveEight->SetBinContent(k+1,l+1,CovAveTwoAveEight[k][l]);  h_CovAveTwoAveTen->SetBinContent(k+1,l+1,CovAveTwoAveTen[k][l]);  h_CovAveFourAveSix->SetBinContent(k+1,l+1,CovAveFourAveSix[k][l]);  h_CovAveFourAveEight->SetBinContent(k+1,l+1,CovAveFourAveEight[k][l]);  h_CovAveFourAveTen->SetBinContent(k+1,l+1,CovAveFourAveTen[k][l]);  h_CovAveSixAveEight->SetBinContent(k+1,l+1,CovAveSixAveEight[k][l]);  h_CovAveSixAveTen->SetBinContent(k+1,l+1,CovAveSixAveTen[k][l]);  h_CovAveEightAveTen->SetBinContent(k+1,l+1,CovAveEightAveTen[k][l]);
  h_CumTwo->SetBinContent(k+1,l+1,CumTwo[k][l]);  h_Two_v->SetBinContent(k+1,l+1,Two_v[k][l]);  h_ErrTwo_v->SetBinContent(k+1,l+1,ErrTwo_v[k][l]);
  h_CumFour->SetBinContent(k+1,l+1,CumFour[k][l]);  h_Four_v->SetBinContent(k+1,l+1,Four_v[k][l]);  h_ErrFour_v->SetBinContent(k+1,l+1,ErrFour_v[k][l]);
  h_CumSix->SetBinContent(k+1,l+1,CumSix[k][l]);  h_Six_v->SetBinContent(k+1,l+1,Six_v[k][l]);  h_ErrSix_v->SetBinContent(k+1,l+1,ErrSix_v[k][l]);
  h_CumEight->SetBinContent(k+1,l+1,CumEight[k][l]);  h_Eight_v->SetBinContent(k+1,l+1,Eight_v[k][l]);  h_ErrEight_v->SetBinContent(k+1,l+1,ErrEight_v[k][l]);
  h_CumTen->SetBinContent(k+1,l+1,CumTen[k][l]);  h_Ten_v->SetBinContent(k+1,l+1,Ten_v[k][l]);  h_ErrTen_v->SetBinContent(k+1,l+1,ErrTen_v[k][l]);

//efficie
  h_W2Twot->SetBinContent(k+1,l+1,W2Twot[k][l]);  h_W4Fourt->SetBinContent(k+1,l+1,W4Fourt[k][l]);  h_W6Sixt->SetBinContent(k+1,l+1,W6Sixt[k][l]);  h_W8Eightt->SetBinContent(k+1,l+1,W8Eightt[k][l]);  h_W10Tent->SetBinContent(k+1,l+1,W10Tent[k][l]);
  h_SumW2Twot->SetBinContent(k+1,l+1,SumW2Twot[k][l]);  h_SumW22Twot->SetBinContent(k+1,l+1,SumW22Twot[k][l]);  h_SumW24Twot->SetBinContent(k+1,l+1,SumW24Twot[k][l]);  h_SumW26Twot->SetBinContent(k+1,l+1,SumW26Twot[k][l]);  h_SumW28Twot->SetBinContent(k+1,l+1,SumW28Twot[k][l]);  h_SumW210Twot->SetBinContent(k+1,l+1,SumW210Twot[k][l]);  h_SumW2TwoW2Twot->SetBinContent(k+1,l+1,SumW2TwoW2Twot[k][l]);
  h_SumW4Fourt->SetBinContent(k+1,l+1,SumW4Fourt[k][l]);  h_SumW24Fourt->SetBinContent(k+1,l+1,SumW24Fourt[k][l]);  h_SumW44Fourt->SetBinContent(k+1,l+1,SumW44Fourt[k][l]);  h_SumW46Fourt->SetBinContent(k+1,l+1,SumW46Fourt[k][l]);  h_SumW48Fourt->SetBinContent(k+1,l+1,SumW48Fourt[k][l]);  h_SumW410Fourt->SetBinContent(k+1,l+1,SumW410Fourt[k][l]);  h_SumW2TwoW4Fourt->SetBinContent(k+1,l+1,SumW2TwoW4Fourt[k][l]);  h_SumW4FourW4Fourt->SetBinContent(k+1,l+1,SumW4FourW4Fourt[k][l]);
  h_SumW6Sixt->SetBinContent(k+1,l+1,SumW6Sixt[k][l]);  h_SumW26Sixt->SetBinContent(k+1,l+1,SumW26Sixt[k][l]);  h_SumW46Sixt->SetBinContent(k+1,l+1,SumW46Sixt[k][l]);  h_SumW66Sixt->SetBinContent(k+1,l+1,SumW66Sixt[k][l]);  h_SumW68Sixt->SetBinContent(k+1,l+1,SumW68Sixt[k][l]);  h_SumW610Sixt->SetBinContent(k+1,l+1,SumW610Sixt[k][l]);  h_SumW2TwoW6Sixt->SetBinContent(k+1,l+1,SumW2TwoW6Sixt[k][l]);  h_SumW4FourW6Sixt->SetBinContent(k+1,l+1,SumW4FourW6Sixt[k][l]);  h_SumW6SixW6Sixt->SetBinContent(k+1,l+1,SumW6SixW6Sixt[k][l]);
  h_SumW8Eightt->SetBinContent(k+1,l+1,SumW8Eightt[k][l]);  h_SumW28Eightt->SetBinContent(k+1,l+1,SumW28Eightt[k][l]);  h_SumW48Eightt->SetBinContent(k+1,l+1,SumW48Eightt[k][l]);  h_SumW68Eightt->SetBinContent(k+1,l+1,SumW68Eightt[k][l]);  h_SumW88Eightt->SetBinContent(k+1,l+1,SumW88Eightt[k][l]);  h_SumW810Eightt->SetBinContent(k+1,l+1,SumW810Eightt[k][l]);  h_SumW2TwoW8Eightt->SetBinContent(k+1,l+1,SumW2TwoW8Eightt[k][l]);  h_SumW4FourW8Eightt->SetBinContent(k+1,l+1,SumW4FourW8Eightt[k][l]);  h_SumW6SixW8Eightt->SetBinContent(k+1,l+1,SumW6SixW8Eightt[k][l]);  h_SumW8EightW8Eightt->SetBinContent(k+1,l+1,SumW8EightW8Eightt[k][l]);
  h_SumW10Tent->SetBinContent(k+1,l+1,SumW10Tent[k][l]);  h_SumW210Tent->SetBinContent(k+1,l+1,SumW210Tent[k][l]);  h_SumW410Tent->SetBinContent(k+1,l+1,SumW410Tent[k][l]);
  h_SumW610Tent->SetBinContent(k+1,l+1,SumW610Tent[k][l]);  h_SumW810Tent->SetBinContent(k+1,l+1,SumW810Tent[k][l]);  h_SumW1010Tent->SetBinContent(k+1,l+1,SumW1010Tent[k][l]);  h_SumW2TwoW10Tent->SetBinContent(k+1,l+1,SumW2TwoW10Tent[k][l]);
  h_SumW4FourW10Tent->SetBinContent(k+1,l+1,SumW4FourW10Tent[k][l]);  h_SumW6SixW10Tent->SetBinContent(k+1,l+1,SumW6SixW10Tent[k][l]);  h_SumW8EightW10Tent->SetBinContent(k+1,l+1,SumW8EightW10Tent[k][l]);  h_SumW10TenW10Tent->SetBinContent(k+1,l+1,SumW10TenW10Tent[k][l]);
  h_AveTwot->SetBinContent(k+1,l+1,AveTwot[k][l]);  h_AveFourt->SetBinContent(k+1,l+1,AveFourt[k][l]);  h_AveSixt->SetBinContent(k+1,l+1,AveSixt[k][l]);  h_AveEightt->SetBinContent(k+1,l+1,AveEightt[k][l]);  h_AveTent->SetBinContent(k+1,l+1,AveTent[k][l]);
  h_VarAveTwot->SetBinContent(k+1,l+1,VarAveTwot[k][l]);  h_VarAveFourt->SetBinContent(k+1,l+1,VarAveFourt[k][l]);  h_VarAveSixt->SetBinContent(k+1,l+1,VarAveSixt[k][l]);  h_VarAveEightt->SetBinContent(k+1,l+1,VarAveEightt[k][l]);  h_VarAveTent->SetBinContent(k+1,l+1,VarAveTent[k][l]);
  h_CovAveTwoAveFourt->SetBinContent(k+1,l+1,CovAveTwoAveFourt[k][l]);  h_CovAveTwoAveSixt->SetBinContent(k+1,l+1,CovAveTwoAveSixt[k][l]);  h_CovAveTwoAveEightt->SetBinContent(k+1,l+1,CovAveTwoAveEightt[k][l]);  h_CovAveTwoAveTent->SetBinContent(k+1,l+1,CovAveTwoAveTent[k][l]);  h_CovAveFourAveSixt->SetBinContent(k+1,l+1,CovAveFourAveSixt[k][l]);  h_CovAveFourAveEightt->SetBinContent(k+1,l+1,CovAveFourAveEightt[k][l]);  h_CovAveFourAveTent->SetBinContent(k+1,l+1,CovAveFourAveTent[k][l]);  h_CovAveSixAveEightt->SetBinContent(k+1,l+1,CovAveSixAveEightt[k][l]);  h_CovAveSixAveTent->SetBinContent(k+1,l+1,CovAveSixAveTent[k][l]);  h_CovAveEightAveTent->SetBinContent(k+1,l+1,CovAveEightAveTent[k][l]);
  h_CumTwot->SetBinContent(k+1,l+1,CumTwot[k][l]);  h_Two_vt->SetBinContent(k+1,l+1,Two_vt[k][l]);  h_ErrTwo_vt->SetBinContent(k+1,l+1,ErrTwo_vt[k][l]);
  h_CumFourt->SetBinContent(k+1,l+1,CumFourt[k][l]);  h_Four_vt->SetBinContent(k+1,l+1,Four_vt[k][l]);  h_ErrFour_vt->SetBinContent(k+1,l+1,ErrFour_vt[k][l]);
  h_CumSixt->SetBinContent(k+1,l+1,CumSixt[k][l]);  h_Six_vt->SetBinContent(k+1,l+1,Six_vt[k][l]);  h_ErrSix_vt->SetBinContent(k+1,l+1,ErrSix_vt[k][l]);
  h_CumEightt->SetBinContent(k+1,l+1,CumEightt[k][l]);  h_Eight_vt->SetBinContent(k+1,l+1,Eight_vt[k][l]);  h_ErrEight_vt->SetBinContent(k+1,l+1,ErrEight_vt[k][l]);
  h_CumTent->SetBinContent(k+1,l+1,CumTent[k][l]);  h_Ten_vt->SetBinContent(k+1,l+1,Ten_vt[k][l]);  h_ErrTen_vt->SetBinContent(k+1,l+1,ErrTen_vt[k][l]);
//
	}


   }

 for (Int_t k=0; k<16; k++) {//over multiplicity bins
   std::cout<<multEv[k]<<std::endl;
   std::cout<<W2[k]<<std::endl;
   std::cout<<W22[k]<<std::endl;
   std::cout<<W24[k]<<std::endl;
   std::cout<<W26[k]<<std::endl;
   std::cout<<W28[k]<<std::endl;
   std::cout<<W210[k]<<std::endl;
   std::cout<<W4[k]<<std::endl;
   std::cout<<W44[k]<<std::endl;
   std::cout<<W46[k]<<std::endl;
   std::cout<<W48[k]<<std::endl;
   std::cout<<W410[k]<<std::endl;
   std::cout<<W6[k]<<std::endl;
   std::cout<<W66[k]<<std::endl;
   std::cout<<W68[k]<<std::endl;
   std::cout<<W610[k]<<std::endl;
   std::cout<<W8[k]<<std::endl;
   std::cout<<W88[k]<<std::endl;
   std::cout<<W810[k]<<std::endl;
   std::cout<<W10[k]<<std::endl;
   std::cout<<W1010[k]<<std::endl;
   
   std::cout<<Mt[k]<<std::endl;
   std::cout<<Mt2[k]<<std::endl;
   
   std::cout<<M2t[k]<<std::endl;
   std::cout<<M2t2[k]<<std::endl;
   std::cout<<MM2t[k]<<std::endl;
   
   std::cout<<M3t[k]<<std::endl;
   std::cout<<M3t2[k]<<std::endl;
   std::cout<<MM3t[k]<<std::endl;
   std::cout<<M2M3t[k]<<std::endl;
   
   std::cout<<M4t[k]<<std::endl;
   std::cout<<M4t2[k]<<std::endl;
   std::cout<<MM4t[k]<<std::endl;
   std::cout<<M2M4t[k]<<std::endl;
   std::cout<<M3M4t[k]<<std::endl;
   
   std::cout<<M5t[k]<<std::endl;
   std::cout<<M5t2[k]<<std::endl;
   std::cout<<MM5t[k]<<std::endl;
   std::cout<<M2M5t[k]<<std::endl;
   std::cout<<M3M5t[k]<<std::endl;
   std::cout<<M4M5t[k]<<std::endl;


      for (Int_t n=0; n<5; n++) {
     std::cout<<SumW2Two[n][k]<<std::endl;
     std::cout<<SumW22Two[n][k]<<std::endl;
     std::cout<<SumW24Two[n][k]<<std::endl;
     std::cout<<SumW26Two[n][k]<<std::endl;
     std::cout<<SumW28Two[n][k]<<std::endl;
     std::cout<<SumW210Two[n][k]<<std::endl;
     std::cout<<SumW2TwoW2Two[n][k]<<std::endl;

     std::cout<<SumW4Four[n][k]<<std::endl;
     std::cout<<SumW24Four[n][k]<<std::endl;
     std::cout<<SumW44Four[n][k]<<std::endl;
     std::cout<<SumW46Four[n][k]<<std::endl;
     std::cout<<SumW48Four[n][k]<<std::endl;
     std::cout<<SumW410Four[n][k]<<std::endl;
     std::cout<<SumW2TwoW4Four[n][k]<<std::endl;
     std::cout<<SumW4FourW4Four[n][k]<<std::endl;
     
     std::cout<<SumW6Six[n][k]<<std::endl;
     std::cout<<SumW26Six[n][k]<<std::endl;
     std::cout<<SumW46Six[n][k]<<std::endl;
     std::cout<<SumW66Six[n][k]<<std::endl;
     std::cout<<SumW68Six[n][k]<<std::endl;
     std::cout<<SumW610Six[n][k]<<std::endl;
     std::cout<<SumW2TwoW6Six[n][k]<<std::endl;
     std::cout<<SumW4FourW6Six[n][k]<<std::endl;
     std::cout<<SumW6SixW6Six[n][k]<<std::endl;
	  
     std::cout<<SumW8Eight[n][k]<<std::endl;
     std::cout<<SumW28Eight[n][k]<<std::endl;
     std::cout<<SumW48Eight[n][k]<<std::endl;
     std::cout<<SumW68Eight[n][k]<<std::endl;
     std::cout<<SumW88Eight[n][k]<<std::endl;
     std::cout<<SumW810Eight[n][k]<<std::endl;
     std::cout<<SumW2TwoW8Eight[n][k]<<std::endl;
     std::cout<<SumW4FourW8Eight[n][k]<<std::endl;
     std::cout<<SumW6SixW8Eight[n][k]<<std::endl;
     std::cout<<SumW8EightW8Eight[n][k]<<std::endl;

     std::cout<<SumW10Ten[n][k]<<std::endl;
     std::cout<<SumW210Ten[n][k]<<std::endl;
     std::cout<<SumW410Ten[n][k]<<std::endl;
     std::cout<<SumW610Ten[n][k]<<std::endl;
     std::cout<<SumW810Ten[n][k]<<std::endl;
     std::cout<<SumW1010Ten[n][k]<<std::endl;
     std::cout<<SumW2TwoW10Ten[n][k]<<std::endl;
     std::cout<<SumW4FourW10Ten[n][k]<<std::endl;
     std::cout<<SumW6SixW10Ten[n][k]<<std::endl;
     std::cout<<SumW8EightW10Ten[n][k]<<std::endl;
     std::cout<<SumW10TenW10Ten[n][k]<<std::endl;
   }
      for (Int_t n=0; n<5; n++) {
     std::cout<<SumW2Twot[n][k]<<std::endl;
     std::cout<<SumW22Twot[n][k]<<std::endl;
     std::cout<<SumW24Twot[n][k]<<std::endl;
     std::cout<<SumW26Twot[n][k]<<std::endl;
     std::cout<<SumW28Twot[n][k]<<std::endl;
     std::cout<<SumW210Twot[n][k]<<std::endl;
     std::cout<<SumW2TwoW2Twot[n][k]<<std::endl;

     std::cout<<SumW4Fourt[n][k]<<std::endl;
     std::cout<<SumW24Fourt[n][k]<<std::endl;
     std::cout<<SumW44Fourt[n][k]<<std::endl;
     std::cout<<SumW46Fourt[n][k]<<std::endl;
     std::cout<<SumW48Fourt[n][k]<<std::endl;
     std::cout<<SumW410Fourt[n][k]<<std::endl;
     std::cout<<SumW2TwoW4Fourt[n][k]<<std::endl;
     std::cout<<SumW4FourW4Fourt[n][k]<<std::endl;
     
     std::cout<<SumW6Sixt[n][k]<<std::endl;
     std::cout<<SumW26Sixt[n][k]<<std::endl;
     std::cout<<SumW46Sixt[n][k]<<std::endl;
     std::cout<<SumW66Sixt[n][k]<<std::endl;
     std::cout<<SumW68Sixt[n][k]<<std::endl;
     std::cout<<SumW610Sixt[n][k]<<std::endl;
     std::cout<<SumW2TwoW6Sixt[n][k]<<std::endl;
     std::cout<<SumW4FourW6Sixt[n][k]<<std::endl;
     std::cout<<SumW6SixW6Sixt[n][k]<<std::endl;
          
     std::cout<<SumW8Eightt[n][k]<<std::endl;
     std::cout<<SumW28Eightt[n][k]<<std::endl;
     std::cout<<SumW48Eightt[n][k]<<std::endl;
     std::cout<<SumW68Eightt[n][k]<<std::endl;
     std::cout<<SumW88Eightt[n][k]<<std::endl;
     std::cout<<SumW810Eightt[n][k]<<std::endl;
     std::cout<<SumW2TwoW8Eightt[n][k]<<std::endl;
     std::cout<<SumW4FourW8Eightt[n][k]<<std::endl;
     std::cout<<SumW6SixW8Eightt[n][k]<<std::endl;
     std::cout<<SumW8EightW8Eightt[n][k]<<std::endl;

     std::cout<<SumW10Tent[n][k]<<std::endl;
     std::cout<<SumW210Tent[n][k]<<std::endl;
     std::cout<<SumW410Tent[n][k]<<std::endl;
     std::cout<<SumW610Tent[n][k]<<std::endl;
     std::cout<<SumW810Tent[n][k]<<std::endl;
     std::cout<<SumW1010Tent[n][k]<<std::endl;
     std::cout<<SumW2TwoW10Tent[n][k]<<std::endl;
     std::cout<<SumW4FourW10Tent[n][k]<<std::endl;
     std::cout<<SumW6SixW10Tent[n][k]<<std::endl;
     std::cout<<SumW8EightW10Tent[n][k]<<std::endl;
     std::cout<<SumW10TenW10Tent[n][k]<<std::endl;

   }
 }
*/
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
Qnana::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}

void
Qnana::initHistos(const edm::Service<TFileService> & fs)
{

  VertexCompositeNtuple = fs->make< TTree>("VertexCompositeNtuple","VertexCompositeNtuple");

   VertexCompositeNtuple->Branch("centDefault",&centDefault,"centDefault/I");
   VertexCompositeNtuple->Branch("centNominal",&centNominal,"centNominal/I");
   VertexCompositeNtuple->Branch("centDown",&centDown,"centDown/I");
   VertexCompositeNtuple->Branch("centUp",&centUp,"centUp/I");

  double hiHFbinedges[201] = {0, 10.5072, 11.2099, 11.8364, 12.478, 13.1194, 13.7623, 14.4081, 15.0709, 15.7532, 16.4673, 17.1881, 17.923, 18.673, 19.4865, 20.3033, 21.1536, 22.0086, 22.9046, 23.8196, 24.7924, 25.8082, 26.8714, 27.9481, 29.0828, 30.2757, 31.5043, 32.8044, 34.1572, 35.6142, 37.1211, 38.6798, 40.3116, 42.0398, 43.8572, 45.6977, 47.6312, 49.6899, 51.815, 54.028, 56.3037, 58.7091, 61.2024, 63.8353, 66.5926, 69.3617, 72.2068, 75.2459, 78.3873, 81.5916, 84.9419, 88.498, 92.1789, 95.9582, 99.8431, 103.739, 107.78, 111.97, 116.312, 120.806, 125.46, 130.269, 135.247, 140.389, 145.713, 151.212, 156.871, 162.729, 168.762, 174.998, 181.424, 188.063, 194.907, 201.942, 209.19, 216.683, 224.37, 232.291, 240.43, 248.807, 257.416, 266.256, 275.348, 284.668, 294.216, 304.053, 314.142, 324.488, 335.101, 345.974, 357.116, 368.547, 380.283, 392.29, 404.564, 417.122, 429.968, 443.116, 456.577, 470.357, 484.422, 498.78, 513.473, 528.479, 543.813, 559.445, 575.411, 591.724, 608.352, 625.344, 642.686, 660.361, 678.371, 696.749, 715.485, 734.608, 754.068, 773.846, 794.046, 814.649, 835.608, 856.972, 878.719, 900.887, 923.409, 946.374, 969.674, 993.435, 1017.62, 1042.21, 1067.28, 1092.72, 1118.64, 1144.96, 1171.71, 1198.98, 1226.67, 1254.82, 1283.46, 1312.65, 1342.21, 1372.27, 1402.85, 1433.93, 1465.49, 1497.62, 1530.29, 1563.49, 1597.22, 1631.49, 1666.37, 1701.8, 1737.75, 1774.35, 1811.51, 1849.29, 1887.75, 1926.79, 1966.6, 2006.97, 2047.99, 2089.71, 2132.1, 2175.23, 2219.17, 2263.72, 2309.2, 2355.43, 2402.47, 2450.33, 2499.05, 2548.66, 2599.16, 2650.59, 2703.03, 2756.32, 2810.75, 2866.27, 2922.91, 2980.54, 3039.47, 3099.53, 3160.98, 3223.66, 3287.71, 3353.18, 3420.34, 3489.13, 3559.72, 3632.06, 3706.18, 3782.42, 3860.78, 3941.42, 4024.52, 4110.27, 4199.4, 4292.8, 4394.49, 4519.52, 5199.95};
  double hiHFbinedgesSysDown[201] = {0, 10.5071, 11.2094, 11.8357, 12.4763, 13.117, 13.7597, 14.4049, 15.0671, 15.7491, 16.4622, 17.1812, 17.9144, 18.6674, 19.4797, 20.2963, 21.1435, 21.9974, 22.8928, 23.8068, 24.7805, 25.7931, 26.8556, 27.9308, 29.0638, 30.2582, 31.4795, 32.7816, 34.1349, 35.5834, 37.0941, 38.6474, 40.2782, 42.0035, 43.8112, 45.6576, 47.5758, 49.6381, 51.6667, 53.7353, 55.8903, 58.1259, 60.4528, 62.8712, 65.3859, 67.9968, 70.7065, 73.5231, 76.4519, 79.4922, 82.6461, 85.9264, 89.3269, 92.8562, 96.5212, 100.322, 104.262, 108.344, 112.585, 116.971, 121.521, 126.225, 131.09, 136.127, 141.328, 146.721, 152.284, 158.014, 163.935, 170.054, 176.372, 182.878, 189.602, 196.532, 203.653, 211.017, 218.599, 226.387, 234.418, 242.667, 251.16, 259.886, 268.852, 278.071, 287.498, 297.2, 307.184, 317.409, 327.894, 338.66, 349.686, 360.996, 372.607, 384.508, 396.669, 409.133, 421.86, 434.906, 448.258, 461.916, 475.906, 490.16, 504.74, 519.663, 534.911, 550.453, 566.322, 582.525, 599.08, 615.968, 633.211, 650.805, 668.76, 687.048, 705.707, 724.774, 744.163, 763.9, 783.999, 804.528, 825.432, 846.746, 868.429, 890.523, 913.007, 935.952, 959.211, 982.919, 1007.08, 1031.63, 1056.62, 1082.08, 1107.96, 1134.24, 1160.99, 1188.22, 1215.91, 1244.06, 1272.69, 1301.85, 1331.45, 1361.51, 1392.07, 1423.18, 1454.77, 1486.93, 1519.57, 1552.81, 1586.55, 1620.87, 1655.79, 1691.26, 1727.27, 1763.93, 1801.12, 1838.97, 1877.47, 1916.61, 1956.45, 1996.89, 2038.04, 2079.84, 2122.35, 2165.52, 2209.53, 2254.24, 2299.83, 2346.19, 2393.31, 2441.28, 2490.16, 2539.86, 2590.57, 2642.16, 2694.74, 2748.23, 2802.81, 2858.47, 2915.33, 2973.2, 3032.28, 3092.56, 3154.24, 3217.19, 3281.45, 3347.18, 3414.6, 3483.65, 3554.56, 3627.2, 3701.66, 3778.25, 3856.97, 3937.98, 4021.48, 4107.62, 4197.21, 4291.05, 4393.19, 4518.6, 5199.95}; 
  double hiHFbinedgesSysUp[201] = {0, 10.5075, 11.2107, 11.838, 12.4797, 13.1213, 13.7641, 14.4124, 15.0745, 15.7577, 16.473, 17.1939, 17.9297, 18.6812, 19.4958, 20.3143, 21.1648, 22.0218, 22.9159, 23.8328, 24.8059, 25.8204, 26.89, 27.9702, 29.1042, 30.3022, 31.528, 32.8347, 34.1896, 35.6439, 37.1542, 38.7172, 40.3518, 42.091, 43.9053, 45.7415, 47.6853, 49.7457, 51.8755, 54.0983, 56.3594, 58.7848, 61.2861, 63.9228, 66.6825, 69.4421, 72.297, 75.3547, 78.4967, 81.6977, 85.0755, 88.6211, 92.3058, 96.1071, 99.9975, 104.065, 108.272, 112.512, 116.906, 121.601, 126.465, 131.482, 136.866, 142.229, 147.786, 153.546, 159.571, 165.586, 171.902, 178.419, 185.063, 191.856, 199.055, 206.261, 213.999, 221.719, 229.671, 237.84, 246.088, 254.828, 263.883, 272.907, 282.236, 291.925, 301.519, 311.477, 321.691, 332.153, 342.892, 353.878, 365.161, 376.742, 388.577, 400.684, 413.075, 425.746, 438.711, 451.989, 465.556, 479.45, 493.608, 508.077, 522.891, 538.003, 553.415, 569.151, 585.216, 601.601, 618.354, 635.422, 652.84, 670.599, 688.699, 707.161, 726.014, 745.185, 764.687, 784.557, 804.838, 825.489, 846.537, 867.951, 889.752, 911.955, 934.588, 957.52, 980.912, 1004.73, 1028.94, 1053.57, 1078.67, 1104.17, 1130.07, 1156.39, 1183.2, 1210.47, 1238.17, 1266.38, 1295.02, 1324.16, 1353.71, 1383.77, 1414.35, 1445.41, 1477, 1509.09, 1541.74, 1574.88, 1608.59, 1642.83, 1677.66, 1713.07, 1748.98, 1785.47, 1822.63, 1860.33, 1898.72, 1937.73, 1977.42, 2017.71, 2058.62, 2100.25, 2142.57, 2185.56, 2229.38, 2273.91, 2319.2, 2365.33, 2412.22, 2459.94, 2508.52, 2557.98, 2608.35, 2659.61, 2711.86, 2765, 2819.23, 2874.58, 2930.97, 2988.46, 3047.12, 3106.95, 3168.15, 3230.6, 3294.37, 3359.58, 3426.47, 3494.95, 3565.21, 3637.21, 3711.03, 3786.91, 3864.85, 3945.11, 4027.8, 4113.06, 4201.73, 4294.72, 4395.9, 4520.5, 5199.95};

  h_hiHF = fs->make<TH1D>("hiHF edges"," ",200,hiHFbinedges);
  h_hiHFdown = fs->make<TH1D>("hiHF edges SysDown"," ",200,hiHFbinedgesSysDown);
  h_hiHFup = fs->make<TH1D>("hiHF edges SysUp"," ",200,hiHFbinedgesSysUp);


/*
  h_eff  = fs->make<TH3D>("Efficiency" , ";eff;p_{T}(GeV/c);cent" , 200, 1, 3, 25, 0.5,3.0,16,0,16 );


  h_multEv  = fs->make<TH1D>("multEv" , ";cent" , 16 , 0, 16 );

  h_W2  = fs->make<TH1D>("W2" , ";cent" , 16 , 0, 16 );
  h_W22  = fs->make<TH1D>("W22" , ";cent" , 16 , 0, 16 );
  h_W24  = fs->make<TH1D>("W24" , ";cent" , 16 , 0, 16 );
  h_W26  = fs->make<TH1D>("W26" , ";cent" , 16 , 0, 16 );
  h_W28  = fs->make<TH1D>("W28" , ";cent" , 16 , 0, 16 );
  h_W210  = fs->make<TH1D>("W210" , ";cent" , 16 , 0, 16 );

  h_W4  = fs->make<TH1D>("W4" , ";cent" , 16 , 0, 16 );
  h_W44  = fs->make<TH1D>("W44" , ";cent" , 16 , 0, 16 );
  h_W46  = fs->make<TH1D>("W46" , ";cent" , 16 , 0, 16 );
  h_W48  = fs->make<TH1D>("W48" , ";cent" , 16 , 0, 16 );
  h_W410  = fs->make<TH1D>("W410" , ";cent" , 16 , 0, 16 );

  h_W6  = fs->make<TH1D>("W6" , ";cent" , 16 , 0, 16 );
  h_W66  = fs->make<TH1D>("W66" , ";cent" , 16 , 0, 16 );
  h_W68  = fs->make<TH1D>("W68" , ";cent" , 16 , 0, 16 );
  h_W610  = fs->make<TH1D>("W610" , ";cent" , 16 , 0, 16 );

  h_W8  = fs->make<TH1D>("W8" , ";cent" , 16 , 0, 16 );
  h_W88  = fs->make<TH1D>("W88" , ";cent" , 16 , 0, 16 );
  h_W810  = fs->make<TH1D>("W810" , ";cent" , 16 , 0, 16 );

  h_W10  = fs->make<TH1D>("W10" , ";cent" , 16 , 0, 16 );
  h_W1010  = fs->make<TH1D>("W1010" , ";cent" , 16 , 0, 16 );
//efficency
  h_Mt  = fs->make<TH1D>("Mt" , ";cent" , 16 , 0, 16 );
  h_Mt2  = fs->make<TH1D>("Mt2" , ";cent" , 16 , 0, 16 );
  
  h_M2t  = fs->make<TH1D>("M2t" , ";cent" , 16 , 0, 16 );
  h_M2t2  = fs->make<TH1D>("M2t2" , ";cent" , 16 , 0, 16 );
  h_MM2t  = fs->make<TH1D>("MM2t" , ";cent" , 16 , 0, 16 );
  
  h_M3t  = fs->make<TH1D>("M3t" , ";cent" , 16 , 0, 16 );
  h_M3t2  = fs->make<TH1D>("M3t2" , ";cent" , 16 , 0, 16 );
  h_MM3t  = fs->make<TH1D>("MM3t" , ";cent" , 16 , 0, 16 );
  h_M2M3t  = fs->make<TH1D>("M" , ";cent" , 16 , 0, 16 );
  
  h_M4t  = fs->make<TH1D>("M4t" , ";cent" , 16 , 0, 16 );
  h_M4t2  = fs->make<TH1D>("M4t2" , ";cent" , 16 , 0, 16 );
  h_MM4t  = fs->make<TH1D>("MM4t" , ";cent" , 16 , 0, 16 );
  h_M2M4t  = fs->make<TH1D>("M2M4t" , ";cent" , 16 , 0, 16 );
  h_M3M4t  = fs->make<TH1D>("M3M4t" , ";cent" , 16 , 0, 16 );
  
  h_M5t  = fs->make<TH1D>("M5t" , ";cent" , 16 , 0, 16 );;
  h_M5t2  = fs->make<TH1D>("M5t2" , ";cent" , 16 , 0, 16 );
  h_MM5t  = fs->make<TH1D>("MM5t" , ";cent" , 16 , 0, 16 );
  h_M2M5t  = fs->make<TH1D>("M2M5t" , ";cent" , 16 , 0, 16 );
  h_M3M5t  = fs->make<TH1D>("M3M5t" , ";cent" , 16 , 0, 16 );
  h_M4M5t  = fs->make<TH1D>("M4M5t" , ";cent" , 16 , 0, 16 );
///

  h_W2Two  = fs->make<TH2D>("W2Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W4Four  = fs->make<TH2D>("W4Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W6Six  = fs->make<TH2D>("W6Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W8Eight  = fs->make<TH2D>("W8Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W10Ten  = fs->make<TH2D>("W10Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_SumW2Two  = fs->make<TH2D>("SumW2Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW22Two  = fs->make<TH2D>("SumW22Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW24Two  = fs->make<TH2D>("SumW24Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW26Two  = fs->make<TH2D>("SumW26Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW28Two  = fs->make<TH2D>("SumW28Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW210Two  = fs->make<TH2D>("SumW210Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW2Two  = fs->make<TH2D>("SumW2TwoW2Two" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_SumW4Four  = fs->make<TH2D>("SumW4Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW24Four  = fs->make<TH2D>("SumW24Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW44Four  = fs->make<TH2D>("SumW44Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW46Four  = fs->make<TH2D>("SumW46Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW48Four  = fs->make<TH2D>("SumW48Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW410Four  = fs->make<TH2D>("SumW410Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW4Four  = fs->make<TH2D>("SumW2TwoW4Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW4FourW4Four  = fs->make<TH2D>("SumW4FourW4Four" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_SumW6Six  = fs->make<TH2D>("SumW6Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW26Six  = fs->make<TH2D>("SumW26Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW46Six  = fs->make<TH2D>("SumW46Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW66Six  = fs->make<TH2D>("SumW66Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW68Six  = fs->make<TH2D>("SumW68Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW610Six  = fs->make<TH2D>("SumW610Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW6Six  = fs->make<TH2D>("SumW2TwoW6Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW4FourW6Six  = fs->make<TH2D>("SumW4FourW6Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW6SixW6Six  = fs->make<TH2D>("SumW6SixW6Six" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_SumW8Eight  = fs->make<TH2D>("SumW8Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW28Eight  = fs->make<TH2D>("SumW28Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW48Eight  = fs->make<TH2D>("SumW48Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW68Eight  = fs->make<TH2D>("SumW68Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW88Eight  = fs->make<TH2D>("SumW88Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW810Eight  = fs->make<TH2D>("SumW810Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW8Eight  = fs->make<TH2D>("SumW2TwoW8Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW4FourW8Eight  = fs->make<TH2D>("SumW4FourW8Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW6SixW8Eight  = fs->make<TH2D>("SumW6SixW8Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW8EightW8Eight  = fs->make<TH2D>("SumW8EightW8Eight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_SumW10Ten  = fs->make<TH2D>("SumW10Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW210Ten  = fs->make<TH2D>("SumW210Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW410Ten  = fs->make<TH2D>("SumW410Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_SumW610Ten  = fs->make<TH2D>("SumW610Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW810Ten  = fs->make<TH2D>("SumW810Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW1010Ten  = fs->make<TH2D>("SumW1010Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW10Ten  = fs->make<TH2D>("SumW2TwoW10Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_SumW4FourW10Ten  = fs->make<TH2D>("SumW4FourW10Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW6SixW10Ten  = fs->make<TH2D>("SumW6SixW10Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW8EightW10Ten  = fs->make<TH2D>("SumW8EightW10Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW10TenW10Ten  = fs->make<TH2D>("SumW10TenW10Ten" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_AveTwo  = fs->make<TH2D>("AveTwo" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveFour  = fs->make<TH2D>("AveFour" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveSix  = fs->make<TH2D>("AveSix" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveEight  = fs->make<TH2D>("AveEight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveTen  = fs->make<TH2D>("AveTen" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_VarAveTwo  = fs->make<TH2D>("VarAveTwo" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveFour  = fs->make<TH2D>("VarAveFour" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveSix  = fs->make<TH2D>("VarAveSix" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveEight  = fs->make<TH2D>("VarAveEight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveTen  = fs->make<TH2D>("VarAveTen" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_CovAveTwoAveFour  = fs->make<TH2D>("CovAveTwoAveFour" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveTwoAveSix  = fs->make<TH2D>("CovAveTwoAveSix" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveTwoAveEight  = fs->make<TH2D>("CovAveTwoAveEight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveTwoAveTen  = fs->make<TH2D>("CovAveTwoAveTen" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveFourAveSix  = fs->make<TH2D>("CovAveFourAveSix" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveFourAveEight  = fs->make<TH2D>("CovAveFourAveEight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveFourAveTen  = fs->make<TH2D>("CovAveFourAveTen" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveSixAveEight  = fs->make<TH2D>("CovAveSixAveEight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveSixAveTen  = fs->make<TH2D>("CovAveSixAveTen" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveEightAveTen  = fs->make<TH2D>("CovAveEightAveTen" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_CumTwo  = fs->make<TH2D>("CumTwo" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Two_v  = fs->make<TH2D>("Two_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrTwo_v  = fs->make<TH2D>("ErrTwo_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_CumFour  = fs->make<TH2D>("CumFour" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Four_v  = fs->make<TH2D>("Four_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrFour_v  = fs->make<TH2D>("ErrFour_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_CumSix  = fs->make<TH2D>("CumSix" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Six_v  = fs->make<TH2D>("Six_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrSix_v  = fs->make<TH2D>("ErrSix_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_CumEight  = fs->make<TH2D>("CumEight" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Eight_v  = fs->make<TH2D>("Eight_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrEight_v  = fs->make<TH2D>("ErrEight_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 
  h_CumTen  = fs->make<TH2D>("CumTen" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Ten_v  = fs->make<TH2D>("Ten_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrTen_v  = fs->make<TH2D>("ErrTen_v" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 ); 

//efficiency
  h_W2Twot  = fs->make<TH2D>("W2Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W4Fourt  = fs->make<TH2D>("W4Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W6Sixt  = fs->make<TH2D>("W6Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W8Eightt  = fs->make<TH2D>("W8Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_W10Tent  = fs->make<TH2D>("W10Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_SumW2Twot  = fs->make<TH2D>("SumW2Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW22Twot  = fs->make<TH2D>("SumW22Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW24Twot  = fs->make<TH2D>("SumW24Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW26Twot  = fs->make<TH2D>("SumW26Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW28Twot  = fs->make<TH2D>("SumW28Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW210Twot  = fs->make<TH2D>("SumW210Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW2Twot  = fs->make<TH2D>("SumW2TwoW2Twot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_SumW4Fourt  = fs->make<TH2D>("SumW4Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW24Fourt  = fs->make<TH2D>("SumW24Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW44Fourt  = fs->make<TH2D>("SumW44Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW46Fourt  = fs->make<TH2D>("SumW46Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW48Fourt  = fs->make<TH2D>("SumW48Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW410Fourt  = fs->make<TH2D>("SumW410Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW4Fourt  = fs->make<TH2D>("SumW2TwoW4Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW4FourW4Fourt  = fs->make<TH2D>("SumW4FourW4Fourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_SumW6Sixt  = fs->make<TH2D>("SumW6Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW26Sixt  = fs->make<TH2D>("SumW26Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW46Sixt  = fs->make<TH2D>("SumW46Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW66Sixt  = fs->make<TH2D>("SumW66Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW68Sixt  = fs->make<TH2D>("SumW68Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW610Sixt  = fs->make<TH2D>("SumW610Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW6Sixt  = fs->make<TH2D>("SumW2TwoW6Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW4FourW6Sixt  = fs->make<TH2D>("SumW4FourW6Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW6SixW6Sixt  = fs->make<TH2D>("SumW6SixW6Sixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_SumW8Eightt  = fs->make<TH2D>("SumW8Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW28Eightt  = fs->make<TH2D>("SumW28Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW48Eightt  = fs->make<TH2D>("SumW48Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW68Eightt  = fs->make<TH2D>("SumW68Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW88Eightt  = fs->make<TH2D>("SumW88Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW810Eightt  = fs->make<TH2D>("SumW810Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW8Eightt  = fs->make<TH2D>("SumW2TwoW8Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW4FourW8Eightt  = fs->make<TH2D>("SumW4FourW8Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW6SixW8Eightt  = fs->make<TH2D>("SumW6SixW8Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW8EightW8Eightt  = fs->make<TH2D>("SumW8EightW8Eightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_SumW10Tent  = fs->make<TH2D>("SumW10Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW210Tent  = fs->make<TH2D>("SumW210Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW410Tent  = fs->make<TH2D>("SumW410Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_SumW610Tent  = fs->make<TH2D>("SumW610Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW810Tent  = fs->make<TH2D>("SumW810Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW1010Tent  = fs->make<TH2D>("SumW1010Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW2TwoW10Tent  = fs->make<TH2D>("SumW2TwoW10Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_SumW4FourW10Tent  = fs->make<TH2D>("SumW4FourW10Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW6SixW10Tent  = fs->make<TH2D>("SumW6SixW10Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW8EightW10Tent  = fs->make<TH2D>("SumW8EightW10Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_SumW10TenW10Tent  = fs->make<TH2D>("SumW10TenW10Tent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_AveTwot  = fs->make<TH2D>("AveTwot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveFourt  = fs->make<TH2D>("AveFourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveSixt  = fs->make<TH2D>("AveSixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveEightt  = fs->make<TH2D>("AveEightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_AveTent  = fs->make<TH2D>("AveTent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_VarAveTwot  = fs->make<TH2D>("VarAveTwot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveFourt  = fs->make<TH2D>("VarAveFourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveSixt  = fs->make<TH2D>("VarAveSixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveEightt  = fs->make<TH2D>("VarAveEightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_VarAveTent  = fs->make<TH2D>("VarAveTent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_CovAveTwoAveFourt  = fs->make<TH2D>("CovAveTwoAveFourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveTwoAveSixt  = fs->make<TH2D>("CovAveTwoAveSixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveTwoAveEightt  = fs->make<TH2D>("CovAveTwoAveEightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveTwoAveTent  = fs->make<TH2D>("CovAveTwoAveTent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveFourAveSixt  = fs->make<TH2D>("CovAveFourAveSixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveFourAveEightt  = fs->make<TH2D>("CovAveFourAveEightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveFourAveTent  = fs->make<TH2D>("CovAveFourAveTent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveSixAveEightt  = fs->make<TH2D>("CovAveSixAveEightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveSixAveTent  = fs->make<TH2D>("CovAveSixAveTent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_CovAveEightAveTent  = fs->make<TH2D>("CovAveEightAveTent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_CumTwot  = fs->make<TH2D>("CumTwot" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Two_vt  = fs->make<TH2D>("Two_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrTwo_vt  = fs->make<TH2D>("ErrTwo_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_CumFourt  = fs->make<TH2D>("CumFourt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Four_vt  = fs->make<TH2D>("Four_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrFour_vt  = fs->make<TH2D>("ErrFour_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_CumSixt  = fs->make<TH2D>("CumSixt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Six_vt  = fs->make<TH2D>("Six_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrSix_vt  = fs->make<TH2D>("ErrSix_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_CumEightt  = fs->make<TH2D>("CumEightt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Eight_vt  = fs->make<TH2D>("Eight_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrEight_vt  = fs->make<TH2D>("ErrEight_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
  h_CumTent  = fs->make<TH2D>("CumTent" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_Ten_vt  = fs->make<TH2D>("Ten_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );  h_ErrTen_vt  = fs->make<TH2D>("ErrTen_vt" , ";vn;cent" , 5, 0, 5, 16 , 0, 16 );
////
*/

}

bool
Qnana::passesTrackCuts(const reco::Track & track, const reco::VertexCollection & vertex, double chi2n)
{
/*   if ( ! applyTrackCuts_ ) return true;

   math::XYZPoint vtxPoint(0.0,0.0,0.0);
   double vzErr =0.0, vxErr=0.0, vyErr=0.0;
   int primaryvtx = 0;
   vtxPoint=vertex[primaryvtx].position();
   vzErr=vertex[primaryvtx].zError();
   vxErr=vertex[primaryvtx].xError();
   vyErr=vertex[primaryvtx].yError();

   double dxy=0.0, dz=0.0, dxysigma=0.0, dzsigma=0.0;
   dxy = track.dxy(vtxPoint);
   dz = track.dz(vtxPoint);
   dxysigma = sqrt(track.d0Error()*track.d0Error()+vxErr*vyErr);
   dzsigma = sqrt(track.dzError()*track.dzError()+vzErr*vzErr);

   //double chi2n = 0;//track.normalizedChi2();
   double nlayers = track.hitPattern().trackerLayersWithMeasurement();
   chi2n = chi2n/nlayers;
   int nhits = track.numberOfValidHits();
   //int algo  = track.algo();

   if(track.quality(reco::TrackBase::qualityByName(qualityString_)) != 1)
       return false;

   if(fabs(dxy/dxysigma) > dxyErrMax_) return false;
   if(fabs(dz/dzsigma) > dzErrMax_) return false;

   if(fabs(track.ptError()) / track.pt() > ptErrMax_) return false;

   if(nhits < nhitsMin_ ) return false;

   int count = 0;
   for(unsigned i = 0; i < algoParameters_.size(); i++){
      if( algo == algoParameters_[i] ) count++;
   }
   if(chi2n > chi2nMax_ ) return false;

 //  if ( algo == 6 && trkMva < 0.98 ) return false;
*/
   return true;
}

bool
Qnana::vtxSort( const reco::Vertex &  a, const reco::Vertex & b )
{
  if( a.tracksSize() != b.tracksSize() )
    return  a.tracksSize() > b.tracksSize() ? true : false ;
  else
    return  a.chi2() < b.chi2() ? true : false ;
}


//define this as a plug-in
DEFINE_FWK_MODULE(Qnana);
