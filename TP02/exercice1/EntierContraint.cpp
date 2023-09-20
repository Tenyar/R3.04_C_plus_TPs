#include "EntierContraint.h"
#include <iostream>

using namespace std;

// A Compléter
// Il faut Implémenter operator int, operator << et operator >>

EntierContraint::EntierContraint(int valeur, int min, int max)
: m_min(min), m_max(max) {
    this->setVal(valeur); // Il faut utiliser setVal pour vérifier que m_min<=valeur<=m_max
}

void EntierContraint::setVal(int valeur) {
    if (valeur < getMin() || valeur > getMax()) // exception levée aussi si m_min>m_max
        throw ("Valeur entier contraint hors intervalle");
    this->m_val = valeur;
}

int EntierContraint::getMin() const {
    return this->m_min;
}

int EntierContraint::getMax() const {
    return this->m_max;
}

int EntierContraint::getVal() const {
    return this->m_val;
}

void EntierContraint::saisir(istream& entree) {
    int val;
    entree >> val;
    entree.ignore(256, '\n'); // pour "consommer" le retour chariot tapé après l'entier
    this->setVal(val); // Il faut utiliser setVal pour vérifier que m_min<=valeur<=m_max
}

void EntierContraint::afficher(ostream& sortie) const {
    sortie << this->getVal();
}


/*
    Si on veut le faire en inline, on doit copier cette ligne dans le .h et à l'extérieure de la classe pour implémenter son code.
    Permet de convertir implicitement l'objet en un entier(int).
    Permet donc de comparer l'objet à un entier car il prendra 'getValeur()' de l'objet qui est un (int) pour comparé à l'entier comparant.
*/
EntierContraint::operator int() const{return this->getVal();}

// Surcharge de l'opérateur '<<' qui effectuera cette action quand appeler pour cet objet.
std::ostream & operator << (std::ostream & sortie, const EntierContraint & ec){
    // afficher sur le stream et retourner le stream sur lequel il à été affiché (par e.g pour qu'il soit utiliser par quelqu'un d'autre).
    ec.afficher(sortie);
    return sortie;
}

// Surcharge de l'opérateur '>>' qui effectuera cette action quand appeler pour cet objet.
std::istream & operator >> (std::istream & entree, EntierContraint & ec){
    ec.saisir(entree);
    return entree;
}