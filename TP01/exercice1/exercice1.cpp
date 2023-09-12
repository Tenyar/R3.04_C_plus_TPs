#include <cstdlib>
#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

void testClassePoint(string &nom, int x, int y){
    Point p(nom, x, y);

    cout << "Test de getNom()" <<  endl
         << "Valeur attendue : " << nom << endl
         << "Valeur obtenue : " << p.getNom() << endl
         << (p.getNom()==nom ? "Succès" : "Echec") << endl;

    cout << "Test de getX()" <<  endl
         << "Valeur attendue : " << x << endl
         << "Valeur obtenue : " << p.getX() << endl
         << (p.getX()==x ? "Succès" : "Echec") << endl;

    cout << "Test de getY()" <<  endl
         << "Valeur attendue : " << y << endl
         << "Valeur obtenue : " << p.getY() << endl
         << (p.getY()==y ? "Succès" : "Echec") << endl;

    cout << "Saisir de nouvelles informations pour ce point : \n";
    p.saisir();
    cout << "========== AFFICHAGE ===========\n";
    p.afficher();
}

void testClassePointDynamique(string &nom, int x, int y){
    // Allocation dynamique.
    // Création du point.
    // Intégration du points au pointeur.
    Point *pts = new Point(nom, x, y);


    cout << "Test de getNom()" <<  endl
         << "Valeur attendue : " << nom << endl
         << "Valeur obtenue : " << pts->getNom() << endl
         << (pts->getNom()==nom ? "Succès" : "Echec") << endl;

    cout << "Test de getX()" <<  endl
         << "Valeur attendue : " << x << endl
         << "Valeur obtenue : " << pts->getX() << endl
         << (pts->getX()==x ? "Succès" : "Echec") << endl;

    cout << "Test de getY()" <<  endl
         << "Valeur attendue : " << y << endl
         << "Valeur obtenue : " << pts->getY() << endl
         << (pts->getY()==y ? "Succès" : "Echec") << endl;

    cout << "Saisir de nouvelles informations pour ce point : \n";
    pts->saisir();
    cout << "========== AFFICHAGE ===========\n";
    pts->afficher();

    delete(pts);
}

int main(int argc, char** argv) {
    // à compléter
    // Quand on initialise par défaut un objet pas de parenthèse pour les paramètres.

    string nom = "PointA";
    int x = 2;
    int y = 4;

    testClassePointDynamique(nom,x,y);

    return 0;
}

