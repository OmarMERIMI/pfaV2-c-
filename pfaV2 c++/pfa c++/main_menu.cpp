#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include "globals.hpp"
#include "utils.hpp"
#include "RendezVous.hpp"
#include "SalleDeTraitement.hpp"


// Fonctions utilitaires
// void clearScreen() {
//     system("cls");
// }

// void pauseScreen() {
//     std::cout << "Appuyez sur Entree pour continuer...";
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     std::cin.get();
// }

// Fonctions de gestion des patients
void afficherPatients() {
    clearScreen();
    std::cout << "=== Liste des Patients ===" << std::endl;
    
    if (patients.empty()) {
        std::cout << "Aucun patient enregistré." << std::endl;
    } else {
        for (size_t i = 0; i < patients.size(); i++) {
            std::cout << i+1 << ". " << patients[i].getNom() << " " << patients[i].getPrenom() 
                      << " (ID: " << patients[i].getId() << ")" << std::endl;
        }
    }
    
    pauseScreen();
}

void ajouterPatient() {
    clearScreen();
    std::cout << "=== Ajouter un Patient ===" << std::endl;
    
    int id;
    std::string username, password, nom, prenom, dateNaissance, historiqueMedical;
    
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Nom d'utilisateur: ";
    std::getline(std::cin, username);
    
    std::cout << "Mot de passe: ";
    std::getline(std::cin, password);
    
    std::cout << "Nom: ";
    std::getline(std::cin, nom);
    
    std::cout << "Prenom: ";
    std::getline(std::cin, prenom);
    
    std::cout << "Date de naissance (JJ/MM/AAAA): ";
    std::getline(std::cin, dateNaissance);
    
    std::cout << "Historique medical: ";
    std::getline(std::cin, historiqueMedical);
    
    Patient nouveauPatient(id, username, password, nom, prenom, dateNaissance, historiqueMedical);
    patients.push_back(nouveauPatient);
    
    std::cout << "\nPatient ajoute avec succes!" << std::endl;
    pauseScreen();
}

void modifierPatient() {
    clearScreen();
    std::cout << "=== Modifier un Patient ===" << std::endl;
    
    if (patients.empty()) {
        std::cout << "Aucun patient enregistre." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des patients
    for (size_t i = 0; i < patients.size(); i++) {
        std::cout << i+1 << ". " << patients[i].getNom() << " " << patients[i].getPrenom() 
                  << " (ID: " << patients[i].getId() << ")" << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numero du patient a modifier (1-" << patients.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(patients.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    Patient& patient = patients[choix-1];
    
    std::string nom, prenom, dateNaissance, historiqueMedical;
    
    std::cout << "Nouveau nom (" << patient.getNom() << "): ";
    std::getline(std::cin, nom);
    if (!nom.empty()) patient.setNom(nom);
    
    std::cout << "Nouveau prenom (" << patient.getPrenom() << "): ";
    std::getline(std::cin, prenom);
    if (!prenom.empty()) patient.setPrenom(prenom);
    
    std::cout << "Nouvelle date de naissance (" << patient.getDateNaissance() << "): ";
    std::getline(std::cin, dateNaissance);
    if (!dateNaissance.empty()) patient.setDateNaissance(dateNaissance);
    
    std::cout << "Nouvel historique medical (" << patient.getHistoriqueMedical() << "): ";
    std::getline(std::cin, historiqueMedical);
    if (!historiqueMedical.empty()) patient.setHistoriqueMedical(historiqueMedical);
    
    std::cout << "\nPatient modifie avec succes!" << std::endl;
    pauseScreen();
}

void supprimerPatient() {
    clearScreen();
    std::cout << "=== Supprimer un Patient ===" << std::endl;
    
    if (patients.empty()) {
        std::cout << "Aucun patient enregistre." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des patients
    for (size_t i = 0; i < patients.size(); i++) {
        std::cout << i+1 << ". " << patients[i].getNom() << " " << patients[i].getPrenom() 
                  << " (ID: " << patients[i].getId() << ")" << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numero du patient a supprimer (1-" << patients.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(patients.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    patients.erase(patients.begin() + (choix-1));
    
    std::cout << "\nPatient supprime avec succes!" << std::endl;
    pauseScreen();
}

// Fonctions de gestion des rendez-vous
void afficherRendezVous() {
    clearScreen();
    std::cout << "=== Liste des Rendez-vous ===" << std::endl;
    
    if (rendezVous.empty()) {
        std::cout << "Aucun rendez-vous enregistre." << std::endl;
    } else {
        for (size_t i = 0; i < rendezVous.size(); i++) {
            std::cout << i+1 << ". Date: " << rendezVous[i].getDate() 
                      << " à " << rendezVous[i].getHeure() 
                      << " - Statut: " << rendezVous[i].getStatut();
            
            if (rendezVous[i].getPatient()) {
                std::cout << " - Patient: " << rendezVous[i].getPatient()->getNom() 
                          << " " << rendezVous[i].getPatient()->getPrenom();
            }
            
            if (rendezVous[i].getDentiste()) {
                std::cout << " - Dentiste: " << rendezVous[i].getDentiste()->getNom();
            }
            
            if (rendezVous[i].getSalle()) {
                std::cout << " - Salle: " << rendezVous[i].getSalle()->getNom();
            }
            
            std::cout << std::endl;
        }
    }
    
    pauseScreen();
}

void ajouterRendezVous() {
    clearScreen();
    std::cout << "=== Ajouter un Rendez-vous ===" << std::endl;
    
    if (patients.empty()) {
        std::cout << "Aucun patient enregistre. Veuillez d'abord ajouter un patient." << std::endl;
        pauseScreen();
        return;
    }
    
    if (dentistes.empty()) {
        std::cout << "Aucun dentiste enregistre. Veuillez d'abord ajouter un dentiste." << std::endl;
        pauseScreen();
        return;
    }
    
    if (salles.empty()) {
        std::cout << "Aucune salle de traitement enregistree. Veuillez d'abord ajouter une salle." << std::endl;
        pauseScreen();
        return;
    }
    
    std::string date, heure, statut = "en attente";
    
    std::cout << "Date (JJ/MM/AAAA): ";
    std::getline(std::cin, date);
    
    std::cout << "Heure (HH:MM): ";
    std::getline(std::cin, heure);
    
    // Afficher la liste des patients
    std::cout << "\n=== Selectionner un Patient ===" << std::endl;
    for (size_t i = 0; i < patients.size(); i++) {
        std::cout << i+1 << ". " << patients[i].getNom() << " " << patients[i].getPrenom() << std::endl;
    }
    
    int choixPatient;
    std::cout << "Entrez le numéro du patient (1-" << patients.size() << "): ";
    std::cin >> choixPatient;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choixPatient < 1 || choixPatient > static_cast<int>(patients.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des dentistes
    std::cout << "\n=== Selectionner un Dentiste ===" << std::endl;
    for (size_t i = 0; i < dentistes.size(); i++) {
        std::cout << i+1 << ". Dr. " << dentistes[i].getNom() 
                  << " (" << dentistes[i].getSpecialite() << ")" << std::endl;
    }
    
    int choixDentiste;
    std::cout << "Entrez le numéro du dentiste (1-" << dentistes.size() << "): ";
    std::cin >> choixDentiste;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choixDentiste < 1 || choixDentiste > static_cast<int>(dentistes.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des salles de traitement
    std::cout << "\n=== Selectionner une Salle de Traitement ===" << std::endl;
    for (size_t i = 0; i < salles.size(); i++) {
        std::cout << i+1 << ". Salle " << salles[i].getNom() 
                  << " (Statut: " << salles[i].getStatut() << ")" << std::endl;
    }
    
    int choixSalle;
    std::cout << "Entrez le numero de la salle (1-" << salles.size() << "): ";
    std::cin >> choixSalle;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choixSalle < 1 || choixSalle > static_cast<int>(salles.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    RendezVous nouveauRdv(date, heure, statut);
    nouveauRdv.setPatient(&patients[choixPatient-1]);
    nouveauRdv.setDentiste(&dentistes[choixDentiste-1]);
    nouveauRdv.setSalle(&salles[choixSalle-1]);
    
    rendezVous.push_back(nouveauRdv);
    
    std::cout << "\nRendez-vous ajoute avec succes!" << std::endl;
    pauseScreen();
}

void modifierRendezVous() {
    clearScreen();
    std::cout << "=== Modifier un Rendez-vous ===" << std::endl;
    
    if (rendezVous.empty()) {
        std::cout << "Aucun rendez-vous enregistre." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des rendez-vous
    for (size_t i = 0; i < rendezVous.size(); i++) {
        std::cout << i+1 << ". Date: " << rendezVous[i].getDate() 
                  << " à " << rendezVous[i].getHeure() 
                  << " - Statut: " << rendezVous[i].getStatut();
        
        if (rendezVous[i].getPatient()) {
            std::cout << " - Patient: " << rendezVous[i].getPatient()->getNom() 
                      << " " << rendezVous[i].getPatient()->getPrenom();
        }
        
        std::cout << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numero du rendez-vous à modifier (1-" << rendezVous.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(rendezVous.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    RendezVous& rdv = rendezVous[choix-1];
    
    std::string date, heure, statut;
    
    std::cout << "Nouvelle date (" << rdv.getDate() << "): ";
    std::getline(std::cin, date);
    if (!date.empty()) rdv.setDate(date);
    
    std::cout << "Nouvelle heure (" << rdv.getHeure() << "): ";
    std::getline(std::cin, heure);
    if (!heure.empty()) rdv.setHeure(heure);
    
    std::cout << "Nouveau statut (" << rdv.getStatut() << ") [en attente/confirme/annule]: ";
    std::getline(std::cin, statut);
    if (!statut.empty()) rdv.setStatut(statut);
    
    std::cout << "\nRendez-vous modifié avec succes!" << std::endl;
    pauseScreen();
}

void supprimerRendezVous() {
    clearScreen();
    std::cout << "=== Supprimer un Rendez-vous ===" << std::endl;
    
    if (rendezVous.empty()) {
        std::cout << "Aucun rendez-vous enregistre." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des rendez-vous
    for (size_t i = 0; i < rendezVous.size(); i++) {
        std::cout << i+1 << ". Date: " << rendezVous[i].getDate() 
                  << " à " << rendezVous[i].getHeure() 
                  << " - Statut: " << rendezVous[i].getStatut();
        
        if (rendezVous[i].getPatient()) {
            std::cout << " - Patient: " << rendezVous[i].getPatient()->getNom() 
                      << " " << rendezVous[i].getPatient()->getPrenom();
        }
        
        std::cout << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numéro du rendez-vous à supprimer (1-" << rendezVous.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(rendezVous.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    rendezVous.erase(rendezVous.begin() + (choix-1));
    
    std::cout << "\nRendez-vous supprimé avec succes!" << std::endl;
    pauseScreen();
}

// Fonctions de gestion des salles de traitement
void afficherSalles() {
    clearScreen();
    std::cout << "=== Liste des Salles de Traitement ===" << std::endl;
    
    if (salles.empty()) {
        std::cout << "Aucune salle de traitement enregistree." << std::endl;
    } else {
        for (size_t i = 0; i < salles.size(); i++) {
            std::cout << i+1 << ". Salle " << salles[i].getNom() 
                      << " (Equipements: " << salles[i].getEquipements() << ")" 
                      << " (Statut: " << salles[i].getStatut() << ")" 
                      << " (ID: " << salles[i].getId() << ")" << std::endl;
        }
    }
    
    pauseScreen();
}

void ajouterSalle() {
    clearScreen();
    std::cout << "=== Ajouter une Salle de Traitement ===" << std::endl;
    
    int id;
    std::string nom, equipements, statut;
    
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Nom de la salle: ";
    std::getline(std::cin, nom);
    
    std::cout << "Equipements: ";
    std::getline(std::cin, equipements);
    
    std::cout << "Statut (disponible/occupee/en maintenance): ";
    std::getline(std::cin, statut);
    
    SalleDeTraitement nouvelleSalle(id, nom, equipements, statut);
    salles.push_back(nouvelleSalle);
    
    std::cout << "\nSalle de traitement ajoutee avec succes!" << std::endl;
    pauseScreen();
}

void modifierSalle() {
    clearScreen();
    std::cout << "=== Modifier une Salle de Traitement ===" << std::endl;
    
    if (salles.empty()) {
        std::cout << "Aucune salle de traitement enregistree." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des salles
    for (size_t i = 0; i < salles.size(); i++) {
        std::cout << i+1 << ". Salle " << salles[i].getNom() 
                  << " (Statut: " << salles[i].getStatut() << ")" << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numéro de la salle à modifier (1-" << salles.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(salles.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    SalleDeTraitement& salle = salles[choix-1];
    
    std::string nom, equipements, statut;
    
    std::cout << "Nouveau nom (" << salle.getNom() << "): ";
    std::getline(std::cin, nom);
    if (!nom.empty()) salle.setNom(nom);
    
    std::cout << "Nouveaux equipements (" << salle.getEquipements() << "): ";
    std::getline(std::cin, equipements);
    if (!equipements.empty()) salle.setEquipements(equipements);
    
    std::cout << "Nouveau statut (" << salle.getStatut() << ") [disponible/occupee/en maintenance]: ";
    std::getline(std::cin, statut);
    if (!statut.empty()) salle.setStatut(statut);
    
    std::cout << "\nSalle de traitement modifiee avec succes!" << std::endl;
    pauseScreen();
}

void supprimerSalle() {
    clearScreen();
    std::cout << "=== Supprimer une Salle de Traitement ===" << std::endl;
    
    if (salles.empty()) {
        std::cout << "Aucune salle de traitement enregistree." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des salles
    for (size_t i = 0; i < salles.size(); i++) {
        std::cout << i+1 << ". Salle " << salles[i].getNom() 
                  << " (Statut: " << salles[i].getStatut() << ")" << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numéro de la salle a supprimer (1-" << salles.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(salles.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    salles.erase(salles.begin() + (choix-1));
    
    std::cout << "\nSalle de traitement supprimee avec succes!" << std::endl;
    pauseScreen();
}

// Fonctions de gestion des assistants
void afficherAssistants() {
    clearScreen();
    std::cout << "=== Liste des Assistants ===" << std::endl;
    
    if (assistants.empty()) {
        std::cout << "Aucun assistant enregistre." << std::endl;
    } else {
        for (size_t i = 0; i < assistants.size(); i++) {
            std::cout << i+1 << ". " << assistants[i].getNom() << " " << assistants[i].getPrenom() 
                      << " (ID: " << assistants[i].getId() << ")" << std::endl;
        }
    }
    
    pauseScreen();
}

void ajouterAssistant() {
    clearScreen();
    std::cout << "=== Ajouter un Assistant ===" << std::endl;
    
    int id;
    std::string username, password, nom, prenom;
    
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Nom d'utilisateur: ";
    std::getline(std::cin, username);
    
    std::cout << "Mot de passe: ";
    std::getline(std::cin, password);
    
    std::cout << "Nom: ";
    std::getline(std::cin, nom);
    
    std::cout << "Prénom: ";
    std::getline(std::cin, prenom);
    
    Assistant nouveauAssistant(id, username, password, nom, prenom);
    assistants.push_back(nouveauAssistant);
    
    std::cout << "\nAssistant ajoute avec succes!" << std::endl;
    pauseScreen();
}

void modifierAssistant() {
    clearScreen();
    std::cout << "=== Modifier un Assistant ===" << std::endl;
    
    if (assistants.empty()) {
        std::cout << "Aucun assistant enregistre." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des assistants
    for (size_t i = 0; i < assistants.size(); i++) {
        std::cout << i+1 << ". " << assistants[i].getNom() << " " << assistants[i].getPrenom() << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numéro de l'assistant à modifier (1-" << assistants.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(assistants.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    Assistant& assistant = assistants[choix-1];
    
    std::string nom, prenom;
    
    std::cout << "Nouveau nom (" << assistant.getNom() << "): ";
    std::getline(std::cin, nom);
    if (!nom.empty()) assistant.setNom(nom);
    
    std::cout << "Nouveau prenom (" << assistant.getPrenom() << "): ";
    std::getline(std::cin, prenom);
    if (!prenom.empty()) assistant.setPrenom(prenom);
    
    std::cout << "\nAssistant modifie avec succes!" << std::endl;
    pauseScreen();
}

void supprimerAssistant() {
    clearScreen();
    std::cout << "=== Supprimer un Assistant ===" << std::endl;
    
    if (assistants.empty()) {
        std::cout << "Aucun assistant enregistre." << std::endl;
        pauseScreen();
        return;
    }
    
    // Afficher la liste des assistants
    for (size_t i = 0; i < assistants.size(); i++) {
        std::cout << i+1 << ". " << assistants[i].getNom() << " " << assistants[i].getPrenom() << std::endl;
    }
    
    int choix;
    std::cout << "\nEntrez le numéro de l'assistant à supprimer (1-" << assistants.size() << "): ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choix < 1 || choix > static_cast<int>(assistants.size())) {
        std::cout << "Choix invalide!" << std::endl;
        pauseScreen();
        return;
    }
    
    assistants.erase(assistants.begin() + (choix-1));
    
    std::cout << "\nAssistant supprime avec succes!" << std::endl;
    pauseScreen();
}

// Menu principal
void afficherMenuPrincipal() {
    clearScreen();
    std::cout << "======================================" << std::endl;
    std::cout << "   GESTION DE CABINET DENTAIRE" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "1. Gestion des Patients" << std::endl;
    std::cout << "2. Gestion des Rendez-vous" << std::endl;
    std::cout << "3. Gestion des Salles de Traitement" << std::endl;
    std::cout << "4. Gestion des Assistants" << std::endl;
    std::cout << "5. Quitter" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Votre choix: ";
}

void menuPatients() {
    int choix = 0;
    
    while (choix != 5) {
        clearScreen();
        std::cout << "======================================" << std::endl;
        std::cout << "   GESTION DES PATIENTS" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "1. Afficher tous les patients" << std::endl;
        std::cout << "2. Ajouter un patient" << std::endl;
        std::cout << "3. Modifier un patient" << std::endl;
        std::cout << "4. Supprimer un patient" << std::endl;
        std::cout << "5. Retour au menu principal" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                afficherPatients();
                break;
            case 2:
                ajouterPatient();
                break;
            case 3:
                modifierPatient();
                break;
            case 4:
                supprimerPatient();
                break;
            case 5:
                // Retour au menu principal
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
                break;
        }
    }
}

void menuRendezVous() {
    int choix = 0;
    
    while (choix != 5) {
        clearScreen();
        std::cout << "======================================" << std::endl;
        std::cout << "   GESTION DES RENDEZ-VOUS" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "1. Afficher tous les rendez-vous" << std::endl;
        std::cout << "2. Ajouter un rendez-vous" << std::endl;
        std::cout << "3. Modifier un rendez-vous" << std::endl;
        std::cout << "4. Supprimer un rendez-vous" << std::endl;
        std::cout << "5. Retour au menu principal" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                afficherRendezVous();
                break;
            case 2:
                ajouterRendezVous();
                break;
            case 3:
                modifierRendezVous();
                break;
            case 4:
                supprimerRendezVous();
                break;
            case 5:
                // Retour au menu principal
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
                break;
        }
    }
}

void menuSalles() {
    int choix = 0;
    
    while (choix != 5) {
        clearScreen();
        std::cout << "======================================" << std::endl;
        std::cout << "   GESTION DES SALLES DE TRAITEMENT" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "1. Afficher toutes les salles" << std::endl;
        std::cout << "2. Ajouter une salle" << std::endl;
        std::cout << "3. Modifier une salle" << std::endl;
        std::cout << "4. Supprimer une salle" << std::endl;
        std::cout << "5. Retour au menu principal" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                afficherSalles();
                break;
            case 2:
                ajouterSalle();
                break;
            case 3:
                modifierSalle();
                break;
            case 4:
                supprimerSalle();
                break;
            case 5:
                // Retour au menu principal
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
                break;
        }
    }
}

void menuAssistants() {
    int choix = 0;
    
    while (choix != 5) {
        clearScreen();
        std::cout << "======================================" << std::endl;
        std::cout << "   GESTION DES ASSISTANTS" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "1. Afficher tous les assistants" << std::endl;
        std::cout << "2. Ajouter un assistant" << std::endl;
        std::cout << "3. Modifier un assistant" << std::endl;
        std::cout << "4. Supprimer un assistant" << std::endl;
        std::cout << "5. Retour au menu principal" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                afficherAssistants();
                break;
            case 2:
                ajouterAssistant();
                break;
            case 3:
                modifierAssistant();
                break;
            case 4:
                supprimerAssistant();
                break;
            case 5:
                // Retour au menu principal
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
                break;
        }
    }
}

// Fonction principale
int main() {
    // Ajouter quelques données de test
    Patient patient1(1, "omarpa", "omarpa123", "omar", "merimi", "15/05/1980", "Allergie au latex");
    Dentiste dentiste1(2, "omarde", "omarde123", "achraf", "elghali");
    Assistant assistant1(3, "omaras", "omaras123", "rania", "dahani");
    
    patients.push_back(patient1);
    dentistes.push_back(dentiste1);
    assistants.push_back(assistant1);
    
    int choix = 0;
    
    while (choix != 5) {
        afficherMenuPrincipal();
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                menuPatients();
                break;
            case 2:
                menuRendezVous();
                break;
            case 3:
                menuSalles();
                break;
            case 4:
                menuAssistants();
                break;
            case 5:
                std::cout << "\nMerci d'avoir utilise notre application!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
                break;
        }
    }
    
    return 0;
}