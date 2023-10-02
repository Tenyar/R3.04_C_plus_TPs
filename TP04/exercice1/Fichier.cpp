#include "Fichier.h"
#include <iostream>

Fichier::Fichier(const std::string &nom, const std::string &dateCreation, int tailleKo)
    : Element(nom), m_dateCreation(dateCreation), m_taille(tailleKo){}

unsigned int Fichier::getTaille() {
    return this->m_taille;
}

void Fichier::ajouter(Element *element) {
    throw "Opération Interdite sur un Fichier";
}

void Fichier::afficher(std::ostream & sortie) const {
    std::cout << "Fichier : ";
    this->Element::afficher(sortie); // réutilise l’op. afficher d’Element
    std::cout << "Date creation : "
           << m_dateCreation << std::endl;
}

Fichier::~Fichier() {}
