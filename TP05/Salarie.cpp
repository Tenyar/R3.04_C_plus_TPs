#include "Salarie.h"
#include "SalarieException.h"
#include <cctype>
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

string Salarie::getNom() const {
    std::string result = m_nom;
    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c)); // cast to unsigned char to ensures that the function works correctly for all characters, including extended ASCII characters.
    }
    return result;
}

void Salarie::setNom(const string &nom) {
    // Création d'un booléan
    bool erreur = false;
    // Parcours tout les caractères du nom
    for (int i = 0; !erreur && i < nom.size(); i++) {
        // Si le caractère n'est pas de l'alphabet et est pas égal à un '-' alors erreur == true.
        erreur = (!isalpha(nom[i]) && nom[i] != '-');
    }
    // Si l'erreur est vrai ou le nom est vide ou un tiret est au début ou à la fin du nom.
    if (erreur || nom.empty() || nom[0]=='-' || nom[nom.size()-1]=='-')
        // Lance l'erreur Nom incorrect
        throw NomIncorrectException(nom);
    this->m_nom = nom;
}

string Salarie::getNumeroSS() const {
    return this->m_numeroSS;
}

void Salarie::setNumeroSS(const string &numeroSS) {
    if (numeroSS.length() < 13){
        throw NumeroIncorrectException(numeroSS);
    }
    for (char c : numeroSS) {
        if (!isdigit(c)){
            throw NumeroIncorrectException(numeroSS);
        }
    }
    this->m_numeroSS = numeroSS;
}

const float Salarie::getSalaireMensuel() const {
    return this->m_salaireMensuel.getVal();
}

void Salarie::setSalaireMensuel(const float & salaireMensuel) {
    if (salaireMensuel < SMIC || salaireMensuel > (SMIC * COEFF_SMIC)){
        throw SalaireIncorrectException(salaireMensuel); // si le salaire n’est pas dans la fourchette autorisée.
    }
    ObjetContraint<float> salaireM(salaireMensuel, SMIC, SMIC * COEFF_SMIC);
    this->m_salaireMensuel = salaireM;
}

const float Salarie::getImpot() const{
    // Iterator pour parcourir toute les clés/valeurs dans la map.
    map<const float, float>::const_iterator iterator = TRANCHES_IMPOT.begin();
    // compare toutes les possibilités de salaires
    float salaireAnnuel = (getSalaireMensuel() * 12);
    while (salaireAnnuel > iterator->first){ // tant que le salaire annuel (salaireMensuel*12) est supérieure à un palier de salaire annuel
        iterator++; // On continue
    }
    iterator--; // Since we check at an index further from the result.

    return iterator->second; // Accède à la valeur de l'élément pointé par iterator. [First = clé, Second = valeur]
}

void Salarie::saisir(istream &entree) {

    // variables
    string nom;
    string numeroSS;
    float salair;

    cout << "saisir le nom: " << flush;
    entree >> nom;
    try{
        this->setNom(nom);
    }catch (SalarieException * e){
        cout << "Exception : " << e->what() << "\n" << endl;
    }

    cout << "saisir le numeroSS: " << flush;
    entree >> numeroSS;
    try{
        this->setNumeroSS(numeroSS);
    }catch (SalarieException * e){
        cout << "Exception : " << e->what() << "\n" << endl;
    }

    cout << "saisir le salaire mensuel: " << flush;
    entree >> salair;

    try{
        this->setSalaireMensuel(salair);
    }catch (SalarieException * e){
        cout << "Exception : " << e->what() << "\n" << endl;
    }
}

const void Salarie::afficher(ostream &sortie) const {
    sortie << "--------- Impôts salarié(e) ---------" << endl
           << "Nom : " << this->getNom() << endl
           << "Numero SS : " << this->getNumeroSS() << endl
           << "Salaire Mensuel : " << this->getSalaireMensuel() << endl
           << "Impôts Annuel : " << this->getImpot();
}

