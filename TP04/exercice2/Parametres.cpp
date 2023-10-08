////////////////////////////////////////////////////////////////////////////////
// COMPLETEZ CE FICHIER
////////////////////////////////////////////////////////////////////////////////

#include "Parametres.h"
#include <iostream>
using namespace std;

Parametres::Parametres(const string & intituleTheme){
    m_theme = new Theme(intituleTheme);
    m_instance = this;
    m_joueur = nullptr;
}

const Theme & Parametres::getTheme() const{
    return *this->m_theme;
}

void Parametres::setTheme(Theme & myTheme){
    if (m_theme != nullptr) {
        delete m_theme;  // Deallocate the previous Theme object
    }
    this->m_theme = new Theme(myTheme);  // Allocate memory for the new Theme object and copy it
}

const Joueur * Parametres::getJoueur() const{
    return this->m_joueur; // deferencing the pointer itself to get the object
}

void Parametres::setJoueur(Joueur & myJoueur){
    if (m_joueur != nullptr){
        delete m_joueur; // Deallocate the previous Theme object
    }
    this->m_joueur = new Joueur(myJoueur); // Allocate memory for the new Theme object and copy it
}


void Parametres::afficher() {
    // flush the output buffer immediately, preventing any additional line breaks or buffering of output.
    cout << "Parametres" << " --> {"
    << "-Theme: '" << this->m_theme->getIntitule() << "', "
    << " Joueur: " << flush;
    if (m_joueur != nullptr) {
        cout << "'" << this->m_joueur->getPseudo() << "'}"<< endl;
    }
    else{
        cout << "'Anonyme'}" << endl;
    }
}

Parametres & Parametres::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Parametres();
    }
    return *m_instance;
}

Parametres * Parametres::m_instance = nullptr; // Init the instance at nullptr

