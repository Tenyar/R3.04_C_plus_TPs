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

    ostream &operator<<(ostream &sortie,  const Billet & billet) {
    sortie << billet.m_trajet << endl
           << billet.m_tarif << endl
           << "Prix du billet " << billet.getPrix() << "€" << endl;
    return sortie;
}