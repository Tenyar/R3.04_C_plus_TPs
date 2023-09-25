#ifndef VISAGE_H
#define VISAGE_H

#include "AttributsVisage.h"
#include <vector>

using namespace std;
// A COMPLETER (spécifiez les attributs)

class Visage {
public:
    Visage(int longueurNez, const Ethnie &uneEthnie);
    void setMoustache(int largeur);
    void addBouton(int diametre);
    void setChapeau(const Chapeau &unChapeau);
    void addBijou(const Bijou &unBijou);
    const Visage &operator=(const Visage &unVisage);
    Visage(const Visage &unVisage);
    ~Visage();

    // fonction amie : aura accès aux attributs "private"  de la classe Visage (pour éviter d'écrire les getters)
    // attention ce n'est pas une méthode !
    friend std::ostream &operator<<(std::ostream &sortie, const Visage &visage);

private:

    // A COMPLETER : CODEZ CORRECTEMENT LES COMPOSITIONS ET AGREGATIONS
    const Chapeau * m_chapeau; // partagé
    Nez m_monNez;
    const Ethnie & m_monEthnie;
    Moustache * m_maMoustache; // partagé
    vector<Bouton> m_mesBoutons; // cloner dnas le const. par recopie
    vector<const Bijou *> m_mesBijoux; // delete automatiquement quand ~Visage() appeler.
};

#endif /* VISAGE_H */

