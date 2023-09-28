#include <iostream>
#include "BilletReduit.h"
using namespace std;

BilletReduit::BilletReduit(Trajet &untrajet, Tarif &untarif, const Promotion &promo) : Billet(untrajet, untarif), m_promo(promo) {}

float BilletReduit::getPrix() {
    return (m_promo.calculePrixReduit((float)getTrajet().getDistance() * getTarif().getPrixAuKm()));
}

const Promotion & BilletReduit::getPromotion(){
    return this->m_promo;
}