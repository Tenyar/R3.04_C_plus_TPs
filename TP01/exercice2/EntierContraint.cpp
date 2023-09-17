#include "EntierContraint.h"
#include <iostream>
#include <string>

using namespace std;
// A COMPLETER



EntierContraint::EntierContraint(int valeur, int min, int max) : m_val(valeur), m_min(min), m_max(max){
    setVal(valeur);
    setMin(min);
    setMax(max);
};

int EntierContraint::getMin() const{
    return this->m_min;
};
int EntierContraint::getMax() const{
    return this->m_max;
};
int EntierContraint::getVal() const{
    return this->m_val;
};

void EntierContraint::setVal(int val2){
    if  (val2 > m_max || val2 < m_min){

        this->m_val = VAL_DEF;
        throw "val is greater than max";
    }
    else
    {
        this->m_val = val2;
    }
};
 
void EntierContraint::setMin(int min2){
    if  (min2 > m_val){
        this->m_min = MIN_DEF;
        throw "min is greater than val";
    }
    else
    {
        this->m_min = min2;
    }
};

void EntierContraint::setMax(int max2){
    if  (max2 < m_val){
        this->m_max = MAX_DEF;
        throw "max is less than val";
    }
    else
    {
        this->m_max = max2;
    }
};

void EntierContraint::saisir(istream & entree){

    cout << "Saisir les informations de l'entier constraint. \n";
    cout << "Saisir sa valeur : \n";
    entree >> m_val;

    cout << "Saisir le minimum de cet entier constraint : \n";
    entree >> m_min;

    cout << "Saisir le maximum de cet entier constraint : \n";
    entree >> m_max;

    try {
        this->setVal(m_val); // This will throw an exception if val < min
    } catch (const char* errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }

    try {
        this->setMin(m_min); // This will throw an exception if min > val
    } catch (const char* errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }

    try {
        this->setMax(m_max); // This will throw an exception if max < val
    } catch (const char* errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
};

void EntierContraint::afficher(ostream & sortie){
    sortie << "La valeur : " << m_val << endl// endl est comme \n
         << " le minimum : " << m_min << endl
         << " le maximum : " << m_max << endl;
}

