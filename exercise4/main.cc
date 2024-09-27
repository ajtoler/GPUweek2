#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "t1.h"

#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h> 
#include <TLorentzVector.h>



//------------------------------------------------------------------------------
// Particle Class
//
class Particle{

	public:
	Particle();
	Particle(double p0, double p1, double p2, double p3);
	double   pt, eta, phi, E, m, p[4];
	void     p4(double, double, double, double);
	void     print();
	void     setMass(double);
	double   sintheta();
};

class Lepton: public Particle{
	public:
	int q;
	void setCharge(int);
};

class Jet: public Particle{
	public:
	int f;
	void setFlavor(int);
};

//------------------------------------------------------------------------------

//*****************************************************************************
//                                                                             *
//    MEMBERS functions of the Particle Class                                  *
//                                                                             *
//*****************************************************************************

//
//*** Default constructor ------------------------------------------------------
//
Particle::Particle(){
	pt = eta = phi = E = m = 0.0;
	p[0] = p[1] = p[2] = p[3] = 0.0;
}

//*** Additional constructor ------------------------------------------------------
Particle::Particle(double p0, double p1, double p2, double p3){ 
    p[0] = p0;
    p[1] = p1;
    p[2] = p2;
    p[3] = p3;
    pt = sqrt(pow(p[1], 2) + pow(p[2], 2));
    double pMag = sqrt(pow(p[1], 2) + pow(p[2], 2) + pow(p[3], 2)); 
    eta = 0.5 * log((pMag + p[3]) / (pMag - p[3])); 
    phi = atan2(p[2], p[1]); 
    E = p0; 
    m = sqrt(pow(p[0], 2) - pow(pMag, 2));
}

//
//*** Members  ------------------------------------------------------
//
double Particle::sintheta(){
	double theta = 2*atan(exp(-1*eta));
	return sin(theta);
}

void Particle::p4(double pT, double eta, double phi, double energy){
	p[0] = energy;
	p[1] = pT*cos(phi);
	p[2] = pT*sin(phi);
	p[3] = pT*sinh(eta);
}

void Particle::setMass(double mass)
{
	m = mass;
}

void Lepton::setCharge(int charge)
{
	q = charge;
}

void Jet::setFlavor(int flavor)
{
	f = flavor;
}

//
//*** Prints 4-vector ----------------------------------------------------------
//
void Particle::print(){
	std::cout << std::endl;
	std::cout << "(" << p[0] <<",\t" << p[1] <<",\t"<< p[2] <<",\t"<< p[3] << ")" << "  " <<  sintheta() << std::endl;
}

int main() {
	
	/* ************* */
	/* Input Tree   */
	/* ************* */

	TFile *f = new TFile("input.root","READ");
	TTree *t1 = (TTree*)(f->Get("t1"));

	// Read the variables from the ROOT tree branches
	t1->SetBranchAddress("lepPt",&lepPt);
	t1->SetBranchAddress("lepEta",&lepEta);
	t1->SetBranchAddress("lepPhi",&lepPhi);
	t1->SetBranchAddress("lepE",&lepE);
	t1->SetBranchAddress("lepQ",&lepQ);
	
	t1->SetBranchAddress("njets",&njets);
	t1->SetBranchAddress("jetPt",&jetPt);
	t1->SetBranchAddress("jetEta",&jetEta);
	t1->SetBranchAddress("jetPhi",&jetPhi);
	t1->SetBranchAddress("jetE", &jetE);
	t1->SetBranchAddress("jetHadronFlavour",&jetHadronFlavour);

	// Total number of events in ROOT tree
	Long64_t nentries = t1->GetEntries();

	// Created array to ensure correctly storing
	std::vector<Lepton> leptons;
	std::vector<Jet> jets;
	Lepton lepton;
	Jet jet;

	for (Long64_t jentry=0; jentry<100;jentry++)
 	{
		t1->GetEntry(jentry);
		std::cout<<" Event "<< jentry <<std::endl;

		// If lepton, save info
		if (lepPt[jentry] !=0 || lepEta[jentry] != 0 || lepPhi[jentry] != 0 || lepE[jentry] != 0 || lepQ[jentry] != 0) {
			// std::cout<<" Lepton Pt: "<< lepPt[jentry] << ", Eta: " << lepEta[jentry] << ", Phi: " << lepPhi[jentry] << ", E: " << lepE[jentry] << ", m: " << lepQ[jentry] <<std::endl;
			lepton.pt = lepPt[jentry];
			lepton.eta = lepEta[jentry];
			lepton.phi = lepPhi[jentry];
			lepton.E = lepE[jentry]; 
			lepton.q = lepQ[jentry];
			lepton.p4(lepPt[jentry], lepEta[jentry], lepPhi[jentry], lepE[jentry]);

			leptons.push_back(lepton);
			std::cout << " Lepton pt: " << lepton.pt << ", eta: " << lepton.eta << ", phi: " << lepton.phi << ", E: " << lepton.E << ", m: " << lepton.m << ", p4: [" << lepton.p[0] << ", " << lepton.p[1] << ", " << lepton.p[2] << ", " << lepton.p[3] << "], q: " << lepton.q << std::endl;
		}

		// If jet(s), loop through all jets and save info
		if (njets != 0){
			std::cout<<" Number of Jets: " << njets << std::endl;
			for (int i = 0; i < njets; i++){
				if (jetPt[i] != 0 || jetEta[i] != 0 || jetPhi[i] != 0 || jetE[i] != 0 || jetHadronFlavour[i] >= 0){
					// std::cout<<" Jet n: " << i << ", Pt: "<< jetPt[i] << ", Eta: " << jetEta[i] << ", Phi: " << jetPhi[i] << ", E: " << jetE[i] << ", flavor: " << jetHadronFlavour[i] <<std::endl;	
					jet.pt = jetPt[i];
					jet.eta = jetEta[i];
					jet.phi = jetPhi[i];
					jet.E = jetE[i]; 
					jet.f = jetHadronFlavour[i];
					jet.p4(jetPt[i], jetEta[i], jetPhi[i], jetE[i]);
					jet.setMass(sqrt(pow(jet.p[0], 2) - pow(jet.p[1], 2) - pow(jet.p[2], 2) - pow(jet.p[3], 2)));

					jets.push_back(jet);
					std::cout << " Jet pt: " << jet.pt << ", eta: " << jet.eta << ", phi: " << jet.phi << ", E: " << jet.E << ", m: " << jet.m << ", p4: [" << jet.p[0] << ", " << jet.p[1] << ", " << jet.p[2] << ", " << jet.p[3] << "], f: " << jet.f << std::endl;

				}
			}
		}
	} // Loop over all events

  	return 0;
}
