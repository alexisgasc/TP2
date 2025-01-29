/**********************************************
 * Titre: Travail pratique #1 - HopitalPoly.cpp
 * Date: 10 janvier 2017
 * Auteur: 
 *********************************************/
 
//test branch 2 Alexis

#include "Medecin.h"
#include "Infirmier.h"
#include "HopitalPoly.h"
#include <iostream>

HopitalPoly::HopitalPoly(const string & nom):nom_(nom) {
}
string  HopitalPoly::getNom() const
{ return nom_;}
vector<shared_ptr<Medecin>> HopitalPoly:: getMedecins() const
{ return tableauMedecins_;}

vector<shared_ptr<Infirmier>> HopitalPoly::getInfirmiers() const
{ return tableauInfirmiers_;}
void  HopitalPoly::setNom( string  nom)
{ nom_ = nom;}
	// Methodes publiques
bool HopitalPoly::chercherMedecin(const shared_ptr<Medecin> &medecin)const
{
	 for ( auto med: tableauMedecins_)
	   if (*med == *medecin)
	      return true;
    return false;		  
}

bool HopitalPoly::chercherInfirmier(const shared_ptr<Infirmier> &infirmier)const
{ 
	for ( auto med: tableauInfirmiers_)
	   if (*med == *infirmier)
	      return true;
    return false;	
}


void HopitalPoly:: afficherMedecins(ostream &out) const
{ 
	for (unsigned i = 0 ; i < tableauMedecins_.size(); i++){
		tableauMedecins_[i]->afficher(out);
	}
}
void HopitalPoly::afficherInfirmiers(ostream &out) const
{
	for ( unsigned i = 0 ; i < tableauInfirmiers_.size(); i++){
		tableauInfirmiers_[i]->afficher(out);
	}
}

ostream &HopitalPoly::afficher(ostream &out) const{
	out << "Nom de l'Hopital: " << nom_ << endl;
	out <<"Liste des infirmiers:"<< endl;
	afficherInfirmiers(out);
	out <<"Liste des medecins:"<< endl;
	afficherMedecins(out);
	return out;
}

HopitalPoly::HopitalPoly(const HopitalPoly& h) : 
nom_(h.nom_), tableauInfirmiers_(h.tableauInfirmiers_), tableauMedecins_(h.tableauMedecins_){}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Medecin>& medecin)
{
	if (!chercherMedecin(medecin)) {
		tableauMedecins_.push_back(medecin);
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Infirmier>& infirmier)
{
	if (!chercherInfirmier(infirmier)) {
		tableauInfirmiers_.push_back(infirmier);
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator+=(const HopitalPoly& hopital)
{
	for (auto inf : hopital.tableauInfirmiers_) {
		*this += inf;
	}
	for (auto med : hopital.tableauMedecins_) {
		*this += med;
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Medecin>& medecin)
{
	if (chercherMedecin(medecin)) {
		for (auto med : this->tableauMedecins_) {
			if (medecin == med) {
				med = tableauMedecins_.back();
				tableauMedecins_.pop_back();
			}
		}
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator-=(string& medecin)
{
	for (int i = 0; i < tableauMedecins_.size(); i++) {
		if (tableauMedecins_[i]->getNom() == medecin) {
			tableauMedecins_[i] = tableauMedecins_.back();
			tableauMedecins_.pop_back();
		}
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Infirmier>& infirmier)
{
	if (this->chercherInfirmier(infirmier)) {
		for (auto inf : this->tableauInfirmiers_) {
			if (inf == infirmier) {
				inf = this->tableauInfirmiers_.back();
				this->tableauInfirmiers_.pop_back();
			}
		}
	}
	return *this;
}

bool HopitalPoly::operator==(const HopitalPoly& rhs) const
{
	return (nom_ == rhs.nom_ && tableauInfirmiers_ == rhs.tableauInfirmiers_ && tableauMedecins_ == rhs.tableauMedecins_);;
}

ostream& operator<<(ostream& o, const HopitalPoly& c)
{
	return c.afficher(o);
}
