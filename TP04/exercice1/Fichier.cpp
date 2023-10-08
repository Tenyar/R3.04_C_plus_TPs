#include "Fichier.h"
#include <iostream>

Fichier::Fichier(const std::string & nom, int tailleKo, const std::string & dateCreation, Usager & usager1)
    : Element(nom, usager1), m_taille(tailleKo),  m_dateCreation(dateCreation){}

string Fichier::rechercher(const string & nom){ // Don't return anyting it's not getNom.
    return "";
}

unsigned int Fichier::getTaille() const{
    return this->m_taille;
}

const std::string & Fichier::getDateModificiation() const{
    return this->m_dateCreation;
}

void Fichier::setDateModification(const string & date){
    this->m_dateCreation = date;
}

void Fichier::ajouter(Element *element) {
    throw "Opération Interdite sur un Fichier";
}

void Fichier::afficher() const {
    std::cout << "[Fichier] ";
    this->Element::afficher(); // réutilise l’op. afficher d’Element
    std::cout << "- Taille : " << this->m_taille << " [Ko] " << endl
           << "- Date creation : " << this->m_dateCreation << endl;
}

Fichier::~Fichier() {}