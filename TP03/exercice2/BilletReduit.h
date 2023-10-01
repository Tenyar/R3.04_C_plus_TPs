#ifndef BILLETREDUIT_H
#define BILLETREDUIT_H

#include "Billet.h"
#include "Promotion.h"

class BilletReduit : public Billet {
public:
    BilletReduit(Trajet &untrajet, Tarif &untarif, const Promotion &promo);

    float getPrix() const;

    const Promotion & getPromotion() const;

    // Comment permettre à des enfants de classe d'avoir des opérateurs '<<' etc.. propre à aux et n'utilisant pas celui de leur parent :
    // https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/#google_vignette
    friend ostream &operator<<(ostream &sortie, const BilletReduit & billetReduit);
private:
const Promotion & m_promo;
};
#endif