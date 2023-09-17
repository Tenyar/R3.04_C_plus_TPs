#ifndef ENTIERCONTRAINT_H
#define ENTIERCONTRAINT_H

#include <iostream>
#include <limits>

using namespace std;

class EntierContraint {
public:
    
    // A COMPLETER
    EntierContraint(int valeur = VAL_DEF, int min = MIN_DEF, int max = MAX_DEF);

    int getMin() const; // const = non modifiable (cette fonction ne modifie rien)
    int getMax() const;
    int getVal() const;

    void setVal(int val2);

    void setMin(int min2);

    void setMax(int max2);

    void saisir(istream & entree = cin);

    void afficher(ostream & sortie = cout);

private:

    // A COMPLETER
    int m_min;
    int m_max;
    int m_val;



    // Constantes de Classe (static) pour définir les valeurs par défaut des attributs d'un entier contraint
    static constexpr int VAL_DEF = 0;
    static constexpr int MIN_DEF = std::numeric_limits<int>::min(); // le plus petit int possible
    static constexpr int MAX_DEF = std::numeric_limits<int>::max(); // le plus grand int possible
};

#endif /* ENTIERCONTRAINT_H */

