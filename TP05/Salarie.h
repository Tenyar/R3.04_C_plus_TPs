#ifndef SALARIE_H
#define	SALARIE_H

#include <string>
#include <iostream>
#include "SalarieException.h"
#include "ObjetContraint.h"
#include <map>

using namespace std;

class Salarie {
public:
    // A COMPLETER : Spécifier les méthodes d'instance d'un Salarie
    Salarie(const string & nom = NOM_DEF,const string & numeroSS = NUMERO_SS_DEF,const float & salaire = SMIC);

    string getNom() const;

    void setNom(const string & nom);

    string getNumeroSS() const;

    void setNumeroSS(const string & nom);

    const float getSalaireMensuel() const;

    void setSalaireMensuel(const float & salaireMensuel);

    const float getImpot() const;

    void saisir(istream & entree = cin);

    const void afficher(ostream & sortie = cout) const;

    // Fourni : Constantes de Classe
    static const float                 SMIC;
    static const float                 COEFF_SMIC;
    static const std::string           NOM_DEF;
    static const std::string           NUMERO_SS_DEF;
    static const std::map<float,float> TRANCHES_IMPOT;

private:
    // A COMPLETER : déclarer les attributs d'instance d'un Salarie
    string m_nom;
    string m_numeroSS;
    ObjetContraint<float> m_salaireMensuel;
};

#endif	/* SALARIE_H */

