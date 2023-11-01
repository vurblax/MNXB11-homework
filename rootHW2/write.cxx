#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TRandom3.h"
#include "write.h"

const Int_t nEvents = 1000; 

void write() {
    TFile* file = new TFile("tree_file.root", "RECREATE");
    TTree* tree = new TTree("tree", "Tree of MyParticles");

    MyParticle* particle = new MyParticle();

    tree->Branch("px", &(particle->px), "px/D");
    tree->Branch("py", &(particle->py), "py/D");
    tree->Branch("pz", &(particle->pz), "pz/D");
    
    Double_t magnitude; 
    tree->Branch("magnitude", &magnitude, "magnitude/D");

    TRandom3* rand = new TRandom3();

    for (Int_t i = 0; i < nEvents; i++) {

        particle->px = rand->Gaus(0, 0.02);
        particle->py = rand->Gaus(0, 0.02);
        particle->pz = rand->Gaus(0, 0.02);

        magnitude = TMath::Sqrt(particle->px * particle->px + particle->py * particle->py + particle->pz * particle->pz);

        tree->Fill();
    }

    tree->Write();
    file->Close();

    delete particle;
    delete file;
}

