#include "HopitalPoly.h"

HopitalPoly::HopitalPoly(const string & nom) : nom_(nom), chambreLibre_(0){}

HopitalPoly::HopitalPoly(const HopitalPoly &h) {
    nom_ = h.getNom();
    chambreLibre_ = h.chambreLibre_;
    employes_ += h.getEmployes();
}

string HopitalPoly::getNom() const {
    return nom_;
}

const Liste<shared_ptr<Employe>>& HopitalPoly::getEmployes() const {
	return employes_;
}

const Liste<shared_ptr<Patient>>& HopitalPoly::getPatients() const {
    return patients_;
}

void HopitalPoly::setNom(string nom) {
    nom_ = nom;
}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Employe>& employe) {
    employes_ += employe;
    return *this;
}

HopitalPoly& HopitalPoly::operator+=(const HopitalPoly &h) {
    employes_ += h.getEmployes();
    return *this;
}

HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Employe>& employe) {
    employes_ -= employe;
    return *this;
}

HopitalPoly& HopitalPoly::operator-=(const string &nomEmploye) {
    employes_ -= nomEmploye;
    return *this;
}

bool HopitalPoly::operator==(const HopitalPoly& rhs) const {
	return nom_ == rhs.nom_;
}


float HopitalPoly::coutSalarialTotal() const {
    float salaire = 0;
    for (size_t i = 0; i < employes_.size(); i++) {
        salaire += employes_[i]->calculerSalaire();
    }
    return salaire;
}


void HopitalPoly::accueillirPatient(shared_ptr<Patient>& patient) {
    int i = patients_.chercher(patient);
    if (i == -1) {
        patient->misAjourSalle(patients_.size());
        patients_ += patient;
        chambreLibre_ -= 1;
    }
    shared_ptr<Infirmier> inf = trouverEmployeLibre<Infirmier>();
    if (inf) {
        inf->examinerPatient(patient);
        patient->assignerInfirmier(inf);
    }
}

void HopitalPoly::traiterPatients() {
    for (int i = patients_.size() - 1; i >= 0; i--) {
        switch (patients_[i]->getTypeSoins()) {
        case TypeSoins::CHIRURGICAL: {
            shared_ptr<Chirurgien> chirurgienLibre = trouverEmployeLibre<Chirurgien>();
            if (chirurgienLibre) {
                patients_[i]->assignerMedecin(chirurgienLibre);
                chirurgienLibre->opererPatient(patients_[i]);
                patients_ -= patients_[i];
            }
            break;
        }
        case TypeSoins::CARDIOLOGIE: {
            shared_ptr<Cardiologue> cardiologueLibre = trouverEmployeLibre<Cardiologue>();
            if (cardiologueLibre) {
                patients_[i]->assignerMedecin(cardiologueLibre);
                cardiologueLibre->opererCoeur(patients_[i]);
                patients_ -= patients_[i];
            }
            break;
        }
        case TypeSoins::PEDIATRIE: {
            shared_ptr<Pediatre> pediatreLibre = trouverEmployeLibre<Pediatre>();
            if (pediatreLibre) {
                patients_[i]->assignerMedecin(pediatreLibre);
                pediatreLibre->examinerPatient(patients_[i]);
                patients_ -= patients_[i];
            }
            break;
        }
        case TypeSoins::PAS_BESOIN: 
            patients_ -= patients_[i];
            break;
        }
    }
}


bool HopitalPoly::chercherEmploye(const shared_ptr<Employe>& employe) const {
    for (size_t i = 0; i < employes_.size(); i++)
        if (employes_[i] == employe)
            return true;
    return false;
}


bool HopitalPoly::chercherEmploye(const string& nomEmploye) const {
    for (size_t i = 0; i < employes_.size(); i++)
        if (employes_[i]->getNom() == nomEmploye)
            return true;
    return false;
}

void HopitalPoly::afficherEmploye(ostream &out) const {
    out << "Employés: \n";
    for(size_t i = 0; i < employes_.size(); i++) {
        employes_[i]->afficher(out);
    }
}


ostream& HopitalPoly::afficher(ostream &out) const {
    out << "Hôpital: " << nom_ << endl;
    afficherEmploye(out);
    return out;
}


ostream &operator<<(ostream &o, const HopitalPoly &h) {
    return h.afficher(o);
}
