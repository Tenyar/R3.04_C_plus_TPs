#include "Repertoire.h"
#include <iostream>
#include "Usager.h"


Repertoire::Repertoire(const std::string & nom, Usager & usager1) : Element(nom, usager1), m_taille(4), m_dateCreation("1970-01-01"){
} // initial value of 4 for m_taille and of m_dateCreation.

string Repertoire::rechercher(const string &nom) {
    if (getNom() == nom) {
        return getNom();
    } else {
        for (Element *ptrElement : m_contenu) {
            if (ptrElement->getNom() == nom) {
                return this->getNom() + "/" + ptrElement->getNom();
            } else {
                // If it's a directory, recursively search in the subdirectory
                    string result = ptrElement->rechercher(nom);
                    if (!result.empty()) {
                        return getNom() + "/" + result;
                    }
                }
        }
        return ""; // Not found in this directory and its subdirectories
    }
}


unsigned int Repertoire::getTaille() const{
    unsigned int sum_taille = m_taille;
    for(Element *ptrElement : this->m_contenu){
        sum_taille += ptrElement->getTaille();
    }
    return sum_taille;
}

const std::string &Repertoire::getDateModificiation() const{
    return this->m_dateCreation;
}

void Repertoire::setDateModification(const string & date){
    // Check if the repository is empty; if it's not, proceed to assign the subsequent date.
    if (m_contenu.empty()){
        this->m_dateCreation = "1970-01-01";
    }
    else{
        for(Element *e : m_contenu){
            if (e->getDateModificiation() > this->m_dateCreation) {
                this->m_dateCreation = e->getDateModificiation();
            }
        }
    }
}

void Repertoire::afficher() const {
    std::cout << "[Repertoire] ";
    // On redéfinit le comportement de afficher pour un répertoire
    this->Element::afficher(); // réutilise l’op. afficher héritée d’Element
    // afficher un "composé" consiste à afficher chacun de ses "composants"
    std::cout << "- Taille : " << this->getTaille() << " Ko " << endl
    << "- Date creation : " << this->getDateModificiation() << endl;
}

void Repertoire::ajouter(Element *e) {
// On implémente ici les opération de gestion des fils, comme l'ajout
    this->m_contenu.push_back(e);
    // A l'ajout d'un élément on modifie la date de modification du fichier.
    this->setDateModification(m_dateCreation);
}

Repertoire::~Repertoire() {
    for (Element* ptrElement : this->m_contenu) delete ptrElement;
}