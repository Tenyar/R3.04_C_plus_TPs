#ifndef OBJETCONTRAINT_H
#define OBJETCONTRAINT_H
#include <stdexcept>

using namespace std;

template <class T>
class ObjetContraint {
    // Spécifiez ici le template de classe ObjetContraint<T>
public:
    inline  ObjetContraint(const T & val,const T & min,const T & max);
    /* code est inséré directement à chaque endroit où elles sont appelées dans le code source lors de la compilation.
        Cela permet d'éviter les frais généraux associés aux appels de fonction.
        /!\ mais cela peut augmenter la taille du code final /!\.
        Les fonctions inline sont principalement utilisées pour de courtes fonctions ou
    pour des fonctions fréquemment utilisées où les avantages de la performance l'emportent sur les inconvénients de la taille du code.
    */

    //les fonctions ne modifient pas l'état interne de l'ObjetContraint car const.
    inline  const T & getMin() const{
        return this->m_min;
    };
    inline  const T & getMax() const{
        return this->m_max;
    };
    inline  const T & getVal() const{
        return this->m_val;
    };

    inline  void setVal(const T & val);

    // Un objet de la classe peut être convertie en un objet de type 'T'.
    // e.g convert object to int will equal getVal for the int.
    inline  operator T() const{
        return getVal();
    };
    // défini l'opérateur d'assignation surchargé
    // Cet opérateur prend un entier 'value' en argument et le transmet à la méthode setVal de l'objet ec1.
    inline ObjetContraint & operator=(int value) {
        setVal(value); // mets à jour la valeur de 'val' (1er paramètre de l'objet).
        // On retourne l'objet directement pour pouvoir faire des opérations en chaine (obligatoire dans la surcharge de l'opérateur '=').
        return *this;
    }

private:
    T m_val;
    T m_min;
    T m_max;
};

// Implémentez ici les méthodes du template ObjetContraint<T> (pas de fichier .cpp pour un template)
template <class T>
    ObjetContraint<T>::ObjetContraint(const T & val,const T & min,const T & max) : m_min(min), m_max(max){
        setVal(val);
}

template <class T>
void ObjetContraint<T>::setVal(const T & val) {
    if(val < m_min || val >m_max){
        throw domain_error("Val hors de l'intervalle Min / Max"); // report error of (domain in the mathematical sense).
    }
    this->m_val = val; // On doit quand même affecter l'erreur à la variable une fois l'exception levée.
}


#endif /* OBJETCONTRAINT_H */

