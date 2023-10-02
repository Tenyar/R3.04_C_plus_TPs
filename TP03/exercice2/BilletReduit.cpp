#include <iostream>
#include "BilletReduit.h"
using namespace std;

BilletReduit::BilletReduit(Trajet &untrajet, Tarif &untarif, const Promotion &promo) : Billet(untrajet, untarif), m_promo(promo) {}

float BilletReduit::getPrix() const{
    return (m_promo.calculePrixReduit((float)getTrajet().getDistance() * getTarif().getPrixAuKm()));
}

const Promotion & BilletReduit::getPromotion() const{
    return this->m_promo;
}

ostream & BilletReduit::afficher(ostream & sortie, const BilletReduit & billet_red) const{
    return sortie << billet_red.getTarif() << endl
                  << billet_red.getTrajet() << endl
                  << billet_red.getPromotion() << endl
                  << "Prix du billet " << billet_red.getPrix() << "€" << endl;
}

ostream &operator<<(ostream &sortie,  const BilletReduit & billet_red) {
    return billet_red.afficher(sortie, billet_red);
}