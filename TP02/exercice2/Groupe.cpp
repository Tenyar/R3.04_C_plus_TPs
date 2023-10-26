#include "Groupe.h"
#include "Personne.h"
#include <string>
#include <iostream>

using namespace std;

// A COMPLETER
// Implémenter les méthodes nécessaires pour la forme canonique de COPLIEN

Groupe::Groupe(const std::string &intitule)
        : m_intitule(intitule) {
}

///////////////////////////////////////////////////
void Groupe::setIntitule(const std::string &intitule) {
    this->m_intitule = intitule;
}

///////////////////////////////////////////////////
void Groupe::addPersonne(const std::string &nom) {
    this->m_effectif.push_back(new Personne(nom));
}

///////////////////////////////////////////////////
void Groupe::setNomPersonne(unsigned int i,
                            const std::string nom) {
    if (i < this->m_effectif.size())
        this->m_effectif[i]->setNom(nom);
}

///////////////////////////////////////////////////
void Groupe::affiche() const {
    cout << "Groupe " << this->m_intitule << " = { ";
    for (Personne *personne: this->m_effectif)
        cout << personne->getNom() << " ";
    cout << "}" << endl;
}

// Forme Canonique de Coplien

Groupe::Groupe(const Groupe& group){
    for (int i = 0; i < group.m_effectif.size(); ++i) {
        this->addPersonne(group.m_effectif.at(i)->getNom());
    }
    this->setIntitule(group.m_intitule);
}

Groupe& Groupe::operator=(const Groupe& group){
    // Libère la mémoire ainsi que ce qu'il y avait dedans avant de faire un clear sûre.
    for (int i = 0; i < m_effectif.size(); ++i) {
        delete this->m_effectif[i];
    }
    this->m_effectif.clear();

    // On duplique les personnes du groupe affecter à l'objet courant qui 'subis' l'affectation.
    for (int i = 0; i < group.m_effectif.size(); ++i) {
        this->addPersonne(group.m_effectif.at(i)->getNom());
    }
    // Dupliquation de l'intitulé.
    this->m_intitule = group.m_intitule;

    // retourne un pointeur vers l'objet courant
    return *this;
}

Groupe::~Groupe(){
    cout << " Suppression de l'objet !" << endl;
    // éfface les objets pointé du tableau (les personnes).
    for (int i = 0; i < this->m_effectif.size(); ++i) {
        delete(this->m_effectif.at(i));
    }
    // Vide le tableau (il n'est plus pointé).
    m_effectif.clear();
    //  effacer le contenu de la chaîne de caractères
    m_intitule.clear();
}