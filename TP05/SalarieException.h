#ifndef SALARIEEXCEPTION_H
#define SALARIEEXCEPTION_H
#include <stdexcept>
#include "ObjetContraint.h"

// A Compléter

// Toutes les exceptions de la classe Salarie seront dues à des valeurs non conformes (nom, numéro SS ou salaire)
// On va donc faire dériver SalarieExcemtion de domain_error qui est l'exception prédéfinie dans <stdexcept> pour ce genre de situation

class SalarieException : public std::domain_error{ // pertinent parceque nous travaillons sur un domaine_error.
public:
     const char * what() const noexcept override{
        return "Le salarié à comporte une erreur.";
    }

protected: // User can't make an instance of this class.
    SalarieException();
};

class NomIncorrectException : public SalarieException {
public:
    std::string m_nom; // Nom qui provoque l'exception
    NomIncorrectException(std::string nom) : m_nom(nom){
    }
    const char * what() const noexcept override {
        return "Le nom d’un salarié n’est pas correct";
    }
};

class NumeroIncorrectException : public SalarieException{
public:
    std::string m_numeroSS;
    NumeroIncorrectException(std::string numeroSS) : m_numeroSS(numeroSS){
    }
    const char * what() const noexcept override {
        return "Le numéro de SS n’est pas valide";
    }
};

class SalaireIncorrectException : public SalarieException{
public:
    ObjetContraint<float> m_salaire;
    SalaireIncorrectException(ObjetContraint<float> salaire) : m_salaire(salaire){
    }
    const char * what() const noexcept override {
        return "Le salaire n’est pas dans la fourchette autorisée";
    }
};

#endif /* SALARIEEXCEPTION_H */

