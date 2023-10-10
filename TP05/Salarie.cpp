#include "Salarie.h"
#include "SalarieException.h"
#include <ctype.h>
#include <map>
#include <limits>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// A COMPLETER : Implémenter les méthodes d'instance de la classe Salarie

// Constantes de classe
const float                  Salarie::SMIC          = 1257.0f;
const float                  Salarie::COEFF_SMIC    = 500.0f;
const std::string            Salarie::NOM_DEF       = "Martin";
const std::string            Salarie::NUMERO_SS_DEF = "1234567890123";
const std::map<float, float> Salarie::TRANCHES_IMPOT {
    {  6000.0f, 0.000f},
    { 12000.0f, 0.055f},
    { 26600.0f, 0.140f},
    { 71400.0f, 0.300f},
    {151200.0f, 0.410f},
    {std::numeric_limits<float>::max(), 0.50f} 
};

Salarie::Salarie(const string &nom, const string &numeroSS, const float &salaire) : m_nom(nom), m_numeroSS(numeroSS), m_salaireMensuel(salaire, SMIC, SMIC * COEFF_SMIC) {

}

const string Salarie::getNom() const {
    this->m_nom;
}

void Salarie::setNom(const string &nom) {
    if (nom.empty()){
        throw NomIncorrectException(nom);
    }
    this->m_nom = nom;
}

const string Salarie::getNumeroSS() const {
    return this->m_numeroSS;
}

void Salarie::setNumeroSS(const string &numeroSS) {
    this->m_numeroSS = numeroSS;
}

const float Salarie::getSalaireMensuel() const {
    return this->m_salaireMensuel;
}

void Salarie::setSalaireMensuel(const ObjetContraint<float> & salaireMensuel) {
    this->m_salaireMensuel = salaireMensuel;
}

const float Salarie::getImpot() const{
    // Iterator pour parcourir toute les clés/valeurs dans la map.
    map<const float, float>::const_iterator iterator = TRANCHES_IMPOT.begin();
    // compare toutes les possibilités de salaires
    while (this->m_salaireMensuel * 12 > iterator->first){ // tant que le salaire annuel (salaireMensuel*12) est supérieure à un palier de salaire annuel
        iterator++; // On continue
    }
    return iterator->second; // Accède à la valeur de l'élément pointé par iterator. [First = clé, Second = valeur]
}

void Salarie::saisir(istream &entree) {
    string nom;
    cout << "saisir le nom: " << flush;
    entree >> nom;
    try{
        this->setNom(nom);
    }catch (SalarieException * e){
        cout << "Exception : " << e->what() << "\n";
    }

    string numeroSS;
    cout << "saisir le numeroSS: " << flush;
    entree >> numeroSS;
    try{
        this->setNumeroSS(numeroSS);
    }catch (SalarieException * e){
        cout << "Exception : " << e->what() << "\n";
    }

    ObjetContraint<float> salairMensuel();
    cout << "saisir le salaire mensuel: " << flush;
    entree >> salairMensuel;
}

const void Salarie::afficher(ostream &sortie) const {
    return;
}

