cmake_minimum_required(VERSION 3.23)
project(TP06)
set(CMAKE_CXX_STANDARD 14)

# 1. Compilation du petit programme de tests "à la main" (exercice 1)

add_executable(exercice1 exercice1.cpp Salarie.h Salarie.cpp SalarieException.h)

# 2. Compilation des tests unitaires (salarieTest)

# Pour inclure la bibliothèque GoogleTest au projet (en allant la chercher sur GitHub
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# Pour Windows: empêche la redéfinition des réglages de compilation/édition de lien du projet "parent"
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(salarieTest salarieTest.cpp Salarie.h Salarie.cpp SalarieException.h)
# Il faut lier l'exécutable à la bibliothèque gtest_main
target_link_libraries(salarieTest gtest_main)