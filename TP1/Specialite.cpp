#include "Specialite.h"
#include <iostream>
#include "Const.h"

Specialite::Specialite()
{
	//todo
	domaine_ = "";
	niveau_ = 0;
}

Specialite::Specialite(const string & domaine, unsigned niveau)
{ 
	// todo
	domaine_ = domaine;
	niveau_ = niveau;
}

std::string Specialite::getDomaine() const
{
	// todo
	return domaine_;
}

unsigned int Specialite::getNiveau() const
{
	// todo
	return niveau_;
}

void Specialite::setDomaine(const std::string & domaine)
{
	// todo
	domaine_  = domaine;
}

void Specialite::setNiveau(unsigned int niveau)
{
	// todo
	niveau_ = niveau;
}

ostream &Specialite::afficher(ostream &out) const
{
	//  todo
	out << "Domaine: " << getDomaine() << endl;
	out << "Niveau: " << getNiveau() << endl;
	return out;
}
