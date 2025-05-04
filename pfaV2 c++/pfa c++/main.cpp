#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "Responsable.hpp"
#include "UtilityFunctions.hpp"

// Simulation de données pour les dentistes, assistants, et patients
struct RendezVous {
    std::string date;
    std::string heure;
    std::string patient;
    std::string dentiste;
};

struct DossierPatient {
    std::string nom;
    std::string prenom;
    std::string dateDeNaissance;
    std::string historiqueMédical;
};

std::vector<DossierPatient> patients;
std::vector<RendezVous> rendezVous;

// Fonction pour effacer l'écran
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";  // Cette séquence fonctionne sous Unix (Linux, MacOS) pour nettoyer l'écran
}

// Fonction pour mettre en pause et attendre une touche
void pauseScreen() {
    std::cout << "Appuyez sur Enter pour continuer..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Fonction pour vérifier les identifiants de connexion
bool verifierConnexion(const std::string& username, const std::string& password, const std::string& role) {
    // Vérification selon le rôle (Responsable, Assistant, Patient)
    if (role == "Responsable") {
        return (username == "admin" && password == "admin");
    } else if (role == "Assistant") {
        return (username == "assistant" && password == "assistant");
    } else if (role == "Patient") {
        return (username == "patient" && password == "patient");
    }
    return false;
}

// Menu principal
void afficherMenuPrincipal() {
    int choix = 0;
    do {
        clearScreen();
        std::cout << "=== GESTION DE CABINET DENTAIRE ===" << std::endl;
        std::cout << "1. Connexion comme Responsable" << std::endl;
        std::cout << "2. Connexion comme Assistant" << std::endl;
        std::cout << "3. Connexion comme Patient" << std::endl;
        std::cout << "4. Quitter" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(choix) {
            case 1:
                verifierConnexionUtilisateur("Responsable");
                break;
            case 2:
                verifierConnexionUtilisateur("Assistant");
                break;
            case 3:
                verifierConnexionUtilisateur("Patient");
                break;
            case 4:
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
        }
    } while(choix != 4);
}

// Fonction pour gérer la connexion d'un utilisateur
void verifierConnexionUtilisateur(const std::string& role) {
    std::string username, password;
    bool connecte = false;
    
    do {
        clearScreen();
        std::cout << "=== Connexion " << role << " ===" << std::endl;
        std::cout << "Nom d'utilisateur: ";
        std::getline(std::cin, username);
        std::cout << "Mot de passe: ";
        std::getline(std::cin, password);
        
        if (verifierConnexion(username, password, role)) {
            connecte = true;
            std::cout << "Connexion réussie!" << std::endl;
            pauseScreen();
            if (role == "Responsable") {
                afficherMenuAdmin();
            } else if (role == "Assistant") {
                afficherMenuAssistant();
            } else if (role == "Patient") {
                afficherMenuPatient();
            }
        } else {
            std::cout << "Identifiants incorrects. Reessayez." << std::endl;
            pauseScreen();
        }
    } while (!connecte);
}

// Menu Administrateur
void afficherMenuAdmin() {
    int choix = 0;
    do {
        clearScreen();
        std::cout << "=== Menu Administrateur ===" << std::endl;
        std::cout << "Connecté en tant que: Admin Principal (admin)" << std::endl;
        std::cout << "\n1. Gérer les utilisateurs" << std::endl;
        std::cout << "2. Générer des rapports" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        std::cout << "\nVotre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(choix) {
            case 1:
                clearScreen();
                gererUtilisateurs();
                pauseScreen();
                break;
            case 2:
                clearScreen();
                genererRapports();
                pauseScreen();
                break;
            case 0:
                std::cout << "Déconnexion..." << std::endl;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
        }
    } while(choix != 0);
}

// Menu Assistant
void afficherMenuAssistant() {
    int choix = 0;
    do {
        clearScreen();
        std::cout << "=== Menu Assistant ===" << std::endl;
        std::cout << "Connecté en tant qu'Assistant" << std::endl;
        std::cout << "\n1. Gérer les rendez-vous" << std::endl;
        std::cout << "2. Gérer les salles de traitement" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        std::cout << "\nVotre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(choix) {
            case 1:
                clearScreen();
                gererRendezVous();
                pauseScreen();
                break;
            case 2:
                clearScreen();
                gererSallesTraitement();
                pauseScreen();
                break;
            case 0:
                std::cout << "Déconnexion..." << std::endl;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
        }
    } while(choix != 0);
}

// Menu Patient
void afficherMenuPatient() {
    int choix = 0;
    do {
        clearScreen();
        std::cout << "=== Menu Patient ===" << std::endl;
        std::cout << "Connecté en tant que: Patient" << std::endl;
        std::cout << "\n1. Prendre un rendez-vous" << std::endl;
        std::cout << "2. Voir votre dossier patient" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        std::cout << "\nVotre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(choix) {
            case 1:
                clearScreen();
                prendreRendezVous();
                pauseScreen();
                break;
            case 2:
                clearScreen();
                voirDossierPatient();
                pauseScreen();
                break;
            case 0:
                std::cout << "Déconnexion..." << std::endl;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
        }
    } while(choix != 0);
}

// Fonction pour prendre un rendez-vous
void prendreRendezVous() {
    std::cout << "=== Prendre un rendez-vous ===" << std::endl;
    std::string date, heure, patient, dentiste;
    std::cout << "Entrez la date du rendez-vous (ex: 2025-05-10): ";
    std::getline(std::cin, date);
    std::cout << "Entrez l'heure du rendez-vous (ex: 14:30): ";
    std::getline(std::cin, heure);
    std::cout << "Entrez votre nom (patient): ";
    std::getline(std::cin, patient);
    std::cout << "Entrez le nom du dentiste: ";
    std::getline(std::cin, dentiste);
    
    RendezVous rdv = {date, heure, patient, dentiste};
    rendezVous.push_back(rdv);
    std::cout << "Rendez-vous pris avec succès!" << std::endl;
}

// Fonction pour voir le dossier du patient
void voirDossierPatient() {
    std::cout << "=== Voir votre dossier patient ===" << std::endl;
    std::string patientName;
    std::cout << "Entrez votre nom pour voir le dossier: ";
    std::getline(std::cin, patientName);
    
    bool found = false;
    for (const auto& patient : patients) {
        if (patient.nom == patientName) {
            std::cout << "Dossier de " << patient.nom << " " << patient.prenom << ":" << std::endl;
            std::cout << "Date de naissance: " << patient.dateDeNaissance << std::endl;
            std::cout << "Historique médical: " << patient.historiqueMédical << std::endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Patient non trouvé!" << std::endl;
    }
}

// Fonction pour gérer les rendez-vous
void gererRendezVous() {
    std::cout << "=== Gestion des Rendez-vous ===" << std::endl;
    // Logique pour gérer les rendez-vous ici
    std::cout << "Rendez-vous gérés!" << std::endl;
}

// Fonction pour gérer les salles de traitement
void gererSallesTraitement() {
    std::cout << "=== Gestion des Salles de Traitement ===" << std::endl;
    // Logique pour gérer les salles de traitement ici
    std::cout << "Salles de traitement gérées!" << std::endl;
}

// Gestion des utilisateurs pour l'administrateur
void gererUtilisateurs() {
    int choix = 0;
    do {
        clearScreen();
        std::cout << "=== Gestion des utilisateurs ===" << std::endl;
        std::cout << "1. Afficher tous les dentistes" << std::endl;
        std::cout << "2. Ajouter un dentiste" << std::endl;
        std::cout << "3. Modifier un dentiste" << std::endl;
        std::cout << "4. Supprimer un dentiste" << std::endl;
        std::cout << "5. Afficher tous les assistants" << std::endl;
        std::cout << "6. Ajouter un assistant" << std::endl;
        std::cout << "7. Modifier un assistant" << std::endl;
        std::cout << "8. Supprimer un assistant" << std::endl;
        std::cout << "9. Afficher tous les patients" << std::endl;
        std::cout << "10. Ajouter un patient" << std::endl;
        std::cout << "11. Modifier un patient" << std::endl;
        std::cout << "12. Supprimer un patient" << std::endl;
        std::cout << "13. Retour" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(choix) {
            case 1:
                // Afficher les dentistes
                break;
            case 2:
                // Ajouter un dentiste
                break;
            case 3:
                // Modifier un dentiste
                break;
            case 4:
                // Supprimer un dentiste
                break;
            case 5:
                // Afficher les assistants
                break;
            case 6:
                // Ajouter un assistant
                break;
            case 7:
                // Modifier un assistant
                break;
            case 8:
                // Supprimer un assistant
                break;
            case 9:
                // Afficher les patients
                break;
            case 10:
                // Ajouter un patient
                break;
            case 11:
                // Modifier un patient
                break;
            case 12:
                // Supprimer un patient
                break;
            case 13:
                return;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
        }
    } while(choix != 13);
}

// Fonction pour générer des rapports
void genererRapports() {
    int choix = 0;
    do {
        clearScreen();
        std::cout << "=== Génération des rapports ===" << std::endl;
        std::cout << "1. Voir les rapports" << std::endl;
        std::cout << "2. Modifier un rapport" << std::endl;
        std::cout << "0. Retour" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(choix) {
            case 1:
                // Voir les rapports
                break;
            case 2:
                // Modifier un rapport
                break;
            case 0:
                return;
            default:
                std::cout << "Choix invalide!" << std::endl;
                pauseScreen();
        }
    } while(choix != 0);
}

int main() {
    afficherMenuPrincipal();
    return 0;
}










// #include <iostream>
// #include <string>
// #include <limits>
// #include "Responsable.hpp"
// #include "UtilityFunctions.hpp"

// // Fonction pour vérifier les identifiants de connexion
// bool verifierConnexion(const std::string& username, const std::string& password, Responsable& admin) {
//     return (username == admin.getUsername() && password == admin.getPassword());
// }

// // Menu principal administrateur
// void afficherMenuAdmin(Responsable& admin) {
//     int choix = 0;
//     do {
//         clearScreen();
//         std::cout << "=== Menu Administrateur ===" << std::endl;
//         std::cout << "Connecte en tant que: " << admin.getNom() << " " << admin.getPrenom() << " (" << admin.getUsername() << ")" << std::endl;
//         std::cout << "\n1. Gerer les utilisateurs" << std::endl;
//         std::cout << "2. Generer des rapports" << std::endl;
//         std::cout << "0. Se deconnecter" << std::endl;
//         std::cout << "\nVotre choix: ";
//         std::cin >> choix;
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         switch(choix) {
//             case 1:
//                 clearScreen();
//                 admin.gererUtilisateurs();
//                 pauseScreen();
//                 break;
//             case 2:
//                 clearScreen();
//                 admin.genererRapports();
//                 pauseScreen();
//                 break;
//             case 0:
//                 std::cout << "Déconnexion..." << std::endl;
//                 break;
//             default:
//                 std::cout << "Choix invalide!" << std::endl;
//                 pauseScreen();
//         }
//     } while(choix != 0);
// }

// int main() {
//     Responsable admin(1, "admin", "admin", "Admin", "Principal"); // Assurez-vous que le constructeur est correctement défini dans Responsable.cpp
//     std::string username, password;
//     bool connecte = false;
//     do {
//         clearScreen();
//         std::cout << "=== Connexion Administrateur ===" << std::endl;
//         std::cout << "Nom d'utilisateur: ";
//         std::getline(std::cin, username);
//         std::cout << "Mot de passe: ";
//         std::getline(std::cin, password);
//         if (verifierConnexion(username, password, admin)) {
//             connecte = true;
//             std::cout << "Connexion reussie!" << std::endl;
//             pauseScreen();
//             afficherMenuAdmin(admin);
//         } else {
//             std::cout << "Identifiants incorrects. Reessayez." << std::endl;
//             pauseScreen();
//         }
//     } while(!connecte);
//     std::cout << "Au revoir!" << std::endl;
//     return 0;
// }