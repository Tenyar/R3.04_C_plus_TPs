#include "Element.h"
#include <ostream>
using namespace std;

Element::Element(const string & nom) : m_nom(nom), proprietaire(){}

const std::string & Element::getNom() const{
    return this->m_nom;
}

void Element::setNom(std::string nouv_nom) {
    this->m_nom = nouv_nom;
}

const Usager &Element::getProprietaire() {
    return this->proprietaire;
}

Element::~Element(){}

// à compléter
void Element::afficher(ostream & sortie) const {
    // Les opérations communes sont visibles dans le composant
    // Si possible, on factorise déjà ici le code commun à tous les éléments
    sortie << "Nom : " << this->getNom() << endl;
}