#include <cstdlib>
#include <iostream>
#include <string>
#include "EntierContraint.h"

using namespace std;

void affichageTest(int val, int min, int max){
    EntierContraint *entierC = new EntierContraint(val, min, max);

    if (entierC == nullptr){
        exit(0);
    }

    cout << "Entier constraint : " << endl
    << " VAL : " << entierC->getVal() << endl
    << " MIN : " << entierC->getMin() << endl
    << " MAX : " << entierC->getMax() << endl << endl;

    cout << "Test de getVal()" <<  endl
         << "Resultat attendue : " << val << endl
         << "Resultat obtenue : " << entierC->getVal() << endl
         << (entierC->getVal()==val ? "Succes" : "Echec") << endl << endl;

    cout << "Test de getMin()" <<  endl
         << "Resultat attendue : " << min << endl
         << "Resultat obtenue : " << entierC->getMin() << endl
         << (entierC->getMin()==min ? "Succes" : "Echec") << endl << endl;

    cout << "Test de getMax()" <<  endl
         << "Resultat attendue : " << max << endl
         << "Resultat obtenue : " << entierC->getMax() << endl
         << (entierC->getMax()==max ? "Succes" : "Echec") << endl << endl;

    entierC->setVal(0);
    cout << "Test de setVal(0)" <<  endl
         << "Resultat attendue : " << "0" << endl
         << "Resultat obtenue : " << entierC->getVal()  << endl
         << (entierC->getVal()==0 ? "Succes" : "Echec") << endl << endl;

    entierC->setMin(-5);
    cout << "Test de setMax(-5)" <<  endl
         << "Resultat attendue : " << "-5" << endl
         << "Resultat obtenue : " << entierC->getMin()  << endl
         << (entierC->getMin()==(-5) ? "Succes" : "Echec") << endl << endl;

    entierC->setMax(20);
    cout << "Test de setMax(20)" <<  endl
         << "Resultat attendue : " << "20" << endl
         << "Resultat obtenue : " << entierC->getMax()  << endl
         << (entierC->getMax()==20 ? "Succes" : "Echec") << endl << endl;

    cout << "Test de saisir()" << endl;
    entierC->saisir();

    cout << "Test de afficher()" << endl;
    entierC->afficher();

    delete(entierC);
}

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    affichageTest(10, 5, 15);

    return 0;
}

