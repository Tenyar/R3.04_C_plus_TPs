#include "gtest/gtest.h"
#include <map>
#include "Salarie.h"
#include "SalarieException.h"
using namespace std;

TEST(SalarieTest, Constructeur) {
    // A COMPLETER : tester Salarie::Salarie

    // Créez un tableau de données de test
    struct TestParams {
        const char* nom;
        const char* numeroSS;
        double salaireMensuel;
        bool isThrowable;
    };

    TestParams testCases[] = {
    {"-spiderMan", "1234567890123", Salarie::SMIC, true}, // cas paramètres nom non valide.
    {"spiderMan", "3234567890123", Salarie::SMIC, true}, // cas paramètres numeroSS non valide.
    {"spiderMan", "1234567890123", Salarie::SMIC - 100, true}, // cas paramètres salaire non valide.
    {"spiderMan", "1234567890123", Salarie::SMIC, false}, // cas paramètres sont tous valides.
    };

    // Test tous les cas
    for (const TestParams& params : testCases) {
        if (params.isThrowable){
            EXPECT_ANY_THROW(Salarie(params.nom, params.numeroSS, params.salaireMensuel));
        }
        else{ // Pour cas valide
            Salarie salarie1(params.nom, params.numeroSS, params.salaireMensuel);
            EXPECT_EQ(salarie1.getNom(), "SPIDERMAN");
            EXPECT_EQ(salarie1.getNumeroSS(), params.numeroSS);
            EXPECT_EQ(salarie1.getSalaireMensuel(), params.salaireMensuel);
        }
    }

}

TEST(SalarieTest, GetNom) { // the error was that getNom started at the letter 1 rather than index 0(the word was cut).
    // A COMPLETER : test Salarie::getNom
    Salarie salarie1("spiderman");
    Salarie salarie2("SPIDERMAN");
    EXPECT_EQ(salarie1.getNom(), "SPIDERMAN");
    EXPECT_EQ(salarie2.getNom(), "SPIDERMAN");
}

TEST(SalarieTest, SetNom) {
    // A COMPLETER : test Salarie::setNom
    Salarie salarie1("spiderman");
    EXPECT_THROW(salarie1.setNom("-spiderman"), NomIncorrectException);
    EXPECT_THROW(salarie1.setNom("spiderman-"), NomIncorrectException);
    EXPECT_THROW(salarie1.setNom(""), NomIncorrectException);
    EXPECT_THROW(salarie1.setNom("-"), NomIncorrectException);
    EXPECT_THROW(salarie1.setNom("6546"), NomIncorrectException);
    EXPECT_THROW(salarie1.setNom("^{@^="), NomIncorrectException);
    // on attend aucune exception donc un test réussit.
    EXPECT_NO_THROW(salarie1.setNom("Jean-michelle"));
    EXPECT_NO_THROW(salarie1.setNom("Jean"));
    //Vérifie si le setNom change bien la variable
    EXPECT_TRUE(salarie1.getNom() == "JEAN");
}

TEST(SalarieTest, SetNumeroSS) {
    // A COMPLETER : test Salarie::setNumeroSS
    Salarie salarie1("spiderman");
    EXPECT_THROW(salarie1.setNumeroSS("05454643"), NumeroIncorrectException);
    EXPECT_THROW(salarie1.setNumeroSS("1"), NumeroIncorrectException);
    EXPECT_THROW(salarie1.setNumeroSS(""), NumeroIncorrectException);
    EXPECT_THROW(salarie1.setNumeroSS("Dix-huits"), NumeroIncorrectException);
    // on attend aucune exception donc un test réussit.
    EXPECT_NO_THROW(salarie1.setNumeroSS("1234567890123")); // identifiant commence par 1 = homme ou 2 = femme.
    EXPECT_EQ(salarie1.getNumeroSS(), "1234567890123");
    EXPECT_NO_THROW(salarie1.setNumeroSS("2234567890123")); // identifiant commence par 1 = homme ou 2 = femme.
    EXPECT_EQ(salarie1.getNumeroSS(), "2234567890123");
}

TEST(SalarieTest, SetSalaire) {
    // A COMPLETER : test Salarie::setSalaire
    Salarie salarie1("spiderman", "1234567890123");
    // Salaire plus petit que le smic
    EXPECT_THROW(salarie1.setSalaireMensuel(Salarie::SMIC-1), SalaireIncorrectException);
    // Salaire plus grand que le smic fois le coefficient
    EXPECT_THROW(salarie1.setSalaireMensuel(Salarie::SMIC*Salarie::COEFF_SMIC+1), SalaireIncorrectException);
    // Salaire dans l'interval smic et coef smic
    EXPECT_NO_THROW(salarie1.setSalaireMensuel(Salarie::SMIC*Salarie::COEFF_SMIC));
    EXPECT_NO_THROW(salarie1.setSalaireMensuel(Salarie::SMIC));
    EXPECT_NO_THROW(salarie1.setSalaireMensuel(Salarie::SMIC * Salarie::COEFF_SMIC -1));
    salarie1.setSalaireMensuel(5555);
    EXPECT_EQ(salarie1.getSalaireMensuel(), 5555);
}

TEST(SalarieTest, GetImpot) {
// A COMPLETER : tester Salarie::getImpot
    Salarie salarie1("spiderman", "1234567891234", Salarie::SMIC);
    // On test les tranches d'impôts par salaire annuel.
    EXPECT_EQ(salarie1.getImpot(), (Salarie::SMIC*12.0f)*0.140f);
    salarie1.setSalaireMensuel(3000);
    EXPECT_EQ(salarie1.getImpot(), (3000*12)*0.300f);
    salarie1.setSalaireMensuel(7000);
    EXPECT_EQ(salarie1.getImpot(), (7000*12)*0.410f);
    salarie1.setSalaireMensuel(15000);
    EXPECT_EQ(salarie1.getImpot(), (15000*12)* 0.50f);
}

