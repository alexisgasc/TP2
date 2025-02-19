#include "Chirurgien.h"

Chirurgien::Chirurgien(const string& nom, unsigned nbHeuresGarde, unsigned int niveau): 
    Medecin(nom, new Specialite("Chirurgie", niveau)), nbHeuresDeGarde_(nbHeuresGarde), nbOperations_(0) {}

unsigned Chirurgien::getNbHeuresDeGarde() const {
    return nbHeuresDeGarde_;
}

void Chirurgien::setNbHeuresDeGarde(int nbHeuresDeGarde) {
    nbHeuresDeGarde_ = nbHeuresDeGarde;
}

unsigned Chirurgien::getNbOperations() const {
    return nbOperations_;
}

void Chirurgien::ajouterNbOperations(unsigned nbOperations) {
    nbOperations_ += nbOperations;
}

void Chirurgien::opererPatient(shared_ptr<Patient>& p) {
    ajouterNbOperations(1);
    setPatient(p);
    p->ajouterAntecedent("Opération chirurgicale effectuée par " + getNom() + ".");
    p->misAjourTypeSoin(TypeSoins::PAS_BESOIN);
}

float Chirurgien::calculerSalaire() const {
    return salaireBase * specialite_->getNiveau() + (nbHeuresDeGarde_ * 20) + (nbOperations_ * 50); // TODO: Remplacer par le calcul du salaire
}

// TODO: Méthode afficher (Voir les tests)
// vous devez réutiliser la methode afficher de medecin
// Cette méthode doit afficher les informations suivantes :
// - Appeler la méthode afficher() de la classe Medecin pour afficher les informations communes
// - Ajouter les informations suivantes :
//    - Heures de garde du chirurgien
//    - Nombre d'opérations effectuées par le chirurgien
ostream& Chirurgien::afficher(ostream& out) const {
    return out;
}
