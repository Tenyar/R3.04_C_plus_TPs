#include "Conteneur.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main(int argc, char** argv) {

    // A COMPLETER : tester le template Conteneur<T>
    Conteneur<string> conteneurStr;

    // On instancie dynamiquement les éléments du conteneur avec (new)
    conteneurStr.ajouter(new string("Bonjour"));
    conteneurStr.ajouter(new string("Salut"));
    conteneurStr.ajouter(new string("Yo"));
    conteneurStr.ajouter(new string("Enchanter"));

    // Test des méthodes afficher et choisir
    bool continuer = true;
    do {

        cout << endl << "Contenu : " << endl;
        conteneurStr.afficher();
        cout << endl << "Numero choisi (0 pour finir) : ";
        try {
            string & element = conteneurStr.choisir();
            cout << endl << "Vous avez choisi : " << element << endl;
        } catch (range_error & exception) {
            // si choisir a levé une exception
            cout << "C'est fini..." << endl;
            continuer = false;
        }

    } while (continuer); // boucle infinie...

    // Test COPLIEN
    Conteneur<string>* autreConteneur = new Conteneur<string>(conteneurStr); // const. par recopie
    Conteneur<string> troisiemeConteneur = *autreConteneur; // opérateur affectation
    delete autreConteneur; // On supprime lsdddde conteneur alloué dynamiquement
    cout << "Contenu du conteneur obtenu par affectation d'un conteneur depuis disparu : " << endl;
    troisiemeConteneur.afficher();

    // conteneur et troisiemeConteneur, alloués dynamiquement, vont être libérés
    // et leurs destructeurs appelés juste avant
    return EXIT_SUCCESS;
}