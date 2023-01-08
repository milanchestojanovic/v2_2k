import FWCore.ParameterSet.Config as cms

d0ana = cms.EDAnalyzer('Qnana',
  doRecoNtuple = cms.untracked.bool(True),
  doGenNtuple = cms.untracked.bool(False),
  doGenMatching = cms.untracked.bool(False),
  doGenMatchingTOF = cms.untracked.bool(False),
  hasSwap = cms.untracked.bool(True),
  decayInGen = cms.untracked.bool(False),
  twoLayerDecay = cms.untracked.bool(False),
  threeProngDecay = cms.untracked.bool(False),
  #PID used only for GEN and/or GEN match
  PID = cms.untracked.int32(421),
  PID_dau1 = cms.untracked.int32(211),
  PID_dau2 = cms.untracked.int32(321),
  deltaR = cms.untracked.double(0.03),
  #VertexCollection = cms.untracked.InputTag("offlinePrimaryVertices"),
  VertexCollection = cms.untracked.InputTag("offlineSlimmedPrimaryVerticesRecovery"),
  TrackCollection = cms.untracked.InputTag("generalTracks"),
  pfCandSrc = cms.untracked.InputTag("particleFlowTmp"),
  srcPFcand = cms.InputTag("packedPFCandidates"),
  chi2Map = cms.InputTag("packedPFCandidateTrackChi2"),

  VertexCompositeCollection = cms.untracked.InputTag("generalD0CandidatesNew:D0"),
  GenParticleCollection = cms.untracked.InputTag("genParticles"),
  MuonCollection = cms.untracked.InputTag("null"),
  doMuon = cms.untracked.bool(False),
  doMuonFull = cms.untracked.bool(False),

  saveTree = cms.untracked.bool(True),
  saveHistogram = cms.untracked.bool(False),
  saveAllHistogram = cms.untracked.bool(False),
  massHistPeak = cms.untracked.double(1.86),
  massHistWidth = cms.untracked.double(0.2),
  massHistBins = cms.untracked.int32(100),

  pTBins = cms.untracked.vdouble(0,1.2,1.5,2.4,3.0,3.5,4.2,5.0,6.0,7.0,8.0),
  yBins = cms.untracked.vdouble(-2.4,-1.0,0.0,1.0,2.4),

  useAnyMVA = cms.bool(False),
  isSkimMVA = cms.untracked.bool(False),
  MVACollection = cms.InputTag("generalD0CandidatesNew:MVAValues"),

  useCentrality = cms.bool(True),
  centralityBinLabel = cms.InputTag("centralityBin","HFtowers"),
  centralitySrc = cms.InputTag("hiCentrality"),
  centralitySrc1 = cms.InputTag("hiCentrality"),
  vertexSrc = cms.InputTag("offlineSlimmedPrimaryVerticesRecovery"),
    applyVertexZCut = cms.bool(False),
    vertexZMax = cms.double(15.),
    vertexZMin = cms.double(0.),
    applyTrackCuts = cms.bool(True),
    qualityString = cms.string("highPurity"),
    dxyErrMax = cms.double(3.0),
    dzErrMax = cms.double(3.0),
    ptErrMax = cms.double(0.1),
    nhitsMin = cms.int32(0),
    chi2nMax = cms.double(9999.0)

                              )

