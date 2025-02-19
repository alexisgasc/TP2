#include "Pediatre.h"

Pediatre::Pediatre(const string& nom, unsigned nbNbEnfantsSoignes, unsigned int niveau):
    Medecin(nom, new Specialite("Pediatrie", niveau)), nbEnfantsSoignes_(nbNbEnfantsSoignes) {
}

void Pediatre::setNbEnfantsSoignes(int nbEnfantsSoignes) {
    nbEnfantsSoignes_ = nbEnfantsSoignes;
}

unsigned Pediatre::getNbNbEnfantsSoignes() const {
    return nbEnfantsSoignes_;
}

void Pediatre::examinerPatient(shared_ptr<Patient> &p) {
    setNbEnfantsSoignes(getNbNbEnfantsSoignes() + 1);
    setPatient(p);
    p->ajouterAntecedent("Examen pédiatrique effectué par " + getNom() + ".");
    p->misAjourTypeSoin(TypeSoins::PAS_BESOIN);
}

vector<string> Pediatre::getCertifications() const {
    return certifications_;
}

void Pediatre::operator+=(const string& certification) {
    certifications_.push_back(certification);
}

float Pediatre::calculerSalaire() const {
    return salaireBase * specialite_->getNiveau() + (nbEnfantsSoignes_ * 100) + (certifications_.size() * 25);
}

ostream& Pediatre::afficher(ostream& out) const {
    Medecin::afficher(out);
    out << "Nombre d'enfants soignés: " << nbEnfantsSoignes_ << "\n";
    out << "Mes certifications sont:\n";
    for (auto certif : certifications_) out << "> " << certif << "\n";
    return out;
}
