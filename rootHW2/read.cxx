#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "write.h"
#include <iostream>

void read() {

    TFile* file = TFile::Open("tree_file.root", "READ");

    if (!file) {
        std::cerr << "Failed to open the ROOT file." << std::endl;
        return;
    }

    TTree* tree = dynamic_cast<TTree*>(file->Get("tree"));

    MyParticle* particle = new MyParticle();
    tree->SetBranchAddress("px", &(particle->px));
    tree->SetBranchAddress("py", &(particle->py));
    tree->SetBranchAddress("pz", &(particle->pz));
    
    TH2F* hist2D = new TH2F("hist2D", "Scatter plot of px * py vs. pz", 100, -0.2, 0.2, 100, -0.2, 0.2);

    for (Int_t i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);

        if (particle->CalculateMagnitude() > 0.1) {
            hist2D->Fill(particle->px * particle->py, particle->pz);
        }
    }

    TCanvas* canvas = new TCanvas("canvas", "Canvas", 800, 600);
    hist2D->Draw("COLZ"); 

    canvas->SaveAs("scatter_plot.png");
    
    delete particle;
    delete canvas;
    file->Close();
}
