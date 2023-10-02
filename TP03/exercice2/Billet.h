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

    virtual ostream & afficher(ostream & sortie, const Billet & billet) const;

    /*
     * When returning by value the constant has no effect as it cannot be enforced anyway.
     * Some compilers issue a warning.
     * However it DOES make sense to return a pointer/reference to constant data.
     * Reference : https://stackoverflow.com/questions/8406898/benefits-of-using-const-with-scalar-type-e-g-const-double-or-const-int
     */
    virtual float getPrix() const; // virtual for polymorpishm

    // fonction amie : aura accès aux attributs "private"  de la classe Visage (pour éviter d'écrire les getters)
    // attention ce n'est pas une méthode !
    friend ostream &operator<<(ostream &sortie, const Billet & billet);
private:
    Trajet const & m_trajet;
    Tarif const & m_tarif;
};
#endif