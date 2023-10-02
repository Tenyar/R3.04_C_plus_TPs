#ifndef BILLET_H
#define BILLET_H

#include <iostream>
#include <iomanip>

#include "Trajet.h"
#include "Tarif.h"

using namespace std;

class Billet {
public:
    Billet(Trajet & untrajet, Tarif & untarif);

    const Trajet & getTrajet() const;

    const Tarif & getTarif() const;

    virtual void afficher(ostream & sortie) const;

    /*
     * When returning by value the constant has no effect as it cannot be enforced anyway.
     * Some compilers issue a warning.
     * However it DOES make sense to return a pointer/reference to constant data.
     * Reference : https://stackoverflow.com/questions/8406898/benefits-of-using-const-with-scalar-type-e-g-const-double-or-const-int
     */
    virtual float getPrix() const; // virtual for polymorpishm

    // Comment permettre à des enfants de classe d'avoir des opérateurs '<<' etc.. propre à aux et n'utilisant pas celui de leur parent :
    // https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/#google_vignette
    // fonction amie : aura accès aux attributs "private"  de la classe Visage (pour éviter d'écrire les getters)
    // attention ce n'est pas une méthode !
    friend ostream &operator<<(ostream &sortie, const Billet & billet);
private:
    const Trajet & m_trajet;
    const Tarif & m_tarif;
};
#endif