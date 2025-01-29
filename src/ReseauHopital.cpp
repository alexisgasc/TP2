#include "HopitalPoly.h"
#include <iostream>
#include "ReseauHopital.h"

ReseauHopital::ReseauHopital(const string & nom):nom_(nom) {
}

string  ReseauHopital::getNom() const
{ return nom_;}

void  ReseauHopital::setNom(const string & nom)
{ nom_ = nom;}

size_t  ReseauHopital::getNumbHospitals()
{ return tableauHopitaux_.size();}

ostream& ReseauHopital::afficher(ostream & out) const
{
	//"Nom du reseau d'hopital: Reseau Sante Quebec\n"
	out << "Nom du reseau d'hopital: " << this->getNom();
	for (const auto& hopital : tableauHopitaux_) {
		cout << hopital;
	}
	return out;
}

bool ReseauHopital::chercherHopital(const HopitalPoly* hopital) const
{
	for (int i = 0; i < tableauHopitaux_.size(); i++) {
		if (tableauHopitaux_[i].get() == hopital)
			return true;
	}
	return false;
}

ReseauHopital& ReseauHopital::operator+=(unique_ptr<HopitalPoly>& hopital)
{
	if (!chercherHopital(hopital.get())) {
		tableauHopitaux_.push_back(std::move(hopital));
	}
	return *this;
}

ReseauHopital& ReseauHopital::operator-=(string& nomHopital)
{
	for (int i = 0; i < tableauHopitaux_.size(); i++) {
		if (tableauHopitaux_[i]->getNom() == nomHopital) {
			tableauHopitaux_[i] = move(tableauHopitaux_.back());
			tableauHopitaux_.pop_back();
		}
	}
	return *this;
}

ostream& operator<<(ostream& o, const ReseauHopital& c)
{
	return c.afficher(o);
}
