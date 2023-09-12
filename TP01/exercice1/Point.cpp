// Dans le fichier d'implémentation d'une classe, on doit inclure le fichier de spécification de cette classe
#include "Point.h"
#include <iostream>
#include <string>

// Et on inclura aussi les librairies utilisées ici

using namespace std;


// A COMPLETER - Implémenter les méthodes de la classe Point
    Point::Point(string &nom, int x, int y) : m_nom(), m_x(x), m_y(y){
        setNom(nom);
        setX(x);
        setY(y);
        cout << "Le point à été initialisé !\n";
    }

    Point::~Point(){
        cout << "Le point " << m_nom << " à été supprimé \n";
    }

    string Point::getNom() const{
        return this->m_nom;
    }
    void Point::setNom(string &nom){
        if (nom.empty()){
            this->m_nom = "hello";
        }
        else
        {
            m_nom = nom;
        }
    }

    int Point::getX() const{
        return this->m_x;
    }
    void Point::setX(int x){
            this->m_x = x;
    }

    int Point::getY() const{
        return this->m_y;
    }
    void Point::setY(int y){
            this->m_y = y;
    }

    void Point::saisir(istream & entree){
        cout << "Saisir les informations du point. \n";
        cout << "Saisir le nom du point : \n";
        cin >> m_nom;
        cout << "Saisir la coordonnée X du point : \n";
        cin >> m_x;
        cout << "Saisir la coordonnée Y du point : \n";
        cin >> m_y;
    }

    void Point::afficher(ostream & sortie) const{
        cout << "Le nom : " << m_nom << endl// endl est comme \n
        << " la coordonnée X : " << m_x << endl
        << " la coordonnée Y : " << m_y << endl;
    }

const int Point::X_DEF = 0;
const int Point::Y_DEF = 0;
// par référence.
string Point::NOM_DEF = "Hello";
