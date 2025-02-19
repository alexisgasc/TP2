#include "Cardiologue.h"

Cardiologue::Cardiologue(const string& nom, unsigned nbPatients, unsigned nbConferences, unsigned int niveau) : 
    Medecin(nom, new Specialite("Cardiologie", niveau)), nbConferences_(nbConferences), nbPublications_(0), nbPatients_(nbPatients) {}

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

// TODO: Implémenter la méthode afficher.
// vous devez réutiliser la methode afficher de medecin
// - Afficher les informations du cardiologue, y compris son nombre de patients, de conférences et de publications.
// - Utiliser la méthode afficher de la classe parente (Medecin) pour afficher les informations de base.
ostream& Cardiologue::afficher(ostream& out) const {
    return out;
}