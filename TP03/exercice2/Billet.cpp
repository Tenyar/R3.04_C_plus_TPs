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

void Billet::afficher(ostream & sortie) const{
   /*
    sortie << "Billet : " << endl
              << getTarif() << endl
              << getTrajet() << endl
              << "Prix du billet " << getPrix() << "€" << endl;
   */

    sortie << "Billet : "    << endl
           << " - Trajet : " << getTrajet() << endl
           << " - Tarif  : " << getTarif() << endl
           << " - Prix   : " << getPrix() << " €" << endl;
}

ostream &operator<<(ostream &sortie, const Billet & billet) {
    billet.afficher(sortie); // Mettre en sortie l'affichage du billet dans "sortie" le stream de sortie.
    return sortie; // Retourner cette sortie.
}