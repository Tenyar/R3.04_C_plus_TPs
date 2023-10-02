#ifndef FICHIER_H
#define FICHIER_H
#include "Element.h"
#include <string>
#include <ostream>

class Fichier : public Element{ // C'est une classe "feuille"
public:
    Fichier(const std::string & nom, const std::string & dateCreation, int tailleKo);

    unsigned  int getTaille() override;

    void afficher(std::ostream & sortie) const override;

    void ajouter(Element * element) override;

    virtual ~Fichier();

private:
    int m_taille;
    std::string m_dateCreation;

    // à compléter
};

#endif /* FICHIER_H */

