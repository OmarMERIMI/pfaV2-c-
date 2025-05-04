
#include <iostream>
#include <vector>
#include <limits>
#include "Patient.hpp"
#include "Dentiste.hpp"
#include "Assistant.hpp"
#include "Responsable.hpp"
#include "globals.hpp"

// Déclarations externes pour accéder aux vecteurs globaux définis dans main_menu.cpp


// Assurez-vous que ces vecteurs sont correctement définis dans main_menu.cpp

// Constructeurs et destructeur
Responsable::Responsable() : Utilisateur(), nom(""), prenom("") {
}

Responsable::Responsable(int id, const std::string& username, const std::string& password,
                       const std::string& nom, const std::string& prenom)
    : Utilisateur(id, username, password), nom(nom), prenom(prenom) {
}

Responsable::~Responsable() {
}

// Getters et setters
std::string Responsable::getNom() const {
    return nom;
}

void Responsable::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Responsable::getPrenom() const {
    return prenom;
}

void Responsable::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

// Méthodes spécifiques
void Responsable::gererUtilisateurs() {
    int choix = 0;
    while (choix != 5) {
        std::cout << "\n=== Gestion des utilisateurs ===" << std::endl;
        std::cout << "1. Afficher tous les utilisateurs" << std::endl;
        std::cout << "2. Ajouter un utilisateur" << std::endl;
        std::cout << "3. Modifier un utilisateur" << std::endl;
        std::cout << "4. Supprimer un utilisateur" << std::endl;
        std::cout << "5. Retour" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choix) {
            case 1:
                std::cout << "\n--- Liste des Patients ---" << std::endl;
                for (size_t i = 0; i < patients.size(); ++i) {
                    std::cout << i+1 << ". Patient: " << patients[i].getNom() << " " << patients[i].getPrenom() << " (ID: " << patients[i].getId() << ")" << std::endl;
                }
                std::cout << "\n--- Liste des Dentistes ---" << std::endl;
                for (size_t i = 0; i < dentistes.size(); ++i) {
                    std::cout << i+1 << ". Dentiste: " << dentistes[i].getNom() << " (ID: " << dentistes[i].getId() << ")" << std::endl;
                }
                std::cout << "\n--- Liste des Assistants ---" << std::endl;
                for (size_t i = 0; i < assistants.size(); ++i) {
                    std::cout << i+1 << ". Assistant: " << assistants[i].getNom() << " (ID: " << assistants[i].getId() << ")" << std::endl;
                }
                std::cout << "\n--- Liste des Responsables ---" << std::endl;
                for (size_t i = 0; i < responsables.size(); ++i) {
                    std::cout << i+1 << ". Responsable: " << responsables[i].getNom() << " (ID: " << responsables[i].getId() << ")" << std::endl;
                }
                break;
            case 2:
                std::cout << "\nQuel type d'utilisateur voulez-vous ajouter ?" << std::endl;
                std::cout << "1. Patient\n2. Dentiste\n3. Assistant\n4. Responsable" << std::endl;
                int typeAjout;
                std::cout << "Votre choix: ";
                std::cin >> typeAjout;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (typeAjout == 1) {
                    // ajouterPatient();
                    std::cout << "Ajout de patient non implemente." << std::endl;
                } else if (typeAjout == 2) {
                    // ajouterDentiste();
                    std::cout << "Ajout de dentiste non implemente." << std::endl;
                } else if (typeAjout == 3) {
                    // ajouterAssistant();
                    std::cout << "Ajout d'assistant non implemente." << std::endl;
                } else if (typeAjout == 4) {
                    // ajouterResponsable();
                    std::cout << "Ajout de responsable non implemente." << std::endl;
                } else {
                    std::cout << "Type invalide." << std::endl;
                }
                break;
            case 3:
                std::cout << "Modification d'utilisateur non implemente." << std::endl;
                break;
            case 4:
                std::cout << "Suppression d'utilisateur non implemente." << std::endl;
                break;
            case 5:
                std::cout << "Retour au menu precedent." << std::endl;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                break;
        }
    }
}

void Responsable::genererRapports() {
    std::cout << "Le responsable " << nom << " " << prenom << " genere des rapports." << std::endl;
}