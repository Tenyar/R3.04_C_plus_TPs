#include "Element.h"
#include <iostream>

using namespace std;

Element::Element(const string & nom, const Usager & proprio) : m_nom(nom), m_proprietaire(proprio){}

const std::string & Element::getNom() const{
    return this->m_nom;
}

void Element::setNom(std::string & nouv_nom) {
    this->m_nom = nouv_nom;
}

const Usager & Element::getProprietaire() const{
    return this->m_proprietaire;
}

void Element::setProprietaire(const Usager & proprietaire){
    this->m_proprietaire = proprietaire;
}

void Element::afficher() const {
    // Les opérations communes sont visibles dans le composant
    // Si possible, on factorise déjà ici le code commun à tous les éléments
    cout << "\n- Nom : " << this->getNom() << endl
         << "- Proprietaire : " << this->getProprietaire().getLogin()
         << "(" << this->getProprietaire().getGroup() << ")" << endl;
}

Element::~Element(){}