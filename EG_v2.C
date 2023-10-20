#include <iostream>
#include <fstream>
using namespace std;

#include <TF1.h>
#include <TH1.h>
#include <TStyle.h>
#include <TMath.h>
#include <TCanvas.h>

void rootfuncgenerate(Int_t nEvents, Int_t nTracks, Double_t v2);

void rootfuncgenerate(Int_t nEvents, Int_t nTracks, Double_t v2) {
    ofstream file("phi_dist.dat");
    cout << "Generating " << nEvents << " events with " << nTracks << " tracks and v2 = " << v2 << endl << endl;

    TH1D* hPhi = new TH1D("hPhi", "Custom Distribution; #phi; Counts", 100, 0, 2 * TMath::Pi());

    TF1* phiFunc = new TF1("phiFunc", "1 + 2*[0]*cos(2*(x))", 0, 2 * TMath::Pi());
    phiFunc->SetParameter(0, v2); // Use the provided v2 parameter

    for (Int_t event = 0; event < nEvents; event++) {
        file << "Event " << event << endl;
        file << "nTracks " << nTracks << endl;

        for (Int_t nt = 0; nt < nTracks; nt++) {
            Double_t phi = phiFunc->GetRandom();
            file << nt << " : " << phi << endl; // Output phi values for tracks
            hPhi->Fill(phi); // Fill the histogram with phi values
        }
    }

    gStyle->SetOptStat(1111);
    gStyle->SetOptFit(1111);

    TCanvas* c1 = new TCanvas("c1", "Custom canvas", 900, 600);
    hPhi->SetMinimum(0);
    hPhi->Draw();

    TF1* fitPhi = new TF1("fitPhi", "[0] + 2*[1]*cos(2*(x))", 0, 2 * TMath::Pi());
    hPhi->Fit(fitPhi);

    c1->SaveAs("rootfunc_v2.jpg");
    file.close();
}