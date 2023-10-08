#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <ostream>
#include "Usager.h"

using namespace std;

class Element { // C'est la classe abstraite "composant" (component)
public:
    Element(const string & nom, const Usager & proprio);

    const string & getNom() const; // virtual inutile {return this->m_nom;}

    void setNom(string & nouv_nom);

    const Usager & getProprietaire() const;

    void setProprietaire(const Usager & proprietaire);

    //Bonus
    virtual string rechercher(const string & nom) = 0;

    virtual unsigned int getTaille() const = 0; // = 0 est égal a abstract

    virtual const string & getDateModificiation() const = 0;

    virtual void setDateModification(const string & date) = 0;

    virtual void afficher() const;

    virtual void ajouter (Element * element) = 0;
// Les opérations propres aux non-terminaux doivent aussi être visibles ici
// Mais on ne les implémente réellement que dans les non-terminaux
    virtual ~Element();
private:
    string m_nom; // Chaque élément du système de fichiers a un nom
    Usager m_proprietaire;
};

#endif /* ELEMENT_H */