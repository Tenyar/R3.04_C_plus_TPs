////////////////////////////////////////////////////////////////////////////////
// NE MODIFIEZ PAS CE FICHIER
////////////////////////////////////////////////////////////////////////////////

#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>

using namespace std;

class Joueur {
public:
    Joueur(const string & intitule) : m_pseudo(intitule) {}

    const string & getPseudo() const { return m_pseudo; }
private:
    string m_pseudo;
};

#endif /* JOUEUR_H */