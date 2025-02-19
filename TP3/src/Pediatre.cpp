#include "Pediatre.h"

// TODO: Implémenter le constructeur de Pediatre.
// - Initialiser le nom du pédiatre en utilisant le constructeur de la classe parente (Medecin).
// - Initialiser la spécialité avec "Pediatrie" et le niveau passé en paramètre.
// - Initialiser nbEnfantsSoignes_ avec la valeur passée en paramètre.
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

// TODO: Implémenter la méthode calculerSalaire.
// - Calculer le salaire du pédiatre en fonction du niveau de spécialité, du nombre d'enfants soignés et des certifications.
// - Exemple de calcul : salaire = salaireBase * niveau + (nbEnfantsSoignes * 100) + (nombre certifications * 25)
float Pediatre::calculerSalaire() const {
    return salaireBase * specialite_->getNiveau() + (nbEnfantsSoignes_ * 100) + (certifications_.size() * 25);
}

// TODO: Implémenter la méthode afficher.
// - Vous devez utiliser la méthode afficher de Medecin
// - Afficher les informations du pédiatre, y compris le nombre d'enfants soignés et les certifications.
ostream& Pediatre::afficher(ostream& out) const {
    return out;
}