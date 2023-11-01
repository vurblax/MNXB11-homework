#ifndef WRITE_H
#define WRITE_H

#include "TObject.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"

class MyParticle {
public:
    MyParticle() : px(0.0), py(0.0), pz(0.0) {}

    Double_t CalculateMagnitude() {
        return TMath::Sqrt(px * px + py * py + pz * pz);
    }

    Double_t px;
    Double_t py;
    Double_t pz;
};

#endif //WRITE_H
