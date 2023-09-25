#include "Visage.h"
#include <iostream>
using namespace std;

// A COMPLETER : IMPLEMENTER LES METHODES DE LA CLASSE VISAGE (ET L'OPERATEUR <<)

Visage::Visage(int longueurNez, const Ethnie &uneEthnie) : m_monNez(longueurNez), m_monEthnie(uneEthnie) {
    // initialisé à null les valeurs non saisit.
    this->m_maMoustache = nullptr;
    this->m_chapeau = nullptr;
} // liste d'initialisation

void Visage::setMoustache(int largeur) {
    if (largeur >= 0){ // allocation dynamique
        this->m_maMoustache = new Moustache(largeur);
    }
}

void Visage::addBouton(int diametre) {
    if (diametre > 0){
        // vu que l'on sait que Bouton est à la classe visage on fait une alloc statiquement / automatiquement car dynamiquement (new) fait un pointer et statiquement n'en fait pas.
        this->m_mesBoutons.push_back(Bouton(diametre));
    }
}

void Visage::setChapeau(const Chapeau &unChapeau) {
    this->m_chapeau = (&unChapeau); // les (modèles) de chapeaux ne nous appartiennent pas donc on alloue qynamiquement.
}

void Visage::addBijou(const Bijou &unBijou) {
this->m_mesBijoux.push_back(&unBijou); // &Bijou pour éviter les copies inutlies. L'objet est partagé entre les objets Visage.
}

const Visage &Visage::operator=(const Visage &unVisage) {
    this->m_mesBoutons = unVisage.m_mesBoutons; // clone ou affectation ?
    this->m_chapeau = unVisage.m_chapeau;
    this->m_mesBijoux = unVisage.m_mesBijoux;
    this->m_maMoustache = unVisage.m_maMoustache;
    //delete(unVisage.m_maMoustache); // vu qu'il peut y avoir une fuite de mémoire il faut enlever a 'unVisage' passé en paramètre ses 'anciennes' moustaches.
    //delete(unVisage.m_chapeau);
    return *this;
}

Visage::Visage(const Visage &unVisage) : m_monNez(unVisage.m_monNez), m_monEthnie(unVisage.m_monEthnie) { // liste d'initialisation
    // Ses objets sont partagé donc par affectation.
    this->m_mesBoutons = unVisage.m_mesBoutons; // clone ou affectation ?
    this->m_chapeau = unVisage.m_chapeau;
    this->m_mesBijoux = unVisage.m_mesBijoux;
    // on clone les moustaches.
    if (unVisage.m_maMoustache != nullptr){
        this->m_maMoustache = new Moustache(*unVisage.m_maMoustache); // ou unVIsage.m_maMoustache->getLargeur()
    }
    else{
        this->m_maMoustache = nullptr;
    }
}

Visage::~Visage() { // destructeur free automatiquement les pointeurs. les vecteurs de la classe Vector se free aussi grâce à leur implémentation.
    // l'object m_monNez est alloué statiquement / automatiquement donc sa fin de vie sera la fin de vie de l'objet.
    this->m_mesBoutons.clear(); // vide le vecteur.
}

std::ostream &operator<<(std::ostream &sortie, const Visage &visage) {
    sortie << visage.m_monEthnie << endl
    << visage.m_monNez << endl;

    if(visage.m_maMoustache == nullptr) {sortie << "pas de moustache" << endl;}
    else{sortie << *visage.m_maMoustache << endl;}

    sortie << *visage.m_chapeau << endl;

    for (Bouton elements : visage.m_mesBoutons) {
        sortie << elements << endl;
    }

    for (const Bijou * elements : visage.m_mesBijoux) {
        sortie << *elements << endl;
    }
    return sortie;
}