import FWCore.ParameterSet.Config as cms
from Configuration.StandardSequences.Eras import eras
process = cms.Process('D0PbPb2018SKIM',eras.Run2_2018_pp_on_AA)

process.load('Configuration.StandardSequences.Services_cff')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.ReconstructionHeavyIons_cff')
#process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("CondCore.CondDB.CondDB_cfi")
process.load('Configuration.EventContent.EventContent_cff')

process.Timing = cms.Service("Timing",
  summaryOnly = cms.untracked.bool(True),
  useJobReport = cms.untracked.bool(True)
)

# Limit the output messages
process.load('FWCore.MessageService.MessageLogger_cfi')
process.MessageLogger.cerr.FwkReport.reportEvery = 100

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool( True ),
)

process.source = cms.Source("PoolSource",
   fileNames = cms.untracked.vstring(
 "/store/hidata/HIRun2018A/HIMinimumBias19/MINIAOD/PbPb18_MiniAODv1-v1/30000/55fb9ef1-ffc5-4e8c-b936-944c64e05c56.root"
   ),
   #lumisToProcess = cms.untracked.VLuminosityBlockRange('327526:179')

)
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))


# Set the global tag
#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
#process.GlobalTag.globaltag = cms.string('103X_dataRun2_v6')
# Set the global tag
#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '103X_dataRun2_v6', '')
process.GlobalTag = GlobalTag(process.GlobalTag, '112X_dataRun2_PromptLike_HI_v3', '')

process.load("RecoHI.HiCentralityAlgos.CentralityBin_cfi")
process.centralityBin.Centrality = cms.InputTag("hiCentrality")
process.centralityBin.centralityVariable = cms.string("HFtowers")

#process.cent_seq = cms.Sequence(process.hiCentrality * process.centralityBin)
#process.cent_seq = cms.Sequence(process.centralityBin)


# D0 candidate rereco 
process.load("vn_10Qum.Qnana.v210analyzer_tree_cfi")
process.v210ana.useAnyMVA = cms.bool(True)
process.v210ana.isCentrality = cms.bool(True)
process.v210ana.MVACollection = cms.InputTag("generalD0CandidatesNewPromptBDT","MVAValuesNewD0")
process.v210ana.VertexCompositeCollection = cms.untracked.InputTag("generalD0CandidatesNewPromptBDT","D0")
process.v210ana.saveTree = True
process.v210ana.saveHistogram = False
process.v210ana.doRecoNtuple = cms.untracked.bool(True)
process.v210ana.doGenNtuple = cms.untracked.bool(False)
process.v210ana.isEventPlane = cms.bool(True)
process.v210ana.eventplaneSrc = cms.InputTag("hiEvtPlaneFlat")
process.v210ana.isSkimMVA = cms.untracked.bool(False) 
process.v210ana.centralitySrc = cms.InputTag("centralityBin","HFtowers")
process.v210ana.centralitySrc1 = cms.InputTag("hiCentrality","","reRECO")

process.v210ana.applyTrackCuts = True
process.v210ana.applyVertexZCut = True
#process.v210ana.doCaloMatched = False
# cut values
process.v210ana.dxyErrMax = 3.0
process.v210ana.dzErrMax = 3.0
process.v210ana.ptErrMax = 0.1
process.v210ana.nhitsMin = 11
process.v210ana.chi2nMax = 0.18



# Add PbPb collision event selection
#process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVerticesRecovery_cfi")
#process.load('HeavyIonsAnalysis.EventAnalysis.skimanalysis_cfi')
#process.load('HeavyIonsAnalysis.Configuration.collisionEventSelection_cff')
#process.load('HeavyIonsAnalysis.Configuration.hfCoincFilter_cff')


# Define the event selection sequence
process.load('HeavyIonsAnalysis.EventAnalysis.skimanalysis_cfi')
process.load('HeavyIonsAnalysis.EventAnalysis.collisionEventSelection_cff')
process.eventFilter = cms.Sequence(
    process.phfCoincFilter2Th4 *
    process.primaryVertexFilter *
    process.clusterCompatibilityFilter
)


# Define the analysis steps
#process.pcentandep_step = cms.Path(process.eventFilter_HM * process.cent_seq * process.evtplane_seq)
#process.pcentandep_step = cms.Path(process.eventFilter_HM * process.centralityBin)
process.d0rereco_step = cms.Path(process.eventFilter*process.v210ana)


# Define the output
process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('v210ana_PbPb2018.root')
                                  )




# Define the process schedule
process.schedule = cms.Schedule(
    #process.eventFilter_HM_step,
    #process.pcentandep_step,
    process.d0rereco_step,
#    process.output_HM_step
)


# peripheral pv recovery 
from HLTrigger.Configuration.CustomConfigs import MassReplaceInputTag
#process = MassReplaceInputTag(process,"offlinePrimaryVertices","offlinePrimaryVerticesRecovery")
#process.offlinePrimaryVerticesRecovery.oldVertexLabel = "offlinePrimaryVertices"
