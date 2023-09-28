#include <iostream>
#include <string>
#include <stdexcept>
#include "Conteneur.h"
#include "Trajet.h"
#include "Tarif.h"
#include "Promotion.h"
#include "Billet.h"
#include "BilletReduit.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Billet *newBillet(Conteneur<Trajet> &trajets,
                  Conteneur<Tarif> &tarifs,
                  Conteneur<Promotion> &promotions) {
// A COMPLETER
return nullptr;
}

//==================================== Question 2.1 Procedure de test pure
void afficherTest(Billet &billet){
    cout << billet;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {

    // variables
    Trajet *traj1 = new Trajet("Grenoble", "Lyon", 100);
    Tarif *tarif1 = new Tarif("Normal", 2.00);
    // A COMPLETER
    Billet billet1(*traj1, *tarif1);
    afficherTest(billet1);
    return EXIT_SUCCESS;

/* Question 2
    // Création des conteneurs de Trajets, TArifs, Promotions
    Conteneur<Trajet> trajets;
    trajets.ajouter(new Trajet("Grenoble", "Lyon", 100));
    trajets.ajouter(new Trajet("Grenoble", "Paris", 600));
    trajets.ajouter(new Trajet("Grenoble", "Marseille", 300));
    Conteneur<Tarif> tarifs;
    tarifs.ajouter(new Tarif("Normal", 2.00));
    tarifs.ajouter(new Tarif("Jeune", 1.00));
    tarifs.ajouter(new Tarif("Vermeil", 3.00));
    Conteneur<Promotion> promotions;
    promotions.ajouter(new Promotion("Noël", 0.5));
    promotions.ajouter(new Promotion("Anniversaire", 0.2));
    */
}

