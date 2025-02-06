#pragma once
#include <vector>
#include "Medecin.h"
#include <memory>
using namespace std;

template<typename T>
class Liste
{   
public:
    Liste(){};
    ~Liste() = default;

    // TODO: Surcharger l'opérateur += pour ajouter un élément à la liste.
    // Vérifier que l'élément n'existe pas déjà avant de l'ajouter.
    Liste& operator+=(const T& obj) {
        // TODO: Implémenter la logique d'ajout d'un élément.
        return *this;
    }

    // TODO: Surcharger l'opérateur += pour ajouter tous les éléments d'une autre liste.
    // Vérifier que les éléments n'existent pas déjà avant de les ajouter.
    Liste& operator+=(const Liste<T>& liste) {
        // TODO: Implémenter la logique d'ajout d'une liste.
        return *this;
    }

    // TODO: Surcharger l'opérateur -= pour retirer un élément de la liste.
    // Utiliser la méthode chercher pour trouver l'élément à retirer.
    Liste& operator-=(const T& obj) {
        // TODO: Implémenter la logique de suppression d'un élément.
        return *this;
    }

    // TODO: Surcharger l'opérateur -= pour retirer un élément par son nom.
    // Utiliser la méthode chercher pour trouver l'élément à retirer.
    Liste& operator-=(const string& nom) {
        // TODO: Implémenter la logique de suppression par nom.
        return *this;
    }

    // TODO: Surcharger l'opérateur -= pour retirer tous les éléments d'une autre liste.
    // Utiliser la méthode chercher pour vérifier l'existence des éléments.
    Liste& operator-=(const Liste<T>& liste) {
        // TODO: Implémenter la logique de suppression d'une liste.
        return *this;
    }

    // TODO: Surcharger l'opérateur [] pour accéder à un élément de la liste par index.
    // Retourner une référence constante à l'élément.
    const T& operator [](int index) const{
        
    }

    // TODO: Surcharger l'opérateur [] pour accéder à un élément de la liste par index.
    // Retourner une référence modifiable à l'élément.
    T& operator [](int index) {
    }

    // TODO: Implémenter la méthode chercher pour trouver un élément par son nom.
    // Retourner l'index de l'élément s'il est trouvé, sinon retourner -1.
    int chercher(const string& nom) const {
        // TODO: Implémenter la recherche par nom.
       
    }

    // TODO: Implémenter la méthode chercher pour trouver un élément par comparaison directe.
    // Retourner l'index de l'élément s'il est trouvé, sinon retourner -1.
    int chercher(const T& obj) const {
        
    }

    // TODO: Implémenter la méthode size pour retourner la taille de la liste.
    size_t size() const {
    }

private:
    vector<T> listes_;
};