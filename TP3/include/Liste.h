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


    Liste& operator+=(const T& obj) {
        if (this->chercher(obj) == -1)
            listes_.push_back(obj);
        return *this;
    }

    Liste& operator+=(const Liste<T>& liste) {
        for (const auto& obj : liste.listes_)
            *this += obj;
        return *this;
    }


    Liste& operator-=(const T& obj) {
        int indice = chercher(obj);
        if (indice != -1) {
            listes_.erase(listes_.begin() + indice);
        }
        return *this;
    }


    Liste& operator-=(const string& nom) {
        int indice = chercher(nom);
        if (indice != -1) {
            listes_.erase(listes_.begin() + indice);
        }
        return *this;
    }

    Liste& operator-=(const Liste<T>& liste) {
        for (const auto& elem : liste.listes_)
            *this -= elem;

        return *this;
    }

    const T& operator [](int index) const{
        return listes_.at(index);
    }

    T& operator [](int index) {
        return listes_.at(index);
    }


    int chercher(const string& nom) const {
        for (size_t i = 0; i < listes_.size(); ++i) {
            if (listes_[i]->getNom() == nom)
                return static_cast<int> (i);
        }
        return -1;
    }

    int chercher(const T& obj) const {
        for (size_t i = 0; i < listes_.size(); ++i) {
            if (listes_[i] == obj)
                return static_cast<int> (i);
        }
        return -1;
    }

    size_t size() const {
        return listes_.size();
    }

private:
    vector<T> listes_;
};