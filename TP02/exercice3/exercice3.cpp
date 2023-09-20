#include "ObjetContraint.h"
#include "Point.h"
#include <iostream>
using namespace std;

void afficherTest(){
    // 5, 0 et 100 sont des valeurs constante donc chaque paramètre du constructeur doit avoir une référence à un type const.
    // Bonne pratique en code pour que le constructeur ne modifie pas les valeurs d'entrée
    // Il permet également de créer des objets 'ObjetContraint<T>' en utilisant des valeurs const.
    ObjetContraint<int> ec1(5,0,100);
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

    cout << "test avant affect ec1 a un int : " << ec1 << " and " << ec1.getVal() << endl << endl;
    // won't work if there isn't default values so 'i' will replace val but not min and max.
    // or since it's a generic model we need to overload (surcharger) the '=' operator and redefine it to our liking.
    ec1 = i+1;
    cout << "test affect ec1 a un int : " << ec1 << endl << endl;

}

int main(int argc, char** argv) {

    // A COMPLETER : Testez ici le template ObjetContraint<T>
    afficherTest();
    return 0;
}

