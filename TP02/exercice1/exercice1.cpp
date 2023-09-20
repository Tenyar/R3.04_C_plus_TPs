#include <cstdlib>
#include <iostream>
#include "EntierContraint.h"
using namespace std;


void afficherTest(){

    EntierContraint ec1(5,0,100);
    int i = int(ec1);

    cout << "Test d'affectation int() : " <<  endl
         << "Resultat attendue : " << ec1.getVal() << endl
         << "Resultat obtenue : " << i << endl
         << (i ==ec1.getVal() ? "Succes" : "Echec") << endl << endl;

    cout << "Test d'affectation int() + 1 : " <<  endl
         << "Resultat attendue : " << 6 << endl
         << "Resultat obtenue : " << 1+i << endl
         << ((1+i)==6 ? "Succes" : "Echec") << endl << endl;

    cout << "Test ecriture de la valeur d'un entier : " << ec1 << endl
         << (ec1==5 ? "Succes" : "Echec") << endl << endl;

    cout << "Test lecture de la valeur d'un entier : ";
    cin >> ec1;
    cout << ec1.getVal() << endl << endl;

    cout << "test avant affect ec1 a un int : " << ec1 << " and " << ec1.getMin() << endl << endl;
    // Marche car il y à les autres paramètres par défaut
    // premier paramètre 'val' = 5 soit = i et le reste sont les valeurs par défaut.
    ec1 = i;
    // donc tout est redéfinie et le min et max change de l'init tout en haut pour devenir les valeurs par défaut.
    cout << "test affect ec1 a un int : " << ec1 << " and " << ec1.getMin() << endl << endl;

}

int main(int argc, char** argv) {
    
    // A Compléter
    // Il faut tester operator int, operator << et operator >> sur la classe EntierContraint
    afficherTest();
    return 0;
}

