#ifndef OBJETCONTRAINT_H
#define OBJETCONTRAINT_H
#include <stdexcept>

using namespace std;

template <class T>
class ObjetContraint {
    // A COMPLETER : Spécifiez ici le template de classe ObjetContraint<T>
public:
    inline  ObjetContraint(T & val, T & min, T & max);
    /* code est inséré directement à chaque endroit où elles sont appelées dans le code source lors de la compilation.
        Cela permet d'éviter les frais généraux associés aux appels de fonction.
        /!\ mais cela peut augmenter la taille du code final /!\.
        Les fonctions inline sont principalement utilisées pour de courtes fonctions ou
    pour des fonctions fréquemment utilisées où les avantages de la performance l'emportent sur les inconvénients de la taille du code. */
    inline  const T & getMin(){
        return this->m_min;
    };
    inline  const T & getMax(){
        return this->m_max;
    };
    inline  const T & getVal(){
        return this->m_val;
    };

    inline  void setVal(const T & val);

    // Un objet de la classe peut être convertie en un objet de type 'T'.
    // e.g convert object to int will equal getVal for the int.
    inline  operator T() const{
        return getVal();
    };
private:
    T m_val;
    T m_min;
    T m_max;
};

// A COMPLETER : Implémentez ici les méthodes du template ObjetContraint<T> (pas de fichier .cpp pour un template)
template <class T>
ObjetContraint<T>::ObjetContraint(T & val, T & min, T & max) : m_min(min), m_max(max){
    setVal(val);
}

template <class T>
void ObjetContraint<T>::setVal(const T & val) {
    if(m_max < val || val < m_min){
        throw domain_error("Val hors de l'intervalle Min / Max"); // report error of (domain in the mathematical sense).
    }
    this->m_val = val; // On doit quand même affecter l'erreur à la variable une fois l'exception levée.
}


#endif /* OBJETCONTRAINT_H */

