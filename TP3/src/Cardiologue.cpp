#include "Cardiologue.h"

Cardiologue::Cardiologue(const string& nom, unsigned nbPatients, unsigned nbConferences, unsigned int niveau) : 
    Medecin(nom, new Specialite("Cardiologie", niveau)), nbPatients_(nbPatients), nbConferences_(nbConferences), nbPublications_(0) {}

unsigned int Cardiologue::getNbPatients() const {
    return nbPatients_;
}

void Cardiologue::setNbPatients(unsigned int nbPatients) {
    nbPatients_ = nbPatients;
}

unsigned int Cardiologue::getNbConferences() const {
    return nbConferences_;
}

void Cardiologue::setNbConferences(unsigned int nbConferences) {
    nbConferences_ = nbConferences;
}

unsigned int Cardiologue::getNbPublications() const {
    return nbPublications_;
}

void Cardiologue::ajouterPublications(unsigned int nbPublications) {
    nbPublications_ += nbPublications;
}

float Cardiologue::calculerSalaire() const {
    return salaireBase * getSpecialite()->getNiveau() + (nbPatients_ * 30) + (nbConferences_ * 50) + (nbPublications_ * 200);
}

void Cardiologue::opererCoeur(shared_ptr<Patient>& p) {
    setPatient(p);
    p->ajouterAntecedent("Examen ou traitement cardiaque effectué par " + getNom() + ".");
    p->misAjourTypeSoin(TypeSoins::PAS_BESOIN);
    nbPatients_ += 1;
}

ostream& Cardiologue::afficher(ostream& out) const {
    Medecin::afficher(out);
    out << "Nombre de patients: " << nbPatients_ << "\n" ;
    out << "Nombre de conférences: " << nbConferences_ << "\n";
    out << "Nombre de publications: " << nbPublications_ << "\n";
    return out;
}