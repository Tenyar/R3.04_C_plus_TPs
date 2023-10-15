#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

#include "Salarie.h"

int main(int argc, char **argv) {
    // A COMPLETER : saisir et afficher un Salarie
    Salarie salarie1;
    salarie1.saisir();
    salarie1.afficher();

    return 0;
}