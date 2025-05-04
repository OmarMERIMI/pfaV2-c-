#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "Utilisateur.hpp"
#include <string>
#include <ctime>

// Déclaration anticipée pour éviter les inclusions circulaires
class DossierPatient;
class RendezVous;

class Patient : public Utilisateur {
private:
    std::string nom;
    std::string prenom;
    std::string dateNaissance; // Utilisation de string pour simplifier
    std::string historiqueMedical;
    DossierPatient* dossier;

public:
    // Constructeurs et destructeur
    Patient();
    Patient(int id, const std::string& username, const std::string& password,
           const std::string& nom, const std::string& prenom, 
           const std::string& dateNaissance, const std::string& historiqueMedical);
    virtual ~Patient();

    // Getters et setters
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getPrenom() const;
    void setPrenom(const std::string& prenom);
    std::string getDateNaissance() const;
    void setDateNaissance(const std::string& dateNaissance);
    std::string getHistoriqueMedical() const;
    void setHistoriqueMedical(const std::string& historiqueMedical);
    DossierPatient* getDossier() const;
    void setDossier(DossierPatient* dossier);

    // Méthodes spécifiques
    void demanderRendezVous();
    void confirmerRendezVous();
    void payerFacture();
};

#endif // PATIENT_H