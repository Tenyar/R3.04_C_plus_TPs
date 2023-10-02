#ifndef BILLETREDUIT_H
#define BILLETREDUIT_H

#include "Billet.h"
#include "Promotion.h"

class BilletReduit : public Billet {
public:
    BilletReduit(Trajet &untrajet, Tarif &untarif, const Promotion &promo);

    float getPrix() const;

    const Promotion & getPromotion() const;

    void afficher(ostream & sortie) const;
private:
const Promotion & m_promo;
};
#endif