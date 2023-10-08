#ifndef REPERTOIRE_H
#define REPERTOIRE_H
#include "Element.h"
#include <string>
#include <ostream>
#include <vector>

using namespace std;

class Repertoire : public Element{
    // C'est une classe "composée" (composite)
public:
    Repertoire(const std::string & nom, Usager & usager);

    //bonus
    string rechercher(const string & nom) override;

    unsigned  int getTaille() const override;

    const std::string & getDateModificiation() const override;

    void setDateModification(const string & date) override;

    void afficher() const override;

    void ajouter(Element * e) override;

    ~Repertoire() override;

private:
    string m_dateCreation;
    int m_taille;
    std::vector<Element *> m_contenu; // le conteneur d'éléments : un vecteur
};

#endif /* REPERTOIRE_H */