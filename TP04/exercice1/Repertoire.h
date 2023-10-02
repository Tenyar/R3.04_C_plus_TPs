#ifndef REPERTOIRE_H
#define REPERTOIRE_H
#include "Element.h"
#include <string>
#include <ostream>
#include <vector>

class Repertoire : public Element{
    // C'est une classe "composée" (composite)
public:
    Repertoire(const std::string & nom, Usager & usager);

    unsigned  int getTaille() override;

    const std::string & getDateModificiation() override;

    void ajouter(Element * e) override;

    void afficher(std::ostream & sortie) const override;

    virtual ~Repertoire();

private:
    string dateModification;
    Usager m_usager;
    int m_taille;
    std::vector<Element *> m_contenu; // le conteneur d'éléments : un vecteur
};

#endif /* REPERTOIRE_H */

