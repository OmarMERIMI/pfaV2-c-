#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Structure simplifiée pour les tests
struct DossierPatient {
    std::string nom;
    std::string prenom;
    std::string dateDeNaissance;
    std::string historiqueMedical;
};

struct RendezVous {
    std::string date;
    std::string heure;
    std::string patient;
    std::string dentiste;
};

// Déclaration des vecteurs globaux
std::vector<DossierPatient> patients;
std::vector<RendezVous> rendezVous;

// Fonctions utilitaires
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    std::cout << "\033[2J\033[1;1H";
    #endif
}

void pauseScreen() {
    std::cout << "Appuyez sur Enter pour continuer..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Fonction pour vérifier les identifiants de connexion
bool verifierConnexion(const std::string& username, const std::string& password, const std::string& role) {
    if (role == "Responsable") {
        return (username == "admin" && password == "admin");
    } else if (role == "Assistant") {
        return (username == "assistant" && password == "assistant");
    } else if (role == "Patient") {
        return (username == "patient" && password == "patient");
    }
    return false;
}

// Fonction pour voir le dossier du patient (simplifiée)
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
            std::cout << "Historique médical: " << patient.historiqueMedical << std::endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Patient non trouvé!" << std::endl;
    }
}

// Fonction principale pour tester
int main() {
    // Ajout de données de test
    DossierPatient patient1 = {"Dupont", "Jean", "1980-01-01", "Aucun problème particulier"};
    patients.push_back(patient1);
    
    RendezVous rdv1 = {"2023-06-15", "14:30", "Dupont", "Dr. Martin"};
    rendezVous.push_back(rdv1);
    
    std::cout << "=== Test du système de gestion de cabinet dentaire ===" << std::endl;
    std::cout << "1. Vérification des données patients" << std::endl;
    
    // Affichage des patients pour test
    for (const auto& patient : patients) {
        std::cout << "Patient: " << patient.nom << " " << patient.prenom << std::endl;
    }
    
    std::cout << "\n2. Vérification des rendez-vous" << std::endl;
    for (const auto& rdv : rendezVous) {
        std::cout << "Rendez-vous: " << rdv.date << " à " << rdv.heure 
                  << " pour " << rdv.patient << " avec " << rdv.dentiste << std::endl;
    }
    
    std::cout << "\nTests terminés avec succès!" << std::endl;
    return 0;
}