#include "Patient.h"

Patient::Patient(std::string nom, int age) :
    nom_(nom), age_(age), typeSoins_(TypeSoins::PAS_BESOIN), infirmier_(nullptr), medecin_(nullptr) {}


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


void Patient::afficher(ostream& out) const {
    out << "Nom: " << getNom() << "\n";
    out << "Âge: " << this->age_ << " ans\n";
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
        case TypeSoins::PAS_BESOIN:
            out << "PAS_BESOIN\n";
            break;
    }
    out << "Antécédents médicaux:\n";
    for(auto a: antecedentsMedicaux_) out << " > " << a << '\n';
}

ostream& operator<<(ostream& out, const Patient& p) {
    p.afficher(out);
    return out;
}