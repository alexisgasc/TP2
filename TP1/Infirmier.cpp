#include "Infirmier.h"
#include <iostream>
#include "Const.h"

Infirmier::Infirmier(const string & nom, 
                    const std::string & prenom, 
					const float & tauxHoraire)
{  
   // todo
   nom_ = nom;
   prenom_ = prenom;
   tauxHoraire_ = tauxHoraire;
   totalChambres_ = 0;
}

string Infirmier::getNom() const
{
	// todo
	return nom_;
}

string Infirmier::getPrenom() const
{
	// todo
	return prenom_;
}

float Infirmier::getTauxHoraire() const
{
	// todo
	return tauxHoraire_;
}

int Infirmier::getTotalChambres() const
{
	// todo
	return totalChambres_;
}

vector<string> Infirmier::getChambre() const
{ 
    // todo
	return listChambres_;
}

void Infirmier::setNom(const string & nom)
{
	// todo
	nom_ = nom;
}

void Infirmier::setPrenom (const string & prenom)
{
	// todo
	prenom_ = prenom;
}

void Infirmier::setTauxHoraire (const float & taux)
{
	// todo
	tauxHoraire_ = taux;
}

bool Infirmier::chercherChambre (const string & nbChambre){
   // todo  
   for (auto c : listChambres_){
		if (nbChambre == c){
			return true;
		}
   }
   return false;
}

void Infirmier:: ajouterChambre(const string & nbChambre){
    // todo
	if (!chercherChambre(nbChambre)){
		listChambres_.push_back(nbChambre);
		totalChambres_++;
	}
}

void Infirmier::retirerChambre (const string & nbChambre){
    // todo
	if (chercherChambre(nbChambre)){
		for (int i = 0; i < totalChambres_ ; i++) {
				if (listChambres_[i] == nbChambre) {
					listChambres_[i] = listChambres_.back();
					listChambres_.pop_back();
					totalChambres_--;
					return;
				}
		}
	}
}

unsigned Infirmier::getHeuresTravaillees() const{
	// todo
	return heuresTravaillees_;
}

void Infirmier::ajouterHeuresTravaillees(unsigned heures){
	// todo
	heuresTravaillees_+= heures;
}  
  
float  Infirmier::calculerSalaire() {
	// todo
	float salaire = heuresTravaillees_ * tauxHoraire_ + totalChambres_ * tauxHoraire_/20;
	heuresTravaillees_ = 0;
	return salaire;
}


ostream &Infirmier::afficher(ostream &out) const
{
	// todo
	out << "Nom: " << getNom() << endl;
	out << "Prenom: " << getPrenom() <<  endl;
	out << "Taux horaire: " << getTauxHoraire() << " $/h" << endl;
	out << "Heures travaillees: " << getHeuresTravaillees() << " heures" << endl;
	out << "Total chambres gerees: " << getTotalChambres() << endl;
	out << "Liste des chambres: ";
	for (auto c : listChambres_) {
		out << c << " ";
	}
	out << endl;
	return out;
}