#include <iostream>
#include "Billet.h"
using namespace std;

Billet::Billet(Trajet & untrajet, Tarif & untarif) : m_trajet(untrajet), m_tarif(untarif){}

const Trajet & Billet::getTrajet() const{
    return this->m_trajet;
}

const Tarif & Billet::getTarif() const{
    return this->m_tarif;
}

float Billet::getPrix() const{
    return ((float)m_trajet.getDistance() * m_tarif.getPrixAuKm());
}

ostream & Billet::afficher(ostream & sortie, const Billet & billet) const{
    return sortie << billet.getTarif() << endl
                  << billet.getTrajet() << endl
                  << "Prix du billet " << billet.getPrix() << "€" << endl;
}

ostream &operator<<(ostream &sortie, const Billet & billet) {
    return billet.afficher(sortie, billet);
}