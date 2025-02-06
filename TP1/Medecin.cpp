/********************************************
 * Titre: Travail pratique #1 - Medecin.cpp
 *  Date: 2005-01-16
 *  Auteur: Noe Masurel 2272702 Alexis Gasc 2279586
 *******************************************/

#include"Medecin.h"
#include <iostream>
#include "Const.h"

Medecin::Medecin(const string& nom)
{
	// todo
	nom_ = nom;
}

Medecin::Medecin(const string& nom,Specialite * uneSpecialite, float salaire)
{
	// todo
	nom_ = nom;
	specialite_ = uneSpecialite;
	salaire_ = salaire;
}

string Medecin::getNom() const
{
	// todo
	return nom_;
}

Specialite * Medecin::getSpecialite() const
{
	// todo
	return specialite_;
}

void Medecin::setNom(const string& nom)
{
	// todo
	nom_ = nom;
}
 
void Medecin::setSpecialite( Specialite * specialite)
{
	// todo
	specialite_ = specialite;
}

float Medecin::calculerSalaire() const{
	// todo
	if (specialite_) {
		return salaire_ * specialite_->getNiveau();
	}
	else {
		return salaire_;
	}
} 
ostream &Medecin::afficher(ostream &out) const
{  
	// todo
	out << "Nom: " << getNom() << endl;
	Specialite* specialite = getSpecialite();
	specialite->afficher(out);
	out << "Salaire: " << calculerSalaire() << " $" << endl;
	
	return out ;
}

