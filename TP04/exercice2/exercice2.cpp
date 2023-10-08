#include "Parametres.h"

int main() {
    // Get the Singleton instance of Parametres
    Parametres & params = Parametres::getInstance();
    // Afficher les paramètres initiaux
    params.afficher();
    // Instancier un thème intitulé "Urbain" et l'associer aux paramètres
    Theme myTheme("Urbain");
    params.setTheme(myTheme);
    // Instancier un joueur nommé "Yoloutre" et l'associer aux paramètres
    Joueur myJoueur("Yoloutre");
    params.setJoueur(myJoueur);
    // Afficher les nouveaux paramètres
    params.afficher();
    return 0;
}

/////// TRACE ATTENDUE //////////////////////////////////
//
// Paramètres { Theme: 'Par Défaut', Joueur: 'Anonyme' }
// Paramètres { Theme: 'Urbain', Joueur: 'Yoloutre' }
//
/////////////////////////////////////////////////////////