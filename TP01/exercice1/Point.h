// Les 2 directives ci-cessous permettent d'éviter les problèmes d'inclusions multiples d'une même classe
#ifndef POINT_H
#define POINT_H

// On inclut les librairies utilisées dans le fichier
#include <iostream>
#include <string>
// Attention : pas de clause "using namespace" dans un fichier ".h" !
using namespace std;

// Spécification de la classe
class Point {

public:
// A COMPLETER - Implémenter les méthodes de la classe Point
    Point(string &nom = NOM_DEF, int x = X_DEF, int y = Y_DEF);

    ~Point();

    std::string getNom() const;

    int getX() const;

    int getY() const;

    // Setteurs
    void setNom(string &nom);
    void setX(int x);
    void setY(int y);

    void saisir(istream & entree = cin);

    void afficher(ostream & sortie = cout) const;

private:


    // attributs d'instance
    string m_nom;
    int m_x;
    int m_y;

    static const int X_DEF;
    static const int Y_DEF;
    static string NOM_DEF;
};

#endif /* POINT_H */

