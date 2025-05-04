#ifndef FACTURE_HPP
#define FACTURE_HPP

#include <string>

// Déclarations anticipées
class Patient;
class Dentiste;

class Facture {
private:
    int id;
    std::string dateEmission; // Utilisation de string pour simplifier
    float montant;
    std::string statut; // ex: payée, en attente, annulée
    Patient* patient;
    Dentiste* dentiste;

public:
    // Constructeurs et destructeur
    Facture();
    Facture(int id, const std::string& dateEmission, float montant, const std::string& statut);
    ~Facture();

    // Getters et setters
    int getId() const;
    void setId(int id);
    std::string getDateEmission() const;
    void setDateEmission(const std::string& dateEmission);
    float getMontant() const;
    void setMontant(float montant);
    std::string getStatut() const;
    void setStatut(const std::string& statut);
    Patient* getPatient() const;
    void setPatient(Patient* patient);
    Dentiste* getDentiste() const;
    void setDentiste(Dentiste* dentiste);

    // Méthodes spécifiques
    float calculerMontant();
    void payer();
};

#endif // FACTURE_H