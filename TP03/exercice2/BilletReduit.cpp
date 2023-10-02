#include <iostream>
#include "BilletReduit.h"
using namespace std;

BilletReduit::BilletReduit(Trajet &untrajet, Tarif &untarif, const Promotion &promo) : Billet(untrajet, untarif), m_promo(promo) {}

float BilletReduit::getPrix() const{
    // return (m_promo.calculePrixReduit((float)getTrajet().getDistance() * getTarif().getPrixAuKm()));
    return (m_promo.calculePrixReduit(Billet::getPrix()));
}

const Promotion & BilletReduit::getPromotion() const{
    return this->m_promo;
}

// Pas besoin de redéfinir '<<' sachant que la fonction virtual afficher sera appeler dedans.
void BilletReduit::afficher(std::ostream & sortie) const {
    Billet::afficher(sortie); // on appelle le afficher de la classe mère
    sortie << "- Promo  : " << getPromotion() << " €" << endl;
}
