#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "Personne.h"

class Groupe {
public:
    Groupe(const std::string & intitule = "Un Groupe");
    void setIntitule(const std::string & intitule);
    void addPersonne(const std::string & nom);
    void setNomPersonne(unsigned int i, const std::string nom);
    void affiche() const;

    // A COMPLETER POUR METTRE SOUS FORME CANONIQUE DE COPLIEN
    Groupe(const Groupe&);
    Groupe& operator=(const Groupe&);
    ~Groupe();

private:
    std::string m_intitule;
    std::vector<Personne*> m_effectif;  // un Groupe est composé de Personnes
};

#endif /* GROUPE_H */

