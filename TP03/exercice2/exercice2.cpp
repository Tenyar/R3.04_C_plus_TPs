#include <iostream>
#include <string>
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

// Saisit d'un trajet.
cout << endl << "--- Création d''un Billet ---" << endl
     << "-- Liste des Trajets" << endl;
trajets.afficher();
cout << "Quel trajet ?";
Trajet &trajet_billet = trajets.choisir(); // Par référence !

// Saisit d'un tarif.
cout << "-- Liste des Tarifs" << endl;
tarifs.afficher();
cout << "Quel tarif ?";
Tarif &tarif_billet = tarifs.choisir(); // Par référence !


char choix;
cout << "Ajouter une promotion O/[N] ?" << endl;
// Prendre le caractère et le mettre dans la case mémoire de 'choix'.
scanf("%c",&choix);
    if (choix == 'O'){
        cout << "-- Liste des Promotions" << endl;
        promotions.afficher();
        cout << "Quel promotion ?";
        Promotion &promo_billet = promotions.choisir(); // Par référence !

        // Création d'un billet avec une promotion.
        BilletReduit * billetReduit_creer;
        billetReduit_creer= new BilletReduit(trajet_billet, tarif_billet, promo_billet);
        cout << "BILLELRZLERLZE : " << endl << *billetReduit_creer << endl;
        return billetReduit_creer;
    }
    else{
        // Création d'un billet sans promotion.
        Billet * billet;
        billet = new Billet(trajet_billet, tarif_billet);
        return billet;
    }
}

//==================================== Question 2.1 Procedure de test pure
void afficherTest(Billet &billet){
    cout << billet;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
/* Question 1
    // variables
    Trajet *traj1 = new Trajet("Grenoble", "Lyon", 100);
    Tarif *tarif1 = new Tarif("Normal", 2.00);
    // A COMPLETER
    Billet billet1(*traj1, *tarif1);
    cout << "Le ttttrajet !" << billet1.getTrajet() << endl;
    afficherTest(billet1);
    return EXIT_SUCCESS;
    */

// Question 2

    // Création du conteneur Billet.
    Conteneur<Billet> billets;
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
    // Condition de la boucle.
    char choix;
    cout << "Ajouter un billet [O]/N ?";
    scanf("%s", &choix);

    while (choix == 'O') {
        // Ajoute un billet par l'appel de la fonction 'newBillet'.
        billets.ajouter(newBillet(trajets, tarifs, promotions));
        cout << "Ajouter un billet [O]/N ?" << endl;
        scanf("%s", &choix);
    }
    cout << "---- Liste des Billets Crees ----" << endl;
    billets.afficher();
}

