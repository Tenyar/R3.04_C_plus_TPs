#ifndef BILLETREDUIT_H
#define BILLETREDUIT_H

#include "Billet.h"
#include "Promotion.h"

class BilletReduit : public Billet {
public:
    BilletReduit(Trajet &untrajet, Tarif &untarif, const Promotion &promo);

    float getPrix();

    const Promotion & getPromotion();

private:
const Promotion & m_promo;


};
#endif