#include <TFile.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>

#include <iostream>
#include <vector>

//  use output TTree for short summary
void summary(TString fname) {
  if (fname.IsNull()) fname = "ma.root";

  TFile *fin = new TFile(fname.Data(), "READ");
  TTreeReader myreader("Score", fin);
  TTreeReaderValue<int> hid(myreader, "HitID");
  TTreeReaderValue<int> tz(myreader, "IonZ");
  TTreeReaderValue<int> ta(myreader, "IonA");
  TTreeReaderValue<int> vc(myreader, "VCode");
  TTreeReaderValue<double> edep(myreader, "Edep");
  TTreeReaderValue<double> time(myreader, "Time");
  TTreeReaderValue<double> xpos(myreader, "Hitxloc");
  TTreeReaderValue<double> ypos(myreader, "Hityloc");
  TTreeReaderValue<double> zpos(myreader, "Hitzloc");
  
  // event loop
  while (myreader.Next())
  {
    std::cout << "<<< Hit Track ID " << *hid << std::endl;
    std::cout << "Ion Z: " << *tz << std::endl;
    std::cout << "Ion A: " << *ta << std::endl;
    std::cout << "deposited energy [MeV]: " << *edep << std::endl;
    std::cout << "global time [ns]: " << *time << std::endl;
    std::cout << "hit volume code: " << *vc << std::endl;
    std::cout << "hit pos x [m]: " << *xpos << std::endl;
    std::cout << "hit pos y [m]: " << *ypos << std::endl;
    std::cout << "hit pos z [m]: " << *zpos << std::endl;
  }

}

//  use output TTree for trajectory summary
void trajectory(TString fname) {
  if (fname.IsNull()) fname = "ma.root";

  TFile *fin = new TFile(fname.Data(), "READ");
  TTreeReader myreader("Score", fin);
  TTreeReader trjreader("Traj", fin);
  TTreeReaderValue<int> evid(myreader, "EventID");
  TTreeReaderValue<int> hid(myreader, "HitID");
  TTreeReaderValue<int> tz(myreader, "IonZ");
  TTreeReaderValue<int> ta(myreader, "IonA");
  TTreeReaderValue<int> vc(myreader, "VCode");
  TTreeReaderValue<double> edep(myreader, "Edep");
  TTreeReaderValue<double> time(myreader, "Time");
  TTreeReaderValue<double> xpos(myreader, "Hitxloc");
  TTreeReaderValue<double> ypos(myreader, "Hityloc");
  TTreeReaderValue<double> zpos(myreader, "Hitzloc");

  TTreeReaderValue<int> evtrj(trjreader, "EventID");
  TTreeReaderValue<int> pdg(trjreader, "Trjpdg");
  TTreeReaderValue<int> vtxc(trjreader, "VtxName");
  TTreeReaderValue<double> trjx(trjreader, "TrjXVtx");
  TTreeReaderValue<double> trjy(trjreader, "TrjYVtx");
  TTreeReaderValue<double> trjz(trjreader, "TrjZVtx");
  
  // event loop
  while (myreader.Next())
  {
    std::cout << "<<< Event ID " << *evid << std::endl;
    std::cout << "<<< Hit Track ID " << *hid << std::endl;
    std::cout << "Ion Z: " << *tz << std::endl;
    std::cout << "Ion A: " << *ta << std::endl;
    std::cout << "deposited energy [MeV]: " << *edep << std::endl;
    std::cout << "global time [ns]: " << *time << std::endl;
    std::cout << "hit volume code: " << *vc << std::endl;
    std::cout << "hit pos x [m]: " << *xpos << std::endl;
    std::cout << "hit pos y [m]: " << *ypos << std::endl;
    std::cout << "hit pos z [m]: " << *zpos << std::endl;
  }
  while (trjreader.Next())
  {
    std::cout << "<<< Event ID " << *evtrj << std::endl;
    std::cout << "Trj PDG: " << *pdg << " Vtx name: " << *vtxc << std::endl;
    std::cout << "vtx x " << *trjx << " vtx y " << *trjy << " vtx z " << *trjz << std::endl;
  }
}
