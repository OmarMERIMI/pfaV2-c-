#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP

#include <iostream>
#include <limits>

void clearScreen() {
    system("cls");
}
void clearScreen();
void pauseScreen();
void verifierConnexionUtilisateur(const std::string& role);
void afficherMenuAdmin();
void afficherMenuAssistant();
void afficherMenuPatient();
void gererRendezVous();
void gererSallesTraitement();
void prendreRendezVous();
void voirDossierPatient();
void gererUtilisateurs();
void genererRapports();

void pauseScreen() {
    std::cout << "Appuyez sur Entree pour continuer...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

#endif // UTILITY_FUNCTIONS_H