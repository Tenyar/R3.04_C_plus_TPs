#ifndef FICHIER_H
#define FICHIER_H
#include "Element.h"
#include <string>
#include <ostream>

class Fichier : public Element{ // C'est une classe "feuille"
public:
    Fichier(const std::string & nom, int tailleKo, const std::string & dateCreation, Usager & usager1);

    //bonus
    string rechercher(const string & nom) override;

    unsigned  int getTaille() const override;

    const std::string & getDateModificiation() const override;

    void setDateModification(const string & date) override;

    void afficher() const override;

    void ajouter(Element * element) override;

    virtual ~Fichier() override;

private:
    int m_taille;
    std::string m_dateCreation;

    // à compléter
};

#endif /* FICHIER_H */

