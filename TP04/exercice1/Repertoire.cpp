#include "Repertoire.h"
#include <iostream>
#include "Usager.h"
// à compléter

Repertoire::Repertoire(const std::string &nom, Usager & usager) : Element(nom), m_usager(usager){}

void Repertoire::ajouter(Element *e) {
// On implémente ici les opération de gestion des fils, comme l'ajout
    this->m_contenu.push_back(e);
}

unsigned int Repertoire::getTaille() {
    unsigned int sum_taille = m_taille;
    for(Element *e : m_contenu){
        sum_taille += e->getTaille();
    }
    return sum_taille;
}

const std::string &Repertoire::getDateModificiation() {
    if (m_contenu.empty()){return "1970-01-01";}
    else{
        for(Element *e : m_contenu){
            if (e->getDateModificiation() < this.)
        }
    }
}


void Repertoire::afficher(std::ostream &sortie) const {
    // On redéfinit le comportement de afficher pour un répertoire
    std::cout << "Répertoire :" << std::endl;
    this->Element::afficher(sortie); // réutilise l’op. afficher héritée d’Element
    // afficher un "composé" consiste à afficher chacun de ses "composants"
    for (Element* ptrElement : m_contenu) ptrElement->afficher(sortie);
}

Repertoire::~Repertoire() {
    for (Element* ptrElement : m_contenu) delete ptrElement;
}

int taille = 4;