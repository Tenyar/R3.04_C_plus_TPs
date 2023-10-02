#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <ostream>
#include "Usager.h"

class Element { // C'est la classe abstraite "composant" (component)
public:
    Element(const std::string & nom);

    const std::string & getNom() const; // virtual inutile {return this->m_nom;}

    void setNom(std::string nouv_nom);

    const Usager & getProprietaire();

    virtual unsigned int getTaille() = 0;

    virtual const std::string & getDateModificiation() = 0;

    virtual void afficher(std::ostream & sortie) const;

    virtual void ajouter (Element * element) = 0;
// Les opérations propres aux non-terminaux doivent aussi être visibles ici
// Mais on ne les implémente réellement que dans les non-terminaux
    virtual ~Element();
private:
    std::string m_nom; // Chaque élément du système de fichiers a un nom
    const Usager & proprietaire;
};

#endif /* ELEMENT_H */

