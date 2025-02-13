#include "Patient.h"

// TODO: Implémenter le constructeur de Patient.
// - Initialiser le nom et l'âge du patient.
// - Initialiser typeSoins_ à PAS_BESOIN.
// - Initialiser infirmier_ et medecin_ à nullptr.
Patient::Patient(std::string nom, int age) : nom_(nom), age_(age) {
    this->typeSoins_ = TypeSoins::PAS_BESOIN;
    this->infirmier_ = nullptr;
    this->medecin_ = nullptr;
}

void Patient::setNom(const string& nom) {
    nom_ = nom;
}

const string& Patient::getNom() const {
    return nom_;
}

int Patient::getSalle() const {
    return numeroSalle_;
}

const TypeSoins& Patient::getTypeSoins() const {
    return typeSoins_;
}

shared_ptr<Infirmier> Patient::getInfirmier() const {
    return infirmier_;
}

shared_ptr<Medecin>  Patient::getMedecin() const {
    return medecin_;
}

vector<string> Patient::getAntecedentsMedicaux() const {
    return antecedentsMedicaux_;
}

void Patient::ajouterAntecedent(const std::string& antecedent) {
    antecedentsMedicaux_.push_back(antecedent);
}

void Patient::misAjourTypeSoin(const TypeSoins& typeSoin) {
    typeSoins_ = typeSoin;
}

void Patient::misAjourSalle(int nSalle) {
    numeroSalle_ = nSalle;
}

void Patient::assignerInfirmier(const shared_ptr<Infirmier>& i){
    infirmier_ = i;
}

void Patient::assignerMedecin(const shared_ptr<Medecin>& m){
    medecin_ = m;
}

// TODO: Implémenter la méthode afficher.
// - Afficher les informations du patient, y compris le nom, l'âge, le numéro de salle, le type de soins et les antécédents médicaux.
void Patient::afficher(ostream& out) const {
    out << "Nom: " << getNom() << '\n';
    out << "Âge: "; //comment pour l'age?
    out << "Numéro de salle: " << getSalle() << '\n';
    out << "Type de soins requis: ";
    switch (getTypeSoins()) {
    case TypeSoins::CHIRURGICAL:
        out << "Chirurgical\n";
        break;
    case TypeSoins::CARDIOLOGIE:
        out << "Cardiologie\n";
        break;
    case TypeSoins::PEDIATRIE:
        out << "Pediatrie\n";
        break;
    out << "Antécédents médicaux:\n";
    for (auto &a : getAntecedentsMedicaux()) out << " > " << a << '\n';
    }
}

// TODO: Surcharger l'opérateur << pour afficher les informations du patient.
ostream& operator<<(ostream& out, const Patient& p) {
    // TODO: Utiliser la méthode afficher pour afficher les informations du patient.
    p.afficher(out);
    return out;
}