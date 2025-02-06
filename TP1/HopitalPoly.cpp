/**********************************************
 * Titre: Travail pratique #1 - HopitalPoly.cpp
 *  Date: 2005-01-16
 *  Auteur: Noe Masurel 2272702 Alexis Gasc 2279586 
 *********************************************/



#include "Medecin.h"
#include "Infirmier.h"
#include "HopitalPoly.h"
#include <iostream>
#include "Const.h"

HopitalPoly::HopitalPoly(const string & nom) {
	// todo
	nom_ = nom;
}
string  HopitalPoly::getNom() const
{  
	// todo
	return nom_;
}
vector<Medecin*> HopitalPoly:: getMedecins() const
{ 
	// todo
	return tableauMedecins_;
}

vector<Infirmier*> HopitalPoly::getInfirmiers() const
{ 
	// todo
	return tableauInfirmiers_;
}
void  HopitalPoly::setNom(string  nom)
{ 
	// todo
	nom_ = nom;

}
	// Methodes publiques
bool HopitalPoly::chercherMedecin(const Medecin * unMedecin)const
{
	// todo
	for(auto medecin : tableauMedecins_){
		if (medecin == unMedecin) {
			return true;
		}
	}
	return false;
}

void HopitalPoly::ajouterMedecin( Medecin * unMedecin)
{
	// todo
	if (!chercherMedecin(unMedecin)) {
		tableauMedecins_.push_back(unMedecin);
	}
}

void HopitalPoly::supprimerMedecin(const Medecin * unMedecin)
{
	// todo
	if (chercherMedecin(unMedecin)) {
		for (int i = 0; i < tableauMedecins_.size(); i++) {
			if (tableauMedecins_[i] == unMedecin) {
				tableauMedecins_[i] = tableauMedecins_.back();
				tableauMedecins_.pop_back();
				return;
			}
		}
	}
}


bool HopitalPoly::chercherInfirmier(const Infirmier * unInfirmier)const
{  
	// todo
	for(auto infirmier : tableauInfirmiers_){
		if (infirmier == unInfirmier) {
			return true;
		}
	}
	return false;
}

void HopitalPoly::ajouterInfirmier(Infirmier * unInfirmier)
{
	// todo
	if (!chercherInfirmier(unInfirmier)) {
		tableauInfirmiers_.push_back(unInfirmier);
	}
}

void HopitalPoly::supprimerInfirmier(const Infirmier * unInfirmier)
{
	// todo
	if (chercherInfirmier(unInfirmier)) {
		for (auto& infirmier : tableauInfirmiers_) {
			if (infirmier == unInfirmier) {
				infirmier = tableauInfirmiers_.back();
				tableauInfirmiers_.pop_back();
				return;
			}
		}
	}
}

void HopitalPoly:: afficherMedecins(ostream &out) const
{ 
	// todo
	for(auto medecin : tableauMedecins_){
		medecin->afficher(out);
	}
}

void HopitalPoly::afficherInfirmiers(ostream &out) const
{
	// todo
	for(Infirmier* infirmier : tableauInfirmiers_){
		infirmier->afficher(out);
	}
}

ostream &HopitalPoly::afficher(ostream &out) const{
	// todo
	out << "Nom de l'Hopital: " << getNom() << endl;
	out << "Liste des infirmiers:\n";
	afficherInfirmiers(out);
	out << "Liste des medecins:\n";
	afficherMedecins(out);
	return out;
}