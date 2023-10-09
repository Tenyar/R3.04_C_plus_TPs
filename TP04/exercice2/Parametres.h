#ifndef PARAMETRES_H
#define PARAMETRES_H
#include <string>
#include "Theme.h"
#include "Joueur.h"

using namespace std;

class Parametres {
public:
    static Parametres & getInstance();

    const Theme & getTheme() const;

    void setTheme(Theme & myTheme);

    const Joueur * getJoueur() const;

    void setJoueur(Joueur & myJoueur);

    void afficher();

protected: // un utilisateur de la classe Singleton ne pourra pas instancier lui-même un objet Singleton.
    Parametres(const string & intituleTheme = "Par Defaut");
private:
    static Parametres* m_instance;
    Theme m_theme;
    Joueur * m_joueur;
};

#endif /* PARAMETRES_H */
