#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>

class Personne {
public:
    Personne(std::string nom);
    const std::string & getNom() const;
    void setNom(const std::string & nom);
    virtual ~Personne();
    static void afficheNbInstances();
private:
    std::string m_nom;
    static unsigned int nbInstances;
};

#endif /* PERSONNE_H */

