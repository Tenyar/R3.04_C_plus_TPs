#ifndef CONTENEUR_H
#define CONTENEUR_H

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Conteneur {

// Spécifiez ici le template Conteneur<T>
public:
    Conteneur();
    // On doit passer obligatoirement pas un String mais bien un Objet de même type Conteneur.
    // Const. par recopie
    Conteneur(const Conteneur<T> & unConteneur);

    // opérateur par affectation
    Conteneur<T> & operator=(const Conteneur<T> & unConteneur);

    inline ~Conteneur(){
        this->clear();
    }

     void ajouter(T * element);
     void afficher(ostream & sortie = cout) const;
     // return reference to object
     T & choisir(istream & entree = cin);
private:
    // Collection de pointeur sur des éléments.
    //indicés (à partir de 0) extensible (réduire ou rallonger).
    vector<T*> m_ptrs;
    // Méthode qui sera appelée dans le constructeur avec argument.
    void clone(const Conteneur<T> & unConteneur);
    // Méthode pour vider le vecteur
    void clear();
};

//  Implémentez ici les méthodes du template Conteneur<T> (pas de fichier .cpp pour un template)

template<class T>
// ': m_ptrs()' vector default constructor. initializing the vector as empty, i.e., it starts with no elements.
Conteneur<T>::Conteneur() : m_ptrs() {}

// Appel la méthode Clone définie lors d'un const. par recopie.
template <class T>
Conteneur<T>::Conteneur(const Conteneur<T> & unConteneur) {
    this->clone(unConteneur);
}

// T = classe distincte & Conteneur<T> = même class que this
// Donc Conteneur<T> = permet l'accès à ses membres privés.
// T = ne donne pas un accès directe aux membres privés de conteneurs.
/*
 *  En résumé, la visibilité des membres privés dépend de la portée et de la structure des classes en jeu.
 *  Dans le premier cas, vous travaillez à l'intérieur de la classe Conteneur<T>,
 *  ce qui permet l'accès à ses membres privés. Dans le second cas,
 *  vous travaillez avec une classe distincte (T),
 *  ce qui ne donne pas un accès direct aux membres privés de Conteneur<T>.
 */
template <class T>
//  So, the unConteneur object itself remains unchanged, but its elements are cloned and added to the m_contenu vector of the current object.
//  This allows you to create a copy of the contents of unConteneur without modifying unConteneur itself.
void Conteneur<T>::clone(const Conteneur<T> & unConteneur){
    for (T * elements : unConteneur.m_ptrs) {
        // Allocation dynamique donc 'new'
        this->m_ptrs.push_back(new T(*elements)); // les données pointées par l'élément sont copiées dans un nouvel objet T.
    }
}

template <class T>
Conteneur<T> & Conteneur<T>::operator=(const Conteneur<T> & unConteneur){
    this->clear();
    this->clone(unConteneur);
    return *this;
}

template <class T>
void Conteneur<T>::clear(){
    // Delete all the elements in the vector.
    for (T * elements : this->m_ptrs) {
        delete(elements);
    }
}

template <class T>
void Conteneur<T>::ajouter(T * element){
    this->m_ptrs.push_back(element); // Ajoute un élément de valeur e à la fin du vecteur
}

template <class T>
void Conteneur<T>::afficher(ostream & sortie) const{
    unsigned int i = 0;
    sortie << "Voici ce qu'il y a dans le conteneur :" << endl;
    for (T * elements : this->m_ptrs) {
        sortie << i++ << " - " << *elements << endl;
    }
}

template <class T>
T & Conteneur<T>::choisir(std::istream & entree) {
    unsigned int index;
    cout << " Choissisez parmi un contenu entre 1 a " << this->m_ptrs.size() << endl;
    entree >> index;
    // Permet une fois validation de la saisit(integer) de nettoyer le caractère ('\n') = nouvelle ligne ou d'autres caractères restant dans le buffer(tampon).
    entree.ignore(256, '\n');
    if (index < 1 || index > this->m_ptrs.size()){
        // L'exception 'range_error' est pertinente pour cette situation.
        throw range_error("Element introuvable");
    }
    else{
        return *(this->m_ptrs[index-1]); // or this->m_prts.at(index - 1);
    }
}

#endif /* CONTENEUR_H */

